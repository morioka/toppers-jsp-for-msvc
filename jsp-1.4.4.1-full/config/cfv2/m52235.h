/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2007 by KURUSUGAWA Electronics Industry Inc, JAPAN
 *  Copyright (C) 2008 by Takahisa Yokota
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
 *  @(#) $Id: m52235.h,v 1.8 2003/06/18 12:40:08 hiro Exp $
 */

/*
 *	M52235 CPU�{�[�h�̃n�[�h�E�F�A�����̒�`
 */

#ifndef _M52235_H_
#define _M52235_H_

#include <sil.h>

#define	MCF_UART0    77
#define	MCF_UART1    78
#define	MCF_UART2    79
#define MCF_PIT0     119

#define TBIT_GP0     (13)
#define TBIT_GP1     (14)

#define TBIT_GP2     (15)

#define TBIT_TT0     (55 - 32)
#define TBIT_TT1     (56 - 32)

#define REF_CLK_MHZ         (25)
#define SYS_CLK_MHZ         (60)
#define REF_CLK_KHZ         (REF_CLK_MHZ * 1000)
#define SYS_CLK_KHZ         (SYS_CLK_MHZ * 1000)
#define SYSTEM_CLOCK        SYS_CLK_MHZ

#define IPSBAR       (0x40000000)

#define MCF_SCM_RAMBAR            (IPSBAR + 0x000008)
#define MCF_SCM_RAMBAR_BDE        (0x00000200)
#define MCF_SCM_RAMBAR_BA(x)      ((x)&0xFFFF0000)

#define MCF_CLK_SYNCR  (IPSBAR + 0x00120000)
#define MCF_CLK_SYNSR  (IPSBAR + 0x00120002)

#define MCF_CLK_SYNCR_PLLEN     (0x0001)
#define MCF_CLK_SYNCR_PLLMODE   (0x0002)
#define MCF_CLK_SYNCR_CLKSRC    (0x0004)
#define MCF_CLK_SYNCR_FWKUP     (0x0020)
#define MCF_CLK_SYNCR_DISCLK    (0x0040)
#define MCF_CLK_SYNCR_LOCEN     (0x0080)
#define MCF_CLK_SYNCR_RFD(x)    (((x)&0x0007)<<8)
#define MCF_CLK_SYNCR_LOCRE     (0x0800)
#define MCF_CLK_SYNCR_MFD(x)    (((x)&0x0007)<<12)
#define MCF_CLK_SYNCR_LOLRE     (0x8000)

#define MCF_CLK_SYNSR_LOCS      (0x04)
#define MCF_CLK_SYNSR_LOCK      (0x08)
#define MCF_CLK_SYNSR_LOCKS     (0x10)
#define MCF_CLK_SYNSR_CRYOSC    (0x20)
#define MCF_CLK_SYNSR_OCOSC     (0x40)
#define MCF_CLK_SYNSR_EXTOSC    (0x80)

#define MCF_CLK_LPCR_LPD(x)     (((x)&0x0F)<<0)

#define MCF_CLK_CCHR_PFD(x)     (((x)&0x07)<<0)

#define MCF_CLK_RTCDR_RTCDF(x)  (((x)&0xFFFFFFFF)<<0)

/* 
 * PLL min/max specifications
 */
#define MAX_FVCO    60000   /* KHz */
#define MAX_FSYS    60000   /* KHz */
#define MAX_FREF    48000   /* KHz */
#define MIN_FREF    1000    /* KHz */
#define MAX_MFD     18      /* Multiplier (not encoded) */
#define MIN_MFD     4       /* Multiplier (not encoded) */
#define MAX_RFD     128     /* Divider (not encoded) */
#define MIN_RFD     1       /* Divider (not encoded) */

/*
 * Low Power Divider specifications
 */
#define MIN_LPD     (1 << 0)    /* Divider (not encoded) */
#define MAX_LPD     (1 << 15)   /* Divider (not encoded) */

#define MCF_CLK_LPCR            (IPSBAR + 0x120007)
#define MCF_CLK_CCHR            (IPSBAR + 0x120008)
#define MCF_CLK_RTCDR           (IPSBAR + 0x12000C)

#define MCF_INTC0    (IPSBAR + 0x0C00)
#define MCF_INTC1    (IPSBAR + 0x0D00)

#define MCF_INTC_IMRL(ch)  (ch + 0x0c)
#define MCF_INTC_IMRH(ch)  (ch + 0x08)
#define MCF_INTC_ICR(ch, n)  (ch + 0x40 + n)

#define MCF_INTC_IMRH_ALL  (0x00000000)
#define MCF_INTC_IMRL_ALL  (0x00000001)

#define MCF_GPIO_PUAPAR     (IPSBAR + 0x100071)
#define MCF_GPIO_PUBPAR     (IPSBAR + 0x100072)
#define MCF_GPIO_PUCPAR     (IPSBAR + 0x100073)
#define MCF_GPIO_PUBPAR_TXD1_TXD1      (0x01)
#define MCF_GPIO_PUBPAR_RXD1_RXD1      (0x04)
#define MCF_GPIO_PUCPAR_TXD2_TXD2      (0x01)
#define MCF_GPIO_PUCPAR_RXD2_RXD2      (0x02)
#define MCF_GPIO_PUAPAR_TXD0_TXD0      (0x01)
#define MCF_GPIO_PUAPAR_RXD0_RXD0      (0x04)

#endif /* _M52235_H_ */
