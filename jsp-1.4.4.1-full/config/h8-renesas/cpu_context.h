/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: cpu_context.h,v 1.7 2007/03/23 07:58:33 honda Exp $
 */

#ifndef _CPU_CONTEXT_H_
#define _CPU_CONTEXT_H_

/*
 *  �^�X�N�R���e�L�X�g���샋�[�`��
 *
 *  ���̃t�@�C���� cpu_conf.h �ƕ������Ă���̂́C���̃t�@�C����TCB��
 *  ��`���ꂽ��ɓǂޕK�v������̂ɑ΂��āCcpu_conf.h �ɂ�TCB���`��
 *  ��O�ɓǂޕK�v�������`���܂�ł��邽�߂ł���D
 */

#include "task.h"

/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̏�����
 *
 *  �^�X�N���x�~��ԂɈڍs���鎞�i�^�X�N�̐������C�^�X�N�̏I�����j�Ɍ�
 *  �΂��D��{�I�ɂ́C�^�X�N�R���e�L�X�g�u���b�N���^�X�N���N���ł���
 *  ��Ԃɐݒ肷�鏈�����Ccreate_context �� activate_context �ōs����
 *  �悢�D�����̏����͂ǂ���̊֐��ōs���Ă��悢�D
 */
Inline void
create_context(TCB *tcb)
{
}

/*
 *  �^�X�N�̋N������
 *
 *  �^�X�N���x�~��Ԃ�����s�ł����ԂɈڍs���鎞�ɌĂ΂��D
 *
 *  �X�^�b�N��ɂ͉����ς܂Ȃ�
 *  activate_r�ł�runtsk����K�v�ȏ������o����̂ŁA
 *  �X�^�b�N�ɐςޕK�v�͂Ȃ��i�����������j
 *
 */
extern void activate_r(void);

Inline void
activate_context(TCB *tcb)
{
        VW      *sp;

        sp = (VW *)(((VB *) tcb->tinib->stk) + tcb->tinib->stksz);
        tcb->tskctxb.sp = sp;
        tcb->tskctxb.pc = (FP)activate_r;
}


/*
 *  ext_tsk ���X�^�b�N��Ɋm�ۂ���_�~�[�̈�̃T�C�Y
 *
 *  �@H8�łł̓_�~�[�̈���m�ۂ���K�v���Ȃ��̂�
 *�@�@ACTIVATED_STACK_SIZE�}�N�����`���Ȃ�
 */

/*
 *  calltex �͎g�p���Ȃ�
 */
#define OMIT_CALLTEX

#endif /* _CPU_CONTEXT_H_ */