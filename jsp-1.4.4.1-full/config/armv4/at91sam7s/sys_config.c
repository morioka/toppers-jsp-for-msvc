/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003      by Advanced Data Controls, Corp
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2006 by GJ Business Division RICOH COMPANY,LTD. JAPAN
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
 *  @(#) $Id$
 */

/*
 *    �^�[�Q�b�g�V�X�e���ˑ����W���[���iAt91sam7s�p�j
 */

#include "jsp_kernel.h"
#include <at91sam7s.h>


/*interrupt mask*/
UW int_mode_table[MAX_INT_NUM]={
    0,
    0,
    0,
    0,
    0,
    0,
    SMR_US0,
    SMR_US1,
    0,
    0,
    0,
    0,
    SMR_TC0,
    SMR_TC1,
    SMR_TC2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
void
sys_initialize()
{
    unsigned int  baud = ((MCK * 10) / (115200 * 16));
    unsigned long brgr;

#ifndef VECTOR_IN_ROM
    /*
     *  ARM�̃x�N�^�e�[�u���֊����݃n���h����o�^
     */
    arm_install_handler(IRQ_Number,IRQ_Handler);
#endif

    /*
     *  sys_putc ���\�ɂȂ�悤��UART��������
     */
    brgr = baud / 10;
    if((baud % 10) >= 5)
        brgr = (baud / 10) + 1;
    sil_wrw_mem((VP)(TADR_PIO_BASE+TOFF_PIO_PDR), (1<<9)|(1<<10));
    sil_wrw_mem((VP)(TADR_DBGU_BASE+TOFF_US_IDR), 0xFFFFFFFF);
    sil_wrw_mem((VP)(TADR_DBGU_BASE+TOFF_US_CR), US_RSTRX|US_RSTTX|US_RXDIS|US_TXDIS);
    sil_wrw_mem((VP)(TADR_DBGU_BASE+TOFF_US_BRGR), brgr);
    sil_wrw_mem((VP)(TADR_DBGU_BASE+TOFF_US_MR), 4<<9);
    sil_wrw_mem((VP)(TADR_DBGU_BASE+TOFF_US_CR), US_TXEN|US_RXEN);
}


/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 */
void
sys_exit(void)
{
    syslog(LOG_EMERG, "End Kernel.....!");
    while(1);
}


/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */

void
sys_putc(char c)
{
    if (c == '\n') {
        uart_putc('\r');
    }
    uart_putc(c);
}


/*
 *  �����݃n���h���̐ݒ�
 *
 *  �����ݔԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 */
void
define_inh(INHNO inhno, FP inthdr)
{
    assert(inhno < MAX_INT_NUM);
	sil_wrw_mem((VP)(TADR_AIC_BASE+TOFF_AIC_IDCR), 1<<inhno);
	sil_wrw_mem((VP)(TADR_AIC_BASE+TOFF_AIC_SVR+inhno*4), (UW)inthdr);
	sil_wrw_mem((VP)(TADR_AIC_BASE+TOFF_AIC_SMR+inhno*4), int_mode_table[inhno]);
	sil_wrw_mem((VP)(TADR_AIC_BASE+TOFF_AIC_ICCR), 1<<inhno);
	sil_wrw_mem((VP)(TADR_AIC_BASE+TOFF_AIC_IECR), 1<<inhno);
}

/*
 *  ����`�̊����݂��������ꍇ�̏���
 */
void
undef_interrupt(){
    syslog(LOG_EMERG, "Unregistered Interrupt occurs.");
    while(1);
}

