
        �� TOPPERS/JSP�J�[�l�� ���[�U�Y�}�j���A�� ��
                    �im16c:TM�J�����j

        �iRelease 1.4.4 �Ή��C�ŏI�X�V: 28-Dec-2010�j

------------------------------------------------------------------------
 TOPPERS/JSP Kernel
     Toyohashi Open Platform for Embedded Real-Time Systems/
     Just Standard Profile Kernel

 Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
                             Toyohashi Univ. of Technology, JAPAN
 Copyright (C) 2003-2004 by Platform Development Center
                                         RIOCH COMPANY,LTD. JAPAN
 Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
               Graduate School of Information Science, Nagoya Univ., JAPAN
 Copyright (C) 2010 by Naoki Saito
            Nagoya Municipal Industrial Research Institute, JAPAN

 ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
     ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
     �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
     �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
     �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
     �̖��ۏ؋K����f�ڂ��邱�ƁD
 (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
     �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
     �ƁD
   (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
       �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
   (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
       �񍐂��邱�ƁD
 (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
     �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD

 �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
------------------------------------------------------------------------

���̃h�L�������g�ł́AM16C�p�̃��l�T�X�G���N�g���j�N�X�Ђ̊J���c�[����
�g�p���āCTOPPERS/JSP�J�[�l�����\�z���邽�߂ɕK�v�ȃt�@�C���ɂ��ĉ������D

1. �f�B���N�g���̍\��

jsp
  +--config
  |     +---m16c-renesas
  |            +---oaks16
  |            +---oaks16_mini
  |            +---m3029
  +--tools
  |     +-----M16C-RENESAS
  +--utils
        +-----m16c-renesas


2.�f�B���N�g���ƃt�@�C���̐���

(1) config/m16c-renesas
	M16C �ˑ����̃t�@�C�����u�����f�B���N�g���D
(2) utils/m16c-renesas
	�r���h�̍ۂɎg����C�ȉ��̃c�[�����u�����f�B���N�g���D
		�E�����݂� CPU ��O�̃x�N�^��������������c�[��(m16cvec.exe)
		�ETCB �̃I�t�Z�b�g�l���A�Z���u���\�[�X�ɐݒ肷��c�[��(m16coffset.exe)
		(�ȉ��́Cmake ��p���ăr���h���鎞�̂ݎg����)
		�E�\�[�X�̈ˑ��֌W�𐶐����� perl �X�N���v�g(makedep.m16c)
(3) tools/M16C-RENESAS
	�����J���� TM ��p���� TOPPERS/JSP �J�[�l�����\�z���邽�߂�
	�t�@�C�����u�����f�B���N�g���D


2.1 config/m16c-renesas

a. Makefile.config
    make �R�}���h��p����M16C�p TOPPERS/JSP ���\�z����ꍇ�� make �t�@�C��
b. oaks16/Makefile.config 
    make �R�}���h��p���� M16C-OAKS16�p TOPPERS/JSP ���\�z����ꍇ�� make �t�@�C��
c. oaks16_mini/Makefile.config 
    make �R�}���h��p���� M16C-OAKS16 MINI�p TOPPERS/JSP ���\�z����ꍇ�� make �t�@�C��
d. ���̑� ---- M16C�ˑ����̃R�[�h


2.2 utils/m16c-renesas

a. makedep.m16c
    make��p���ĊJ�����ꍇ�A�\�[�X�̈ˑ��֌W�𐶐�����PERL�X�N���v�g
b: m16coffset.c
    m16coffset �R�}���hC����L�q
c: m16cvec.c
    m16cvec �R�}���hC����L�q
d: Makefile
    MinGW ��GCC��p���� m16coffset, m16cvec �R�}���h���r���h����ۂ�
    �p����t�@�C��

2.3 tools/M16C-RENESAS

a.Jsp14sample1.tmi,Jsp14sample1.tmk 
   TM��p���� OAKS16�p�� TOPPERS/JSP ���\�z���邽�߂̃v���W�F�N�g�t�@�C��
b.Jsp14sample1m.tmi,Jsp14samplem1.tmk
   TM��p���� OAKS16 MINI�p�� TOPPERS/JSP ���\�z���邽�߂̃v���W�F�N�g�t�@�C��
c.Jsp14sample1_m3029.tmi,Jsp14samplem1_m3029.tmk 
   TM��p���� M3029�p�� TOPPERS/JSP ���\�z���邽�߂̃v���W�F�N�g�t�@�C��
d.Jsp14sample1.id 
   �������� MOT �t�@�C����OAKS16 �{�[�h�̃t���b�V��ROM�̏������ގ��Ɏg�p����ID�t�@�C��
e.Jsp14sample1m.id 
   �������� MOT �t�@�C����OAKS16 MINI�{�[�h�̃t���b�V��ROM�̏������ގ��Ɏg�p����ID�t�@�C��
f.Jsp14sample1_m3029.id 
   �������� MOT �t�@�C���� M3029 �̃t���b�V��ROM�̏������ގ��Ɏg�p����ID�t�@�C��
g.sample1.cfg 
   OAKS16, M3029�p �� TOPPERS/JSP ���\�z���邽�߂̃R���t�B�M�����[�V�����t�@�C��
h.sample1m.cfg 
   OAKS16 MINI�p�� TOPPERS/JSP ���\�z���邽�߂̃R���t�B�M���t�@�C��


2.4  sample

a.Makefile.m16c-oaks16 
   make�R�}���h��p����OAKS16�p��TOPPERS/JSP���\�z���邽�߂�make�t�@�C��


3�Dm16cvec, m16coffset �R�}���h�̍\�z���@

m16cvec �y�� m16coffset �R�}���h�̍\�z�� MinGW ��p���ăR���p�C�����s���D
�R���p�C������ہCutils/m16c-renesas �f�B���N�g���ֈړ����C
�P�� make �R�}���h�����s����΂悢�D
����m�F���� GCC �̃o�[�W������ 4.5.0 �ł���D
