/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                2003      by  Advanced Data Controls, Corp
 *                2009 by Suikan
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
 */

/*
 *  CPU�ˑ��^�C�}���W���[���iCQ-FRK-NXP-ARM�p�j
 *  TIMER3���g�p
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include "lpc2388.h"




/*
 *  �^�C�}�����݂̊����ݔԍ�
 */
#define    INHNO_TIMER    INHNO_TIMER3

#ifndef _MACRO_ONLY

/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UW    CLOCK;

/*
 *  �^�C�}�l�̓����\���ƃ~���b�E�ʕb�P�ʂƂ̕ϊ�
 *  TIMER_CLOCK �̓^�[�Q�b�g�{�[�h���ɐݒ�
 */
#define TO_CLOCK(nume, deno) (LP2388_SYSTEM_TIMER3_CLOCK/1000 * (nume) / (deno))
#define TO_USEC(clock)       ((clock) * 1000 / TIMER_CLOCK)

/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */
#define MAX_CLOCK    ((CLOCK) 0xffffffff)
/*
 *  �^�C�}�̌��ݒl�������ݔ����O�̒l�Ƃ݂Ȃ����̔��f
 */
#define GET_TOLERANCE    100
#define BEFORE_IREQ(clock) \
        ((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �^�C�}�̋N������
 *
 * �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D�^�C�}�[3�ƃ}�b�`���W�X�^0���g���B
 * �O���Œ�`�����PCLK (Hz)���N���b�N���͂Ƃ��Ďg���B
 */
Inline void
hw_timer_initialize()
{

    /*
     *  �^�C�}�֘A�̐ݒ�
     */
    		/* �^�C�}��~����у��Z�b�g */
    T3TCR = 0x0002;
    		/* �����݂̃N���A  */
    T3IR =  0x0001;				/* MR0���荞�݂̃N���A */

	T3CTCR = 0;			/* PCLK�̃G�b�W�𐔂���B�L���v�`�����͖͂��� */
	T3PR = 0;			/* PCLK�̃G�b�W�����ׂĐ�����B�v���X�P�[���Ȃ� */
    T3MR3 = (LP2388_SYSTEM_TIMER3_CLOCK/1000) -1;		/* 1mS���ƂɃ}�b�`������ */
	T3MCR = 0x3 << 9;	/* MR3S:R:I = 0:1:1�B�}�b�`������J�E���^�����Z�b�g���A���荞�݂������� */

	T3TCR = 1;			/* TIMER3���J�E���g�J�n�ɂ��� */

		/* �^�C�}�[���荞�݂�L���ɂ��� */
	VICIntEnable = 1<< INHNO_TIMER;
}

/*
 *  �^�C�}�����ݗv���̃N���A
 */
Inline void
hw_timer_int_clear()
{
    		/* �����݂̃N���A  */
	T3IR = 1<<3;			/* MR3�}�b�`�̊��荞�݂��N���A���� */
}

/*
 *  �^�C�}�̒�~����
 */
Inline void
hw_timer_terminate()
{
    		/* �^�C�}��~����у��Z�b�g */
    T3TCR = 0x0002;
    		/* �����݂̃N���A  */
    T3IR =  0x0001;				/* MR0���荞�݂̃N���A */
}

/*
 *  �^�C�}�̌��ݒl�̓ǂ݂���
 *
 *  �����݋֎~��Ԓ��ŌĂяo�����ƁD
 */
Inline CLOCK
hw_timer_get_current(void)
{
    return(T3TC);
}

Inline BOOL
hw_timer_fetch_interrupt(void)
{
    return(T3IR & (1<<3));		/* MR3 ���}�b�`���Ă�����^ */
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */



