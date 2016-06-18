/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
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
 *  @(#) $Id: sh7615frt.h,v 1.5 2005/07/06 00:45:07 honda Exp $
 */

/*
 *	�^�C�}�h���C�o
 *  FRT���g�p
 */

#ifndef _MCFPIT_H_
#define _MCFPIT_H_

/*
 *   �^�C�}�ւ̓��̓N���b�N�̕�����ݒ�
 *   	f/8�ŃJ�E���g
 */
#define TCR_CKS         0x0

/*
 *   �^�C�}�ɋ��������N���b�N���g��[kHz]
 *      60MHz/2 = 30MHz
 */
#define	TIMER_CLOCK		(25000)

/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UH CLOCK;

/*
 *  �^�C�}�l�̓����\���ƃ~���b�E�ʕb�P�ʂƂ̕ϊ�
 *
 */
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)
#define CLOCK_PER_TICK	((CLOCK) TO_CLOCK(TIC_NUME, TIC_DENO))

/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */
#define	MAX_CLOCK	((CLOCK) 0xffff)

/*
 *  �^�C�}�̌��ݒl�������ݔ����O�̒l�Ƃ݂Ȃ����̔��f
 */
#define	GET_TOLERANCE	100		/* �����x��̌��ς�l�i�P�ʂ͓����\���j */
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  ���W�X�^�̐ݒ�l
 */
#define MCF_PIT_PCSR_EN   (0x0001u)
#define MCF_PIT_PCSR_RLD  (0x0002u)
#define MCF_PIT_PCSR_PIF  (0x0004u)
#define MCF_PIT_PCSR_PIE  (0x0008u)
#define MCF_PIT_PCSR_OVW  (0x0010u)
#define MCF_PIT_PCSR_DBG  (0x0020u)
#define MCF_PIT_PCSR_DOZE (0x0040u)

/*
 *  �R���g���[�����W�X�^�̃A�h���X
 */
#define MCF_PIT0_PCSR   (VH*)(IPSBAR + 0x00150000)
#define MCF_PIT0_PMR    (VH*)(IPSBAR + 0x00150002)
#define MCF_PIT0_PCNTR  (VH*)(IPSBAR + 0x00150004)


#ifndef _MACRO_ONLY

/*
 *  �^�C�}�X�^�[�g
 */
Inline void
mcf_timer_start ()
{
     sil_wrh_mem (MCF_PIT0_PCSR, sil_reh_mem (MCF_PIT0_PCSR) | MCF_PIT_PCSR_EN);
}

/*
 *  �^�C�}�ꎞ��~
 */
Inline void
mcf_timer_stop ()
{
    	/* �^�C�}���~ 	  */
	sil_wrh_mem (MCF_PIT0_PCSR, sil_reh_mem (MCF_PIT0_PCSR) & ~MCF_PIT_PCSR_EN);
}
/*
 *  �^�C�}�����ݗv���̃N���A
 *	TCR���W�X�^��IMFA�r�b�g��1��ǂݏo������ɂO����������
 */
Inline void
mcf_timer_int_clear ()
{
	/* ���荞�ݗv�����N���A     */
	sil_wrh_mem (MCF_PIT0_PCSR, sil_reh_mem (MCF_PIT0_PCSR));
}


/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
mcf_timer_initialize ()
{
	CLOCK cyc = TO_CLOCK (TIC_NUME, TIC_DENO);

	/*
	 *  �^�C�}�֘A�̐ݒ�
	 */
	mcf_timer_stop ();			/* �^�C�}��~ */
	/* �^�C�}����l�̃`�F�b�N */
	assert (cyc <= MAX_CLOCK);
       /*
         *  �^�C�}�����݂̊����݃��x����ݒ肵�C�v�����N���A������C
         *  �}�X�N����������D
         */
        sil_wrh_mem (MCF_PIT0_PCSR, (VH)(MCF_PIT_PCSR_OVW | MCF_PIT_PCSR_PIF | MCF_PIT_PCSR_RLD));
        sil_wrh_mem (MCF_PIT0_PMR, (VH)CLOCK_PER_TICK);
        sil_wrh_mem (MCF_PIT0_PCNTR,0x0000);
        sil_wrh_mem (MCF_PIT0_PCSR, sil_reh_mem(MCF_PIT0_PCSR) | MCF_PIT_PCSR_PIE);	//���荞�݋���
}

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
Inline void
mcf_timer_terminate ()
{
	/*
	 *  �^�C�}�̓�����~����D
	 */
	mcf_timer_stop();
        mcf_timer_int_clear ();
	/*
	 *  �^�C�}�����݂��}�X�N���C�v�����N���A����D
	 */
	sil_wrh_mem (MCF_PIT0_PCSR, sil_reh_mem(MCF_PIT0_PCSR) & ~MCF_PIT_PCSR_PIE);	//���荞�ݕs����
	sil_wrh_mem (MCF_PIT0_PCNTR,0x0000);
	sil_wrh_mem (MCF_PIT0_PMR,0x0000); 
        sil_wrw_mem (MCF_INTC_IMRH(MCF_INTC0), sil_rew_mem(MCF_INTC_IMRH(MCF_INTC0)) | (1 << (TBIT_TT0)));
}

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 */
Inline CLOCK
mcf_timer_get_current ()
{
	CLOCK	clk;
        
	clk = TO_CLOCK(TIC_NUME, TIC_DENO) - sil_reh_mem(MCF_PIT0_PCNTR);
	return (clk);
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline BOOL
mcf_timer_fetch_interrupt ()
{
        return (sil_reh_mem (MCF_PIT0_PCSR) & MCF_PIT_PCSR_PIF);
}

#endif /* _MACRO_ONLY */
#endif /* _MCFPIT_H_ */
