/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
 *  Copyright (C) 2007 by KURUSUGAWA Electronics Technology Inc
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
 *  @(#) $Id: hw_serial.h,v 1.9 2003/07/08 14:57:15 hiro Exp $
 */

/*
 *	�V���A��I/O�f�o�C�X�iSIO/MCFUART)�h���C�o�iM52235EVB�p�j
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>

#ifndef _MACRO_ONLY
#include "mcfuart.h"

/* ���o�̓|�[�g�̐ݒ��sys_config.c */
/* �����݃x�N�^�ԍ��̐ݒ��hw_serial.h */
/* �Ǘ��u���b�N�̐ݒ��mcfuart.c */

#ifndef GDB_STUB

#define INHNO_SERIAL	 MCF_UART0
#if TNUM_PORT >= 2
#define INHNO_SERIAL2	 MCF_UART1
#endif /* TNUM_PORT >= 2 */

#else	/*  GDB_STUB  */

#define INHNO_SERIAL	 MCF_UART0

#endif	/*  GDB_STUB  */

/*
 *  SIO�h���C�o�̏��������[�`��
 */
#define	sio_initialize	mcfuart_initialize

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
Inline SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB	*siopcb;
	BOOL	openflag;

        /*
	 *  �I�[�v�������|�[�g�����邩�� openflag �ɓǂ�ł����D
	 */
	openflag = mcfuart_openflag(siopid);

	/*
	 *  �f�o�C�X�ˑ��̃I�[�v�������D
	 */
	siopcb = mcfuart_opn_por(siopid, exinf);

	/*
	 *  �V���A��I/O�����݂̊����݃��x����ݒ肵�C�}�X�N����������D
	 */
	if (!openflag) {
            if (siopcb->siopinib->reg_base == (IPSBAR + 0x00000200)) {
                sil_wrb_mem (MCF_INTC_ICR(MCF_INTC0, 13), siopcb->siopinib->int_level);
            } else if (siopcb->siopinib->reg_base == (IPSBAR + 0x00000240)) {
                sil_wrb_mem (MCF_INTC_ICR(MCF_INTC0, 14), siopcb->siopinib->int_level);
            }
        }
	return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
Inline void
sio_cls_por(SIOPCB *siopcb)
{
	/*
	 *  �f�o�C�X�ˑ��̃N���[�Y�����D
	 */
	mcfuart_cls_por(siopcb);

	/*
	 *  �V���A��I/O�����݂��}�X�N����D
	 */
        if (siopcb->siopinib->reg_base == (IPSBAR + 0x00000200)) {
          sil_wrb_mem (MCF_INTC_ICR(MCF_INTC0, 13), 0);
        } else if (siopcb->siopinib->reg_base == (IPSBAR + 0x00000240)) {
          sil_wrb_mem (MCF_INTC_ICR(MCF_INTC0, 14), 0);
        }
}

/*
 *  SIO�̊����݃n���h��
 */
#define	sio_handler	mcfuart_isr
#if TNUM_PORT >= 2
#define	sio_handler2	mcfuart_isr2
#endif /* TNUM_PORT >= 2 */

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
#define	sio_snd_chr	mcfuart_snd_chr

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
#define	sio_rcv_chr	mcfuart_rcv_chr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
#define	sio_ena_cbr	mcfuart_ena_cbr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
#define	sio_dis_cbr	mcfuart_dis_cbr

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
#define	sio_ierdy_snd	mcfuart_ierdy_snd

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
#define	sio_ierdy_rcv	mcfuart_ierdy_rcv

#endif /* _MACRO_ONLY */
#endif /* _HW_SERIAL_H_ */
