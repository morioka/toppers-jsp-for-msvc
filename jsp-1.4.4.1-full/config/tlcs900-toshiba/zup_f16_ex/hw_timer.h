/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2010 by Witz Corporation, JAPAN
 * 
 *  The above copyright holders grant permission gratis to use,
 *  duplicate, modify, or redistribute (hereafter called use) this
 *  software (including the one made by modifying this software),
 *  provided that the following four conditions (1) through (4) are
 *  satisfied.
 * 
 *  (1) When this software is used in the form of source code, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be retained in the source code without modification.
 * 
 *  (2) When this software is redistributed in the forms usable for the
 *      development of other software, such as in library form, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be shown without modification in the document provided
 *      with the redistributed software, such as the user manual.
 * 
 *  (3) When this software is redistributed in the forms unusable for the
 *      development of other software, such as the case when the software
 *      is embedded in a piece of equipment, either of the following two
 *      conditions must be satisfied:
 * 
 *    (a) The above copyright notice, this use conditions, and the
 *           disclaimer shown below must be shown without modification in
 *        the document provided with the redistributed software, such as
 *        the user manual.
 * 
 *    (b) How the software is to be redistributed must be reported to the
 *        TOPPERS Project according to the procedure described
 *        separately.
 * 
 *  (4) The above copyright holders and the TOPPERS Project are exempt
 *      from responsibility for any type of damage directly or indirectly
 *      caused from the use of this software and are indemnified by any
 *      users or end users of this software from any and all causes of
 *      action whatsoever.
 * 
 *  THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 *  THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 *  PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 *  TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 *  INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE
 *  �Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒��쌠
 *      �\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[�X
 *      �R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg�p
 *      �ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p�҃}
 *      �j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L�̖���
 *      �؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg�p
 *      �ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g�ɕ�
 *        �����邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹�Q
 *      ������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD�܂��C
 *      �{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝�R�Ɋ��
 *      ������������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂���
 *  ��TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI�ɑ΂�
 *  ��K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p
 *  �ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC��
 *  ��Ȃ��D
 * 
 *  @(#) $Id: hw_timer.h,v 1.1 2006/04/10 08:19:25 honda Exp $
 */

/*
 *	�^�C�}�h���C�o�iZup-F16�g���{�[�h�p�j
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include <sil.h>
#include <tmp91cy22.h>

/*
 *  �^�C�}�����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_TIMER		INT_NO_TA0

/*
 *  �^�C�}�[�̊��荞�݃��x��
 */
#define INT_LEVEL_TIMER	0x04

#ifndef _MACRO_ONLY

/*
 *  1ms�̃^�C�}�[���荞�݂��g�p����̂ł��̃N���b�N���`����D
 */
#define TIMER_CLOCK		192


/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
#pragma inline hw_timer_initialize
void
hw_timer_initialize()
{
	/* �^�C�}0��~	*/
	sil_wrb_mem((VP)TADR_SFR_TA01RUN,
		(VB)(sil_reb_mem((VP)TADR_SFR_TA01RUN) & ~TBIT_TA0RUN));
	/* ���[�h�ݒ�	 IDLE2:����,8bit���[�h,�\�[�X�N���b�N/16,1ms	*/
	sil_wrb_mem((VP)TADR_SFR_TA01RUN,
		(sil_reb_mem((VP)TADR_SFR_TA01RUN) | TBIT_I2TA01));
	sil_wrb_mem((VP)TADR_SFR_TA01MOD,
		(sil_reb_mem((VP)TADR_SFR_TA01MOD) | TBIT_TA0CLK16));
	sil_wrb_mem((VP)TADR_SFR_TA0REG, (VB)(TIMER_CLOCK - 1) );
	/* �����ݐݒ�	�����ݗv���N���A,�����݃��x��5	*/
	sil_wrb_mem((VP)TADR_SFR_INTCLR, TBIT_TA0_CLR );
	sil_wrb_mem((VP)TADR_SFR_INTETA01,
		(VB)((sil_reb_mem((VP)TADR_SFR_INTETA01) & ~TBIT_INTM_L) | INT_LEVEL_TIMER));
	/* �^�C�}0����уv���X�P�[���N��	*/
	sil_wrb_mem((VP)TADR_SFR_TA01RUN,
		(VB)(sil_reb_mem((VP)TADR_SFR_TA01RUN) | (TBIT_TA01PRUN | TBIT_TA0RUN)));
}

/*
 *  �^�C�}�����ݗv���̃N���A
 */
#pragma inline hw_timer_int_clear
void
hw_timer_int_clear()
{
	/* �����ݗv���N���A	*/
	sil_wrb_mem((VP)TADR_SFR_INTCLR, TBIT_TA0_CLR );
}

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
#pragma inline hw_timer_terminate
void
hw_timer_terminate()
{
	/* �^�C�}0��~	*/
	sil_wrb_mem((VP)TADR_SFR_TA01RUN,
		(VB)(sil_reb_mem((VP)TADR_SFR_TA01RUN) & ~TBIT_TA0RUN));
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
#pragma inline hw_timer_fetch_interrupt
BOOL
hw_timer_fetch_interrupt(void)
{
	return (sil_reb_mem((VP)TADR_SFR_INTETA01) & TBIT_INTC_L);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
