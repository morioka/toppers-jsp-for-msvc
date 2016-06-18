/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2003      by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2010 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 */

/*
 *  �v���Z�b�T�ˑ����W���[���iXstormy16�p�j
 */

#include "jsp_kernel.h"
#include <s_services.h>
#include <hw_timer.h>
#include <hw_serial.h>
#include <cpu_sfrs.h>

/*
 *  �^�C���e�B�b�N�̎���
 */
UINT _kernel_tic_nume = 1u ;

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize(void)
{
                                /*
                                 *  ��O�̋���
                                 */
    __UNLOCK_EXCP() ;               /* unlock writing EXCPL/EXCPH */
    __SFR_BITSET( __EXCPL, 0 ) ;    /* enable invalid instruction exception */
    __SFR_BITSET( __EXCPL, 2 ) ;    /* enable odd/word access exception */
    __SFR_BITSET( __EXCPL, 4 ) ;    /* enable outrange access exception */
    __LOCK_EXCP() ;                 /* lock writing EXCPL/EXCPH */
                                /*
                                 *  �J�[�l���^�C�}�[�̋N��
                                 */
    hw_timer_initialize() ;
}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate(void)
{
                                /*
                                 *  �J�[�l���^�C�}�[�̒�~
                                 */
    hw_timer_terminate() ;
                                /*
                                 *  ��O�̋֎~
                                 */
    __UNLOCK_EXCP() ;               /* unlock writing EXCPL/EXCPH */
    __SFR_BITCLR( __EXCPL, 0 ) ;    /* disable invalid instruction exception */
    __SFR_BITCLR( __EXCPL, 2 ) ;    /* disable odd/word access exception */
    __SFR_BITCLR( __EXCPL, 4 ) ;    /* disable outrange access exception */
    __LOCK_EXCP() ;                 /* lock writing EXCPL/EXCPH */
}

/*
 *  ���荞�݃n���h���̓o�^
 */
void _kernel_define_inh(INHNO inhno, FP inthdr)
{
    extern FP _kernel_ih_table[TNUM_INTERRUPT] ;
    if ( inhno < TNUM_INTERRUPT ) {
        _kernel_ih_table[inhno] = inthdr ;
    }
}

/*
 *  ��O�n���h���̓o�^
 */
void _kernel_define_exc(EXCNO excno, FP exchdr)
{
    extern FP _kernel_eh_table[TNUM_EXCEPTION] ;
    if ( excno < TNUM_EXCEPTION ) {
        _kernel_eh_table[excno] = exchdr ;
    }
}

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */
void sys_putc(char c)
{
    sio_asnd_chr( (INT)c ) ;
}

/*
 *  �������ԑ҂�
 */
void sil_dly_nse( UINT dlytim )
{
    UINT n ;
    for ( n = 3 ; n < dlytim ; n++ ) __asm__ volatile ( "nop" ) ;
}

