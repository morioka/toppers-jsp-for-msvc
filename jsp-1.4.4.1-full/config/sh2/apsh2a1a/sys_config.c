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

	/* SCIF3 */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x10));
	sil_wrh_mem (PECRL4, sil_reh_mem (PECRL4) | (0x0030 | 0x0003));

#else /* GDB_STUB */

	/* SCIF3 */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x10));
	sil_wrh_mem (PECRL4, sil_reh_mem (PECRL4) | (0x0003 | 0x0030));

#endif /* GDB_STUB */

	/* CMT0 */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x04));
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
	sil_wrh_mem (FRQCR, 0x0104);	/* �N���b�N�ݒ� I��=200MHz, B��=66.666MHz, P��=33.333MHz */

	/* �o�X�R���g���[���̐ݒ� */
	sil_wrw_mem (CMNCR, 0x00001010);
	sil_wrw_mem (CS0BCR, 0x24920400);
	sil_wrw_mem (CS0WCR, 0x00001382);
	sil_wrw_mem (CS3BCR, 0x24924600);
	sil_wrw_mem (CS3WCR, 0x00004912);
	sil_wrw_mem (SDCR, 0x00000909);
	sil_wrw_mem (RTCSR, 0xa55a0010);
	sil_wrw_mem (RTCOR, 0xa55a0040);

	/* I/O�|�[�g�̐ݒ� */
	sil_wrh_mem (PBIORL, 0x0c00);	/* PC11,PC10 �o�͕��� (LED�ڑ��|�[�g) */
	sil_wrh_mem (PBCRL4, 0x5a00);
	sil_wrh_mem (PBCRL3, 0x0000);	/* PC11,PC10���[�h �|�[�g�I�� (LED�ڑ��|�[�g) */
	sil_wrh_mem (PBCRL2, 0x0000);
	sil_wrh_mem (PBCRL1, 0x0000);
	sil_wrh_mem (PCIORL, 0x0000);
	sil_wrh_mem (PCCRL4, 0x0011);
	sil_wrh_mem (PCCRL3, 0x1111);
	sil_wrh_mem (PCCRL2, 0x1111);
	sil_wrh_mem (PCCRL1, 0x1111);
	sil_wrh_mem (PDIORL, 0x0000);
	sil_wrh_mem (PDCRL4, 0x1111);
	sil_wrh_mem (PDCRL3, 0x1111);
	sil_wrh_mem (PDCRL2, 0x1111);
	sil_wrh_mem (PDCRL1, 0x1111);
	sil_wrh_mem (PEIORL, 0x0000);
	sil_wrh_mem (PECRL4, 0x0000);
	sil_wrh_mem (PECRL3, 0x1010);
	sil_wrh_mem (PECRL2, 0x1111);
	sil_wrh_mem (PECRL1, 0x1111);
	sil_wrh_mem (PFIORH, 0x7fff);
	sil_wrh_mem (PFIORL, 0xffff);
	sil_wrh_mem (PFCRH4, 0x0000);
	sil_wrh_mem (PFCRH3, 0x0000);
	sil_wrh_mem (PFCRH2, 0x0000);
	sil_wrh_mem (PFCRH1, 0x0000);
	sil_wrh_mem (PFCRL4, 0x0000);
	sil_wrh_mem (PFCRL3, 0x0000);
	sil_wrh_mem (PFCRL2, 0x0000);
	sil_wrh_mem (PFCRL1, 0x0000);

	/* CMT �փN���b�N���� */
	sil_wrb_mem (STBCR4, (VB) ((VB) sil_reb_mem (STBCR4) & ~0x04));

	/* 100usec �҂� */
	sil_wrh_mem (CMSTR, 0x0000);	/* STR0=0 �J�E���^0 ��~ */
	sil_wrh_mem (CMCSR_0, 0x0000);	/* CKS=00 �N���b�N�I�� P��/8 */
	sil_wrh_mem (CMCNT_0, 0);		/* �J�E���^0 �N���A�C���R���X�^���g�l�ݒ� */
	sil_wrh_mem (CMCOR_0, ((((PCLOCK / 8)/1000000) * 100) - 1));
	sil_wrh_mem (CMSTR, 0x0001);	/* STR0=1 �J�E���^0 �J�n */
	while ((sil_reh_mem (CMCSR_0) & 0x0080) == 0);
									/* CMF==1 �ɂȂ�܂ő҂� */

	sil_wrh_mem (SDRAM_MODE, 0x000);	/* SDRAM���[�h���W�X�^��ݒ� */

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
