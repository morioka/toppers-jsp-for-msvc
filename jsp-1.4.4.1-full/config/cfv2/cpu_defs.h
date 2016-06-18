/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2007 by Kurusugawa-Electronics Technology Inc
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
 *  @(#) $Id: cpu_defs.h,v 1.13 2005/11/12 14:58:24 hiro Exp $
 */

/*
 *	�v���Z�b�T�Ɉˑ������`�iCOLDFIRE�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h �� sil.h �ŃC���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃t�@�C�����C��
 *  �N���[�h����O�ɁCt_stddef.h �� itron.h ���C���N���[�h�����̂ŁC
 *  �����Ɉˑ����Ă��悢�D
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

/*
 *  ���[�U�[��`���
 */
#include <user_config.h>	/*  SUPPORT_VXGET_TIM�}�N���̒�`  */

/* �J�[�l���N�����̃��b�Z�[�W   */
#define COPYRIGHT_CPU \
"Copyright (C) 2007 by Kurusugawa-Electronics Industory Inc\n" \
"Copyright (C) 2008 by Takahisa Yokota\n" \
"   \n\n"

#define CFV2		/* �v���Z�b�T���� */

#ifndef _MACRO_ONLY

/*
 *  �����݁^CPU��O�n���h���ԍ��̌^
 */
typedef	UINT	INHNO;		/* �����݃n���h���ԍ� */
typedef	UINT	EXCNO;		/* CPU��O�n���h���ԍ� */

/*
 *  �����݃}�X�N�̌^�Ɗ����݃}�X�N�̕ύX�^�Q��
 */
typedef	UINT	IPM;		/* �����݃}�X�N */

extern ER	chg_ipm(IPM ipm) throw();
extern ER	get_ipm(IPM *p_ipm) throw();
/*
 *  SIL�֘A�̒�`
 */


/*
 *  ���݂̊����݃}�X�N�̓Ǐo��
 */
#define _current_intmask_	current_intmask

/*
 *  �����݃}�X�N�̐ݒ�
 */
#define _set_intmask_		set_intmask

/*
 *  NMI���������ׂĂ̊����݂��֎~
 *  �@disint()���J�[�l�����Ǘ����銄���݂݂̂��֎~����̂ɑ΂���
 *  �@_disint_()�̓J�[�l���Ǘ��O�̊����݂��܂߂ċ֎~����B
 *  �@��̓I�ɂ�GDB stub�̃V���A����M�����݂̈������قȂ�B
 */
Inline void
_disint_()
{
	UW sr;

	Asm("move.w  %%sr, %0" : "=d"(sr));
	sr |= 0x0700;
	Asm("move.w %0, %%sr" : : "d"(sr) );
}


/*
 *  �����݃��b�N��Ԃ̐���
 */
#define	SIL_PRE_LOC	UW _intmask_ = _current_intmask_()
#define	SIL_LOC_INT()	_disint_()
#define	SIL_UNL_INT()	_set_intmask_(_intmask_)

/*
 *  �������ԑ҂�
 */
Inline void
sil_dly_nse(UINT dlytim)
{
	register VW d0 asm("d0") = (VW) dlytim;
	Asm("jsr _sil_dly_nse" : "=g"(d0) : "0"(d0));
}

#endif /* _MACRO_ONLY */

/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define	SIL_ENDIAN	SIL_ENDIAN_BIG	/* �r�b�O�G���f�B�A�� */

#ifndef _MACRO_ONLY
/*
 *  ���\�]���p�V�X�e�������̎Q��
 */

#ifdef SUPPORT_VXGET_TIM
typedef	UD	SYSUTIM;	/* ���\�]���p�V�X�e������ */

extern ER	vxget_tim(SYSUTIM *p_sysutim) throw();

#endif /*  SUPPORT_VXGET_TIM  */

#endif /* _MACRO_ONLY */

#endif /* _CPU_DEFS_H_ */
