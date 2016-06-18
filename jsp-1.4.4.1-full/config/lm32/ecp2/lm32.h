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
 *  @(#) $Id: lm32.h,v 1.14 2007/07/27 11:28:44 honda Exp $
 */

#ifndef _LM32_H_
#define _LM32_H_

#define MICO32_CPU_CLOCK_HZ     (25000000)
//#define MICO32_CPU_CLOCK_HZ   (100000000)

#define DEFAULT_UART_BAUDRATE  (115200)

#define TIMER_BASE_REG          (0x80000100)
#define UART1_BASE_REG          (0x80000180)

/*
 * Timer Registers
 */
#define TIMER_STATUS            (TIMER_BASE_REG)
#define TIMER_CONTROL           (TIMER_BASE_REG + 0x04)
#define TIMER_PERIOD            (TIMER_BASE_REG + 0x08)
#define TIMER_SNAPSHOT          (TIMER_BASE_REG + 0x0C)

#define TIMER_STATUS_TO         (0x01)
#define TIMER_CONTROL_ITO       (0x01)
#define TIMER_CONTROL_CONT      (0x02)
#define TIMER_CONTROL_START     (0x04)
#define TIMER_CONTROL_STOP      (0x08)

/*
 * UART0 Registers
 */
#define UART1_RX_TX    (UART1_BASE_REG)
#define UART1_IER      (UART1_BASE_REG + 0x04)
#define UART1_IIR      (UART1_BASE_REG + 0x08)
#define UART1_LCR      (UART1_BASE_REG + 0x0C)
#define UART1_MCR      (UART1_BASE_REG + 0x10)
#define UART1_LSR      (UART1_BASE_REG + 0x14)
#define UART1_MSR      (UART1_BASE_REG + 0x18)
#define UART1_DIV      (UART1_BASE_REG + 0x1C)

/*
 * UART1 Registers
 */
#define UART2_RX_TX    (UART2_BASE_REG)
#define UART2_IER      (UART2_BASE_REG + 0x04)
#define UART2_IIR      (UART2_BASE_REG + 0x08)
#define UART2_LCR      (UART2_BASE_REG + 0x0C)
#define UART2_MCR      (UART2_BASE_REG + 0x10)
#define UART2_LSR      (UART2_BASE_REG + 0x14)
#define UART2_MSR      (UART2_BASE_REG + 0x18)
#define UART2_DIV      (UART2_BASE_REG + 0x1C)

#define UART_IER_RX_INT_MASK    (0x01)
#define UART_IER_TX_INT_MASK    (0x02)
#define UART_LSR_RX_RDY_MASK    (0x01)
#define UART_LSR_TX_RDY_MASK    (0x20)
#define UART_IIR_RXRDY          (0x04)
#define UART_IIR_TXRDY          (0x02)

#define MAX_INT_NUM     32

#define INHNO_TIMER     0
#define INHNO_SIO1		1

#define TNUM_PORT   1
#define TNUM_SIOP   1

#ifndef _MACRO_ONLY

extern void uart1_isr(void);
extern void uart2_isr(void);

typedef struct sio_port_initialization_block 
{
    volatile VP rxtx;
    volatile VP ier;
    volatile VP iir;
    volatile VP lcr;
    volatile VP mcr;
    volatile VP lsr;
    volatile VP msr;
    volatile VP div;
}
SIOPINIB;

typedef struct sio_port_control_block 
{
    const SIOPINIB  *siopinib;
    VP_INT          exinf;
    BOOL            openflag;
    BOOL            sendflag;
    BOOL            getready;
    BOOL            putready;
    UW              ier_snapshot;
}SIOPCB;

#define SIO_ERDY_SND    1u
#define SIO_ERDY_RCV    2u

extern void      uart_putc(char c);
extern void      uart_initialize(void);
extern BOOL      uart_openflag(void);
extern SIOPCB   *uart_opn_por(ID siopid, VP_INT exinf);
extern void      uart_cls_por(SIOPCB *siopcb);
extern BOOL      uart_snd_chr(SIOPCB *siopcb, char c);
extern INT       uart_rcv_chr(SIOPCB *siopcb);
extern void      uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn);
extern void      uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn);
extern void      uart_in_isr(void);
extern void      uart_out_isr(void);
extern void      uart_ierdy_snd(VP_INT exinf);
extern void      uart_ierdy_rcv(VP_INT exinf);

#endif /* _MACRO_ONLY */
#endif /* _LM32_H_ */
