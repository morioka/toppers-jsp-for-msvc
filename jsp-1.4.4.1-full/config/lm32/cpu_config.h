/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: cpu_config.h,v 1.14 2007/07/27 11:28:44 honda Exp $
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

#include "cpu_defs.h"

#ifndef _MACRO_ONLY
#include <cpu_insn.h>
#endif

#ifndef _MACRO_ONLY

extern UW exception_count;
extern UW exception_registers[40];

typedef struct task_context_block {
        VP	sp;             
        FP	pc;             
} CTXB;


Inline BOOL
sense_context()
{
    return(exception_count > 0);
}

Inline BOOL
sense_lock()
{
    return((current_sr() & 0x1) == 0);
}

#define t_sense_lock     sense_lock
#define i_sense_lock     sense_lock

Inline void
lock_cpu()
{
    disint();
}

Inline void
unlock_cpu()
{
    enaint();
}

#define EXC_ENTRY(exchdr)     exchdr
#define EXCHDR_ENTRY(exchdr)  extern void exchdr(VP sp)

Inline BOOL
exc_sense_context(VP p_excinf)
{
    return(exception_count > 1);
}

Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return((current_sr() & 0x2) == 0);
}


#define t_lock_cpu      lock_cpu
#define i_lock_cpu      lock_cpu
#define t_unlock_cpu    unlock_cpu
#define i_unlock_cpu    unlock_cpu

extern void dispatch(void);
extern void exit_and_dispatch(void);

extern FP int_table[TMAX_ALL_INTNO];
extern FP exc_table[TMAX_CORE_EXCNO];

Inline void define_inh(INTNO intno, FP inthdr)
{
    int_table[intno] = inthdr;
}

Inline void define_exc(EXCNO excno, FP exchdr)
{
    exc_table[excno] = exchdr;
}

extern void _start();
extern void Breakpoint_exception();
extern void InstructionBusError_exception();
extern void Watchpoint_exception();
extern void DataBusError_exception();
extern void DivideByZero_exception();
extern void Interrupt_exception();
extern void SystemCall_exception();

extern void cpu_initialize(void);
extern void cpu_terminate(void);

#endif /* _MACRO_ONLY */

#endif /* _CPU_CONFIG_H_ */

