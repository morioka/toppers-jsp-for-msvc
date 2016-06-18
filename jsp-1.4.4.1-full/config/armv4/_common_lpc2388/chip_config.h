/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                2003      by Advanced Data Controls, Corp
 *  Copyright (C) 2009 by Suikan
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
 *  �^�[�Q�b�g�`�b�v�ˑ����W���[���iLPC2388�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Csys_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */


#ifndef _CHIP_CONFIG_H_
#define _CHIP_CONFIG_H_


/*
 * �����݃n���h���̍ő吔
 */
#define MAX_INT_NUM 31

/*
 *  vxget_tim ���T�|�[�g���邩�ǂ����̒�`
 */
#define  SUPPORT_VXGET_TIM



/*
 *  �����ݑ҂���Ԃł̎��s���[�`��
 */
#ifdef ARM920T_CORE
#define WAIT_INTERRUPT  mcr p15, 0, r3, c7, c0, 4
#else
#define WAIT_INTERRUPT  nop
#endif

/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define SIL_ENDIAN  SIL_ENDIAN_LITTLE  /* ���g���G���f�B�A�� */


/*
 * ----------------------- ���荞�݃x�N�g���錾 --------------------
 * INTNO_UART0 �ł͂Ȃ� INTO_U0 ���g���̂́AUART��TOPPERS/JSP�����̃f�o�C�X���Ƃ���
 * �g���Ă���AUART�̔ԍ���LPC2388�̔񓯊��ʐM�f�o�C�X�̔ԍ�����v���Ȃ����߂ł���B
 *
 */
#define	INTNO_WDT		0
/*reserverved interrupt 1*/
#define	INTNO_ARM0		2
#define	INTNO_ARM1		3
#define	INTNO_TIMER0	4
#define	INTNO_TIMER1	5
#define	INTNO_U0		6
#define	INTNO_U1		7
#define	INTNO_PWM1		8
#define	INTNO_I2C0		9
#define	INTNO_SSP0		10
#define	INTNO_SSP1		11
#define	INTNO_PLL		12
#define	INTNO_RTC		13
#define	INTNO_EINT0		14
#define	INTNO_EINT1		15
#define	INTNO_EINT2		16
#define	INTNO_EINT3		17
#define	INTNO_ADC0		18
#define	INTNO_I2C1		19
#define	INTNO_BOD		20
#define	INTNO_ETHERNET	21
#define	INTNO_USB		22
#define	INTNO_CAN		23
#define	INTNO_SD		24
#define	INTNO_GPDMA		25
#define	INTNO_TIMER2	26
#define	INTNO_TIMER3	27
#define	INTNO_U2		28
#define	INTNO_U3		29
#define	INTNO_I2C2		30
#define	INTNO_I2S		31

#define	INHNO_WDT		0
/*reserverved interrupt 1*/
#define	INHNO_ARM0		2
#define	INHNO_ARM1		3
#define	INHNO_TIMER0	4
#define	INHNO_TIMER1	5
#define	INHNO_U0		6
#define	INHNO_U1		7
#define	INHNO_PWM1		8
#define	INHNO_I2C0		9
#define	INHNO_SSP0		10
#define	INHNO_SSP1		11
#define	INHNO_PLL		12
#define	INHNO_RTC		13
#define	INHNO_EINT0		14
#define	INHNO_EINT1		15
#define	INHNO_EINT2		16
#define	INHNO_EINT3		17
#define	INHNO_ADC0		18
#define	INHNO_I2C1		19
#define	INHNO_BOD		20
#define	INHNO_ETHERNET	21
#define	INHNO_USB		22
#define	INHNO_CAN		23
#define	INHNO_SD		24
#define	INHNO_GPDMA		25
#define	INHNO_TIMER2	26
#define	INHNO_TIMER3	27
#define	INHNO_U2		28
#define	INHNO_U3		29
#define	INHNO_I2C2		30
#define	INHNO_I2S		31

/*
 * SIO1,2,3�ɂ�U0,U2,U3�����蓖�Ă�
 */
#define INHNO_SIO		INHNO_U0
#define INHNO_SIO2		INHNO_U2
#define INHNO_SIO3		INHNO_U3

/*
 * ----------------------- UART �ݒ� ---------------------------
 */

/*
 *     UART�̂����A��̃|�[�g��PDIC�Ƃ��Ďg�p���邩�錾����B
 *     LPC2388�łł͍ő�3
 */
#define TNUM_SIOP_UART	TNUM_SIOP

/*
 *    UART�̃��W�X�^�����o�C�g���E�ɔz�u����Ă��邩���w�肷��B�w��ł���l��1,2,4�̂����ꂩ�B
 */
#define UART_BOUNDARY	4

/*
 * UART ���W�X�^�ւ̃A�N�Z�X��sil_xxb_iop()�g���ꍇ�ɂ͂��̃}�N����錾����B
 * �l�͕s�v�B�錾���Ȃ��ꍇ�Asil_xxb_mem()�ɂ���ăA�N�Z�X����BLPC2388����
 * �ł�mem�A�N�Z�X���g�p����B
 */
/* #define UART_IOP_ACCESS */

/*
 *     UART�̃x�[�X�E�A�h���X���w�肷��B�x�[�X�A�h���X�Ƃ�THR�̃A�h���X�̂��ƁB
 *     U0,2,3���g���̂́ALPC2388�ɂ�����U1�����ʈ����̂���
 */
#define UART0_ADDRESS 0xE000C000
#define UART1_ADDRESS 0xE0078000	/*U2*/
#define UART2_ADDRESS 0xE007C000	/*U3*/

/*
 * UART�����̕�����H�̐ݒ�l���w�肷��B16�r�b�g�̒l�Blpc2388uart.c������
 * ��ʂƉ��ʂɕ�������DLM/DLL���W�X�^�ɐݒ肳���B
 *
 * UART�̃f�o�C�U�̏o�͂͏��]����{�[���[�g��16�{�łȂ���΂Ȃ�Ȃ��B
 * U0,2,3���g���̂́ALPC2388�ɂ�����U1�����ʈ����̂���
 */
#define UART0_DIVISOR (LP2388_SYSTEM_UART0_CLOCK/16/UART0_BAUD_RATE)
#define UART1_DIVISOR (LP2388_SYSTEM_UART1_CLOCK/16/UART2_BAUD_RATE) /*U2*/
#define UART2_DIVISOR (LP2388_SYSTEM_UART1_CLOCK/16/UART3_BAUD_RATE) /*U3*/


/*
 * ----------------------- UART �ݒ肨��� ---------------------------
 */


#ifndef _MACRO_ONLY

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
extern void    sys_initialize(void);

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 *
 *  �V�X�e�����I�����鎞�Ɏg���DROM���j�^�ďo���Ŏ������邱�Ƃ�z�肵
 *  �Ă���D
 */
extern void    sys_exit(void);

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 *
 *  �V�X�e���̒჌�x���̕����o�̓��[�`���DROM���j�^�ďo���Ŏ������邱
 *  �Ƃ�z�肵�Ă���D
 */
extern void    sys_putc(char c);



/*
 *  IRQ�n���h��(sys_support.S)
 */
extern void IRQ_Handler(void);

/*
 *  �����݃n���h���̏o���������̐����}�N��
 *
 */
#define INTHDR_ENTRY(inthdr)  extern void inthdr(void)

#define INT_ENTRY(inthdr) inthdr

/*
 *  �����݃n���h���̐ݒ�
 *
 *  �����ݔԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 */
extern void define_inh(INHNO inhno, FP inthdr);

extern void undef_interrupt();

extern void init_IRQ();
extern void init_vector();
extern void init_uart0();

/*
 * ���荞�݂̃C�l�[�u���A�f�B�Z�[�u��
 */

extern ER dis_int(INTNO intno);
extern ER ena_int(INTNO intno);
extern ER chg_ims(unsigned int enableMask);
extern ER get_ims(unsigned int *p_enableMask);

#endif /* _MACRO_ONLY */
#endif /* _SYS_CONFIG_H_ */
