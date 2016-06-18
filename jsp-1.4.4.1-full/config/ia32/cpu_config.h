/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2002 by Monami software, Limited Partners.
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
 *  @(#) $Id: cpu_config.h,v 1.1 2004/07/21 02:49:36 monaka Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���ii386�p�j
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include <cpu_rename.h>

/*
 *  �v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`
 */
#ifndef _MACRO_ONLY
#include <cpu_insn.h>
#endif /* _MACRO_ONLY */

/*
 *  TCB �֘A�̒�`
 *
 *  cpu_context.h �ɓ��������G���K���g�����C�Q�Ƃ̈ˑ����̊֌W�ŁC
 *  cpu_context.h �ɂ͓�����Ȃ��D
 */

/*
 *  TCB ���̃t�B�[���h�̃r�b�g���̒�`
 */
#define	TBIT_TCB_PRIORITY	8	/* priority �t�B�[���h�̃r�b�g�� */
#define	TBIT_TCB_TSTAT		8	/* tstat �t�B�[���h�̃r�b�g�� */
#define	TBIT_TCB_TWAIT		8	/* twait �t�B�[���h�̃r�b�g�� */

#ifndef _MACRO_ONLY
/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
	VP	esp;		/* �X�^�b�N�|�C���^ */
	FP	eip;		/* �v���O�����J�E���^ */
} CTXB;

/*
 *  ���荞�݂̃l�X�g��
 *
 *  1�ȏ�̎��͔�^�X�N�R���e�L�X�g�ɂȂ�B���荞�݃n���h�����O�n���h����
 *  �o�����ŃC���N�������g�E�f�N�������g�����B
 */
extern UW nest;

/*
 *  �V�X�e����ԎQ��
 */

Inline BOOL
sense_context()
{
	return (nest != 0);
}

Inline BOOL
sense_lock()
{
	unsigned _int32_ eflag;

	Asm("pushf");
	Asm("popl %0" : "=g"(eflag));

	return ((eflag & 0x200) == 0);
}

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU���b�N�Ƃ��̉���
 *
 */

Inline void x_lock_cpu(void) {
	disint();
	Asm("":::"memory");
}

#define i_lock_cpu() x_lock_cpu()
#define t_lock_cpu() x_lock_cpu()

Inline void x_unlock_cpu(void) {
	Asm("":::"memory");
	enaint();
}

#define i_unlock_cpu() x_unlock_cpu()
#define t_unlock_cpu() x_unlock_cpu()

/*
 *  �^�X�N�f�B�X�p�b�`��
 */

/*
 *  �ō��D�揇�ʃ^�X�N�ւ̃f�B�X�p�b�`�icpu_support.S�j
 *
 *  dispatch �́C�^�X�N�R���e�L�X�g����Ăяo���ꂽ�T�[�r�X�R�[������
 *  ���ŁCCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void	dispatch(void);

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`�icpu_support.S�j
 *
 *  exit_and_dispatch �́CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void	exit_and_dispatch(void);

/*
 *  CPU��O�n���h���̐ݒ�
 */

/*
 *  ��O�n���h���̏o���������icpu_support.S�j
 */
extern void exception0(void);
extern void exception1(void);
extern void exception2(void);
extern void exception3(void);
extern void exception4(void);
extern void exception5(void);
extern void exception6(void);
extern void exception7(void);
extern void exception8(void);
extern void exception9(void);
extern void exception10(void);
extern void exception11(void);
extern void exception12(void);
extern void exception13(void);
extern void exception14(void);
extern void exception16(void);
extern void exception17(void);
extern void exception18(void);
extern void exception19(void);

/*
 *  CPU��O�n���h���̃e�[�u���icpu_config.c�j
 *
 *  CPU��O�n���h���͈�U���̃e�[�u���ɓo�^����A�ʂɗp�ӂ��ꂽ�o��������
 *  ���Ăяo���B
 */
extern FP exc_table[0x20];

/*
 *  CPU��O�n���h���̐ݒ�
 *  �x�N�g���ԍ� excno ��CPU��O�n���h���̋N���Ԓn�� exchdr �ɐݒ�
 */
extern void define_exc(EXCNO excno, FP exchdr);

/*
 *  CPU��O�n���h���̏o��������
 */

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 */

#define EXCHDR_ENTRY(exchdr) extern void exchdr(VP p_excinf)

#define EXC_ENTRY(exchdr) exchdr

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃R���e�L�X�g�̎Q��
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	return (nest > 1);
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return ((((UW *)p_excinf)[3] & 0x200) == 0);
}

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
extern void	cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������
 */
extern void	cpu_terminate(void);

/*
 * i386�Z�O�����g�f�X�N���v�^�̐ݒ�
 */
extern void set_segment_descriptor(int sel, unsigned addr, unsigned limit, unsigned type, unsigned dpl);
extern void set_gate_descriptor(int sel, unsigned selector, void *func, unsigned type, unsigned dpl);

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
