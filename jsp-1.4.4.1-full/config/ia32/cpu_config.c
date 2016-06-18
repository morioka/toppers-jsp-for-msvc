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
 *  @(#) $Id: cpu_config.c,v 1.1 2004/07/21 02:49:36 monaka Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���ii386�p�j
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include <i386.h>

UW nest = 0; /* ���荞�݃l�X�g�� */
FP exc_table[0x20]; /* CPU��O�n���h���̃e�[�u�� */

static SEGDESC gdt[3];    /* �O���[�o���f�B�X�N���v�^�e�[�u�� */
static GATEDESC idt[256]; /* ���荞�݃f�B�X�N���v�^�e�[�u�� */

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize()
{
	DESCPTR desc_ptr;

	/* Flat model */
	set_segment_descriptor(0, 0x0, 0x00000, 0x00, 0);
	set_segment_descriptor(1, 0x0, 0xfffff, I386_TYPE_SEG_CODE | I386_TYPE_SEG_READABLE, 0);
	set_segment_descriptor(2, 0x0, 0xfffff, I386_TYPE_SEG_DATA | I386_TYPE_SEG_WRITEABLE, 0);

	desc_ptr.limit = sizeof(gdt) - 1;
	desc_ptr.base = (unsigned)gdt;

	Asm("movl	%0, %%eax": : "g"(&desc_ptr) : "eax");
	Asm("lgdt	(%eax)		\n"
	    "ljmp	$0x8, $csinit	\n" /* �p�C�v���C���ɐ�ǂ݂������߂��N���A���� */
	    "csinit:			\n"
	    "movw	$0x10, %ax	\n"
	    "movw	%ax, %ds	\n"
	    "movw	%ax, %es	\n"
	    "movw	%ax, %fs	\n"
	    "movw	%ax, %gs	\n"
	    "movw	%ax, %ss");

	set_gate_descriptor( 0, 0x8, exception0,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 1, 0x8, exception1,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 2, 0x8, exception2,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 3, 0x8, exception3,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 4, 0x8, exception4,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 5, 0x8, exception5,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 6, 0x8, exception6,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 7, 0x8, exception7,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 8, 0x8, exception8,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor( 9, 0x8, exception9,  I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(10, 0x8, exception10, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(11, 0x8, exception11, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(12, 0x8, exception12, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(13, 0x8, exception13, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(14, 0x8, exception14, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(16, 0x8, exception16, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(17, 0x8, exception17, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(18, 0x8, exception18, I386_TYPE_GATE_INTR, 0);
	set_gate_descriptor(19, 0x8, exception19, I386_TYPE_GATE_INTR, 0);

	desc_ptr.limit = sizeof(idt) - 1;
	desc_ptr.base = (unsigned)idt;

	Asm("movl	%0, %%eax	" : : "g"(&desc_ptr) : "eax");
	Asm("lidt	(%eax)		");

}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate()
{
}


/*
 * i386�Z�O�����g�f�X�N���v�^�̐ݒ�
 */
void
set_segment_descriptor(int sel, unsigned addr, unsigned limit, unsigned type, unsigned dpl)
{
	SEGDESC *desc;
	desc = &gdt[sel];
	desc->base_L = (addr & 0xffffff);
	desc->base_H = ((addr >> 24) & 0xff);
	desc->limit_L = (limit & 0xffff);
	desc->limit_H = ((limit >> 16) & 0xf);
	desc->type = (type & 0xf);
	desc->s = 1;		/* code/data segment */
	desc->dpl = dpl;
	desc->p = 1;		/* segment is existing */
	desc->avl = 0;		/* unused */
	desc->x = 0;		/* reserved */
	desc->db = 1;		/* 32bits segment */
	desc->g = 1;		/* 4KB limits */
}

void
set_gate_descriptor(int sel, unsigned selector, void *func, unsigned type, unsigned dpl)
{
	GATEDESC *desc;
	desc = &idt[sel];
	desc->offset_L = ((unsigned)func & 0xffff);
	desc->offset_H = (((unsigned)func >> 16) & 0xffff);
	desc->selector = selector;
	desc->copy = 0;
	desc->type = type;
	desc->s = 0;
	desc->dpl = dpl;
	desc->p = 1;
}


void
define_exc(EXCNO excno, FP exchdr)
{
#if 0
	if (inhno >= 0x20 || inthdr == NULL)
	{
		return; /*??? Should I generate assertion? */
	}
#endif
	exc_table[excno] = exchdr;
}
