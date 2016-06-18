;
;   TOPPERS/JSP Kernel
;       Toyohashi Open Platform for Embedded Real-Time Systems/
;       Just Standard Profile Kernel
;
;   Copyright (C) 2006-2010 by Witz Corporation, JAPAN
;  
;   The above copyright holders grant permission gratis to use,
;   duplicate, modify, or redistribute (hereafter called use) this
;   software (including the one made by modifying this software),
;   provided that the following four conditions (1) through (4) are
;   satisfied.
;  
;   (1) When this software is used in the form of source code, the above
;       copyright notice, this use conditions, and the disclaimer shown
;       below must be retained in the source code without modification.
;  
;   (2) When this software is redistributed in the forms usable for the
;       development of other software, such as in library form, the above
;       copyright notice, this use conditions, and the disclaimer shown
;       below must be shown without modification in the document provided
;       with the redistributed software, such as the user manual.
;  
;   (3) When this software is redistributed in the forms unusable for the
;       development of other software, such as the case when the software
;       is embedded in a piece of equipment, either of the following two
;       conditions must be satisfied:
;  
;     (a) The above copyright notice, this use conditions, and the
;            disclaimer shown below must be shown without modification in
;         the document provided with the redistributed software, such as
;         the user manual.
;  
;     (b) How the software is to be redistributed must be reported to the
;         TOPPERS Project according to the procedure described
;         separately.
;  
;   (4) The above copyright holders and the TOPPERS Project are exempt
;       from responsibility for any type of damage directly or indirectly
;       caused from the use of this software and are indemnified by any
;       users or end users of this software from any and all causes of
;       action whatsoever.
;  
;   THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
;   THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
;   INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
;   PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
;   TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
;   INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
;
;   ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
;   �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE
;   �Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
;   (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒��쌠
;       �\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[�X
;       �R�[�h���Ɋ܂܂�Ă��邱�ƁD
;   (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg�p
;       �ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p�҃}
;       �j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L�̖���
;       �؋K����f�ڂ��邱�ƁD
;   (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg�p
;       �ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
;     (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
;         ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
;     (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g�ɕ�
;         �����邱�ƁD
;   (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹�Q
;       ������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD�܂��C
;       �{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝�R�Ɋ��
;       ������������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
;  
;   �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂���
;   ��TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI�ɑ΂�
;   ��K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p
;   �ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC��
;   ��Ȃ��D
;  
;   @(#) $Id: sys_support.app,v 1.1 2006/04/10 08:19:25 honda Exp $
;

	$MAXIMUM
	module sys_support_app

;
;	�^�[�Q�b�g�V�X�e���ˑ����W���[�� �A�Z���u�����ꕔ
;	�iZup-F16�g���{�[�h�p�j
;

#include "jsp_rename.h"
#include "cpu_rename.h"
#include "sys_rename.h"
#include "tmp91cy22.h"

f_code section code large align=1,1

;
; �^�[�Q�b�g�n�[�h�E�F�A�Ɉˑ����ĕK�v�ȏ���������������ꍇ
;
	public hardware_init_hook
hardware_init_hook:
; ����N���b�N�ݒ�(�����N���b�N1������4���{��1/2)�i6.144*(1/1)*4*(1/2)=12.288�j
	ldb		(TADR_SFR_SYSCR0), 0xa0
	ldb		(TADR_SFR_SYSCR1), 0x00
	ldb		(TADR_SFR_SYSCR2), 0x2c ; halt���߂ɂ�IDLE2�ɑJ��
	ldb		(TADR_SFR_DFMCR1), 0x0b
	ldb		(TADR_SFR_DFMCR0), 0x40
lockup:			; ���b�N�A�b�v�҂�
	bit		5, (TADR_SFR_DFMCR0)
	jr		nz, lockup
	ldb		(TADR_SFR_DFMCR0), 0x80

; �O���A�h���X���2����
	ldb		(TADR_SFR_B2CS), 0x00
; �O���A�h���X���1�L��(1MByteSRAM)
	ldb		(TADR_SFR_P1CR), 0x00
	ldb		(TADR_SFR_P1FC), 0xff	; AD0�`AD15���g�p
	ldb		(TADR_SFR_P2CR), 0xff
	ldb		(TADR_SFR_P2FC), 0x0f	; A16�`A19���g�p(�c��̓|�[�g)
	ldb		(TADR_SFR_P2), 0xff
	ldb		(TADR_SFR_P3), 0x78
	ldb		(TADR_SFR_P3CR), 0x7f
	ldb		(TADR_SFR_P3FC), 0x07	; RD/WR/HWR���g�p
	ldb		(TADR_SFR_P4FC), 0x02	; CS1���g�p
	ldb		(TADR_SFR_P4CR), 0x0e
	ldb		(TADR_SFR_MSAR1), 0x10	; 0x00100000�`
	ldb		(TADR_SFR_MAMR1), 0x3f	; 0x001fffff
	ldb		(TADR_SFR_B1CS), 0x83	; 0�E�F�C�g/16bitDataBus

; WDT��~
	ldb		(TADR_SFR_WDMOD), 0x00
	ldb		(TADR_SFR_WDCR), 0xb1

	ret

;
;  �������ԑ҂�
;
	public _sil_dly_nse
_sil_dly_nse:
	ld	WA, (XSP+0x4)
	sub	WA, 3173
	ret	le
	nop
sil_dly_nse1:
	sub	WA, 732
	jr	gt, sil_dly_nse1
	ret


	end


