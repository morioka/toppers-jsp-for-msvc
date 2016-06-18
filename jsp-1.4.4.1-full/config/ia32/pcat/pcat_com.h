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
 *  @(#) $Id$
 */

/*
 *	COM�h���C�o�iPC/AT�p�j
 */

#ifndef _PCAT_COM_H_
#define _PCAT_COM_H_

#include <s_services.h>

#define SIO_ERDY_RCV (1u)
#define SIO_ERDY_SND (2u)

#ifndef _MACRO_ONLY

/*
 *  �V���A���|�[�g�̃n�[�h�E�F�A�ˑ����̒�`
 */
typedef struct {
  short base_address;
  short com_irq;
	UH divisor_latch;
} SIOPINIB;
typedef struct pcat_hardware_serial_port_descripter {
	const SIOPINIB *siopinib;
  INT	    initflag;	   /* �������σt���O�ւ̃|�C���^   */
  VP_INT spcb;
} SIOPCB;

/*
 *  �V���A��I/O�|�[�g�̏�����
 */
extern void pcat_com_initialize();

extern void pcat_com1_handler();
#if TNUM_PORT >= 2
extern void pcat_com2_handler();
#endif

extern SIOPCB *pcat_com_opn_por(ID portid, VP_INT spcb);

/*
 *  �V���A��I/O�|�[�g�̏I��
 */
extern void pcat_com_cls_por(SIOPCB *p);

extern void pcat_com_ierdy_rcv(VP_INT exinf);

extern void pcat_com_ierdy_snd(VP_INT exinf);

/*
 *  ��M���������̎��o��
 */
extern INT pcat_com_rcv_chr(SIOPCB *p);

/*
 *  ���M���镶���̏�������
 */
extern BOOL pcat_com_snd_chr(SIOPCB *p, char c);

extern void pcat_com_ena_cbr(SIOPCB *siopcb, UINT cbrtn);

extern void pcat_com_dis_cbr(SIOPCB *siopcb, UINT cbrtn);

extern void pcat_com_init(ID siopid);

extern void pcat_com_putc(ID siopid, char c);

#endif /* _MACRO_ONLY */

#endif /* _PCAT_COM_H_ */
