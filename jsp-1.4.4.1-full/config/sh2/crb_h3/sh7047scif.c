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

/*
 *  SH7047�����V���A���R�~���j�P�[�V�����C���^�[�t�F�C�XSCI�p �ȈՃh���C�o
 */

#include <s_services.h>
#include "sh7047.h"
#include "sh7047scif.h"

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
static const SIOPINIB siopinib_table[TNUM_PORT] = {
	{
		(IOREG_SCI_BASE+IOREG_SCI_WINDOW*1),
		(IOREG_INTC_BASE+IOREG_IPRI_OFFSET),
		9,
		ISR_SCR3_SHIFT
	},
	{
		(IOREG_SCI_BASE+IOREG_SCI_WINDOW*2),
		(IOREG_INTC_BASE+IOREG_IPRI_OFFSET),
		8,
		ISR_SCR4_SHIFT
	}
};

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 *      ID = 1 ��SCI3�ɑΉ������Ă���.
 */
SIOPCB siopcb_table[TNUM_PORT];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  ��������M�ł��邩�H
 */
Inline BOOL
sh7047scif_getready (SIOPCB * siopcb)
{
	/* ���V�[�u�f�[�^���W�X�^�t���E�t���O�̃`�F�b�N */
	return (sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SSR_OFFSET)) & SSR_RDRF);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
sh7047scif_putready (SIOPCB * siopcb)
{
	/* �g�����X�~�b�gFIFO�f�[�^���W�X�^�G���v�e�B�E�t���O�̃`�F�b�N */
	return (sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SSR_OFFSET)) & SSR_TDRE);
}

/*
 *  ��M���������̎��o��
 */
Inline char
sh7047scif_getchar (SIOPCB * siopcb)
{
	VB data;

	data = sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_RDR_OFFSET));
	/* ���V�[�u�f�[�^���W�X�^�t���E�t���O�̃N���A */
	sil_wrb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SSR_OFFSET),
		sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SSR_OFFSET)) & ~SSR_RDRF);
	return data;
}

/*
 *  ���M���镶���̏�����
 */
Inline void
sh7047scif_putchar (SIOPCB * siopcb, char c)
{
	sil_wrb_mem((VP)(siopcb->siopinib->cntrl+IOREG_TDR_OFFSET), c);
	/* �g�����X�~�b�gFIFO�f�[�^���W�X�^�G���v�e�B�E�t���O�̃N���A */
	sil_wrb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SSR_OFFSET),
		sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SSR_OFFSET)) & ~SSR_TDRE);
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
sh7047scif_initialize ()
{
	SIOPCB *siopcb;
	UINT i;

	/*
     *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
     */
	for (siopcb = siopcb_table, i = 0; i < TNUM_PORT; siopcb++, i++) {
		siopcb->siopinib = &siopinib_table[i];
		siopcb->openflag = FALSE;
	}
}

/*
 *  �I�[�v�����Ă���|�[�g�͂��邩�H
 */
BOOL
sh7047scif_openflag (ID siopid)
{
	if(siopcb_table[INDEX_SIOP(siopid)].openflag)
		return TRUE;
	sil_dly_nse(sh2scif_DELAY*4);	/* Wait for Banner */
	return FALSE;
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
sh7047scif_opn_por (ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb;
	UW     base;
	unsigned char  dummy;

	siopcb = get_siopcb (siopid);
	base   = siopcb->siopinib->cntrl;
	/* ����M��~ */
	sil_wrb_mem((VP)(base+IOREG_SCR_OFFSET),
		 sil_reb_mem((VP)(base+IOREG_SCR_OFFSET)) & ~(SCR_TE | SCR_RE));
	/* ���[�h���W�X�^�̐ݒ� */
	sil_wrb_mem((VP)(base+IOREG_SMR_OFFSET), DEFAULT_SMR);
	/* �{�[���[�g�̐ݒ� */
	sil_wrb_mem((VP)(base+IOREG_BRR_OFFSET), DEFAULT_BRR);

	sil_dly_nse(sh2scif_DELAY);
	/* ����M�A��M�����݋��� */
	sil_wrb_mem((VP)(base+IOREG_SCR_OFFSET), SCR_RIE|SCR_TE|SCR_RE);
	dummy = sil_reb_mem((VP)(base+IOREG_SSR_OFFSET));		/* Dummy read */
	/* �����݃R���g���[���̐ݒ� */
	sil_wrb_mem((VP)(base+IOREG_SSR_OFFSET), SSR_TDRE);		/* Clear error flags */
	siopcb->exinf    = exinf;
	siopcb->openflag = TRUE;
	return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
sh7047scif_cls_por (SIOPCB * siopcb)
{
	/* ����M��~�A�����݋֎~ */
	sil_wrb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SCR_OFFSET),
			sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SCR_OFFSET)) & ~(SCR_TIE|SCR_RIE|SCR_TE|SCR_RE));

	siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
sh7047scif_snd_chr (SIOPCB * siopcb, char c)
{
	if (sh7047scif_putready (siopcb)) {
		sh7047scif_putchar (siopcb, c);
		return (TRUE);
	}
	return (FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
sh7047scif_rcv_chr (SIOPCB * siopcb)
{
	if (sh7047scif_getready (siopcb)) {
		return ((INT) (UB) sh7047scif_getchar (siopcb));
	}
	return (-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N����
 */
void
sh7047scif_ena_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	UW base = siopcb->siopinib->cntrl;

	switch (cbrtn) {
	case SIO_ERDY_SND:		/* ���M�����ݗv�������� */
		sil_wrb_mem((VP)(base+IOREG_SCR_OFFSET), sil_reb_mem((VP)(base+IOREG_SCR_OFFSET)) | SCR_TIE);
		break;
	case SIO_ERDY_RCV:		/* ��M�����ݗv�������� */
		sil_wrb_mem((VP)(base+IOREG_SCR_OFFSET), sil_reb_mem((VP)(base+IOREG_SCR_OFFSET)) | SCR_RIE);
		break;
	default:
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�֎~
 */
void
sh7047scif_dis_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	UW base = siopcb->siopinib->cntrl;

	switch (cbrtn) {
	case SIO_ERDY_SND:		/* ���M�����ݗv�����֎~ */
		sil_wrb_mem((VP)(base+IOREG_SCR_OFFSET), sil_reb_mem((VP)(base+IOREG_SCR_OFFSET)) & ~SCR_TIE);
		break;
	case SIO_ERDY_RCV:		/* ��M�����ݗv�����֎~ */
		sil_wrb_mem((VP)(base+IOREG_SCR_OFFSET), sil_reb_mem((VP)(base+IOREG_SCR_OFFSET)) & ~SCR_RIE);
		break;
	default:
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��鑗�M�����ݏ���
 */
Inline void
sh7047scif_isr_siop_out (SIOPCB * siopcb)
{
	VB scr0 = sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SCR_OFFSET));

	if ((scr0 & SCR_TIE) != 0 && sh7047scif_putready (siopcb)) {
		/*
		 *  ���M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sh7047scif_ierdy_snd (siopcb->exinf);
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂����M�����ݏ���
 */
Inline void
sh7047scif_isr_siop_in (SIOPCB * siopcb)
{
	VB scr0 = sil_reb_mem((VP)(siopcb->siopinib->cntrl+IOREG_SCR_OFFSET));

	if ((scr0 & SCR_RIE) != 0 && sh7047scif_getready (siopcb)) {
		/*
		 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sh7047scif_ierdy_rcv (siopcb->exinf);
	}
}

/*
 *  SIO���M�����݃T�[�r�X���[�`��(SCI3�p)
 */
void
sh7047scif3_isr_out ()
{
	if (siopcb_table[0].openflag) {
		sh7047scif_isr_siop_out (&(siopcb_table[0]));
	}
}

/*
 *  SIO���M�����݃T�[�r�X���[�`��(SCI4�p)
 */
void
sh7047scif4_isr_out ()
{
	if (siopcb_table[1].openflag) {
		sh7047scif_isr_siop_out (&(siopcb_table[1]));
	}
}

/*
 *  SIO��M�����݃T�[�r�X���[�`��(SCI3�p)
 */
void
sh7047scif3_isr_in ()
{
	if (siopcb_table[0].openflag) {
		sh7047scif_isr_siop_in (&(siopcb_table[0]));
	}
}

/*
 *  SIO��M�����݃T�[�r�X���[�`��(SCI4�p)
 */
void
sh7047scif4_isr_in ()
{
	if (siopcb_table[1].openflag) {
		sh7047scif_isr_siop_in (&(siopcb_table[1]));
	}
}

/*
 *  SIO��M�G���[�����݃T�[�r�X���[�`��(SCI3�p)
 */
void
sh7047scif3_isr_error (void)
{
	UW base = siopcb_table[0].siopinib->cntrl;

	if (siopcb_table[0].openflag) {
		sil_wrb_mem((VP)(base+IOREG_SSR_OFFSET), sil_reb_mem((VP)(base+IOREG_SSR_OFFSET)) & ~(SSR_OPER|SSR_FER|SSR_PER));
	}
}

/*
 *  SIO��M�G���[�����݃T�[�r�X���[�`��(SCI4�p)
 */
void
sh7047scif4_isr_error (void)
{
	UW base = siopcb_table[1].siopinib->cntrl;

	if (siopcb_table[1].openflag) {
		sil_wrb_mem((VP)(base+IOREG_SSR_OFFSET), sil_reb_mem((VP)(base+IOREG_SSR_OFFSET)) & ~(SSR_OPER|SSR_FER|SSR_PER));
	}
}


