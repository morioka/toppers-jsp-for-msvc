/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2006 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2006 by Logic Research Co., Ltd.
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

/*
 *    �^�[�Q�b�g�V�X�e���ˑ����W���[���iFRK_ADuC�p�j
 */

#include "jsp_kernel.h"
#include "frk_aduc.h"


/*interrupt mask*/
const UW int_mask_table[MAX_INT_NUM]={
	MASK_ALL_INT,
	MASK_IRQ_SWI,
	MASK_IRQ_TIMER0,
	MASK_IRQ_TIMER1,
	MASK_IRQ_TIMER2,
	MASK_IRQ_TIMER3,
	MASK_IRQ_FLA_CTRL,
	MASK_IRQ_ADC_CH,
	MASK_IRQ_PLL_LOCK,
	MASK_IRQ_I2C0_SLV,
	MASK_IRQ_I2C0_MST,
	MASK_IRQ_I2C1_MST,
	MASK_IRQ_SPI_SLV,
	MASK_IRQ_SPI_MST,
	MASK_IRQ_UART,
	MASK_IRQ_EXT_IRQ0,
	MASK_IRQ_COMP,
	MASK_IRQ_PSM,
	MASK_IRQ_EXT_IRQ1,
	MASK_IRQ_PLA_IRQ0,
	MASK_IRQ_PLA_IRQ1,
	MASK_IRQ_EXT_IRQ2,
	MASK_IRQ_EXT_IRQ3,
	MASK_IRQ_PWM_TRIP
};


/*
 * �����݃n���h���o�^�p�e�[�u��
 */
FP   int_table[MAX_INT_NUM];


/*
 * OSC�̏�����
 */
void
init_clock(void)
{
    UW    reg;

    /* POWCON key1 */
    sil_wrw_mem((VP)POWKEY1, POWKEY1_DATA);

    /* Core Clock 41.78MHz , Active mode*/
    reg = (POWCON_PC_ACT | POWCON_CD_41M);
    sil_wrw_mem((VP)POWCON, reg);

    /* POWCON key2 */
    sil_wrw_mem((VP)POWKEY2, POWKEY2_DATA);
}


/*
 * GPIO�̏�����
 */
void
init_gpio(void)
{
	/* LED port */
	sil_wrw_mem((VP)GP4CON, 0);			/* GPIO mode */
	sil_wrw_mem((VP)GP4DAT, P47_DIR);	/* Output */
	sil_wrw_mem((VP)GP4SET, LED);		/* LED off */

	/* UART port */
	sil_wrw_mem((VP)GP0CON, GP07_SIN);
	sil_wrw_mem((VP)GP1CON, (GP10_SIN|GP11_SOUT|GP12_RTS|
							 GP13_CTS|GP14_RI|GP15_DCD|
							 GP16_DSR|GP17_DTR));
	sil_wrw_mem((VP)GP2CON, GP20_SOUT);

}


/*
 *  �����݊֘A�̏�����
 */
void
init_IRQ(void)
{
    int i;
    
    /* IRQ�����݋֎~ */
    sil_wrw_mem((VP)IRQCLR, INT_DISABLE_ALL);
    
    /*
     *  �����݃e�[�u���̏�����
     */
    for(i = 0; i < MAX_INT_NUM; i++){
        int_table[i] = 0x00;        /* ���Z�b�g */   
    }
}


/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
void
sys_initialize()
{
    int i;

    init_clock();

	init_gpio();

    init_IRQ();

	/*
	 * SRAM
	 */
    for(i = 0; i <=7; i++){
        arm_vector_add[i] = arm_vector_add[i] + VCT_TB_SRAM/4;
    }

  	for(i=0; i <=14; i++) {
		*((volatile UW *)VCT_TB_SRAM + i) = *((volatile UW *)VCT_TB + i);
	}

 	sil_wrw_mem((VP)REMAP, REMAP_SRAM);

    /*
     *  ARM�̃x�N�^�e�[�u���֊����݃n���h����o�^
     */
    arm_install_handler(IRQ_Number, IRQ_Handler);

    /*
     *  sys_putc ���\�ɂȂ�悤��UART��������
     */
    init_uart();
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
    int_table[inhno] = inthdr;

}

/*
 *  ����`�̊����݂��������ꍇ�̏���
 */
void
undef_interrupt(){
    syslog(LOG_EMERG, "Unregistered Interrupt occurs.");
    while(1);
}


/*IRQ���W�X�^���N���A�����܂ő҂�*/
#define INT_CLEAR_DELAY  0x70
void poll_intreg(int int_mask)
{
    int i;
    
    //while(*IRQEN & int_mask);
    for(i=0;i<INT_CLEAR_DELAY;i++);
    enaint();

}

