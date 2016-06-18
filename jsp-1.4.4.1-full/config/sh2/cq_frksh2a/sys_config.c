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
 *  @(#) $Id
 */

#include "jsp_kernel.h"
#include <sil.h>
#include <s_services.h>
#include "sh726xscif.h"

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
/*
 *  �V���A��I/O�|�[�g�̏����� banner�o�͂̂��߃J�[�l���̏������Ɩ��֌W�ɍs��
 */
void
sys_initialize ()
{
	SIOPCB *siopcb;

	/* �g�p������Ӌ@��͂����ŗL���ɂ��Ă����B */
	/*  SCIF�f�[�^���o�̓|�[�g�̐ݒ�  */

#ifndef GDB_STUB

	/* SCIF2 */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x20));
	sil_wrh_mem (PFCR0, sil_reh_mem (PFCR0) | (0x0400 | 0x0040));
#if TNUM_PORT >=2
	/* SCIF3 */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x10));
	sil_wrh_mem (PFCR1, sil_reh_mem (PFCR1) | 0x0004);
	sil_wrh_mem (PFCR0, sil_reh_mem (PFCR0) | 0x4000);
#endif /*TNUM_PORT >=2 */

#else /* GDB_STUB */

	/* SCIF3 */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x10));
	sil_wrh_mem (PFCR1, sil_reh_mem (PFCR1) | 0x0004);
	sil_wrh_mem (PFCR0, sil_reh_mem (PFCR0) | 0x4000);

#endif /* GDB_STUB */

	/* CMT0 */
	sil_wrb_mem (STBCR7, (VB) ((VB) sil_reb_mem (STBCR7) & ~0x04));
	/*
	 *  �f�o�C�X�ˑ��̃I�[�v�������D
	 */
	/*�o�i�[�o�͂��邽�� */
	sh2scif_initialize();
	siopcb = sh2scif_opn_por (LOGTASK_PORTID, 0);
}

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 */
void
sys_exit ()
{
	sh2_exit ();
}

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */
void
sys_putc (char c)
{
	if (c == '\n') {
		sh2_putc (LOGTASK_PORTID, '\r');
	}
	sh2_putc (LOGTASK_PORTID, c);
}

/* �n�[�h�E�F�A�̐ݒ� */
/* �����ł̓o�X�̐ݒ�̂ݍs���B���Ӌ@��̐ݒ��sys_initialize�ōs���B */
#ifndef GDB_STUB
void
hardware_init_hook (void)
{
	/* �N���b�N���U��̏����� */
	sil_wrh_mem (FRQCR, 0x1104);	/* �N���b�N�ݒ� I��=144MHz, B��=48MHz, P��=24MHz */

	/* I/O�|�[�g�̐ݒ� */
	sil_wrh_mem (PCIOR0, 0x0100);	/* PC8�|�[�g �o�͕��� (LED�ڑ��|�[�g) */
	sil_wrh_mem (PCCR2, 0x0000);	/* PC8���[�h �|�[�g�I�� (LED�ڑ��|�[�g) */

	/* �L���b�V���̐ݒ� */
	sil_wrw_mem (CCR1, 0x00000808);	/* �L���b�V�����t���b�V�� */
	sil_wrw_mem (CCR1, CCR_MODE);	/* �L���b�V�����[�h��ݒ� */
}
#else /*  GDB_STUB  */
void
hardware_init_hook (void)
{
}
#endif /*  GDB_STUB  */
