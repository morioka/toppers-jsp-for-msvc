/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: lm32.c,v 1.14 2007/07/27 11:28:44 honda Exp $
 */

#include <s_services.h>
#include <lm32.h>

const SIOPINIB siopinib_table[TNUM_SIOP] = {
    {
        (VP)UART1_RX_TX,
        (VP)UART1_IER,
        (VP)UART1_IIR,
        (VP)UART1_LCR,
        (VP)UART1_MCR,
        (VP)UART1_LSR,
        (VP)UART1_MSR,
        (VP)UART1_DIV
    }
#if TNUM_SIOP >= 2
    ,
    {
        (VP)UART2_RX_TX,
        (VP)UART2_IER,
        (VP)UART2_IIR,
        (VP)UART2_LCR,
        (VP)UART2_MCR,
        (VP)UART2_LSR,
        (VP)UART2_MSR,
        (VP)UART2_DIV
    }
#endif /* TNUM_SIOP >= 2 */
};

SIOPCB  siopcb_table[TNUM_SIOP];

#define INDEX_SIOP(siopid)  ((UINT)((siopid) - 1))
#define get_siopcb(siopid)  (&(siopcb_table[INDEX_SIOP(siopid)]))

Inline BOOL
uart_getready(SIOPCB *siopcb)
{
    return(sil_rew_mem((VP)(siopcb->siopinib->lsr)) & UART_LSR_RX_RDY_MASK);
}

Inline BOOL
uart_putready(SIOPCB *siopcb)
{
    return(sil_rew_mem((VP)(siopcb->siopinib->lsr)) & UART_LSR_TX_RDY_MASK);
}

Inline UB
uart_getchar(SIOPCB *siopcb)
{
    return(sil_rew_mem((VP)(siopcb->siopinib->rxtx)));
}

Inline void
uart_putchar(SIOPCB *siopcb, UB c)
{
    sil_wrw_mem((VP)(siopcb->siopinib->rxtx), c);
}

Inline void
uart_enable_send(SIOPCB *siopcb)
{
	const SIOPINIB *siopinib;
	siopinib = siopcb->siopinib;
	siopcb->ier_snapshot |= UART_IER_TX_INT_MASK;
    sil_wrw_mem((VP)siopinib->ier, siopcb->ier_snapshot);	
}

Inline void
uart_disable_send(SIOPCB *siopcb)
{
	const SIOPINIB *siopinib;
	siopinib = siopcb->siopinib;	
	siopcb->ier_snapshot &= (~UART_IER_TX_INT_MASK);
    sil_wrw_mem((VP)siopinib->ier, siopcb->ier_snapshot);	
}

Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
	const SIOPINIB *siopinib;
	siopinib = siopcb->siopinib;	
	siopcb->ier_snapshot |= UART_IER_RX_INT_MASK;
    sil_wrw_mem((VP)siopinib->ier, siopcb->ier_snapshot);	
}

Inline void
uart_disable_rcv(SIOPCB *siopcb)
{
	const SIOPINIB *siopinib;
	siopinib = siopcb->siopinib;
	siopcb->ier_snapshot &= (~UART_IER_RX_INT_MASK);
    sil_wrw_mem((VP)siopinib->ier, siopcb->ier_snapshot);	
}

void
init_uart(void)
{
    volatile unsigned int divisor;
    UW sr;

    sil_wrw_mem((VP)UART1_IER, 0);

    /* 8Data, 1Stop, No Parity*/
    sil_wrw_mem((VP)UART1_LCR, 0x3);

    /* 115200bps */
    divisor = ((1048576.0 * (DEFAULT_UART_BAUDRATE/100)) / (MICO32_CPU_CLOCK_HZ/100)) + 0.5;
    //divisor = 0x12e0;
    sil_wrw_mem((VP)UART1_DIV, divisor);

    sil_wrw_mem((VP)UART1_IER, UART_IER_RX_INT_MASK);
}

void
uart_putc(char c)
{
	volatile unsigned int lsr;
	
	while(1)
	{
		lsr = sil_rew_mem((VP)(UART1_LSR));
		if(lsr & UART_LSR_TX_RDY_MASK)		
		{
			sil_wrw_mem((VP)UART1_RX_TX, (VW)c);
			return;
		}
	}
}

void
uart_initialize()
{
    SIOPCB  *siopcb;
    UINT    i;

    for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
        siopcb->siopinib = &(siopinib_table[i]);
        siopcb->openflag = FALSE;
        siopcb->sendflag = FALSE;
    }
}

BOOL
uart_openflag(void)
{
    return(siopcb_table[0].openflag);
}

SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
    SIOPCB *siopcb;
    const SIOPINIB *siopinib;
    volatile unsigned int divisor;
    UW sr;

    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;

    sil_wrw_mem((VP)siopinib->ier, 0);

    /* 8Data, 1Stop, No Parity*/
    sil_wrw_mem((VP)siopinib->lcr, 0x3);

    /* 115200bps */
    divisor = ((1048576.0 * (DEFAULT_UART_BAUDRATE/100)) / (MICO32_CPU_CLOCK_HZ/100)) + 0.5;
    //divisor = 0x12e0;
    sil_wrw_mem((VP)siopinib->div, divisor);

    siopcb->ier_snapshot = UART_IER_RX_INT_MASK;
    sil_wrw_mem((VP)siopinib->ier, siopcb->ier_snapshot);
    
    Asm("rcsr %0, im" : "=r"(sr));
    sr |= (1 << INHNO_SIO1);
    Asm("wcsr im, %0" : : "r"(sr) );    
    
    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;
    
    return(siopcb);
}

void
uart_cls_por(SIOPCB *siopcb)
{
	const SIOPINIB *siopinib;
	siopinib = siopcb->siopinib;
    sil_wrw_mem((VP)siopinib->ier, 0);
    siopcb->openflag = FALSE;
}

BOOL
uart_snd_chr(SIOPCB *siopcb, char c)
{
    if (uart_putready(siopcb)){
        uart_putchar(siopcb, c);
        return(TRUE);
    }
    return(FALSE);
}

INT
uart_rcv_chr(SIOPCB *siopcb)
{
    if (uart_getready(siopcb)) {
        return((INT)(UB) uart_getchar(siopcb));
    }
    return(-1);
}

void
uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    switch (cbrtn) {
        case SIO_ERDY_SND:
            uart_enable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            uart_enable_rcv(siopcb);
            break;
    }
}

void
uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    switch (cbrtn) {
        case SIO_ERDY_SND:
            uart_disable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            uart_disable_rcv(siopcb);
            break;
    }
}

static void
uart_isr_siop(SIOPCB *siopcb)
{
	volatile UW iir;
	
	iir = sil_rew_mem((VP)(siopcb->siopinib->iir));
	
    if (uart_getready(siopcb)) {
        uart_ierdy_rcv(siopcb->exinf);
    }
    if (uart_putready(siopcb)) {
        uart_ierdy_snd(siopcb->exinf);
    }
}

void
uart_isr0()
{
    uart_isr_siop(&(siopcb_table[0]));
}

#if TNUM_SIOP >= 2
void
uart_isr1()
{
    uart_isr_siop(&(siopcb_table[1]));
}
#endif

