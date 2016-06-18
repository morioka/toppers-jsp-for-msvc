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
 *  @(#) $Id: vector_table.c,v 1.3 2005/07/06 00:45:07 honda Exp $
 */

/*
 *	��O�x�N�^�̒�`�iCOLDFIRE�p�j
 */

#include "jsp_kernel.h"


#ifdef KERNEL_HAS_A_VECTOR_TABLE

static VP _current_vbr = EXCVT_ORIG;

extern void start(void);		/*  start.S  */
extern void no_reg_exception(void);	/*  cpu_support.S  */

VP
current_vbr()
{
        return _current_vbr;
}

void
set_vbr(VP vbr)
{
        _current_vbr = vbr;
	Asm("movec %0, %%vbr" : : "r"(vbr));
}

FP vector_table [192] = {
	(FP)INIT_STACK,		/*   0:�X�^�b�N�|�C���^�̏����l  */
        RESET_VECTOR,		/*   1:�p���[�I�����Z�b�g  */
	ACC_VECTOR,		/*   2:�A�N�Z�X�G���[      */
  	ADD_VECTOR,		/*   3:�A�h���X�G���[      */
  	II_VECTOR,		/*   4:��ʕs������        */
	RESERVED_VECTOR,	/*   5:d zero              */
	RESERVED_VECTOR,        /*   6:�\��                */
        II_VECTOR,              /*   7:�V�X�e���\��        */
	RESERVED_VECTOR,	/*   8:pv�V�X�e���\��        */
        RESERVED_VECTOR,        /*   9:trace               */
	RESERVED_VECTOR,	/*  10:line a emulator     */
	RESERVED_VECTOR,	/*  11:line f emulator     */
	RESERVED_VECTOR,	/*  12:�V�X�e���\��        */
        RESERVED_VECTOR,        /*  13:�V�X�e���\��        */
	RESERVED_VECTOR,	/*  14:�V�X�e���\��        */
	RESERVED_VECTOR,	/*  15:�V�X�e���\��        */
	RESERVED_VECTOR,	/*  16:�V�X�e���\��        */
        RESERVED_VECTOR,        /*  17:�V�X�e���\��        */
	RESERVED_VECTOR,	/*  18:�V�X�e���\��        */
	RESERVED_VECTOR,	/*  19:�V�X�e���\��        */
	RESERVED_VECTOR,	/*  20:�V�X�e���\��        */
        RESERVED_VECTOR,        /*  21:�V�X�e���\��        */
	RESERVED_VECTOR,	/*  22:�V�X�e���\��        */
	RESERVED_VECTOR,	/*  23:�V�X�e���\��        */
	RESERVED_VECTOR,	/*  24:�X�v���A�X���荞��  */
				/*  �c��̓f�t�H���g�̗�O����  */
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
	no_reg_exception,
};

#endif /* KERNEL_HAS_A_VECTOR_TABLE */

