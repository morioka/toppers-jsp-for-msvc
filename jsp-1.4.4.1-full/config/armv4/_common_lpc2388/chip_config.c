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
 *  �����ݗp�̃e�[�u��
 */
#define VICVectAddress ((volatile FP **)0xFFFFF100)




/*
 *  �����݊֘A�̏�����(LPC2388����)
 */
void
init_IRQ()
{
	int i;

	for( i=0; i<32; i++ )
		VICVectAddress[i] = (volatile FP *)undef_interrupt;
}

extern unsigned int __data_start;

/*
 * LPC2388��SRAM�̈��FLASH�̃x�N�g�����R�s�[���A
 * ���}�b�v����BLPC2388���ʂŕK�v�B
 */
void
init_vector()
{
	unsigned char *flash, *sram;
	int i;

		/* ROM���R�[�h��SRAM��œ����R�[�h�ł́A��O�x�N�g���̈������Ⴄ�B
		 * ROM������ꍇ�́ASRAM REMAP�̑O��Flash ROM��̗�O�x�N�g���̒l��
		 * SRAM��̃��}�b�v�̈�Ɉڂ��Ȃ���΂Ȃ�Ȃ��B����ASRAM��œ��삷��
		 * �ꍇ�́A���}�b�v�̈�ւ̓f�o�b�K�������l���������ށB
		 * ���̂��߁A���}�b�v�̈�̏������菇���K�v���ۂ��̔��ʂ��s���B���ʂ�
		 * __data_start�̒l���g���B���̒l��lpc2388_sram.ld�̒���0�ɏ���������
		 * ����Blpc2388.ld�̒��ł͔�[���̃A�h���X����������B���������āA
		 * ���}�b�v�̈�̏�������__data_start����[���̂Ƃ������s���B */
	if ( __data_start != 0 )
	{
		flash =(unsigned char*) 0;				/* FLASH�̐擪�A�h���X */
		sram = (unsigned char*) 0x40000000;	/* SRAM�̐擪�A�h���X */

			/* FLASH�̐擪64�o�C�g��SRAM�ɃR�s�[ */
		for (i=0; i<64; i++)
		{
			*sram = *flash;
			sram++;
			flash++;
		}
	}
		/* SRAM ���x�N�g���G���A�Ƀ��}�b�v���� */
	MEMMAP = 0x02;
}

/*
 * LPC2388�ˑ���UART���������[�`���Bsys_putc()�p��uart0������������B
 */
#define	DLAB 0x80
void
init_uart0()
{
    /*
     *  ������̐ݒ�
     */
    /* Divisor Enable */
	U0LCR |= DLAB;
    U0DLL = UART0_DIVISOR & 0xFF ;
    U0DLM = UART0_DIVISOR >> 8;
    /* Divisor Disable */
    U0LCR &= ~DLAB;

    /* ���[�h�ݒ�, �p���e�B���� 8bit data, 1 stop bit */
    U0LCR = 0x03;

    /* �����݋֎~ */
    U0IER = 0;
}

/*
 *  �V�X�e���I���t�b�N�B�t�@�[���E�F�A�ɃV�X�e���I��API������Ȃ�
 *  ������ĂԂƂ悢�B
 */
void
sys_exit()
{
	while(1)
		;
}



/*
 *  �^�[�Q�b�g�V�X�e���̕����o�́Bsyslog�^�X�N���N������O�Ƀv�����g���s�����߂�
 *  ���[�`���ł���A�����ł̓|�[�����O���s���Ă���BLF�L���������Ă�����A
 *  CR LF�ɕϊ����ăv�����g����Bsys_putc�̓f�o�C�X�����������Ȃ��B
 *  ��������kernel_start()�̒��ŏI����Ă���Ɖ��肵�Ă���B
 */

void
sys_putc(char c)
{
	if ( c== 0x0A )			/* ���� LF �Ȃ�� */
		sys_putc( 0x0D );	/* CR���ꕶ�����M */

	while( !( U0LSR & (1<<5)) )
		;		/* UART0 LSR��THRE��1�ɂȂ�܂ő҂B1�Ȃ�Α��M���W�X�^�󂫁B*/

	U0THR = c;	/* �ꕶ�����M */
}


/*
 *  �����݃n���h���̐ݒ�
 *
 *  �����ݔԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 *  VICVectAddress[]�͓����̃��W�X�^��Ƀ}�b�v����Ă���B���������āA
 *  define_inh���ĂԂƁAVICVectAddressX���W�X�^�������������B
 */
void
define_inh(INHNO inhno, FP inthdr)
{
    assert(inhno <= MAX_INT_NUM);
    VICVectAddress[inhno] = (volatile FP*)inthdr;

}

/*
 *  ����`�̊����݂��������ꍇ�̏���
 */
void
undef_interrupt(){
    syslog(LOG_EMERG, "Unregistered Interrupt occurs.");
    while(1);
}


/*
 * ���荞�݂̃C�l�[�u���A�f�B�Z�[�u��
 */
/*
 * intno�ł���킳��銄�荞�݂��f�B�Z�[�u���ɂȂ�B
 */
ER dis_int(INTNO intno)
{
	if ( intno > MAX_INT_NUM )
		return E_PAR;
	VICIntEnClr = 1<<intno;
	return 0;
}

/*
 * intno�ł���킳��銄�荞�݂��C�l�[�u���ɂȂ�B
 */
ER ena_int(INTNO intno)
{
	if ( intno > MAX_INT_NUM )
		return E_PAR;
	VICIntEnable = 1<<intno;
	return 0;
}

/*
 * ���荞�݃C�l�[�u���}�X�N���w�肷��B�}�X�N��VICIntEnable�ɑ�������
 */
ER chg_ims(unsigned int enableMask)
{
	VICIntEnClr = 0xFFFFFFFF;
	VICIntEnable = enableMask;
	return 0;
}

/*
 * ���荞�݃C�l�[�u���}�X�N���擾�B
 */
ER get_ims(unsigned int *p_enableMask)
{
	*p_enableMask = VICIntEnable;
	return 0;
}


