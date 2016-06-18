/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
#   Copyright (C) 2007 by KURUSUGAWA Electronics Industry Inc, JAPAN
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
 *  @(#) $Id: m52235evb.h,v 1.2 2003/06/04 01:52:23 hiro Exp $
 */

/*
 *  �t���[�X�P�[���E�Z�~�R���_�N�^ M52235EVB
 *  �{�[�h�ŗL�̒�`
 */

#ifndef _M52235EVB_H_
#define _M52235EVB_H_
#include "m52235.h"
/*
 *  �����݃��x���ݒ�̂��߂̒�`
 */
#define	TIRQ_NMI	0x7u		/* �m���}�X�J�u�������� */
#define	TIRQ_LEVEL6	0x6u		/* �����݃��x��6 */
#define	TIRQ_LEVEL5	0x5u		/* �����݃��x��5 */
#define	TIRQ_LEVEL4	0x4u		/* �����݃��x��4 */
#define	TIRQ_LEVEL3	0x3u		/* �����݃��x��3 */
#define	TIRQ_LEVEL2	0x2u		/* �����݃��x��2 */
#define	TIRQ_LEVEL1	0x1u		/* �����݃��x��1 */

#ifndef _MACRO_ONLY
/*
 *  GDB STUB�ďo�����[�`��
 */

extern void mcfuart_putc_pol(ID portid, char c);	/*  mcfuart.c  */

#ifdef GDB_STUB

#define cfv2_exit	gdb_stub_exit
#define cfv2_putc	gdb_stub_putc

Inline void
gdb_stub_exit (void)
{
	/* �e�X�g���Ă��Ȃ� */
	Asm("trap #3"::);
}

Inline int
gdb_stub_putc (ID portid, int c)
{
	mcfuart_putc_pol (portid, c);
	return(c);
}

#else /* GDB_STUB */

Inline void
cfv2_exit ()
{
	while (1);
}

Inline void
cfv2_putc (ID portid, char c)
{
	mcfuart_putc_pol (portid, c);
}

#endif /* GDB_STUB */
#endif /* _MACRO_ONLY */
#endif /* _M52235EVB_H_ */
