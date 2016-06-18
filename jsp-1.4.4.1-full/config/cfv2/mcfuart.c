/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
 *  Copyright (C) 2007 by KURUSUGAWA Electronics Industry Inc, JAPAN
 *  Copyright (C) 2008 by Takahisa Yokota
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
 *  @(#) $Id: mcfuart.c,v 1.3 2005/07/06 00:45:07 honda Exp $
 */

/*
 *   COLDFIRE����UART�p �ȈՃh���C�o
 */

#include <s_services.h>
#include "mcfuart.h"

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
/* ���o�̓|�[�g�̐ݒ��sys_config.c */
/* �����݃x�N�^�ԍ��̐ݒ��hw_serial.h */
/* �Ǘ��u���b�N�̐ݒ��mcfuart.c */

#ifndef GDB_STUB

const SIOPINIB siopinib_table[TNUM_PORT] = {
	{IPSBAR + 0x00000200, BRR9600, 0x0, 0x27}, /* UART0 */
#if TNUM_PORT >= 2
	{IPSBAR + 0x00000240, BRR9600, 0x0, 0x27}, /* UART1 */
#endif /* TNUM_PORT >= 2 */
};

#else /* GDB_STUB */

const SIOPINIB siopinib_table[TNUM_PORT] = {
	{IPSBAR + 0x00000200, BRR9600, 0x0, 6}, /* SCIF2 */
};

#endif /* GDB_STUB */

#if defined(TTM)
/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 *  �@2ch�T�|�[�g�Ɋg������ꍇ�͏����l�p�̃f�[�^���܂߂�
 */
struct sio_port_control_block
{
	VP_INT exinf;				/* �g����� */
	BOOL openflag;				/* �I�[�v���ς݃t���O */
};
#endif
/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
static SIOPCB siopcb_table[TNUM_PORT];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  ��������M�ł��邩�H
 */
Inline BOOL
mcfuart_getready (SIOPCB * siopcb)
{
  return (sil_reb_mem((VB *) (siopcb->siopinib->reg_base + MCF_UART_USR)) & MCF_UART_USR_RXRDY);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
mcfuart_putready (SIOPCB * siopcb)
{
  /* Wait until space is available in the FIFO */
  return (sil_reb_mem((VB*)(siopcb->siopinib->reg_base + MCF_UART_USR)) & MCF_UART_USR_TXRDY);
}

/*
 *  ��M���������̎�o��
 */
Inline char
mcfuart_getchar (SIOPCB * siopcb)
{
	VB data;
        data = sil_reb_mem ((VB*)(siopcb->siopinib->reg_base + MCF_UART_URB));
	return data;
}

/*
 *  ���M���镶���̏�����
 */
Inline void
mcfuart_putchar (SIOPCB * siopcb, char c)
{
    /* Send the character */
    sil_wrb_mem ((VB*)(siopcb->siopinib->reg_base + MCF_UART_UTB), c);
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
mcfuart_initialize ()
{
	SIOPCB *siopcb;
	UINT i;
        /*
	 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_PORT; siopcb++, i++) {
		siopcb->openflag = FALSE;
		siopcb->siopinib = (&siopinib_table[i]);
	}
}

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
BOOL
mcfuart_openflag (ID siopid)
{
	return (siopcb_table[siopid -1].openflag);
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
mcfuart_opn_por (ID siopid, VP_INT exinf)
{
        volatile int i;
	SIOPCB *siopcb = get_siopcb(siopid);
        // ���M��~
  	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UCR), (VB) (MCF_UART_UCR_MISC_RR));
    	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UCR), (VB) (MCF_UART_UCR_MISC_RT));
      	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UCR), (VB) (MCF_UART_UCR_MISC_RRC));

        sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UMR1), 0x93);
        sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UMR2), 0x07);
        sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UCSR), 0xDD);

        sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UBG1), (VB) (siopcb->siopinib->brr >> 8));
    	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UBG2), (VB) (siopcb->siopinib->brr & 0x00ff));

         /*  �����݋���  */
        siopcb->imr = (VB)MCF_UART_UIMR_RXRDY;
    	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UIMR), (VB) (siopcb->imr));

        /*  ����M����  */
  	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UCR), (VB) (MCF_UART_UCR_TC_EN | MCF_UART_UCR_RC_EN));

	siopcb->exinf = exinf;
        siopcb->openflag = TRUE;
        if (siopcb->siopinib->reg_base == (IPSBAR + 0x00000200)) {  
          sil_wrw_mem ((VW*)MCF_INTC_IMRL(MCF_INTC0), sil_rew_mem((VW*)MCF_INTC_IMRL(MCF_INTC0)) & (~(1 << (TBIT_GP0))));
        } else if (siopcb->siopinib->reg_base == (IPSBAR + 0x00000240)) {
          sil_wrw_mem ((VW*)MCF_INTC_IMRL(MCF_INTC0), sil_rew_mem((VW*)MCF_INTC_IMRL(MCF_INTC0)) & (~(1 << (TBIT_GP1))));
        }
        for (i = 0; i < 1000;i++);
	return (siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
mcfuart_cls_por (SIOPCB * siopcb)
{
	/*  ����M�֎~  */
  	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UCSR),
				 (VB) (MCF_UART_UCR_TC_DIS | MCF_UART_UCR_RC_DIS));
	/*  �����݋֎~  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UIMR), 0);
        if (siopcb->siopinib->reg_base == (IPSBAR + 0x00000200)) {    
          sil_wrw_mem (MCF_INTC_IMRL(MCF_INTC0), sil_rew_mem(MCF_INTC_IMRL(MCF_INTC0)) | (1 << TBIT_GP0));
        }  else if (siopcb->siopinib->reg_base == (IPSBAR + 0x00000240)) {
          sil_wrw_mem (MCF_INTC_IMRL(MCF_INTC0), sil_rew_mem(MCF_INTC_IMRL(MCF_INTC0)) | (1 << TBIT_GP1));
        }
	siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
mcfuart_snd_chr (SIOPCB * siopcb, char c)
{
	if (mcfuart_putready (siopcb)) {
		mcfuart_putchar (siopcb, c);
		return (TRUE);
	}
	return (FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
mcfuart_rcv_chr (SIOPCB * siopcb)
{
	if (mcfuart_getready (siopcb)) {
		return ((INT) (UB) mcfuart_getchar (siopcb));
	}
	return (-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
mcfuart_ena_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* ���M���荞�ݗv�������� */
                siopcb->imr |= MCF_UART_UIMR_TXRDY;
		break;
	case SIO_ERDY_RCV:			/* ��M���荞�ݗv�������� */
                siopcb->imr |= MCF_UART_UIMR_RXRDY;
		break;
	}
        sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UIMR), siopcb->imr);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
mcfuart_dis_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* ���M���荞�ݗv�����֎~ */
                siopcb->imr &= ~MCF_UART_UIMR_TXRDY;
		break;
	case SIO_ERDY_RCV:			/* ��M���荞�ݗv�����֎~ */
                siopcb->imr &= ~MCF_UART_UIMR_RXRDY;
		break;
	}
        sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UIMR), siopcb->imr);
}

/*
 * �|�[�����O�ɂ�镶���̑��M
 */
void
mcfuart_putc_pol (ID portid, char c)
{
	while (!mcfuart_putready (&siopcb_table[portid - 1]));
	mcfuart_putchar (&siopcb_table[portid - 1], c);
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��鑗�M�����ݏ���
 */
Inline void
mcfuart_isr_siop (SIOPCB * siopcb)
{
	VB uisr = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + MCF_UART_UISR));
        uisr &= siopcb->imr;
	if ((uisr & MCF_UART_UISR_TXRDY) && mcfuart_putready (siopcb)) {
		/*
		 *  ���M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		mcfuart_ierdy_snd (siopcb->exinf);
	}
	else if ((uisr & MCF_UART_UISR_RXRDY) && mcfuart_getready (siopcb)) {
		/*
		 *  ���M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		mcfuart_ierdy_rcv (siopcb->exinf);
        }
}

/* ���荞�݌��o */
void
mcfuart_isr (void)
{
  if (siopcb_table[0].openflag) {
    mcfuart_isr_siop (get_siopcb (1));
  }
}

#if TNUM_PORT >= 2
/* ���荞�݌��o */
void
mcfuart_isr2 (void)
{

  if (siopcb_table[1].openflag) {
    mcfuart_isr_siop (get_siopcb (2));
  }
}
#endif
