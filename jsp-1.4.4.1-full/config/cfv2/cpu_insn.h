/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2007 by Kurusugawa-Electronics Technology Inc
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
 *  @(#) $Id: cpu_insn.h,v 1.9 2003/06/04 01:51:39 hiro Exp $
 */

/*
 *	�v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`�iCOLDFIRE�p�j
 */

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/*
 *  �X�e�[�^�X���W�X�^�iSR�j�̌��ݒl�̓Ǐo��
 */
Inline UH
current_sr()
{
	UH	sr;

	Asm("move.w %%sr, %0" : "=d"(sr));
	return(sr);
}

/*
 *  �X�e�[�^�X���W�X�^�iSR�j�̌��ݒl�̕ύX
 */
Inline void
set_sr(UH sr)
{
         Asm("move.w %0, %%sr" : : "d"(sr) : "cc");
}

/*
 *  NMI���������ׂĂ̊����݂��֎~
 */
Inline void
disint()
{
  set_sr((current_sr() | 0x0700));
}

/*
 *  ���ׂĂ̊����݂�����
 */
Inline void
enaint()
{
  set_sr((current_sr() & ~0x0700));
}

/*
 *  �x�N�^�x�[�X���W�X�^�iVBR�j�̌��ݒl�̓Ǐo��
 *
 *  ColdFire��movec vbr, dx���T�|�[�g���Ȃ�����
 *  ���̂悤�Ȉ����ɂȂ�
 *
 */
extern VP current_vbr();


/*
 *  �x�N�^�x�[�X���W�X�^�iVBR�j�̐ݒ�
 */
extern void set_vbr(VP vbr);


/*
 *  ���f�B�L���[�T�[�`�̂��߂̃r�b�g�}�b�v�T�[�`�֐�
 *
 *  �r�b�g�}�b�v�̉���16�r�b�g���g�p���C�ŉ��ʃr�b�g���Œ�D��x�ɑΉ�
 *  ������D
 */
#define	CPU_BITMAP_SEARCH
#define	PRIMAP_BIT(pri)		(0x8000u >> (pri))

Inline UINT
bitmap_search(UINT bitmap)
{
        UINT offset;
	/*
	 *  ���̃R�[�h�́Cbitmap�iUINT�^�j��32�r�b�g�ł��邱�Ƃ����肵
	 *  �Ă���D
	 */
        Asm("ff1.l %0" : "=d"(offset): "d"(bitmap & 0x0000FFFF));
	return(offset - 16);
}

#endif /* _CPU_INSN_H_ */
