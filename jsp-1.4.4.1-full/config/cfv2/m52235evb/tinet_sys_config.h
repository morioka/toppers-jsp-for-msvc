/*
 *  TINET (TCP/IP Protocol Stack)
 * 
 *  Copyright (C) 2001-2006 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2007 by KURUSUGAWA Electronics Industry Inc, JAPAN
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
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̏����𖞂������ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 *
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: $
 */

#ifndef _TINET_SYS_CONFIG_H_
#define _TINET_SYS_CONFIG_H_

/*
 *  �f�[�^�����N�w (�l�b�g���[�N�C���^�t�F�[�X) �Ɋւ����`
 */

/*
 *  NIC (NE2000 �݊�) �Ɋւ����`
 */

#define NUM_IF_FEC_TXBUF		2	/* ���M�o�b�t�@��			*/
#define NUM_IF_FEC_RXBUF		1	/* ���M�o�b�t�@��			*/


#define TMO_IF_FEC_GET_NET_BUF	1	/* [ms]�A��M�p net_buf �l���^�C���A�E�g	*/
					/* [s]�A ���M�^�C���A�E�g			*/
#define TMO_IF_FEC_XMIT		(2*IF_TIMER_HZ)

/*#define IF_ED_CFG_ACCEPT_ALL		 �}���`�L���X�g�A�G���[�t���[������M����Ƃ��̓R�����g���O���B*/

/*
 *  �C�[�T�l�b�g�o�͎��ɁANIC �� net_buf ���J������ꍇ�Ɏw�肷��B
 *
 *  ����: �ȉ��̎w��́A�w���ł���Aif_ed �ł́A
 *        �J�����Ȃ��̂ŁA�ȉ��̃R�����g���O���Ă͂Ȃ�Ȃ��B
 */

/*#define ETHER_NIC_CFG_RELEASE_NET_BUF*/

/*
 *  FEC �Ɋւ����`
 */
#define FEC_BASE_ADDRESS	(IPSBAR + 0x001000)	/* FEC�̃��W�X�^�x�[�X�A�h���X */
#define PHY_BASE_ADDRESS	(IPSBAR + 0x1E0000)	/* EPHY�̃��W�X�^�x�[�X�A�h���X */
#define FEC_PHY0                (0x00)

#define INHNO_FEC_XINF     87
#define INHNO_FEC_XINB     88
#define INHNO_FEC_UN       89
#define INHNO_FEC_RL       90
#define INHNO_FEC_RINF     91
#define INHNO_FEC_RINB     92
#define INHNO_FEC_MII      93
#define INHNO_FEC_LC       94
#define INHNO_FEC_HBERR    95
#define INHNO_FEC_GRA      96
#define INHNO_FEC_EBERR    97
#define INHNO_FEC_BABT     98
#define INHNO_FEC_BABR     99
#define INHNO_EPHY         100

#define TBIT_FEC_XINF     23
#define TBIT_FEC_XINB     24
#define TBIT_FEC_UN       25
#define TBIT_FEC_RL       26
#define TBIT_FEC_RINF     27
#define TBIT_FEC_RINB     28
#define TBIT_FEC_MII      29
#define TBIT_FEC_LC       30
#define TBIT_FEC_HBERR    31
#define TBIT_FEC_GRA      32
#define TBIT_FEC_EBERR    33
#define TBIT_FEC_BABT     34
#define TBIT_FEC_BABR     35
#define TBIT_EPHY         36

/*
 *  JSP-1.4.2 �ȍ~�ł́A�����݃n���h���̓o�^���@���ύX����A
 *  �����݃v���C�I���e�B�E���x����ݒ肷��K�v������B
 */
#define FEC_INT_LEVEL			5
#define FEC_INT_PRI			7

/*  
 * �����݃n���h�����s���̊����݃}�X�N�̒l
 * �@�@���̊����݂��}�X�N���邽�߂̐ݒ�  
 * �@�@�����Ɠ������x���̊����ݗv�����u���b�N���邽�߁A
 * �@�@��L�̊����ݗv�����x�����P�������x���ɐݒ肷��B
 */
#define if_fec_handler_intmask		(FEC_INT_LEVEL+1)

#ifndef _MACRO_ONLY

#if TKERNEL_PRVER < 0x1042u	/* JSP-1.4.2 �ȑO */

/*
 *  JSP-1.4.2 �ȑO�ł́AIPM ���G���[���������Ȃ��悤�ɒ�`����B
 */

typedef UINT	IPM;

#else	/* of #if TKERNEL_PRVER < 0x1042u */

#define fec_ena_inter(ipm)	chg_ipm(ipm)

#endif	/* of #if TKERNEL_PRVER < 0x1042u */

/*
 *  �֐�
 */

#if TKERNEL_PRVER < 0x1042u	/* JSP-1.4.2 �ȑO */

extern void fec_ena_inter (IPM ipm);

#endif	/* of #if TKERNEL_PRVER < 0x1042u */

extern IPM fec_dis_inter (void);
extern void fec_bus_init (void);
extern void fec_inter_init (void);

#endif	/* of #ifndef _MACRO_ONLY */

#endif /* _TINET_SYS_CONFIG_H_ */
