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
 *  Copyright (C) 2010 by Cronus Computer Works, JAPAN
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
 *  @(#) $Id: sh7615scif.h,v 1.1 2005/07/06 00:45:07 honda Exp $
 */

/*
 *   SH2�����V���A���R�~���j�P�[�V�����C���^�t�F�[�XSCI�p �ȈՃh���C�o
 */

#ifndef _SH726xSCI_H_
#define _SH726xSCI_H_

#include <t_config.h>

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
typedef struct sio_port_initialization_block
{
	UW reg_base;				/* ���W�X�^�̃x�[�X�A�h���X */
	UB brr;						/* �{�[���[�g�̐ݒ�l   */
	UB smr;						/* ���[�h���W�X�^�̐ݒ�l   */
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
	BOOL sendflag;				/* ���M�����݃C�l�[�u���t���O */
	BOOL getready;				/* ��������M������� */
	BOOL putready;				/* �����𑗐M�ł����� */
} SIOPCB;

/*
 *  �R���g���[�����W�X�^�̃A�h���X�̃I�t�Z�b�g 
 */
#define SCIF_SCFSR	0x10
#define SCIF_SCLSR	0x24
#define SCIF_SCFRDR	0x14
#define SCIF_SCFTDR	0x0c
#define SCIF_SCSCR	0x08
#define SCIF_SCFCR	0x18
#define SCIF_SCSMR	0x00
#define SCIF_SCBRR	0x04

/*
 *  �R���g���[�����W�X�^�̐ݒ�l
 */
/*  FIFO�R���g���[�����W�X�^SCFCR�̃r�b�g  */
#define SCFCR_TFRST	0x0004		/* �g�����X�~�b�gFIFO�f�[�^���W�X�^���Z�b�g */
#define SCFCR_RFRST	0x0002		/* ���V�[�uFIFO�f�[�^���W�X�^���Z�b�g */
/*  �V���A���R���g���[�����W�X�^SCSCR�̃r�b�g  */
#define SCSCR_TIE	0x0080		/* �g�����X�~�b�g�C���^���v�g�C�l�[�u�� */
#define SCSCR_RIE	0x0040		/* ���V�[�u�C���^���v�g�C�l�[�u��   */
#define SCSCR_TE	0x0020		/* �g�����X�~�b�g�C�l�[�u��         */
#define SCSCR_RE	0x0010		/* ���V�[�u�C�l�[�u��           */
/*  �V���A���X�e�[�^�X���W�X�^SC1SSR�̃r�b�g  */
#define SCFSR_TEND	0x0040
#define SCFSR_TDFE	0x0020		/* �g�����X�~�b�gFIFO�f�[�^���W�X�^�G���v�e�B */
#define SCFSR_ER	0x0080		/* ���V�[�u�G���[       */
#define SCFSR_FER	0x0008		/* �t���[�~���O�G���[       */
#define SCFSR_PER	0x0004		/* �p���e�B�G���[       */
#define SCFSR_RDRF	0x0002		/* ���V�[�u�f�[�^���W�X�^�t��       */
#define SCFSR_BRK	0x0010		/* �u���[�N���o */
/*  �V���A���X�e�[�^�X���W�X�^SC2SSR�̃r�b�g  */
#define SCLSR_ORER	0x01		/* �I�[�o�[�����G���[ */

#define sh2scif_DELAY 	1000000


/*
 *  SCIF�̐ݒ�
 */
#define SMR_CKS 	0x0			/*  ������ P���N���b�N/1 [�ύX�s��] */
/* BRR�ݒ�l�̌v�Z */
#define BRR_VALUE(bps)	(((PCLOCK / 32) / (bps)) - 1)

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND	1u		/* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV	2u		/* ��M�ʒm�R�[���o�b�N */

/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void sh2scif_initialize (void);

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
extern BOOL sh2scif_openflag (ID siopid);

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB *sh2scif_opn_por (ID siopid, VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void sh2scif_cls_por (SIOPCB * siopcb);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL sh2scif_snd_chr (SIOPCB * siopcb, char c);

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT sh2scif_rcv_chr (SIOPCB * siopcb);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void sh2scif_ena_cbr (SIOPCB * siopcb, UINT cbrtn);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void sh2scif_dis_cbr (SIOPCB * siopcb, UINT cbrtn);

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void sh2scif_isr (void);

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void sh2scif_ierdy_snd (VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void sh2scif_ierdy_rcv (VP_INT exinf);

#endif /* _SH726xSCI_H_ */
