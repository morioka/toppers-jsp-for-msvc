/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
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


#include "jsp_kernel.h"
#include "sh7047.h"
#include <sil.h>

void hardware_init_hook(void)
{
	unsigned long *p = (unsigned long *)SRAM_START;

	/* initial Module Standby register */
	sil_wrh_mem((VP)(IOREG_MST_BASE+IOREG_CR1_OFFSET), 0xf023);	/* sci4,sci3,sci2	*/
	sil_wrh_mem((VP)(IOREG_MST_BASE+IOREG_CR2_OFFSET), 0xe0f0);	/* cmt */

	/* initial base state */
	sil_wrh_mem((VP)(IOREG_BSC_BASE+IOREG_BCR1_OFFSET), 0x600e);/* CS0:8bit */
	sil_wrh_mem((VP)(IOREG_BSC_BASE+IOREG_BCR2_OFFSET), 0xffff);/* CS0:idle cycle 3*/
	sil_wrh_mem((VP)(IOREG_BSC_BASE+IOREG_WCR1_OFFSET), 0xfff2);/* CS0 2Wait */

	/* �h�n�|�[�g�ݒ� */
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PACRL1_OFFSET), 0x1115);	/*	0001 0001 0001 0101	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PACRL2_OFFSET), 0x4000);	/*	0100 0000 0000 0000	*/	/*	PA6	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PACRL3_OFFSET), 0x03bf);	/*	0000 0011 1011 1111	*/	/*	PA6	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PAIORL_OFFSET), 0x5ebf);	/*	0101 1110 1011 1111	*/

	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PBCR1_OFFSET), 0x2c00);	/*	0010 1100 0000 0000	*/	/*	TXD4,RXD4	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PBCR2_OFFSET), 0x04f5);	/*	0000 0100 1111 0101	*/	/*	TXD4,RXD4	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PBIOR_OFFSET), 0x0023);	/*	0000 0000 0010 0011	*/	/*	TXD4,RXD4	*/

	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PDCRL1_OFFSET), 0x00ff);	/*	0000 0000 1111 1111	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PDCRL2_OFFSET), 0x0000);	/*	0000 0000 0000 0000	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PDIORL_OFFSET), 0x0000);	/*	0000 0000 0000 0000	*/

	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PECRH_OFFSET), 0x0fff);	/*	0000 1111 1111 1111	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PECRL1_OFFSET), 0x0000);	/*	0000 0000 0000 0000	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PECRL2_OFFSET), 0xff00);	/*	1111 1111 0000 0000	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PEIORH_OFFSET), 0x003f);	/*	0000 0000 0011 1111	*/
	sil_wrh_mem((VP)(IOREG_PFC_BASE+IOREG_PEIORL_OFFSET), 0x00f0);	/*	0000 0000 1111 0000	*/

	/* SRAM clear */
	while(p < (unsigned long *)SRAM_END){
		*p++ = 0L;
	}
}

/*
 * ���荞�݃R���g���[���̏�����
 */
void sh2_init_intcontorller (void)
{
	sil_wrh_mem((VP)(IOREG_INTC_BASE+IOREG_IPRA_OFFSET), 0x0000);
	sil_wrh_mem((VP)(IOREG_INTC_BASE+IOREG_IPRD_OFFSET), 0x0000);
	sil_wrh_mem((VP)(IOREG_INTC_BASE+IOREG_IPRE_OFFSET), 0x0000);
	sil_wrh_mem((VP)(IOREG_INTC_BASE+IOREG_IPRF_OFFSET), 0x0000);
	sil_wrh_mem((VP)(IOREG_INTC_BASE+IOREG_IPRG_OFFSET), 0x0000);
	sil_wrh_mem((VP)(IOREG_INTC_BASE+IOREG_IPRH_OFFSET), 0x0000);
}

