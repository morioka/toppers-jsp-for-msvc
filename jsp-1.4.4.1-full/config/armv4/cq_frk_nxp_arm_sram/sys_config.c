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
 *                2009 by Suikan
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
 *    �^�[�Q�b�g�V�X�e���ˑ����W���[���iCQ-FRK-NXP-ARM�j
 */

#include "jsp_kernel.h"
#include <lpc2388.h>



/*
 * OSC�̏�����(�V�X�e���ŗL). 4MHz �̓����I�V���[�^���g��
 */
static void
init_clock()
{
	/* 1. ����PLL���g�p���Ă���Ȃ�A�f�B�X�R�l�N�g���A�t�B�[�h�E�V�[�P���X�𓥂� */
	PLLCON &= 0xFFFFFFFD;	/* Clear bit 1, PLL bypassed */
	PLLFEED = 0xAA;
	PLLFEED = 0x55;

	/* 2. PLL���f�B�Z�[�u�����A�t�B�[�h�E�V�[�P���X�𓥂ށB */
	PLLCON = 0;		/* Disable PLL */
	PLLFEED = 0xAA;
	PLLFEED = 0x55;

	/* 3. CPU�N���b�N�E�f�B�o�C�_�̐ݒ���APLL�Ȃ��ł��x���Ȃ肷���Ȃ��悤�ɐݒ肷��B */
	CCLKCFG = 0;	/* CCLK = PCLK / 1 */

	/* 4. PLL�̃N���b�N�\�[�X��ύX����B */
	CLKSRCSEL = 0;	/* Select 4MHz internal oscillator*/
//	CLKSRCSEL = 1;	/* Select 12MHz main oscillator*/

	/* 5. PLLCFG�ւ̏������݂��s���A�t�B�[�h�E�V�[�P���X�𓥂�ŗL��������B
	 * PLLCFG�́APLL���f�B�Z�[�u���̂Ƃ��ɂ����ύX�ł���B */
	PLLCFG = 35;	/* Divide by 1, Multiply by 72, PCLK = 4*72 = 288MHz */
//	PLLCFG = 11;	/* Divide by 1, Multiply by 24, PCLK = 12*24 = 288MHz */
	PLLFEED = 0xAA;
	PLLFEED = 0x55;

	/* 6. PLL���C�l�[�u���ɂ��A�t�B�[�h�E�V�[�P���X�𓥂�. */
	PLLCON = 1;		/* Enable PLL */
	PLLFEED = 0xAA;
	PLLFEED = 0x55;

	/* 7. CPU�N���b�N�E�f�B�o�C�_�̒l���APLL����p�ɕύX����B
	 * ����͕K���APLL���N���b�N���Ƃ��Đڑ�����O�ɍs���B */
	CCLKCFG = 3;	/* CCLK = PCLK/4 = 288/4 = 72MHz */

	/* 8. PLLSTAT���W�X�^��PLOCK bit�𒲂ׂāAPLL�����b�N����܂ő҂B
	 * ���邢��PLOCK���荞�݂��g�p���Ă������B���邢�́APLL�̓��̓N���b�N��������(32kHz�Ȃ�)�Ȃ�A
	 * �P���ɃE�F�C�g�E���[�v���񂵂Ă������B*/
	while ( !(PLLSTAT & (1<<26)))
		;

	/* 9. PLL���V�X�e���ɐڑ����A�t�B�[�h�V�[�P���X�����s���� */
	PLLCON = 3;		/* Select PLL as CPU clock source */
	PLLFEED = 0xAA;
	PLLFEED = 0x55;
}




/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
void
sys_initialize()
{
    int i;

    init_vector();			/* SRAM�̃��}�b�v�BLPC2388���� */

    init_clock();			/* PLL�̐ݒ�B�V�X�e���ŗL */

    init_uart0();			/* UART0�̏������B�V�X�e���ŗL */

    init_IRQ();				/* VIC������������BLPC2388���� */

    		/* �K�v�ȃy���t�F�����̓d��������(�V�X�e���ŗL) */
			/* �Ȃ��AUART0��TIMER3��LPC2388���ʂŕK�v */
	PCONP |= 0x00800008;	/* bit3:UART0, bit23:TIMER3 */

			/* UART0�̃s����ݒ� (LPC2388����) */
	PINSEL0 &= ~0xF0;			/* bit 4-7�������N���A */
	PINSEL0 |= 0x50;			/* UART���o�͂����蓖�� */

    /*
     *  ARM�̃x�N�^�e�[�u���֊����݃n���h����o�^�i�ǂ�ARMv4�V�X�e���ł��v�������j
     */
    arm_install_handler(IRQ_Number,IRQ_Handler);

}





