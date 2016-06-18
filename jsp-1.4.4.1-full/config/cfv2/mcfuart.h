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
 *  @(#) $Id: mcfuart.h,v 1.1 2005/07/06 00:45:07 honda Exp $
 */

/*
 *   COLDFIRE����UART�p �ȈՃh���C�o
 */

#ifndef _MCFUART_H_
#define _MCFUART_H_

#include <t_config.h>

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
typedef struct sio_port_initialization_block
{
	UW reg_base;				/* ���W�X�^�̃x�[�X�A�h���X */
	UH brr;					/* �{�[���[�g�̐ݒ�l   */
	UB smr;					/* ���[�h���W�X�^�̐ݒ�l   */
	UB int_level;				/* ���荞�݃��x���̐ݒ�l   */
} SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N
 */
typedef struct sio_port_control_block
{
	const SIOPINIB *siopinib;	/* �V���A��I/O�|�[�g�������u���b�N */
	VP_INT exinf;				/* �g����� */
	BOOL openflag;				/* �I�[�v���ς݃t���O */
	BOOL getready;				/* ��������M������� */
	BOOL putready;				/* �����𑗐M�ł����� */
	VB   imr;				/* �����݃}�X�N�̏�� */
} SIOPCB;

/*
 *  �R���g���[�����W�X�^�̃A�h���X�̃I�t�Z�b�g 
 */
#define MCF_UART_UMR1	0x00
#define MCF_UART_UMR2	0x00
#define MCF_UART_USR	0x04
#define MCF_UART_UCSR	0x04
#define MCF_UART_UCR	0x08
#define MCF_UART_URB	0x0c
#define MCF_UART_UTB	0x0c
#define MCF_UART_UIPCR	0x10
#define MCF_UART_UACR	0x10
#define MCF_UART_UISR	0x14
#define MCF_UART_UIMR	0x14
#define MCF_UART_UBG1	0x18
#define MCF_UART_UBG2	0x1c
#define MCF_UART_UIP	0x34
#define MCF_UART_UOP1	0x38
#define MCF_UART_UOP0	0x3c

/*
 *  �R���g���[�����W�X�^�̐ݒ�l
 */
/*  FIFO�R���g���[�����W�X�^SCFCR�̃r�b�g  */
#define MCF_UART_UCR_RC_MASK  0x03
#define MCF_UART_UCR_RC_EN   0x01
#define MCF_UART_UCR_RC_DIS  0x02
#define MCF_UART_UCR_TC_MASK  0x0C
#define MCF_UART_UCR_TC_EN   0x04
#define MCF_UART_UCR_TC_DIS  0x08
#define MCF_UART_UCR_MISC_MASK 0x70
#define MCF_UART_UCR_MISC_RRC  0x10
#define MCF_UART_UCR_MISC_RR   0x20
#define MCF_UART_UCR_MISC_RT   0x30
#define MCF_UART_UCR_MISC_RE   0x40
#define MCF_UART_UCR_MISC_RBK  0x50
#define MCF_UART_UCR_MISC_SBK  0x60
/*  �V���A���R���g���[�����W�X�^UIMR�̃r�b�g  */
#define MCF_UART_UIMR_TXRDY 0x01
#define MCF_UART_UIMR_RXRDY 0x02
#define MCF_UART_UIMR_DB    0x04
/*  �V���A���R���g���[�����W�X�^UISR�̃r�b�g  */
#define MCF_UART_UISR_TXRDY 0x01
#define MCF_UART_UISR_RXRDY 0x02
#define MCF_UART_UISR_DB    0x04
/*  �V���A���X�e�[�^�X���W�X�^SC1SSR�̃r�b�g  */
#define MCF_UART_USR_RXRDY (0x01)	/* ��M���f�B */
#define MCF_UART_USR_FULL  (0x02)	/* FIFO�t��   */
#define MCF_UART_USR_TXRDY (0x04)	/* ���M���f�B */
#define MCF_UART_USR_TEMP  (0x08)	/* �g�����X�~�b�^�G���v�e�B */
#define MCF_UART_USR_OE    (0x10)	/* �I�[�o�[�����G���[ */
#define MCF_UART_USR_RE    (0x20)	/* �p���e�B�G���[ */
#define MCF_UART_USR_FE    (0x40)	/* �t���[�~���O�G���[ */
#define MCF_UART_USR_RB    (0x80)	/* �u���[�N��M */

/*
 *  UBG�̐ݒ�
 */
#define SMR_CKS 	0x0			/*  ������          */
#define BRR9600 	195 			/*  9600 �r�b�g���[�g    */
#define BRR19200	97			/*  19200 �r�b�g���[�g    */
#define BRR38400	48			/*  38400 �r�b�g���[�g    */
#define BRR57600 	32			/*  57600 �r�b�g���[�g 	*/
#define BRR115200 	16			/*  115200 �r�b�g���[�g */

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND	1u		/* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV	2u		/* ��M�ʒm�R�[���o�b�N */

/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void mcfuart_initialize (void);

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
extern BOOL mcfuart_openflag (ID siopid);

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB *mcfuart_opn_por (ID siopid, VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void mcfuart_cls_por (SIOPCB * siopcb);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL mcfuart_snd_chr (SIOPCB * siopcb, char c);

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT mcfuart_rcv_chr (SIOPCB * siopcb);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void mcfuart_ena_cbr (SIOPCB * siopcb, UINT cbrtn);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void mcfuart_dis_cbr (SIOPCB * siopcb, UINT cbrtn);

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void mcfuart_isr (void);

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void mcfuart_ierdy_snd (VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void mcfuart_ierdy_rcv (VP_INT exinf);

#endif /* _MCFUART_H_ */
