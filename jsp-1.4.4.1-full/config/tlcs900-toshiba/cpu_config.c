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
 *  @(#) $Id: cpu_config.c,v 1.1 2006/04/10 08:19:25 honda Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���iTLCS-900L1�p�j
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/* 
 *  ������/CPU��O�l�X�g�J�E���^
 */
UINT	intcnt;

/*
 *  �^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
#ifdef SUPPORT_CHG_IPM
UH	task_intmask;
#endif /* SUPPORT_CHG_IPM */

/*
 *  ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
UH	int_intmask;

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize()
{
	/* �����݃l�X�g�J�E���g������(�����݃R���e�L�X�g) */
	intcnt = 1;

	/*
	 *  �^�X�N�R���e�L�X�g�ł̊����݃}�X�N�̏�����
	 */
#ifdef SUPPORT_CHG_IPM
	task_intmask = 0x0000;
#endif /* SUPPORT_CHG_IPM */

}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate()
{
}

#ifdef SUPPORT_CHG_IPM

/*
 *  �����݃}�X�N�̕ύX
 *
 *  chg_ipm ���g���� IPM �� 7�iNMI �ȊO�̂��ׂĂ̊����݂��֎~�j�ɕύX
 *  ���邱�Ƃ͂ł��Ȃ��DNMI �ȊO�̂��ׂĂ̊����݂��֎~�������ꍇ�ɂ́C
 *  loc_cpu �ɂ��CPU���b�N��Ԃɂ���΂悢�D
 *  IPM �� 0 �ȊO�̎��ɂ��C�^�X�N�f�B�X�p�b�`�͕ۗ�����Ȃ��DIPM �́C
 *  �^�X�N�f�B�X�p�b�`�ɂ���āC�V�������s��ԂɂȂ����^�X�N�ֈ����p��
 *  ���D���̂��߁C�^�X�N�����s���ɁC�ʂ̃^�X�N�ɂ���� IPM ���ύX��
 *  ���ꍇ������DJSP�J�[�l���ł́CIPM �̕ύX�̓^�X�N��O�������[�`
 *  ���ɂ���Ă��N����̂ŁC����ɂ���Ĉ���������Ȃ�󋵂͏��Ȃ���
 *  �v����DIPM �̒l�ɂ���ă^�X�N�f�B�X�p�b�`���֎~�������ꍇ�ɂ́C
 *  dis_dsp �𕹗p����΂悢�D
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
	ER	ercd;

	LOG_CHG_IPM_ENTER(ipm);
	CHECK_TSKCTX_UNL();
	CHECK_PAR(0 <= ipm && ipm <= 6);

	t_lock_cpu();
	task_intmask = (ipm << 12);
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_CHG_IPM_LEAVE(ercd);
	return(ercd);
}

/*
 *  �����݃}�X�N�̎Q��
 */
SYSCALL ER
get_ipm(IPM *p_ipm)
{
	ER	ercd;

	LOG_GET_IPM_ENTER(p_ipm);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	*p_ipm = (task_intmask >> 12);
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_GET_IPM_LEAVE(ercd, *p_ipm);
	return(ercd);
}

#endif /* SUPPORT_CHG_IPM */
