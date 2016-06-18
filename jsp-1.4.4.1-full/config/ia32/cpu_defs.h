/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2002 by Monami software, Limited Partners.
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
 *  @(#) $Id: cpu_defs.h,v 1.1 2004/07/21 02:49:36 monaka Exp $
 */

/*
 *	�v���Z�b�T�Ɉˑ������`�ii386�p�j
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#define IA32

#ifndef _MACRO_ONLY

typedef	UINT		EXCNO;		/* CPU��O�n���h���ԍ� */

#define SIL_ENDIAN SIL_ENDIAN_LITTLE

#define SIL_REV_ENDIAN_H(data) ((VH)((((UH)(data) & 0xff) << 8) | (((UH)(data) >> 8) & 0xff)))

#define SIL_REV_ENDIAN_W(data) ((VW)((((UW)(data) & 0xff) << 24) | (((UW)(data) & 0xff00) << 8) | (((UW)(data) >> 8) & 0xff00) | (((UW)(data) >> 24) & 0xff)))

Inline VB sil_reb_iop(VP iop) {
	VB data;
	Asm("inb %%dx, %%al" : "=a"(data) : "d"(iop));
	return data;
}

Inline VH sil_reh_iop(VP iop) {
	VH data;
	Asm("inw %%dx, %%ax" : "=a"(data) : "d"(iop));
	return data;
}

Inline VW sil_rew_iop(VP iop) {
	VW data;
	Asm("inl %%dx, %%eax" : "=a"(data) : "d"(iop));
	return data;
}

#define sil_reh_lep(iop) sil_reh_iop(iop)
#define sil_rew_lep(iop) sil_rew_iop(iop)

Inline VH sil_reh_bep(VP iop) {
	return SIL_REV_ENDIAN_H(sil_reh_iop(iop));
}

Inline VW sil_rew_bep(VP iop) {
	return SIL_REV_ENDIAN_W(sil_rew_iop(iop));
}

Inline void sil_wrb_iop(VP iop, VB data) {
	Asm("outb %%al, %%dx" : : "a"(data), "d"(iop));
}

Inline void sil_wrh_iop(VP iop, VH data) {
	Asm("outw %%ax, %%dx" : : "a"(data), "d"(iop));
}

Inline void sil_wrw_iop(VP iop, VW data) {
	Asm("outl %%eax, %%dx" : : "a"(data), "d"(iop));
}

#define sil_wrh_lep(iop, data) sil_wrh_iop(iop, data)
#define sil_wrw_lep(iop, data) sil_wrw_iop(iop, data)

Inline void sil_wrh_bep(VP iop, VH data) {
	sil_wrh_iop(iop, SIL_REV_ENDIAN_H(data));
}

Inline void sil_wrw_bep(VP iop, VW data) {
	sil_wrw_iop(iop, SIL_REV_ENDIAN_W(data));
}

#endif /* _MACRO_ONLY */
#endif /* _CPU_DEFS_H_ */
