/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: cpu_config.h,v 1.14 2003/07/08 14:57:12 hiro Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���iCFV2�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include <cpu_rename.h>

/*
 *  ���l�f�[�^�����񉻗p�}�N���̒�`
 */
#include <util.h>

/*
 *  ���[�U�[��`���
 */
#include <user_config.h>

/*
 *  �ݒ�\�ȍō��D��x
 */
#ifdef GDB_STUB
#define MAX_IPM  0x6	/* �X�^�u����̏ꍇ�͗D��x6��CPU���b�N   */
#else
#define MAX_IPM  0x7	/* �X�^�u�Ȃ��̏ꍇ�͍ō��D��x��CPU���b�N */
#endif /*  GDB_STUB  */

#define str_MAX_IPM  		TO_STRING(MAX_IPM)

/*
 *  �v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`
 */
#ifndef _MACRO_ONLY
#include <cpu_insn.h>
#endif /* _MACRO_ONLY */

/*
 *  chg_ipm/get_ipm ���T�|�[�g���邩�ǂ����̒�`
 */
#define	SUPPORT_CHG_IPM

/*
 *  TCB ���̃t�B�[���h�̃r�b�g���̒�`
 *
 *  cpu_context.h �ɓ��������G���K���g�����C�Q�Ƃ̈ˑ����̊֌W�ŁC
 *  cpu_context.h �ɂ͓�����Ȃ��D
 */
#define	TBIT_TCB_TSTAT		8	/* tstat �t�B�[���h�̃r�b�g�� */
#define	TBIT_TCB_PRIORITY	8	/* priority �t�B�[���h�̃r�b�g�� */

#ifndef _MACRO_ONLY
/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
	VP	msp;		/* �X�^�b�N�|�C���^ */
	FP	pc;		/* �v���O�����J�E���^ */
} CTXB;

/*
 *  �����݃}�X�N���색�C�u����
 *
 *  �����݃}�X�N�iintmask�j�́CIPM�iInterrupt Priority Mask�j��8�r�b�g
 *  ���ɃV�t�g�������̂ł���D
 */

/*
 *  ���݂̊����݃}�X�N�̓Ǐo��
 */
Inline UH
current_intmask()
{
	return(current_sr() & 0x0700);
}

/*
 *  �����݃}�X�N�̐ݒ�
 */
Inline void
set_intmask(UH intmask)
{
	set_sr((current_sr() & ~0x0700) | intmask);
}

/*
 *  �����݁^CPU��O�l�X�g�J�E���^
 */
extern UW	intnest;

/*
 *  �V�X�e����ԎQ��
 */

Inline BOOL
sense_context()
{
	return(intnest > 0);
}

Inline BOOL
sense_lock()
{
	return(current_intmask() == (MAX_IPM << 8));
}

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU���b�N�Ƃ��̉����i�^�X�N�R���e�L�X�g�p�j
 *
 *  task_intmask �́Cchg_ipm ���T�|�[�g���邽�߂̕ϐ��Dchg_ipm ���T�|�[
 *  �g���Ȃ��ꍇ�ɂ́Ctask_intmask ����� 0 �ɂȂ��Ă���ƍl����΂悢�D
 */

#ifdef SUPPORT_CHG_IPM
extern UH	task_intmask;	/* �^�X�N�R���e�L�X�g�ł̊����݃}�X�N */
#endif /* SUPPORT_CHG_IPM */

Inline void
t_lock_cpu()
{
	disint();
}

Inline void
t_unlock_cpu()
{
#ifdef SUPPORT_CHG_IPM
	/*
	 *  t_unlock_cpu ���Ăяo�����̂� CPU���b�N��Ԃ݂̂ł��邽
	 *  �߁C�����̓r���� task_intmask ����������邱�Ƃ͂Ȃ��D
	 */
	set_intmask(task_intmask);
#else /* SUPPORT_CHG_IPM */
	enaint();
#endif /* SUPPORT_CHG_IPM */
}

/*
 *  CPU���b�N�Ƃ��̉����i��^�X�N�R���e�L�X�g�p�j
 */

extern UH	int_intmask;	/* ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N */

Inline void
i_lock_cpu()
{
	UH	intmask;

	/*
	 *  �ꎞ�ϐ� intmask ���g���Ă���̂́Ccurrent_intmask() ����
	 *  �񂾒���Ɋ����݂��������C�N�����ꂽ�����݃n���h������
	 *  int_intmask ���ύX�����\�������邽�߂ł���D
	 */
	intmask = current_intmask();
	disint();
	int_intmask = intmask;
}

Inline void
i_unlock_cpu()
{
	set_intmask(int_intmask);
}

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

#endif  /* _MACRO_ONLY */

/*
 *  �����݃n���h���^CPU��O�n���h���̐ݒ�
 */

/*
 *  ��O�x�N�^�e�[�u���̒�`
 *  �@�@�}�N���̐���
 *  �@�@�@KERNEL_HAS_A_VECTOR_TABLE
 *  �@�@�@�@�J�[�l������O�x�N�^�e�[�u��������
 *  �@�@�@SIO_RESERVED
 *  �@�@�@�@�V���A���f�o�C�X���f�o�b�K�ɂ���Ďg�p����Ă���
 */
#ifndef _MACRO_ONLY

#ifdef KERNEL_HAS_A_VECTOR_TABLE
extern FP vector_table[];	/*  ��O�x�N�^�e�[�u��  */
#endif /* KERNEL_HAS_A_VECTOR_TABLE */

typedef struct exc_vector_entry {
	FP	exchdr;			/* ��O�n���h���̋N���Ԓn */
} EXCVE;

/*
 *  �����݃n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 */
Inline void
define_inh(INHNO inhno, FP inthdr)
{
#ifdef GDB_STUB
        Asm("moveq.l #0x8,%%d0;  move.l %0,%%d2; move.l %1,%%d3; trap #0xf"
	    : /* no output */
	    : "r"(inhno), "r"(inthdr)
	    : "%%d0", "%%d2", "%%d3");
#else	/*  GDB_STUB  */

#ifdef KERNEL_HAS_A_VECTOR_TABLE

/* SIO_RESERVED�͎g�p���Ȃ��Bsys_config.h�ŃR�����g�ɂ��Ă��� */
/*#ifdef SIO_RESERVED	*//*  �V���A�����荞�݂͔�����  */
/*	if ((inhno != RXI0) && (inhno != TXI0))*/
/*#endif *//* SIO_RESERVED */ 
	vector_table[inhno] = inthdr;

#endif /* KERNEL_HAS_A_VECTOR_TABLE */

#endif	/*  GDB_STUB  */
}

/*
 *  CPU��O�n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� excno ��CPU��O�n���h���̋N���Ԓn�� exchdr �ɐݒ肷��D
 */
Inline void
define_exc(EXCNO excno, FP exchdr)
{
	define_inh(excno, exchdr);
}

/*  C���ꃋ�[�`���̊֐���������������̃��x���𐶐�  
 *     kernel_cfg.c�Ŏg�p
 */
#define	INT_ENTRY(inthdr)	_kernel_##inthdr##_entry
#define	EXC_ENTRY(exchdr)	_kernel_##exchdr##_entry


/*
 *  �����݃n���h���^CPU��O�n���h���̓��������̋��ʕ���
 *
 *	ColdFire�ł́A�����݂�CPU��O�̈������قƂ�Ǔ����Ȃ̂ŁA
 *	���������̃}�N�������ʂɒ�`���Ă���
 *
 *�@�@����
 *	label�F���������̃��x��
 *	inthdr�FC���ꃋ�[�`���̐擪�A�h���X
 *	common_routine�Fcpu_support.S���̕����A�h���X
 *			interrupt_entry�F�����݂̏ꍇ
 *			cpu_exception_entry�FCPU��O�̏ꍇ
 *
 *�@�@���W�X�^����
 *�@�@�@�@d1�F�����ݎ�t�����SR�̃R�s�[
 *�@�@�@�@a0�FC���ꃋ�[�`���̐擪�A�h���X
 *
 *	�����݂�CPU��O�̑���_
 *	�@�@�ECPU��O�n���h���Ɉ�����^����
 *	�@�@�ECPU��O�ł́A��O��������IPM�Ɠ����l�Ŋ����݂�������
 *		�iCPU��O�ɂ��AIPM��ω������Ȃ��j
 *
 *	�@�@�E�����݃n���h���̏ꍇ				
 *	�@�@  	�����ݎ�t���Ƀn�[�h�E�F�A��IPM��ݒ肷��	
 *	�@�@  	�����݋��ɂ͂���IPM�̒l��p����		
 *	�@�@�ECPU��O�n���h���̏ꍇ				
 *	�@�@  	CPU��O��t����IPM�̒l�͕ω����Ȃ�		
 *	�@�@  	�����݋��ɂ�CPU��O��������IPM�̒l��p����	
 */
#define	HANDLER_ENTRY_PROC(label, handler, common_routine)		   \
asm(".text								\n"\
"	.align 2							\n"\
"	.global "#label"						\n"\
#label":								\n"\
"	lea.l   -16(%sp), %sp		\n"                                \
"	movem.l %d0-%d1/%a0-%a1, (%sp)	\n" /* �X�N���b�`���W�X�^��ۑ� */ \
				/*  �����݋֎~��SR�����̏���  		*/ \
"	move.w	%sr,%d1							\n"\
	/*  �����݋֎~  						*/ \
	/*     �����݂��֎~����O�ɕʂ̊����݂��������ꍇ�̒��ӓ_�� 	*/ \
	/*     cpu_suppourt.S��ret_int���Q�� 				*/ \
"	move.l	#("str_MAX_IPM" << 8),%d0	                        \n"\
"	ori.l	#0x00002000,%d0	                                        \n"\
"	move.w	%d0,%sr	                                                \n"\
"	move.l	#"#handler", %a0				                \n"\
"	jbra	_kernel_"#common_routine"        \n" /* C���ꃋ�[�`���̐擪�A�h���X*/\
)

/*
 *  �����݃n���h���̓��������̐����}�N��
 *
 */
#define INTHDR_ENTRY(inthdr)	INTHDR_ENTRY2(INT_ENTRY(inthdr), inthdr)

#define INTHDR_ENTRY2(entry, inthdr)					\
	extern void entry(void);					\
	HANDLER_ENTRY_PROC(entry, inthdr, interrupt_entry)


/*
 *  CPU��O�n���h���̓��������̐����}�N��
 */
#define	EXCHDR_ENTRY(exchdr)	EXCHDR_ENTRY2(EXC_ENTRY(exchdr), exchdr)

#define EXCHDR_ENTRY2(entry, exchdr)					\
	extern void entry(void);					\
	HANDLER_ENTRY_PROC(entry, exchdr, cpu_exception_entry)
	/*
	 *  void entry()�͒P�Ȃ�G���g���̃��x���Ȃ̂ŁA
	 *  �����͕t���Ȃ�
	 */

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃R���e�L�X�g�̎Q��
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	/* 
	 *  �P�Ɣ�r����̂́A���ݎ��s����CPU��O�̕�
	 *  �����݃l�X�g�J�E���^���C���N�������g����Ă��邽�� 	
	 *  
	 *  CPU��O�̓����������ɕʂ�CPU��O�͔������Ȃ��Ɖ���
	 *  ���Ă���
	 */
	return(intnest > 0);
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return((*((UH *) p_excinf) & 0x0700) == 0x0700);
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
 *  ���L�̃��O�o�͎��̃X�^�b�N�\���̒�`
 */
typedef struct exc_stack {
	VW	d0;
	VW	d1;
	VW	d2;
	VW	d3;
	VW	d4;
	VW	d5;
	VW	d6;
	VW	d7;
	VW	a0;
	VW	a1;
	VW	a2;
	VW	a3;
	VW	a4;
	VW	a5;
	VW	a6;
	VW	a7;
	VW	sr;	/*  �X�e�[�^�X�E���W�X�^  	*/
	VW	pc;	/*  �v���O�����E�J�E���^  	*/
} EXCSTACK;


/*
 * ��O�������̃��O�o�� (cpu_config.c, cpu_support.S)
 */
extern void     cpu_experr(EXCSTACK *);

#endif /* _MACRO_ONLY */


/*
 *  ��O�x�N�^�ɐݒ肷��f�t�H���g�̒l
 *  	�ȉ��̗�O�v���Ńf�t�H���g�Ƃ͈قȂ��O�x�N�^���`
 *	����ꍇ�́Asys_config.h�ŊY������}�N�����`����B
 */
#define RESET_VECTOR 	start		/*  ���Z�b�g�x�N�^  */
#define INIT_STACK  	STACKTOP	/*  �X�^�b�N�|�C���^�̏����l  */

#define RESERVED_VECTOR	RESET_VECTOR	/*  �V�X�e���\��̃��Z�b�g�x�N�^  */
					/*  ���ۂɂ͎g�p����Ȃ�  */

#ifndef ACC_VECTOR	/*  �A�N�Z�X�G���[  */
#define ACC_VECTOR	RESET_VECTOR
#endif /* ACC_VECTOR */

#ifndef ADD_VECTOR	/*  �A�N�Z�X�G���[  */
#define ADD_VECTOR	RESET_VECTOR
#endif /* ACC_VECTOR */

#ifndef II_VECTOR	/*  �s������  */
#define II_VECTOR	RESET_VECTOR
#endif /* II_VECTOR */

#ifndef PV_VECTOR	/*  �X���b�g�s������  */
#define PV_VECTOR	RESET_VECTOR
#endif /* SII_VECTOR */

#ifndef CAE_VECTOR	/*  CPU�A�h���X�G���[  */
#define CAE_VECTOR	RESET_VECTOR
#endif /* CAE_VECTOR */

#ifndef DAE_VECTOR	/*  DMA�A�h���X�G���[  */
#define DAE_VECTOR	RESET_VECTOR
#endif /* DAE_VECTOR */

#ifndef NMI_VECTOR	/*  NMI  */
#define NMI_VECTOR	RESET_VECTOR
#endif /* NMI_VECTOR */

#endif /* _CPU_CONFIG_H_ */
