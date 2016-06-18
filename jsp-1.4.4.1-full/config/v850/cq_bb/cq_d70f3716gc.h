/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2007-2010 by Monami Software Limited Partnership, JAPAN.
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

#ifndef	_CQ_D70F3716GC_H_
#define	_CQ_D70F3716GC_H_
/*
 *	�v���Z�b�T�Ɉˑ������`�iV850ES/JG2�p�j
 */

/*
 * ����RAM
 */
#define	IRAM_TOP	0x00140000		/* ����RAM�̐擪�A�h���X */
#define IRAM_SIZE	0x6000			/* ����RAM�̑傫�� 24Kbyte */
/*
 * ����FlashROM
 */
#define	IROM_TOP	0x0000000		/* ����FlashROM�̐擪�A�h���X */
#define IROM_SIZE	0x40000			/* ����FlashROM�̑傫�� 256Kbyte */


/* 
 * V850ES/JG2��IO���W�X�^��`
 */
#define PRCMD		(0xFFFFF1FC)	/* Command Register */
#define VSWC		(0xFFFFF06E)	/* System Wait Control Register */
#define OCDM		(0xFFFFF9FC)	/* OnChip Debug Mode Register */
#define WDTM2		(0xFFFFF6D0)	/* Watchdog Debug Mode Register2 */

/*
 * �N���b�N�֘A
 */
#define PCC			(0xFFFFF828)	/* Processor Clock Control Register */
#define PLLCTL		(0xFFFFF82C)	/* PLL �R���g���[���E���W�X�^ */

/*
 * LED�֘A
 */
/* �|�[�gCT */
#define PCT			(0xFFFFF00A)	/* PCT Register vector */
#define PMCT		(0xFFFFF02A)	/* PCT Mode Register vector */
#define PMCCT		(0xFFFFF04A)	/* PCT Mode Control Register vector */

#define LED_BIT		(0x40)			/* LED */

/*
 * 16bit Interval Timer M
 */
#define TM0CTL0		(0xFFFFF690)
#define TM0CMP0		(0xFFFFF694)

/*
 * UART0�֘A
 */
/* �|�[�g */
#define PMC3		(0xFFFFF446)
#define PFC3		(0xFFFFF466)
#define PFCE3L		(0xFFFFF706)

/* UART0 */
#define UA0CTL0		(0xFFFFFA20)	/* UARTA0 ���䃌�W�X�^0 */
#define UA0OPT0		(0xFFFFFA23)	/* UARTA0 �I�v�V�������䃌�W�X�^0 */
#define UA0STR		(0xFFFFFA24)	/* UARTA0 ��ԃ��W�X�^ */
#define UA0RX		(0xFFFFFA26)	/* UARTA0 ��M�f�[�^���W�X�^ */
#define UA0TX		(0xFFFFFA27)	/* UARTA0 ���M�f�[�^���W�X�^ */

/* �{�[���[�g */
#define UA0CTL1		(0xFFFFFA21)	/* UARTA0 ���䃌�W�X�^1 */
#define UA0CTL2		(0xFFFFFA22)	/* UARTA0 ���䃌�W�X�^2 */

/*
 * IntC
 */
#define TM0EQIC0	(0xFFFFF150)	/* TM0EQ0 �����ݐ��䃌�W�X�^ */
#define UA0RIC		(0xFFFFF16A)	/* UART0 ��M���������ݐ��䃌�W�X�^ */
#define UA0TIC		(0xFFFFF16C)	/* UART0 ���M�������ݐ��䃌�W�X�^ */
#define IMR2		(0xFFFFF104)	/* �����݃}�X�N���W�X�^2 */
#define IMR2H		(0xFFFFF105)	/* �����݃}�X�N���W�X�^2H */
#define IMR2L		(0xFFFFF104)	/* �����݃}�X�N���W�X�^2L */
#define ISPR		(0xFFFFF1FA)	/* �C���T�[�r�X�E�v���C�I���e�B�E���W�X�^ */

#endif	/* _CQ_D70F3716GC_H_ */
