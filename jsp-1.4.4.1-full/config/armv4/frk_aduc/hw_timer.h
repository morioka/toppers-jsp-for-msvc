/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2006 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2006 by Logic Research Co., Ltd.
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
 *  CPU�ˑ��^�C�}���W���[���iFRK_ADuC�p�j
 *  TIMER1(41.78MHz�Œ�)���g�p
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include "frk_aduc.h"


/*
 *  �^�C�}�����݂̊����ݔԍ�
 */
#define    INHNO_TIMER    IRQ_TIM1_BIT

#ifndef _MACRO_ONLY


/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UW    CLOCK;


/*
 *  �^�C�}�l�̓����\���ƃ~���b�E�ʕb�P�ʂƂ̕ϊ�
 *  TIMER_CLOCK �̓^�[�Q�b�g�{�[�h���ɐݒ�
 */
#define TO_CLOCK(nume, deno) (TIMER_CLOCK * (nume) / (deno))
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
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
hw_timer_initialize()
{
    CLOCK    cyc = TO_CLOCK(TIC_NUME, TIC_DENO);
        
    /*
     *  �^�C�}�֘A�̐ݒ�
     */
    /* �^�C�}��~ */
    sil_wrw_mem((VP)T1CON, 0);
    /* �^�C�}����l�̃`�F�b�N */
    assert(cyc <= MAX_CLOCK);       
    /* �����݂̃N���A  */
    sil_wrw_mem((VP)T1CLRI, 0x01);
    /* �J�E���g�l���Z�b�g */
    sil_wrw_mem((VP)T1LD,cyc);
    /* �J�E���g�X�^�[�g   */
    sil_wrw_mem((VP)T1CON, (T1CON_CLS_CORE|T1CON_ENA|
							T1CON_MOD|T1CON_FMT_BIN|T1CON_PSC_1));
    /* �����݋��� */        
    sil_wrw_mem((VP)IRQEN, IRQ_TIMER1);
}


/*
 *  �^�C�}�����ݗv���̃N���A
 */
Inline void
hw_timer_int_clear()
{
  sil_wrw_mem((VP)T1CLRI, 0x01);
}


/*
 *  �^�C�}�̒�~����
 */
Inline void
hw_timer_terminate()
{
    /* �y���f�B���O�r�b�g���N���A */
    sil_wrw_mem((VP)T1CLRI, 0x01);    
    /* �^�C�}��~ */
    sil_wrw_mem((VP)T1CON, (sil_rew_mem((VP)T1CON)&~T1CON_ENA));
    /* �����ݕs����*/
    sil_wrw_mem((VP)IRQEN, (sil_rew_mem((VP)IRQEN)&~IRQ_TIMER1));
}


/*
 *  �^�C�}�̌��ݒl�̓ǂ݂���
 *
 *  �����݋֎~��Ԓ��ŌĂяo�����ƁD
 */
Inline CLOCK
hw_timer_get_current(void)
{
    return(TO_CLOCK(TIC_NUME, TIC_DENO) - sil_rew_mem((VP)T1VAL));
}


/*
 * �^�C�}�����݂��������Ă��邩�̔���
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
    return(sil_rew_mem((VP)IRQSTA) & IRQ_TIMER1);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */

