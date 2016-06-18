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
 *  @(#) $Id: cpu_config.c,v 1.14 2007/07/27 11:28:44 honda Exp $
 */

#include "jsp_kernel.h"
#include "cpu_config.h"

UW exception_count;

UW exception_registers[40];

FP exc_table[TMAX_CORE_EXCNO] =
{
    (FP)_start,
    (FP)Breakpoint_exception,
    (FP)InstructionBusError_exception,
    (FP)Watchpoint_exception,
    (FP)DataBusError_exception,
    (FP)DivideByZero_exception,
    (FP)Interrupt_exception,
    (FP)SystemCall_exception
};

void dump_registers()
{
    syslog(LOG_EMERG, "r0  : 0x%08x, r1  : 0x%08x, r2  : 0x%08x, r3  : 0x%08x",
    	exception_registers[0], exception_registers[1], exception_registers[2], exception_registers[3]);
    syslog(LOG_EMERG, "r4  : 0x%08x, r5  : 0x%08x, r6  : 0x%08x, r7  : 0x%08x",
    	exception_registers[4], exception_registers[5], exception_registers[6], exception_registers[7]);
    syslog(LOG_EMERG, "r8  : 0x%08x, r9  : 0x%08x, r10 : 0x%08x, r11 : 0x%08x",
    	exception_registers[8], exception_registers[9], exception_registers[10], exception_registers[11]);
    syslog(LOG_EMERG, "r12 : 0x%08x, r13 : 0x%08x, r14 : 0x%08x, r15 : 0x%08x",
    	exception_registers[12], exception_registers[13], exception_registers[14], exception_registers[15]);    	
    syslog(LOG_EMERG, "r16 : 0x%08x, r17 : 0x%08x, r18 : 0x%08x, r19 : 0x%08x",
        exception_registers[16], exception_registers[17], exception_registers[18], exception_registers[19]);
    syslog(LOG_EMERG, "r20 : 0x%08x, r21 : 0x%08x, r22 : 0x%08x, r23 : 0x%08x",
        exception_registers[20], exception_registers[21], exception_registers[22], exception_registers[23]);    	
    syslog(LOG_EMERG, "r24 : 0x%08x, r25 : 0x%08x, r26 : 0x%08x, r27 : 0x%08x",
        exception_registers[24], exception_registers[25], exception_registers[26], exception_registers[27]);    	    	
    syslog(LOG_EMERG, "sp  : 0x%08x, ra  : 0x%08x, ea  : 0x%08x, ba  : 0x%08x",
        exception_registers[28], exception_registers[29], exception_registers[30], exception_registers[31]);
        
    syslog(LOG_EMERG, "ie  : 0x%08x, im  : 0x%08x, ip  : 0x%08x, icc : 0x%08x",
        exception_registers[32], exception_registers[33], exception_registers[34], exception_registers[35]);
    syslog(LOG_EMERG, "dcc : 0x%08x, cc  : 0x%08x, cfg : 0x%08x, eba : 0x%08x",
        exception_registers[36], exception_registers[37], exception_registers[38], exception_registers[39]);  	
}

void Breakpoint_exception()
{
    syslog(LOG_EMERG, "Breakpoint Exception occurs.");
    dump_registers();  
    while(1);
}

void InstructionBusError_exception()
{
    syslog(LOG_EMERG, "InstructionBusError Exception occurs.");
    dump_registers(); 
    while(1);
}

void Watchpoint_exception()
{
    syslog(LOG_EMERG, "Watchpoint Exception occurs.");
    dump_registers(); 
    while(1);
}

void DataBusError_exception()
{
    syslog(LOG_EMERG, "DataBusError Exception occurs.");
    dump_registers();       
    while(1);
}

void DivideByZero_exception()
{
    syslog(LOG_EMERG, "DivideByZero Exception occurs.");
    dump_registers();        
    while(1);
}

void Interrupt_exception()
{
    syslog(LOG_EMERG, "Interrupt Exception occurs.");
    dump_registers();         
    while(1);
}

void SystemCall_exception()
{
    syslog(LOG_EMERG, "SystemCall Exception occurs.");
    dump_registers();     
    while(1);
}

void cpu_initialize(void) 
{
	exception_count = 1;
}

void cpu_terminate(void)
{

}
