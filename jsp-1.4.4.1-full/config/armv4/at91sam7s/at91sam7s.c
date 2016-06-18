/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003      by Advanced Data Controls, Corp
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN  
 *  Copyright (C) 2006 by GJ Business Division RICOH COMPANY,LTD. JAPAN
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
 *  @(#) $Id$
 *  
 */

/*
 * At91sam7s �����@�\�p�h���C�o
 */
#include <s_services.h>
#include <at91sam7s.h>

#define BAUDRATE   115200

/*
 * �V���A��I/O�|�[�g�������u���b�N
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
    {(VP)(TADR_DBGU_BASE),         (VP)(TADR_PIO_BASE+TOFF_PIO_PDR),
     (VP)0,
     (VW)((1<<9)|(1<<10)),         0
    }
#if TNUM_SIOP >= 2
    ,
    {(VP)(TADR_US_BASE+US_WINDOW), (VP)(TADR_PIO_BASE+TOFF_PIO_PDR),
     (VP)(TADR_PMC_BASE+TOFF_PMC_PCER),
     (VW)((1<<21)|(1<<22)),        1<<IRQ_US1_PID
    }

#endif /* TNUM_SIOP >= 2 */
};


/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
SIOPCB  siopcb_table[TNUM_SIOP];


/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)  ((UINT)((siopid) - 1))
#define get_siopcb(siopid)  (&(siopcb_table[INDEX_SIOP(siopid)]))


/*
 * ��������M������?
 */ 
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
    return(((sil_rew_mem((VP)(siopcb->siopinib->uart_base+TOFF_US_CSR)) & US_RXRDY)!=0));
}

/*
 * �����𑗐M�ł��邩?
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
    return((sil_rew_mem((VP)(siopcb->siopinib->uart_base+TOFF_US_CSR)) & US_TXEMPTY)!=0);
}

/*
 *  ��M���������̎��o��
 */
Inline UB
uart_getchar(SIOPCB *siopcb)
{
    return(sil_rew_mem((VP)(siopcb->siopinib->uart_base+TOFF_US_RHR)));
}

/*
 *  ���M���镶���̏�������
 */
Inline void
uart_putchar(SIOPCB *siopcb, UB c)
{
    sil_wrw_mem((VP)(siopcb->siopinib->uart_base+TOFF_US_THR),c);
}

/*
 *  ���M�����݋���
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->uart_base+TOFF_US_IER), 1<<1);
}

/*
 *  ���M�����݋֎~
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->uart_base+TOFF_US_IDR), 1<<1);
}


/*
 *  ��M�����݋���
 */
Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->uart_base+TOFF_US_IER), 1<<0);
}

/*
 *  ��M�����݋֎~
 */
Inline void
uart_disable_rcv(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->uart_base+TOFF_US_IDR), 1<<0);
}

/*
 *  SIO�h���C�o�̏��������[�`��
 *  1�|�[�g�����Ȃ����߁C���܂�Ӗ��͂Ȃ�
 */
void
uart_initialize()
{
    SIOPCB  *siopcb;
    UINT    i;

    /*
     *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
     */
    for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
        siopcb->siopinib = &(siopinib_table[i]);
        siopcb->openflag = FALSE;
        siopcb->sendflag = FALSE;
    }
}

/*
 * �I�[�v�����Ă���|�[�g�����邩
 */
BOOL
uart_openflag(void)
{
    return(siopcb_table[0].openflag);
}

/*
 * �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
    unsigned int baud = ((MCK * 10) / (BAUDRATE * 16));

    SIOPCB      *siopcb;
    const SIOPINIB  *siopinib;

    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;

    /*
     * Wait ������D
     */
    sil_dly_nse(5000);

    if(siopinib->pmc_pcer)
        sil_wrw_mem((VP)siopinib->pmc_pcer, siopinib->irq_bit);
    /* Disable Interrupt */
    sil_wrw_mem((VP)(siopinib->uart_base+TOFF_US_IDR), 0xFFFFFFFF);
    sil_wrw_mem((VP)(siopinib->uart_base+TOFF_US_CR), (US_RSTRX|US_RSTTX|US_RXDIS|US_TXDIS));
    sil_wrw_mem((VP)(siopinib->uart_base+TOFF_PDC_RCR), 0);
    sil_wrw_mem((VP)(siopinib->uart_base+TOFF_PDC_TCR), 0);
    sil_wrw_mem((VP)siopinib->linectrl_pdr, siopinib->pdr_bit);
    /* 8Data, 1Stop, No Parity */
    sil_wrw_mem((VP)(siopinib->uart_base+TOFF_US_MR), (US_CLKS_MCK|US_CHRL_8|US_PAR_NO|US_NBSTOP_1|US_CHMODE_NORMAL));
    /* 115200bps */
    if((baud % 10) >= 5)
        sil_wrw_mem((VP)(siopinib->uart_base+TOFF_US_BRGR), (baud/10)+1);
    else
        sil_wrw_mem((VP)(siopinib->uart_base+TOFF_US_BRGR), (baud/10));

    /*
     * �����݊֘A�̐ݒ�
     */
    if(siopinib->pmc_pcer){
        sil_wrw_mem((VP)(siopinib->uart_base+TOFF_US_TTGR), 0);
        sil_wrw_mem((VP)(siopinib->uart_base+TOFF_US_CR), US_TXEN|US_RXEN);
        sil_wrw_mem((VP)(siopinib->uart_base+TOFF_US_IER), 1<<0);
    }
	else{
        /* �N���b�N�C�l�[�u�� */
        sil_wrw_mem((VP)(TADR_PMC_BASE+TOFF_PMC_PCER), (1<<IRQ_TC2_PID));
        /* �^�C�}��~ */
        sil_wrw_mem((VP)(TADR_TC_BASE+TC_WINDOW*2+TOFF_TC_CCR), TC_CLKDIS);
        sil_wrw_mem((VP)(TADR_TC_BASE+TC_WINDOW*2+TOFF_TC_IDR), 0xFFFFFFFF);
        /* �J�E���g�l���Z�b�g */
        sil_wrw_mem((VP)(TADR_TC_BASE+TC_WINDOW*2+TOFF_TC_CMR), TC_CLKS_MCK8);	/* 47,923,200Hz/8=5,990,400Hz */
        sil_wrw_mem((VP)(TADR_TC_BASE+TC_WINDOW*2+TOFF_TC_CMR), sil_rew_mem((VP)(TADR_TC_BASE+TC_WINDOW*2+TOFF_TC_CMR)) | TC_WAVESEL10);
        sil_wrw_mem((VP)(TADR_TC_BASE+TC_WINDOW*2+TOFF_TC_RC), 59900);			/* 10ms */
        /* �����݂̃N���A  */
        sil_wrw_mem((VP)(TADR_TC_BASE+TC_WINDOW*2+TOFF_TC_IER), TC_CPCS);
        /* �J�E���g�X�^�[�g   */
        sil_wrw_mem((VP)(TADR_TC_BASE+TC_WINDOW*2+TOFF_TC_CCR), (TC_CLKEN|TC_SWTRG));

        sil_wrw_mem((VP)(siopinib->uart_base+TOFF_US_CR), US_TXEN|US_RXEN);
    }
    sil_rew_mem((VP)(siopinib->uart_base+TOFF_US_RHR));

    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;

    return(siopcb);
}



/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
uart_cls_por(SIOPCB *siopcb)
{
    const SIOPINIB  *siopinib;

    siopinib = siopcb->siopinib;
	sil_wrw_mem((VP)(siopinib->uart_base+TOFF_US_CR), US_RSTRX|US_RSTTX|US_RXDIS|US_TXDIS);
    siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
uart_snd_chr(SIOPCB *siopcb, char c)
{
    if(siopcb->siopinib->pmc_pcer == 0){
        while(!uart_putready(siopcb));
        uart_putchar(siopcb, c);
        return(TRUE);
    }
    else if (uart_putready(siopcb)){
        uart_putchar(siopcb, c);
        return(TRUE);
    }
    return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
uart_rcv_chr(SIOPCB *siopcb)
{
    if (uart_getready(siopcb)) {
        return((INT)(UB) uart_getchar(siopcb));
    }
    return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
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


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
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



/*
 *  �V���A��I/O�|�[�g�ɑ΂��銄���ݏ���
 */
static void
uart_isr_siop(SIOPCB *siopcb)
{
    if (uart_getready(siopcb)) {
        /*
         *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
         */
        uart_ierdy_rcv(siopcb->exinf);
    }
    if (uart_putready(siopcb)) {
        /*
         *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
         */
        uart_ierdy_snd(siopcb->exinf);
    }
}


/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
void
int_timer2()
{
    SIOPCB *siopcb = &(siopcb_table[0]);

    sil_rew_mem((VP)(TADR_TC_BASE+TC_WINDOW*2+TOFF_TC_SR));
    if (uart_getready(siopcb)) {
        /*
         *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
         */
        uart_ierdy_rcv(siopcb->exinf);
    }
}

#if TNUM_SIOP >= 2
void
uart_isr1()
{
    uart_isr_siop(&(siopcb_table[1]));
}
#endif
