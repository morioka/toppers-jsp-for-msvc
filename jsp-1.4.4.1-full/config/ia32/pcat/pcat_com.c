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

#include <s_services.h>
#include <pcat_com.h>

#define PCAT_COM_IIR_RLS (0x06)
#define PCAT_COM_IIR_RXD (0x04)
#define PCAT_COM_IIR_TXD (0x02)

#define PCAT_COM_IER_LS (4)
#define PCAT_COM_IER_TX (2)
#define PCAT_COM_IER_RX (1)

#define PCAT_COM_RBR 0
#define PCAT_COM_THR 0
#define PCAT_COM_DLL 0
#define PCAT_COM_IER 1
#define PCAT_COM_DLM 1
#define PCAT_COM_IIR 2
#define PCAT_COM_FCR 2
#define PCAT_COM_LCR 3
#define PCAT_COM_MCR 4
#define PCAT_COM_LSR 5
#define PCAT_COM_MSR 6
#define PCAT_COM_SCR 7

#define PCAT_COM_DIVISOR_LATCH(a) (24000000 / 13 / 16 / (a))

#ifndef PCAT_COM1_BAUD_RATE
#define PCAT_COM1_BAUD_RATE 9600
#endif
#if TNUM_SIOP >= 2
#ifndef PCAT_COM2_BAUD_RATE
#define PCAT_COM2_BAUD_RATE 9600
#endif
#endif

/*
 *  �჌�x���|�[�g���Ǘ��u���b�N�̏����l
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{
		PCAT_COM1_BASE,
		TO_INTNO(PCAT_COM1_INHNO),
		PCAT_COM_DIVISOR_LATCH(PCAT_COM1_BAUD_RATE)
	},
#if TNUM_SIOP >= 2
	{
		PCAT_COM2_BASE,
		TO_INTNO(PCAT_COM2_INHNO),
		PCAT_COM_DIVISOR_LATCH(PCAT_COM2_BAUD_RATE)
	},
#endif
};
SIOPCB siopcb_table[TNUM_SIOP];

Inline UB pcat_com_read(UH base, UH offset) {
	return sil_reb_iop((VP)(base + offset));
}

Inline void pcat_com_write(UH base, UH offset, UB data) {
	sil_wrb_iop((VP)(base + offset), data);
}

/*
 *  ��������M�������H
 */
Inline BOOL
hw_port_getready(SIOPCB *p)
{
  UB stat;
  stat = pcat_com_read(p->siopinib->base_address, PCAT_COM_LSR);

  return ((stat & 0x01) != 0);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
hw_port_putready(SIOPCB *p)
{
  UB stat;
  stat = pcat_com_read(p->siopinib->base_address, PCAT_COM_LSR);

  return ((stat & 0x20) != 0);
}

SIOPCB *
pcat_com_set_mode(ID portid) {
  SIOPCB *p;

  p = &(siopcb_table[portid - 1]);
	if (p->initflag) {
		return p;
	}
  pcat_com_write(p->siopinib->base_address, PCAT_COM_IER, 0); // Disable interrupt.
  pcat_com_write(p->siopinib->base_address, PCAT_COM_LCR, 0x83); // DLAB=1, 8bit, stop=1, Non parity.
  pcat_com_write(p->siopinib->base_address, PCAT_COM_DLL, (UB)p->siopinib->divisor_latch);
  pcat_com_write(p->siopinib->base_address, PCAT_COM_DLM, (UB)(p->siopinib->divisor_latch >> 8));
  pcat_com_write(p->siopinib->base_address, PCAT_COM_LCR, 0x03); // DLAB=0, 8bit, stop=1, Non parity.
  pcat_com_write(p->siopinib->base_address, PCAT_COM_FCR, 0x07);  // Enable FIFO.


  pcat_com_read(p->siopinib->base_address, PCAT_COM_LSR);
  pcat_com_read(p->siopinib->base_address, PCAT_COM_RBR);
  pcat_com_read(p->siopinib->base_address, PCAT_COM_IIR);
  pcat_com_read(p->siopinib->base_address, PCAT_COM_MCR);

  p->initflag = TRUE;			/* �������t���O�ݒ� */

  return p;
}

void pcat_com_isr(VP_INT exinf) {
	SIOPCB *p = (SIOPCB *)exinf;
	while (1) {
		switch (pcat_com_read(p->siopinib->base_address, PCAT_COM_IIR) & 7) {
		case PCAT_COM_IIR_TXD:
			pcat_com_ierdy_snd(p->spcb);
			break;
		case PCAT_COM_IIR_RXD:
			pcat_com_ierdy_rcv(p->spcb);
			break;
		case PCAT_COM_IIR_RLS:
			pcat_com_read(p->siopinib->base_address, PCAT_COM_LSR);
			break;
		default:
			return;
		}
	}
}

void
pcat_com_initialize()
{
	UINT i;
	for (i = 0; i < TNUM_SIOP; ++i) {
		siopcb_table[i].siopinib = &siopinib_table[i];
	}
}

/*
 *  �V���A��I/O�|�[�g�̊����݃n���h��
 */
void
pcat_com1_handler()
{
	pcat_com_isr(&siopcb_table[0]);
}
#if TNUM_PORT >= 2
void
pcat_com2_handler()
{
	pcat_com_isr(&siopcb_table[1]);
}
#endif

SIOPCB *
pcat_com_opn_por(ID portid, VP_INT spcb)
{
  SIOPCB *p;

  p = pcat_com_set_mode(portid);
  p->spcb = spcb;

  pcat_com_write(p->siopinib->base_address, PCAT_COM_MCR, 0x0b); // Enable OUT2 interrupt.

  return p;
}

/*
 *  �V���A��I/O�|�[�g�̏I��
 */
void
pcat_com_cls_por(SIOPCB *p)
{
    
  p->initflag = FALSE;
  pcat_com_write(p->siopinib->base_address, PCAT_COM_IER, 0); // Disable interrupt.
}

/*
 *  ��M���������̎��o��
 */
INT
pcat_com_rcv_chr(SIOPCB *p)
{
  UB ch;
  
	if (!hw_port_getready(p)) {
		return -1;
	}
  ch = pcat_com_read(p->siopinib->base_address, PCAT_COM_RBR);
  return (INT)ch;
}

/*
 *  ���M���镶���̏�������
 */
BOOL
pcat_com_snd_chr(SIOPCB *p, char c)
{
  if (!hw_port_putready(p)) {
    return FALSE;
  }
  pcat_com_write(p->siopinib->base_address, PCAT_COM_THR, c);
  return TRUE;
}

void
pcat_com_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB ier = pcat_com_read(siopcb->siopinib->base_address, PCAT_COM_IER);
	if (cbrtn == SIO_ERDY_SND) {
		ier |= PCAT_COM_IER_TX;
	} else if (cbrtn == SIO_ERDY_RCV) {
		ier |= PCAT_COM_IER_LS | PCAT_COM_IER_RX;
	}
	pcat_com_write(siopcb->siopinib->base_address, PCAT_COM_IER, ier);
}

void
pcat_com_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB ier = pcat_com_read(siopcb->siopinib->base_address, PCAT_COM_IER);
	if (cbrtn == SIO_ERDY_SND) {
		ier &= ~PCAT_COM_IER_TX;
	} else if (cbrtn == SIO_ERDY_RCV) {
		ier &= ~(PCAT_COM_IER_LS | PCAT_COM_IER_RX);
	}
	pcat_com_write(siopcb->siopinib->base_address, PCAT_COM_IER, ier);
}

void pcat_com_init(ID siopid) {
	pcat_com_initialize();
	pcat_com_set_mode(siopid);
}

void pcat_com_putc(ID siopid, char c) {
	SIOPCB *p;
	p = &siopcb_table[siopid - 1];
	while (!pcat_com_snd_chr(p, c)) {
	}
}
