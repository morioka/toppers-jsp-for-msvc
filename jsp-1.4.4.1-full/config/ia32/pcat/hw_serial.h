/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2002 by Monami software, Limited Partners.
 *  Copyright (C) 2002 by MURANAKA Masaki
 *  Copyright (C) 2008-     by Monami Software Limited Partnership, JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
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
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: hw_serial.h,v 1.1 2004/07/21 02:49:36 monaka Exp $
 */

/*
 *	�^�[�Q�b�g�ˑ��V���A��I/O���W���[���iPC/AT�p�j
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>
#include <irc.h>
#include <pcat_com.h>

/*
 *  �V���A��I/O�̊����݃n���h���̃x�N�^�ԍ�
 */
#define INHNO_SIO1	 PCAT_COM1_INHNO
#if TNUM_PORT >= 2
#define INHNO_SIO2	 PCAT_COM2_INHNO
#endif

#ifndef _MACRO_ONLY

/*
 *  �V���A��I/O�|�[�g�̏�����
 */
#define sio_initialize pcat_com_initialize

#define sio1_handler pcat_com1_handler
#if TNUM_PORT >= 2
#define sio2_handler pcat_com2_handler
#endif

Inline SIOPCB *
sio_opn_por(ID portid, VP_INT spcb)
{
  SIOPCB *p;

  p = pcat_com_opn_por(portid, spcb);

  irc_ena_irq(p->siopinib->com_irq);

  return p;
}

/*
 *  �V���A��I/O�|�[�g�̏I��
 */
Inline void
sio_cls_por(SIOPCB *p)
{
	pcat_com_cls_por(p);
  irc_dis_irq(p->siopinib->com_irq);
}

#define sio_ierdy_rcv pcat_com_ierdy_rcv

#define sio_ierdy_snd pcat_com_ierdy_snd

/*
 *  ��M���������̎��o��
 */
#define sio_rcv_chr pcat_com_rcv_chr

/*
 *  ���M���镶���̏�������
 */
#define sio_snd_chr pcat_com_snd_chr

#define sio_ena_cbr pcat_com_ena_cbr

#define sio_dis_cbr pcat_com_dis_cbr

#endif /* _MACRO_ONLY */

#endif /* _HW_SERIAL_H_ */
