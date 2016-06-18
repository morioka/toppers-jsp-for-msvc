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
 *  @(#) $Id: i386.h,v 1.1 2004/07/21 02:49:36 monaka Exp $
 */

#ifndef	_I386_H_
#define	_I386_H_

/* Segment type */
#define	I386_TYPE_SEG_DATA       (0x00) /* 0000	�f�[�^�Z�O�����g */
#define	I386_TYPE_SEG_EXPAND     (0x04) /* 0100 �G�N�X�p���h�_�E�� */
#define	I386_TYPE_SEG_WRITEABLE  (0x02) /* 0010 �������݉� */
#define	I386_TYPE_SEG_ACCESSED   (0x01) /* 0001 �A�N�Z�X���ꂽ���H */
#define	I386_TYPE_SEG_CODE       (0x08) /* 1000 �R�[�h�Z�O�����g */

#define	I386_TYPE_SEG_CONFORMING (0x04) /* 0100 �R���t�H�[�~���O */
#define	I386_TYPE_SEG_READABLE   (0x02) /* 0010 �ǂݎ��� */
#define	I386_TYPE_SEG_ACCESSED   (0x01) /* 0001 �A�N�Z�X���ꂽ���H */

/* Gate type */
#define	I386_TYPE_GATE_INTR		0xe
#define	I386_TYPE_GATE_TRAP		0xf

/* Segment descriptor */
typedef struct __i386_segment_descriptor {
	unsigned	limit_L:16;
	unsigned	base_L:24;
	unsigned	type:4;
	unsigned	s:1;
	unsigned	dpl:2;
	unsigned	p:1;
	unsigned	limit_H:4;
	unsigned	avl:1;
	unsigned	x:1;
	unsigned	db:1;
	unsigned	g:1;
	unsigned	base_H:8;
}   __attribute__ ((packed)) SEGDESC;

/* Gate descriptor */
typedef struct __i386_gate_descriptor {
	unsigned long offset_L:16;
	unsigned long selector:16;
	unsigned long copy:8;
	unsigned long type:4;
	unsigned long s:1;
	unsigned long dpl:2;
	unsigned long p:1;
	unsigned long offset_H:16;
}   __attribute__ ((packed)) GATEDESC;

typedef	struct {
	unsigned	limit:16;
	unsigned	base:32;
}  __attribute__ ((packed)) DESCPTR;

#endif	/* _I386_H_ */
