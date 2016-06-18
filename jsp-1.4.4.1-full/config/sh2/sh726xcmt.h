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
 *  Copyright (C) 2010 by Cronus Computer Works, JAPAN
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
 *  @(#) $Id
 */

/*
 *	�^�C�}�h���C�o
 *  CMT���g�p
 */

#ifndef _SH726XCMT_H_
#define _SH726XCMT_H_

/*
 *   �^�C�}�ւ̓��̓N���b�N�̕�����ݒ�
 *   	f/8�ŃJ�E���g
 */
//#define TCR_CKS         0x0   /* sys_def.h ���ֈړ� */

/*
 *   �^�C�}�ɋ��������N���b�N���g��[kHz]
 */
#if TCR_CKS == 0
#define TIMER_CLOCK     ((PCLOCK / 1000) / 8)
#elif TCR_CKS == 1
#define TIMER_CLOCK     ((PCLOCK / 1000) / 32)
#elif TCR_CKS == 2
#define TIMER_CLOCK     ((PCLOCK / 1000) / 128)
#elif TCR_CKS == 3
#define TIMER_CLOCK     ((PCLOCK / 1000) / 512)
#endif


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
 *  �R���g���[�����W�X�^�̃A�h���X
 */
#ifndef CMSTR
#define CMSTR	(VH *)0xfffec000
#define CMCSR_0	(VH *)0xfffec002
#define CMCNT_0	(VH *)0xfffec004
#define CMCOR_0	(VH *)0xfffec006
#endif


#ifndef _MACRO_ONLY
/*
 *  �^�C�}�X�^�[�g
 */
Inline void
sh2_timer_start ()
{
	sil_wrh_mem (CMSTR, sil_reh_mem (CMSTR) | 0x0001);
}

/*
 *  �^�C�}�ꎞ��~
 */
Inline void
sh2_timer_stop ()
{
    	/* �^�C�}���~ 	  */
	sil_wrh_mem (CMSTR, sil_reh_mem (CMSTR) & ~0x0001);
}

/*
 *  �^�C�}�����ݗv���̃N���A
 *	TCR���W�X�^��IMFA�r�b�g��1��ǂݏo������ɂO����������
 */
Inline void
sh2_timer_int_clear ()
{
	/* ���荞�ݗv�����N���A     */
	sil_wrh_mem (CMCSR_0, sil_reh_mem (CMCSR_0) & ~0x0080);
				/* CMF�R���y�A�}�b�`�t���O�̃N���A */
}


/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
sh2_timer_initialize ()
{
	CLOCK cyc = TO_CLOCK (TIC_NUME, TIC_DENO);

#if defined(SH7203) || defined(SH7263)
	sil_wrb_mem (STBCR4, (sil_reb_mem(STBCR4)& ~0x04));
#endif
#if defined(SH7262) || defined(SH7264)
	sil_wrb_mem (STBCR7, (sil_reb_mem(STBCR7)& ~0x04));
#endif
	/*
	 *  �^�C�}�֘A�̐ݒ�
	 */
	sh2_timer_stop ();			/* �^�C�}��~ */
	/* �^�C�}����l�̃`�F�b�N */
	assert (cyc <= MAX_CLOCK);

	/*  ������ݒ�  clock 1/8  �A���荞�݋֎~ */
    sil_wrh_mem(CMCSR_0,0x0000);
	/*  CMCOR0���W�X�^�ݒ�i�J�E���^�ڕW�l�j      */
	sil_wrh_mem (CMCOR_0,(VH)CLOCK_PER_TICK);
	/* �J�E���^���N���A             */
	sil_wrh_mem (CMCNT_0,0x0000);
	sil_wrh_mem (CMCSR_0, sil_reh_mem(CMCSR_0) | 0x0040);	/* ���荞�݋��� */
}

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
Inline void
sh2_timer_terminate ()
{
	sh2_timer_stop ();			/* �^�C�}���~     */
	sh2_timer_int_clear ();		/* ���荞�ݗv�����N���A */

	sil_wrh_mem (CMCSR_0, sil_reh_mem(CMCSR_0) & ~0x0040);	//���荞�ݕs����
	sil_wrh_mem (CMCNT_0,0x0000);
	sil_wrh_mem (CMCOR_0,0x0000);
#if defined(SH7203) || defined(SH7263)
	sil_wrb_mem (STBCR4, (sil_reb_mem(STBCR4) | 0x04));
#endif
#if defined(SH7262) || defined(SH7264)
	sil_wrb_mem (STBCR7, (sil_reb_mem(STBCR7) | 0x04));
#endif
}

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 *�@�@�@�^�C�}�̓�����ꎞ�I�ɒ�~���C�^�C�}�l��ǂݏo���D
 */
Inline CLOCK
sh2_timer_get_current ()
{
	CLOCK	clk;
/* SH1�Ɠ��� */
	sh2_timer_stop ();			/*  �^�C�}��~  */

	/*  �{���͑҂����Ԃ�����ׂ�  */

	clk = sil_reh_mem(CMCNT_0);
	sh2_timer_start();			/*  �^�C�}�X�^�[�g  */
	
	return(clk);
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline BOOL
sh2_timer_fetch_interrupt ()
{
	return (sil_reh_mem (CMCSR_0) & 0x0080);
}

#endif /* _MACRO_ONLY */
#endif /* _SH726XCMT_H_ */
