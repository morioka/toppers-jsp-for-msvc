/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
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
 */

/*
 *  CPU�ˑ��^�C�}���W���[���iSH7047�p�j
 *  CMT0���g�p
 *
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include "crb_h3.h"

/*
 *  �R���y�A�}�b�`�^�C�}�X�^�[�g���W�X�^CMSTR�̃r�b�g�ݒ�
 */
#define CMSTR_STR1	0x0002	/* �J�E���g�X�^�[�g1 */
#define CMSTR_STR0  0x0001	/* �J�E���g�X�^�[�g0 */

/*
 *  �R���y�A�}�b�`�^�C�}�R���g���[���^�X�e�[�^�X���W�X�^CMCSR�̃r�b�g�ݒ�
 */
#define CMCSR_CMF   0x0080	/* �R���y�A�}�b�`�t���O */
#define CMCSR_CMIE  0x0040	/* �R���y�A�}�b�`�����݃C�l�[�u�� */
#define CMCSR_CKS8  0x0000	/* 8�����N���b�N�Z���N�g */

/*
 *  �^�C�}�����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_TIMER	CMI0

/*
 *   �^�C�}�ɋ��������N���b�N���g��[kHz]
 *   	40.000MHz/8 =5.0000MHz =5000.0kHz
 */
#define TIMER_CLOCK     (CLOCK_RATE/8000L)

#ifndef _MACRO_ONLY
/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UH CLOCK;

/*
 *  �^�C�}�l�̓����\���ƃ~���b�E�ʕb�P�ʂƂ̕ϊ�
 *
 */
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)
#define CLOCK_PER_TICK	((CLOCK) TO_CLOCK(TIC_NUME, TIC_DENO))

/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */
#define	MAX_CLOCK	((CLOCK) 0xffff)

/*
 *  �^�C�}�̌��ݒl�������ݔ����O�̒l�Ƃ݂Ȃ����̔��f
 */
#define	GET_TOLERANCE	100		/* �����x��̌��ς�l�i�P�ʂ͓����\���j */
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)


/*  �����݃��x����ݒ背�W�X�^�ɑ������Ƃ��̃V�t�g��  */
#define FRT_BIT_SHIFT	4

/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
hw_timer_initialize()
{
	/* �^�C�}�f�o�C�X���̂̏����� */
	sil_wrh_mem((VP)IOREG_CMSTR_BASE, 0x0000);	/* �^�C�}�X�g�b�v */
												/* �J�E���^�l�ݒ� */
	sil_wrh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCOR_OFFSET), TO_CLOCK(TIC_NUME, TIC_DENO));

	/* ���荞�݃��x���ݒ�   */
	define_int_plevel ((VH*)(IOREG_INTC_BASE+IOREG_IPRG_OFFSET), TIMER_INTLVL, FRT_BIT_SHIFT);

	/*  �����ݐݒ�Ɨv�����N���A�ƃN���b�N�Z�b�g */
	sil_wrh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCSR_OFFSET), (CMCSR_CMIE|CMCSR_CKS8));
	sil_wrh_mem((VP)IOREG_CMSTR_BASE, CMSTR_STR0);	/* �^�C�}�X�^�[�g */
}

/*
 *  �^�C�}�����ݗv���̃N���A
 */
Inline void
hw_timer_int_clear()
{
	sil_wrh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCSR_OFFSET),
		(sil_reh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCSR_OFFSET)) & ~CMCSR_CMF));
}

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
Inline void
hw_timer_terminate()
{
	sil_wrh_mem((VP)IOREG_CMSTR_BASE,			/* �^�C�}�̒�~ */
		(sil_reh_mem((VP)IOREG_CMSTR_BASE) & ~CMSTR_STR0));
	sil_wrh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCSR_OFFSET), CMCSR_CKS8);/* �����ݒ�~�Ɨv���̃N���A */
}

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 *�@�@�@�^�C�}�̓�����ꎞ�I�ɒ�~���C�^�C�}�l��ǂݏo���D
 */
Inline CLOCK
hw_timer_get_current(void)
{
	return sil_reh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCNT_OFFSET));
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return ((sil_reh_mem((VP)(IOREG_CMT0_BASE+IOREG_CMCSR_OFFSET)) & CMCSR_CMIE) != 0);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
