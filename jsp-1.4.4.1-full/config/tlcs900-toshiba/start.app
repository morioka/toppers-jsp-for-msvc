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
;   @(#) $Id: start.app,v 1.1 2006/04/10 08:19:25 honda Exp $
;

	$MAXIMUM
	module start_app

;
;	�J�[�l���p�̃X�^�[�g�A�b�v���W���[���iTLCS-900�p�j
;
#include "jsp_rename.h"
#include "cpu_rename.h"
#include "sys_rename.h"
#include "tlcs900vec.inc"

; �O���Q�ƃV���{����`
	extern large	__StackTop
	extern large	__AreaRAM
	extern large	__AreaRAM_size
	extern large	__DataRAM
	extern large	__DataRAM_ini
	extern large	__DataRAM_size
	extern large	hardware_init_hook
	extern large	software_init_hook
	extern large	_kernel_start

f_code section code large align=1,1

	public _start
_start:
; �����݋֎~
	di		; ���Z�b�g����IFF��7���ݒ肳��邽��DI��ԂƂȂ�
			; �n�[�h�E�F�A���Z�b�g����di���ߕs�v
			; �\�t�g�ɂ� jp _start ����\�����l�����R�[�h���c��

; �X�^�b�N������
	ld		xsp, __StackTop

; INTNEST���W�X�^������
	ld		hl, 0
	ldc		intnest, hl

; hardware_init_hook ���ďo���i0 �łȂ��ꍇ�j
; �^�[�Q�b�g�n�[�h�E�F�A�Ɉˑ����ĕK�v�ȏ���������������ꍇ
; �́Chardware_init_hook �Ƃ����֐���p�ӂ���D
	ld		xhl, hardware_init_hook
	cp		xhl, 0
	call	nz, hardware_init_hook

; �����l����RAM�̈�̃N���A
	ld		xde, __AreaRAM			; �擪�Ԓn�ƃT�C�Y�擾
	ld		xbc, __AreaRAM_size
	ld		ix, bc					; �ŉ���bit�ێ�(��Ŏg�p)
	srl		1, xbc					; 2byte�P�ʂŏ������邽�߃T�C�Y/2
	jr		z, area_clr_byte
	ld		xhl, xde				; �擪�Ԓn�ێ�(��Ŏg�p)
	ldw		(xde+), 0				; �擪�Ԓn�N���A
	sub		xbc, 1					; �T�C�Y�f�N�������g
	jr		z, area_clr_byte
	ldirw	(xde+), (xhl+)			; �擪�Ԓn(�O��0�ݒ�)�̒l�����Ԓn��...
									; �̗v�̂�BC���W�X�^���u���b�N���[�h
	cp		qbc, 0
	jr		eq, area_clr_byte			; ���16bit��0�Ȃ�I��
	ld		wa, qbc
area_clr_loop:						; ���16bit(0x10000�P��)�ł̏���
	ldirw	(xde+), (xhl+)			; 0x10000���u���b�N���[�h
	djnz	wa, area_clr_loop
area_clr_byte:
	bit		0, ix					; �̈�T�C�Y����Ȃ�1byte�N���A
	jr		z, area_clr_end
	ldb		(xde), 0
area_clr_end:

; �����l�L��RAM�̈�ւ̃f�[�^���[�h
	ld		xde, __DataRAM			; ���[�h���E���[�h��Ԓn�ƃT�C�Y�擾
	ld		xhl, __DataRAM_ini
	ld		xbc, __DataRAM_size
	or		xbc, xbc				; �T�C�Y0�Ȃ�I��
	jr		z, data_ld_end
	ldirb	(xde+), (xhl+)			; BC���W�X�^���u���b�N���[�h
	cp		qbc, 0
	jr		eq, data_ld_end			; ���16bit��0�Ȃ�I��
	ld		wa, qbc
data_ld_loop:						; ���16bit(0x10000�P��)�ł̏���
	ldirb	(xde+), (xhl+)			; 0x10000���u���b�N���[�h
	djnz	wa, data_ld_loop
data_ld_end:

; software_init_hook ���ďo���i0 �łȂ��ꍇ�j
; �\�t�g�E�F�A���i���Ƀ��C�u�����j�Ɉˑ����ĕK�v�ȏ�������
; ��������ꍇ�́Csoftware_init_hook �Ƃ����֐���p�ӂ���D
	ld		xhl, software_init_hook
	cp		xhl, 0
	call	nz, software_init_hook

; �J�[�l���N��
	jp		_kernel_start

; EXIT���[�v
exit:
	jr		exit

	end
