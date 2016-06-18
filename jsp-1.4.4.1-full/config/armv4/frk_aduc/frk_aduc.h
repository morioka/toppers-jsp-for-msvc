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

#ifndef _FRK_ADUC_H_
#define _FRK_ADUC_H_

#ifndef _MACRO_ONLY
#include <itron.h>
#include <sil.h>
#endif /* _MACRO_ONLY */

#include <armv4.h>
#include "sys_config.h"
#include "cpu_config.h"



/*
 * GPIO
 */
/* GPIO Register address */
#define GPIO_BASE	0xFFFFF400		/* GPIO base-address */
#define GP0CON		(GPIO_BASE | 0x00)		/* GPIO port0 condition register */
#define GP1CON		(GPIO_BASE | 0x04)		/* GPIO port1 condition register */
#define GP2CON		(GPIO_BASE | 0x08)		/* GPIO port2 condition register */
#define GP4CON		(GPIO_BASE | 0x10)		/* GPIO port4 condition register */
#define GP4DAT		(GPIO_BASE | 0x60)		/* GPIO data register */
#define GP4SET		(GPIO_BASE | 0x64)		/* GPIO SET feild */
#define GP4CLR		(GPIO_BASE | 0x68)		/* GPIO CLEAR feild */

/* Port4 data */
#define P47_DIR	0x80000000		/* Port4 pin7 Direction - Output */
#define LED		0x00800000			/* Port4 pin7 data */

/* Serial mode */
#define	GP07_SIN	0x20000000
#define	GP10_SIN	0x00000001
#define	GP11_SOUT	0x00000010
#define	GP12_RTS	0x00000100
#define	GP13_CTS	0x00001000
#define	GP14_RI		0x00010000
#define	GP15_DCD	0x00100000
#define	GP16_DSR	0x01000000
#define	GP17_DTR	0x10000000
#define	GP20_SOUT	0x00000002




/*
 * PLL
 */
/* PLL Registers */
#define	PLL_BASE		0xFFFF0400	/* PLL base-address */
#define	POWKEY1_VCT		0x04
#define	POWCON_VCT		0x08
#define	POWKEY2_VCT		0x0C
#define	PLLKEY1_VCT		0x10
#define	PLLCON_VCT		0x14
#define	PLLKEY2_VCT		0x18

#define	POWKEY1		(PLL_BASE|POWKEY1_VCT)	/* POWKEY1 address */
#define	POWCON		(PLL_BASE|POWCON_VCT)	/* POWCOM address */
#define	POWKEY2		(PLL_BASE|POWKEY2_VCT)	/* POWKEY2 address */
#define	PLLKEY1		(PLL_BASE|PLLKEY1_VCT)	/* PLLKEY1 address */
#define	PLLCON		(PLL_BASE|PLLCON_VCT)	/* PLLCON address */
#define	PLLKEY2		(PLL_BASE|PLLKEY2_VCT)	/* PLLKEY2 address */



/* KEY's offset */
#define	POWKEY1_DATA	0x01		/* POWKEY1 data */
#define	POWKEY2_DATA	0xF4		/* POWKEY2 data */
#define	PLLKEY1_DATA	0xAA		/* PLLKEY1 data */
#define	PLLKEY2_DATA	0x55		/* PLLKEY2 data */

/* POWCON bits */
#define	POWCON_PC_STP	0x40		/* Stop mode */
#define	POWCON_PC_SLP	0x30		/* Sleep mode */
#define	POWCON_PC_NAP	0x20		/* Nap. */
#define	POWCON_PC_PAU	0x10		/* Pause mode */
#define	POWCON_PC_ACT	0x00		/* Active mode */

#define	POWCON_CD_326K	0x07		/* Core Clock = 326KHz */
#define	POWCON_CD_653K	0x06		/* Core Clock = 653KHz */
#define	POWCON_CD_1M	0x05		/* Core Clock = 1.31MHz */
#define	POWCON_CD_2M	0x04		/* Core Clock = 2.61MHz */
#define	POWCON_CD_5M	0x03		/* Core Clock = 5.22MHz */
#define	POWCON_CD_10M	0x02		/* Core Clock = 10.44MHz */
#define	POWCON_CD_20M	0x01		/* Core Clock = 20.89MHz */
#define	POWCON_CD_41M	0x00		/* Core Clock = 41.78MHz */

/* PLLCON bits */
#define	PLLCON_OSEL			0x20	/* 1:internal oscillator, 0:external crystal */

#define	PLLCON_MDCLK_EXT	0x03	/* External Clock on P0.7 pin */
#define	PLLCON_MDCLK_PLL	0x01	/* PLL */



/*
 * FRK_ADuC Peripheral Base Address
 */
#define	IRQ_BASE	0xFFFF0000			/* IRQ base-address */
#define	TIMER_BASE	0xFFFF0300		/* Timer base-address */
#define	UART_BASE	0xFFFF0700



/*
 * Remap Register
 */
#define REMAP	0xFFFF0220

#define REMAP_SRAM	0x01	/* remap the sram to address to 0 */



/*
 * IRQ
 */
/* IRQ Registers */
#define	IRQSTA		(IRQ_BASE | 0x00)	/* IRQ Status Register */
#define	IRQSIG		(IRQ_BASE | 0x04)	/* IRQ Signal Register */
#define	IRQEN		(IRQ_BASE | 0x08)	/* IRQ enable Register */
#define	IRQCLR		(IRQ_BASE | 0x0C)	/* IRQ Clear Register */
#define SWICFG		(IRQ_BASE | 0x10)

#define	IRQ_PWMTRIP_BIT		23
#define IRQ_EXT3_BIT		22
#define IRQ_EXT2_BIT		21
#define IRQ_PLA1_BIT		20
#define IRQ_PLA0_BIT		19
#define IRQ_EXT1_BIT		18
#define IRQ_PSM_BIT			17
#define IRQ_COMP_BIT		16
#define IRQ_EXT0_BIT		15
#define IRQ_UART_BIT		14
#define IRQ_SPIM_BIT		13
#define IRQ_SPIS_BIT		12
#define IRQ_I2C1M_BIT		11
#define IRQ_I2C0M_BIT		10
#define IRQ_I2C0S_BIT		 9
#define IRQ_PLLL_BIT		 8
#define IRQ_ADCC_BIT		 7
#define IRQ_FLAC_BIT		 6
#define IRQ_TIM3_BIT		 5
#define IRQ_TIM2_BIT		 4
#define IRQ_TIM1_BIT		 3
#define IRQ_TIM0_BIT		 2
#define IRQ_SWI_BIT			 1
#define ALL_INT_OR			 0

#define IRQ_PWM_TRIP	(1 << IRQ_PWMT_BIT)
#define IRQ_EXT_IRQ3	(1 << IRQ_EXT3_BIT)
#define IRQ_EXT_IRQ2	(1 << IRQ_EXT2_BIT)
#define IRQ_PLA_IRQ1	(1 << IRQ_PLA1_BIT)
#define IRQ_PLA_IRQ0	(1 << IRQ_PLA0_BIT)
#define IRQ_EXT_IRQ1	(1 << IRQ_EXT1_BIT)
#define IRQ_PSM			(1 << IRQ_PSM_BIT)
#define IRQ_COMP		(1 << IRQ_COMP_BIT)
#define IRQ_EXT_IRQ0	(1 << IRQ_EXT0_BIT)
#define IRQ_UART		(1 << IRQ_UART_BIT)
#define IRQ_SPI_MST		(1 << IRQ_SPIM_BIT)
#define IRQ_SPI_SLV		(1 << IRQ_SPIS_BIT)
#define IRQ_I2C1_MST	(1 << IRQ_I2C1M_BIT)
#define IRQ_I2C0_MST	(1 << IRQ_I2C0M_BIT)
#define IRQ_I2C0_SLV	(1 << IRQ_I2C0S_BIT)
#define IRQ_PLL_LOCK	(1 << IRQ_PLLL_BIT)
#define IRQ_ADC_CH		(1 << IRQ_ADCC_BIT)
#define IRQ_FLA_CTRL	(1 << IRQ_FLAC_BIT)
#define IRQ_TIMER3		(1 << IRQ_TIM3_BIT)
#define IRQ_TIMER2		(1 << IRQ_TIM2_BIT)
#define	IRQ_TIMER1		(1 << IRQ_TIM1_BIT)
#define	IRQ_TIMER0		(1 << IRQ_TIM0_BIT)
#define IRQ_SWI			(1 << IRQ_SWI_BIT)
#define ALL_INT			(1 << ALL_INT_OR)

#define MASK_IRQ_TIMER3		0xFFFFFF
#define MASK_IRQ_TIMER2		0xFFFFDF
#define	MASK_IRQ_TIMER1		0xFFFFCF
#define	MASK_IRQ_TIMER0		0xFFFFC7
#define MASK_IRQ_UART		0xFFFFC3
#define MASK_IRQ_SWI		0xFFBFC3

#define MASK_IRQ_PWM_TRIP	0xFFBFC1
#define MASK_IRQ_EXT_IRQ3	0x7FBFC1
#define MASK_IRQ_EXT_IRQ2	0x3FBFC1
#define MASK_IRQ_PLA_IRQ1	0x1FBFC1
#define MASK_IRQ_PLA_IRQ0	0x0FBFC1
#define MASK_IRQ_EXT_IRQ1	0x07BFC1
#define MASK_IRQ_PSM		0x03BFC1
#define MASK_IRQ_COMP		0x01BFC1
#define MASK_IRQ_EXT_IRQ0	0x00BFC1
#define MASK_IRQ_SPI_MST	0x003FC1
#define MASK_IRQ_SPI_SLV	0x001FC1
#define MASK_IRQ_I2C1_MST	0x000FC1
#define MASK_IRQ_I2C0_MST	0x0007C1
#define MASK_IRQ_I2C0_SLV	0x0003C1
#define MASK_IRQ_PLL_LOCK	0x0001C1
#define MASK_IRQ_ADC_CH		0x0000C1
#define MASK_IRQ_FLA_CTRL	0x000041
#define MASK_ALL_INT		0x000001

#define INT_DISABLE_ALL		0xFFFFFF

/*
 * Timer0
 */
/* Timer0 Register address */
#define T0LD		(TIMER_BASE | 0x00)	/* Timer0 Load Register */
#define T0VAL		(TIMER_BASE | 0x04)	/* Timer0 Value Register */
#define T0CON		(TIMER_BASE | 0x08)	/* Timer0 Control Register */
#define T0CLRI		(TIMER_BASE | 0x0C)	/* Timer0 Clear Register */

/* Timer0 Control Register bits */
#define	T0CON_ENA		0x80		/* Timer0 enable */
#define	T0CON_MOD		0x40		/* 1:periodic mode, 0:free-running mode */
#define T0CON_PSC_UDF	0x0C		/* Prescale: undefined, equal 0x00 */
#define	T0CON_PSC_256	0x08		/* Prescale: 1/256 */
#define	T0CON_PSC_16	0x04		/* Prescale: 1/16 */
#define	T0CON_PSC_1		0x00		/* Prescale: 1/1 */

/* Timer0 count number */
#define	TIM0_COUNT_MAX		0xFFFF	/* 16 bit */
#define	TIM0_COUNT			0x55FF	/* 16 bit */



/*
 * Timer1
 */
/* Timer1 Register address */
#define T1LD		(TIMER_BASE | 0x20)	/* Timer1 Load Register */
#define T1VAL		(TIMER_BASE | 0x24)	/* Timer1 Value Register */
#define T1CON		(TIMER_BASE | 0x28)	/* Timer1 Control Register */
#define T1CLRI		(TIMER_BASE | 0x2C)	/* Timer1 Clear Register */
#define T1CAP		(TIMER_BASE | 0x30)	/* Timer1 Capture Register */

/* Timer1 Control Register bits */
#define T1CON_CAP		0x20000		/* capture */

#define	T1CON_CLS_P0_6	0x0600		/* Clock source from Port0 pin6 */
#define	T1CON_CLS_P1_0	0x0400		/* Clock source from Port1 pin0 */
#define	T1CON_CLS_OSCI	0x0200		/* Clock source from oscillator */
#define	T1CON_CLS_CORE	0x0000		/* Clock source from core clock */

#define T1CON_CUP		0x0100		/* 1:count up, 0:count down */
#define	T1CON_ENA		0x0080		/* Timer1 enable */
#define	T1CON_MOD		0x0040		/* 1:periodic mode, 0:free-running mode */

#define T1CON_FMT_BIN	0x0000		/* Format: binary */
#define T1CON_FMT_23H	0x0020		/* Format: hr:min:sec:hundredths -23h to 0h */
#define T1CON_FMT_255H	0x0030		/* Format: hr:min:sec:hundredths -255h to 0h */

#define T1CON_PSC_32768	0x000F		/* Prescale: 1/32768 */
#define	T1CON_PSC_256	0x0008		/* Prescale: 1/256 */
#define	T1CON_PSC_16	0x0004		/* Prescale: 1/16 */
#define	T1CON_PSC_1		0x0000		/* Prescale: 1/1 */


/* Timer1 count number */
//#define	TIM1_CNT_1S		41780000	/* 1s (41.78MHz) */
//#define	TIM1_CNT_1mS	41780	/* 1ms (41.78MHz) */
//#define	TIM1_CNT_OSC	32768		/* 1s (32.768kHz) */



/*
 * UART
 */
/* UART Registers */
#define	COMTX		(UART_BASE | 0x00)	/* Transmit */
#define	COMRX		(UART_BASE | 0x00)	/* Receive */
#define	COMDIV0		(UART_BASE | 0x00)	/* Low-byte divisor latch */
#define	COMIEN0		(UART_BASE | 0x04)	/* Interrupt Enable */
#define	COMDIV1		(UART_BASE | 0x04)	/* High-byte divisor latch */
#define	COMIID0		(UART_BASE | 0x08)	/* Interrupt identification */
#define	COMCON0		(UART_BASE | 0x0C)	/* Line control */
#define	COMSTA0		(UART_BASE | 0x14)	/* Line status */
#define	COMSCR		(UART_BASE | 0x1C)	/* Scratch register */


/* COMIEN0 bits */
#define	COMIEN0_EDSSI	0x08	/* Modem status interrupt-enable */
#define	COMIEN0_ELSI	0x04	/* RX status interrupt-enable */
#define	COMIEN0_ETBEI	0x02	/* Enable Transmit buffer empty interrupt */
#define	COMIEN0_ERBFI	0x01	/* Enable Receive buffer full interrupt */

/* COMIID0 bits */
#define	COMIID0_NOINT	0x01	/* No Interrutp */
#define	COMIID0_RXLINT	0x06	/* Recieve line status Interrupt */
#define	COMIID0_RXFINT	0x06	/* Recieve buffer full Interrupt */
#define	COMIID0_TXEINT	0x02	/* Transmit buffer empty Interrupt */
#define	COMIID0_MODINT	0x00	/* Modem status Interrupt */

/* COMCON0 bits */
#define	COMCON0_DLAB	0x80	/* Set: Enable access COMDIV0 and COMDIV1 */
								/* Clear: Enable access COMRX and COMTX */
#define	COMCON0_BRK		0x40	/* Force SOUT to 0 */
#define	COMCON0_SP		0x20	/* Stick Parity (?) */
#define	COMCON0_EPS		0x10	/* Even Parity Select bit */
#define	COMCON0_PEN		0x08	/* Parity Enable bit */
#define	COMCON0_STOP	0x04	/* Stop bit */

#define COMCON0_WLS_8b	0x03	/* Word length is 8 bits */
#define COMCON0_WLS_7b	0x02	/* Word length is 7 bits */
#define COMCON0_WLS_6b	0x01	/* Word length is 6 bits */
#define COMCON0_WLS_5b	0x00	/* Word length is 5 bits */

/* COMSTA0 bits */
#define COMSTA0_TEMT	0x40	/* COMTX empty */
#define COMSTA0_THRE	0x20	/* COMTX and COMRX empty */
#define COMSTA0_BI		0x10	/* Break error */
#define COMSTA0_FE		0x08	/* Framing error */
#define COMSTA0_PE		0x04	/* parity error */
#define COMSTA0_OE		0x02	/* Overrun error */
#define COMSTA0_DR		0x01	/* Data ready (COMRX is full) */

/* COMDIVx bits : Baud Rate = 9600 */
#define COMDIV0_BR9600	0x88		/* Low byte */
#define COMDIV1_BR9600	0x00		/* High byte */

/*
 * SRAM
 */
#define VCT_TB_SRAM	0x10000
#define VCT_TB		0x00000


#ifndef _MACRO_ONLY

/*
 * ����UART�p �Ȉ�SIO�h���C�o
 */
/*
 * �J�[�l���N�����p�̏�����(sys_putc���g�p���邽��)
 */
extern void init_uart(void);


/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
typedef struct sio_port_initialization_block 
{
    VP uart_data;
	VP divisor_lo;
	VP divisor_hi;
    VP int_enable;
    VP int_identifier;
    VP line_control;
    VP line_status;
	VW irq_bit;
}
SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
typedef struct sio_port_control_block 
{
    const SIOPINIB  *siopinib;  /* �V���A��I/O�|�[�g�������u���b�N */
    VP_INT          exinf;      /* �g����� */
    BOOL    openflag;       /* �I�[�v���ς݃t���O */
    BOOL    sendflag;       /* ���M�����݃C�l�[�u���t���O */
    BOOL    getready;       /* ��������M������� */
    BOOL    putready;       /* �����𑗐M�ł����� */

}SIOPCB;


/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND    1u      /* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV    2u      /* ��M�ʒm�R�[���o�b�N */

/*
 *  �I���`�b�v��UART����̃|�[�����O�o��
 */
extern void uart_putc(char c);

/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void uart_initialize(void);

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
extern BOOL uart_openflag(void);

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB   *uart_opn_por(ID siopid, VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void uart_cls_por(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL uart_snd_chr(SIOPCB *siopcb, char c);

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT  uart_rcv_chr(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void uart_in_isr(void);
extern void uart_out_isr(void);

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void uart_ierdy_snd(VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void uart_ierdy_rcv(VP_INT exinf);



#endif /* _MACRO_ONLY */
#endif /* _FRK_ADUC_H_ */
