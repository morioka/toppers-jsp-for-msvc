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
 *  @(#) $Id: sys_config.c,v 1.7 2003/07/08 14:57:15 hiro Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iMCF52235EVB�p�j
 */

#include "jsp_kernel.h"
#include <sil.h>
#include "mcfuart.h"

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
void
sys_initialize()
{
    SIOPCB *siopcb;

    sil_wrb_mem (MCF_GPIO_PUAPAR, (MCF_GPIO_PUAPAR_RXD0_RXD0|MCF_GPIO_PUAPAR_TXD0_TXD0));
    sil_wrb_mem (MCF_GPIO_PUBPAR, (MCF_GPIO_PUBPAR_RXD1_RXD1|MCF_GPIO_PUBPAR_TXD1_TXD1));
    mcfuart_initialize ();
    siopcb = mcfuart_opn_por (LOGTASK_PORTID, 0);
}

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 */
void
sys_exit()
{
	cfv2_exit();
}

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */
void
sys_putc(char c)
{
	if (c == '\n') {
		cfv2_putc(LOGTASK_PORTID, '\r');
	}
	cfv2_putc(LOGTASK_PORTID, c);
}

/* �n�[�h�E�F�A�̐ݒ� */
#ifndef GDB_STUB


static void init_clock_config (void)
{
    sil_wrb_mem ((VP)MCF_CLK_CCHR,  (UB)MCF_CLK_CCHR_PFD(0x4));
    
    sil_wrh_mem ((VP)MCF_CLK_SYNCR,  (UH)0x4103);
    while (!(sil_reb_mem((VP)MCF_CLK_SYNSR) & 0x08));
    
    sil_wrh_mem ((VP)MCF_CLK_SYNCR,  (UH)0x4003);
    
    while (!(sil_reb_mem((VP)MCF_CLK_SYNSR) & 0x08));
    
    sil_wrh_mem ((VP)MCF_CLK_SYNCR,  (UH)0x4007);
}

void
hardware_init_hook (void)
{
  init_clock_config ();
  sil_wrw_mem ((VP) MCF_INTC_IMRH(MCF_INTC0), ~MCF_INTC_IMRH_ALL);
  sil_wrw_mem ((VP) MCF_INTC_IMRL(MCF_INTC0), ~MCF_INTC_IMRL_ALL);
  sil_wrw_mem ((VP) MCF_INTC_IMRH(MCF_INTC1), ~MCF_INTC_IMRH_ALL);
  sil_wrw_mem ((VP) MCF_INTC_IMRL(MCF_INTC1), ~MCF_INTC_IMRL_ALL);
  sil_wrw_mem ((VP) MCF_SCM_RAMBAR, (MCF_SCM_RAMBAR_BA(0x20000000) | MCF_SCM_RAMBAR_BDE));  
  return;
}
#else
void
hardware_init_hook (void)
{
}
#endif
