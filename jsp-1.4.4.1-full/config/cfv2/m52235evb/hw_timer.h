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
 *  @(#) $Id: hw_timer.h,v 1.9 2003/07/08 14:57:15 hiro Exp $
 */

/*
 *  CPU�ˑ��^�C�}���W���[���iSH7145�p�j
 *  PIT���g�p
 *�@�^�C�}�f�o�C�X���̂Ɉˑ����鏈����mcfpit.h�ɋL�q����
 */
#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>

#ifndef _MACRO_ONLY
#include "mcfpit.h"
#endif /* _MACRO_ONLY */

/*
 *  �^�C�}�����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_TIMER	MCF_PIT0

#ifndef _MACRO_ONLY

/*
 *  �^�C�}�����ݗv���̃N���A
 */
#define hw_timer_int_clear	mcf_timer_int_clear

/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
hw_timer_initialize()
{
	/*
	 *  �^�C�}�f�o�C�X���̂̏�����
	 */
	mcf_timer_initialize();

	/*
	 *  �����݊֘A�̐ݒ�
	 */
	/* ���荞�݃��x���ݒ�   */
        /* Set tic for timers	*/
        sil_wrb_mem (MCF_INTC_ICR(MCF_INTC0, 55), ((TIMER_INTLVL) << 3) | (TIMER_INTPRI));
        sil_wrw_mem (MCF_INTC_IMRH(MCF_INTC0), sil_rew_mem(MCF_INTC_IMRH(MCF_INTC0)) & (~(1 << (TBIT_TT0))));
        mcf_timer_int_clear();
        mcf_timer_start();
}

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
#define hw_timer_terminate		mcf_timer_terminate

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 */
#define hw_timer_get_current		mcf_timer_get_current

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
#define hw_timer_fetch_interrupt        mcf_timer_fetch_interrupt

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
