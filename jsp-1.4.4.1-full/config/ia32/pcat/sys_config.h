/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2002 by Monami software, Limited Partners.
 *  Copyright (C) 2002 by MURANAKA Masaki
 *  Copyright (C) 2008-     by Monami Software Limited Partnership, JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
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
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: sys_config.h,v 1.1 2004/07/21 02:49:37 monaka Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iPC/AT�p�j
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include <sys_rename.h>

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g�V�X�e����
 */
#define	TARGET_NAME	"IA-32(PC/AT)"

/*
 *  vxget_tim ���T�|�[�g���邩�ǂ����̒�`
 */
#if 0
#define	SUPPORT_VXGET_TIM
#endif

/*
 * ��^�X�N�R���e�L�X�g�p�̃X�^�b�N�̏����l
 */
#define	STACKTOP	$(stack + STACKSIZE)
#define	STACKSIZE	8192

/*
 *  �V���A���|�[�g���̒�`
 */
#define TNUM_PORT	2	/* �T�|�[�g����V���A���|�[�g�̐� */
#define	TNUM_SIOP	2	/* �T�|�[�g����V���A��I/O�|�[�g�̐� */

/*
 *  �V���A���|�[�g�ԍ��Ɋւ����`
 */
#ifndef LOGTASK_PORTID
#define	LOGTASK_PORTID	1	/* �V�X�e�����O�ɗp����V���A���|�[�g�ԍ� */
#endif


#define PIT_INHNO 0x20

#define PCAT_COM1_INHNO 0x24
#define PCAT_COM2_INHNO 0x23
#define PCAT_COM1_BASE (0x03F8)
#define PCAT_COM2_BASE (0x02F8)

#define	IRQ0_VECTOR	0x20
#define	IRQ8_VECTOR	0x28
#define	IRQ_VECTOR(x)	(IRQ0_VECTOR + (x))

#define TO_INTNO(a) ((a) - 0x20)

#ifndef _MACRO_ONLY

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
extern void	sys_initialize(void);

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 */
extern void	sys_exit(void);

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */
extern void	sys_putc(char c);

/*
 *  �����݃n���h���̐ݒ�
 */

/*
 *  �����݃n���h���̏o���������isys_support.S�j
 */
extern void interrupt0(void);
extern void interrupt1(void);
extern void interrupt2(void);
extern void interrupt3(void);
extern void interrupt4(void);
extern void interrupt5(void);
extern void interrupt6(void);
extern void interrupt7(void);
extern void interrupt8(void);
extern void interrupt9(void);
extern void interrupt10(void);
extern void interrupt11(void);
extern void interrupt12(void);
extern void interrupt13(void);
extern void interrupt14(void);
extern void interrupt15(void);

/*
 *  �����݃n���h���̃e�[�u���isys_config.c�j
 *
 *  �����݃n���h���͈�U���̃e�[�u���ɓo�^����A�ʂɗp�ӂ��ꂽ�o��������
 *  ���Ăяo���B
 */
extern FP int_table[0x10];

/*
 *  �����݃n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 */
extern void define_inh(INHNO inhno, FP inthdr);

/*
 *  �����݃n���h���̏o��������
 */

/*
 *  �����݃n���h���̏o���������̐����}�N��
 */

#define INTHDR_ENTRY(inthdr) extern void inthdr(void)

#define INT_ENTRY(inthdr) inthdr

#endif /* _MACRO_ONLY */
#endif /* _SYS_CONFIG_H_ */
