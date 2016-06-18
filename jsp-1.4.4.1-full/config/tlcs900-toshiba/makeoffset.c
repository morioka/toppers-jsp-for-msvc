/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2010 by Witz Corporation, JAPAN
 * 
 *  The above copyright holders grant permission gratis to use,
 *  duplicate, modify, or redistribute (hereafter called use) this
 *  software (including the one made by modifying this software),
 *  provided that the following four conditions (1) through (4) are
 *  satisfied.
 * 
 *  (1) When this software is used in the form of source code, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be retained in the source code without modification.
 * 
 *  (2) When this software is redistributed in the forms usable for the
 *      development of other software, such as in library form, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be shown without modification in the document provided
 *      with the redistributed software, such as the user manual.
 * 
 *  (3) When this software is redistributed in the forms unusable for the
 *      development of other software, such as the case when the software
 *      is embedded in a piece of equipment, either of the following two
 *      conditions must be satisfied:
 * 
 *    (a) The above copyright notice, this use conditions, and the
 *           disclaimer shown below must be shown without modification in
 *        the document provided with the redistributed software, such as
 *        the user manual.
 * 
 *    (b) How the software is to be redistributed must be reported to the
 *        TOPPERS Project according to the procedure described
 *        separately.
 * 
 *  (4) The above copyright holders and the TOPPERS Project are exempt
 *      from responsibility for any type of damage directly or indirectly
 *      caused from the use of this software and are indemnified by any
 *      users or end users of this software from any and all causes of
 *      action whatsoever.
 * 
 *  THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 *  THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 *  PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 *  TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 *  INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE
 *  �Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒��쌠
 *      �\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[�X
 *      �R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg�p
 *      �ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p�҃}
 *      �j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L�̖���
 *      �؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg�p
 *      �ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g�ɕ�
 *        �����邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹�Q
 *      ������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD�܂��C
 *      �{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝�R�Ɋ��
 *      ������������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂���
 *  ��TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI�ɑ΂�
 *  ��K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p
 *  �ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC��
 *  ��Ȃ��D
 * 
 *  @(#) $Id: makeoffset.c,v 1.1 2006/04/10 08:19:25 honda Exp $
 */


/*
 *	offset.inc (�������� offset.h) �ɂ���
 *
 *	  offset.inc �͍\���̂̓���̗v�f���\���̂̐擪���牽�o�C�g�ڂ�
 *	���݂��邩�Ƃ������Ƃ�, ����̃r�b�g�t�B�[���h���擪����
 *	���o�C�g��̉��r�b�g�ڂɑ��݂��邩, �Ƃ�������
 *	�A�Z���u������t�@�C���ɗ^���邽�߂ɑ��݂��Ă���.
 *
 *	  offset.inc �t�@�C���̒��g��, �P�Ȃ�V���{����`�t�@�C���ł���.
 *	�V���{���Ƃ����Ă���`����V���{���̖��̂ɂ̓p�^�[��������,
 *	�傫�������Ď���3��ނɕ��ނł���.
 *
 *	<�\���̖�>_<�v�f��>	(��) TCB_sp, TCB_pc, TCB_enatex �Ȃ�
 *	<�\���̖�>_<�v�f��>_bit	(��) TCB_enatex_bit �Ȃ�
 *	<�\���̖�>_<�v�f��>_mask (��) TCB_enatex_mask �Ȃ�
 *
 *	(��)
 *		TCB_texptn		equ		14
 *		TCB_sp			equ		20
 *		TCB_pc			equ		24
 *		TCB_enatex		equ		12
 *		TCB_enatex_bit	equ		14
 *		TCB_enatex_mask	equ		0x4000
 *
 *	  ��Ԃ͂��߂͓���̗v�f���\���̂̐擪���牽�o�C�g��ɂ��邩
 *	�Ƃ������Ƃ��������l�ɂ��郉�x���̖���.
 *	  ��Ԗڂ͓���̃r�b�g�t�B�[���h���̃r�b�g��, ���ʂ��琔����
 *	���r�b�g�ڂɂ��邩�Ƃ������Ƃ��������l�ɂ��郉�x���̖���. 
 *	0����n�܂鐔�l�ŕ\������. �ł����ʂ̃r�b�g�͑�0�r�b�g�ł���.
 *	  �O�Ԗڂ͐�قǂ� <�\���̖�>_<�v�f��>_bit �Ƃ��֘A���邪,
 *	����̃r�b�g�t�B�[���h���̃r�b�g�̃}�X�N�l�̖���.
 *	*_bit �� *_mask �̒l�̊Ԃɂ͎��̊֌W������.
 *		(*_mask) == (1 << *_bit)
 *	(��) TCB_enatex_bit �� 14 �̎�, TCB_enatex_mask �� 0x4000
 *
 *	  ���Ȃ݂�TLCS-900L1�ˑ����̎����ł�, ����r�b�g�̃`�F�b�N�Ȃǂ�
 *	�r�b�g���߃A�h���b�V���O���g�p���Ă���̂� *_mask �Ƃ������x����
 *	�g�p���Ă��Ȃ�.
 */

#include "jsp_kernel.h"
#include "task.h"


void makeoffset(void);

void
makeoffset()
{
	Asm("; BEGIN TCB_texptn\n");
	(((TCB *)0)->texptn) |= (TEXPTN)1;
	Asm("; END");

	Asm("; BEGIN TCB_sp\n");
	(((TCB *)0)->tskctxb.xsp) = (VP)1;
	Asm("; END");

	Asm("; BEGIN TCB_pc\n");
	(((TCB *)0)->tskctxb.pc)();
	Asm("; END");

	Asm("; BEGIN TCB_enatex\n");
	(((TCB *)0)->enatex) = 1;
	Asm("; END");
}

