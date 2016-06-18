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

#ifndef _TINET_CPU_CONFIG_H_
#define _TINET_CPU_CONFIG_H_

/*
 *  TCP/IP �Ɋւ����`
 */

/* TCP �Ɋւ����` */

/*
 *  MAX_TCP_SND_SEG: ���M�Z�O�����g�T�C�Y�̍ő�l
 *
 *    ���肩�� MSS �I�v�V�����ŃZ�O�����g�T�C�Y���w�肳��Ă��A
 *    ���̒l�ŁA�Z�O�����g�T�C�Y�𐧌��ł���B
 */

#ifndef MAX_TCP_SND_SEG
#define MAX_TCP_SND_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))
#endif	/* of #ifndef MAX_TCP_SND_SEG */

/*
 *  DEF_TCP_RCV_SEG: ��M�Z�O�����g�T�C�Y�̋K��l
 */

#ifndef DEF_TCP_RCV_SEG
#define DEF_TCP_RCV_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))
#endif	/* of #ifndef DEF_TCP_RCV_SEG */

/* 
 *  �Z�O�����g�̏��Ԃ����ւ���Ƃ��ɐV���Ƀl�b�g���[�N�o�b�t�@�������ĂāA
 *  �f�[�^���R�s�[����T�C�Y�̂������l
 */
#define MAX_TCP_REALLOC_SIZE	1024	

#define TCP_CFG_OPT_MSS		/* �R�l�N�V�����J�ݎ��ɁA�Z�O�����g�T�C�Y�I�v�V���������đ��M����B*/
#define TCP_CFG_DELAY_ACK	/* ACK ��x�点��Ƃ��̓R�����g���O���B			*/
#define TCP_CFG_ALWAYS_KEEP	/* ��ɃL�[�v�A���C�u���鎞�̓R�����g���O���B		*/

/* UDP �Ɋւ����` */

#define UDP_CFG_IN_CHECKSUM	/* UDP �̓��̓`�F�b�N�T�����s���ꍇ�̓R�����g���O���B	*/
#define UDP_CFG_OUT_CHECKSUM	/* UDP �̏o�̓`�F�b�N�T�����s���ꍇ�̓R�����g���O���B	*/

/* ICMPv4/v6 �Ɋւ����` */

#define ICMP_REPLY_ERROR		/* ICMP �G���[���b�Z�[�W�𑗐M����ꍇ�̓R�����g���O���B*/

/* IPv4 �Ɋւ����` */

//#define IP4_CFG_FRAGMENT		/* �f�[�^�O�����̕����E�č\���s���ꍇ�̓R�����g���O���B*/
#define NUM_IP4_FRAG_QUEUE	2	/* �f�[�^�O�����č\���L���[�T�C�Y			*/
#define IP4_CFG_FRAG_REASSM_SIZE	4096	/* �č\���o�b�t�@�T�C�Y				*/

/* IPv6 �Ɋւ����` */

#define NUM_IP6_DAD_COUNT	1	/* �d���A�h���X���o�ő��M����ߗחv���̉񐔁A		*/
					/*  0 ���w�肷��ƁA�d���A�h���X���o���s��Ȃ��B	*/
#define NUM_ND6_CACHE_ENTRY	10	/* �ߗ׃L���b�V���̃G���g����			*/

#ifdef SUPPORT_ETHER

#define IP6_CFG_AUTO_LINKLOCAL		/* �����N���[�J���A�h���X�̎����ݒ���s���ꍇ�̓R�����g���O���B*/

/*
 *  �f�B�t�H���g���[�^���X�g�̃G���g�����B
 *  0 ���w�肷��ƃ��[�^�ʒm����M���Ȃ��B
 */
#define NUM_ND6_DEF_RTR_ENTRY	2

/*
 *  �N�����̃��[�^�v���o�͉񐔁B
 *  0 ���w�肷��ƃ��[�^�v�����o�͂��Ȃ��B
 */
#define NUM_ND6_RTR_SOL_RETRY	3	

#endif	/* of #ifdef SUPPORT_ETHER */

/*
 *  �f�[�^�����N�w (�l�b�g���[�N�C���^�t�F�[�X) �Ɋւ����`
 */

/*
 *  PPP�A���f���Ɋւ����`
 */

#define MODEM_CFG_DIAL		"ATD"	/* �_�C�A���R�}���h������			*/
#define MODEM_CFG_RETRY_CNT	3	/* �_�C�A�����g���C��			*/
#define MODEM_CFG_RETRY_WAIT	10000	/* �_�C�A�����g���C�܂ł̑҂����� [ms]	*/

/*
 *  PPP�AHDLC �Ɋւ����`
 */

#define DEF_LOCAL_ACCM		0x000a0000	/* ������ ACCM�AXON �� XOFF �̂ݕϊ�	*/
#define DEF_REMOTE_ACCM		0xffffffff	/* ����� ACCM�A�����l�͑S�ĕϊ�		*/

/*
 *  PPP�ALCP �Ɋւ����`
 */

#define LCP_CFG_MRU		0x0001	/* MRU					*/
#define LCP_CFG_ACCM		0x0002	/* ACCM					*/
#define LCP_CFG_MAGIC		0x0004	/* �}�W�b�N�ԍ�				*/
#define LCP_CFG_PCOMP		0x0008	/* �v���g�R�������k�@�\			*/
#define LCP_CFG_ACCOMP		0x0010	/* �A�h���X�E���䕔���k			*/
#define LCP_CFG_PAP		0x0020	/* PAP					*/
/*#define LCP_CFG_CHAP		0x0040	   CHAP �͎����\��			*/

#ifdef LCP_CFG_MAGIC

#define LCP_ECHO_INTERVAL	(20*NET_TIMER_HZ)	/* �C���^�[�o������		*/
#define LCP_ECHO_FAILS		9			/* ���s臒l			*/

#endif	/* of #ifdef LCP_CFG_MAGIC */

/*
 *  PPP�APAP �Ɋւ����`
 */

#define DEF_PAP_TIMEOUT		(3*NET_TIMER_HZ)
#define DEF_PAP_REQTIME		(30*NET_TIMER_HZ)	/* �^�C���A�E�g�������s���Ƃ��̓R�����g���O���B*/
#define MAX_PAP_REXMT		10			/* �F�ؗv���̍ő�đ���	*/

/*
 *  ARP �Ɋւ����`
 */

#define NUM_ARP_ENTRY		10			/* ARP �L���b�V���G���g����	*/

/*
 *  DHCP �Ɋւ����`
 *
 *    �E����: TINET �́ADHCP ���������Ă��Ȃ��B���p�v���O�����ŁA
 *            DHCP ���b�Z�[�W����M���邽�߂̒�`�ł���B
 *            �܂��A���݂� IPv4 �̂ݗL���ł���B
 */

/*#define DHCP_CFG					 DHCP ����������ꍇ�̓R�����g���O���B*/

/*
 *  Ethernet �Ɋւ����`
 */

/*#define ETHER_CFG_ACCEPT_ALL		 �}���`�L���X�g�A�G���[�t���[������M����Ƃ��̓R�����g���O���B	*/
/*#define ETHER_CFG_UNEXP_WARNING	 ��T�|�[�g�t���[���̌x����\������Ƃ��̓R�����g���O���B		*/
/*#define ETHER_CFG_802_WARNING		 IEEE 802.3 �t���[���̌x����\������Ƃ��̓R�����g���O���B		*/
/*#define ETHER_CFG_MCAST_WARNING	 �}���`�L���X�g�̌x����\������Ƃ��̓R�����g���O���B		*/

/*
 *  �ėp�l�b�g���[�N�Ɋւ����`
 */

/* �l�b�g���[�N�o�b�t�@�� */

#ifdef SUPPORT_PPP

/*
 *  PPP �ł́A��M�p�� �l�b�g���[�N�o�b�t�@�� PDU (1502) �T�C�Y�����
 *  ���蓖�ĂȂ���΂Ȃ�Ȃ��̂� PDU �T�C�Y�𑽂߂Ɋm�ۂ���B
 */

#ifndef NUM_MPF_NET_BUF_CSEG
#define NUM_MPF_NET_BUF_CSEG	2	/* IF + IP + TCP�A2 �ȏ�*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_CSEG */

#ifndef NUM_MPF_NET_BUF_64
#define NUM_MPF_NET_BUF_64	0	/* 64 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_64 */

#ifndef NUM_MPF_NET_BUF_128
#define NUM_MPF_NET_BUF_128	0	/* 128 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_128 */

#ifndef NUM_MPF_NET_BUF_256
#define NUM_MPF_NET_BUF_256	0	/* 256 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_256 */

#ifndef NUM_MPF_NET_BUF_512
#define NUM_MPF_NET_BUF_512	0	/* 512 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_512 */

#ifndef NUM_MPF_NET_BUF_1024
#define NUM_MPF_NET_BUF_1024	0	/* 1024 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_1024 */

#ifndef NUM_MPF_NET_BUF_IF_PDU
#define NUM_MPF_NET_BUF_IF_PDU	2	/* IF �ő� PDU �T�C�Y	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IF_PDU */

#if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT)

#ifndef NUM_MPF_NET_BUF_REASSM
#define NUM_MPF_NET_BUF_REASSM	2	/* �č\���o�b�t�@�T�C�Y	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_REASSM */

#endif	/* of #if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT) */

#endif	/* of #ifdef SUPPORT_PPP */

#ifdef SUPPORT_ETHER

/*
 *  �C�[�T�l�b�g�̏ꍇ�̃l�b�g���[�N�o�b�t�@���̊��蓖��
 */

/*
 *  ����!!
 *
 *  NE2000 �݊� NIC �̃f�B�o�C�X�h���C�o�iif_ed�j�̍Œኄ���Ē���
 *  60�i�A���C������ 62�j�I�N�e�b�g�̂��� IF + IP +TCP ����
 *  64 �I�N�e�b�g�̃l�b�g���[�N�o�b�t�@�̕����œK�ł���B
 */

#ifndef NUM_MPF_NET_BUF_CSEG
#define NUM_MPF_NET_BUF_CSEG	0	/* IF + IP + TCP	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_CSEG */

#ifndef NUM_MPF_NET_BUF_64
#define NUM_MPF_NET_BUF_64	2	/* 64 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_64 */

#ifndef NUM_MPF_NET_BUF_128
#define NUM_MPF_NET_BUF_128	0	/* 128 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_128 */

#ifndef NUM_MPF_NET_BUF_256
#define NUM_MPF_NET_BUF_256	0	/* 256 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_256 */

#ifndef NUM_MPF_NET_BUF_512
#define NUM_MPF_NET_BUF_512	0	/* 512 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_512 */

#if defined(SUPPORT_INET4)

#ifndef NUM_MPF_NET_BUF_IP_MSS
#define NUM_MPF_NET_BUF_IP_MSS	0	/* IF + 576 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IP_MSS */

#endif	/* of #if defined(SUPPORT_INET4) */

#ifndef NUM_MPF_NET_BUF_1024
#define NUM_MPF_NET_BUF_1024	0	/* 1024 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_1024 */

#if defined(SUPPORT_INET6)

#ifndef NUM_MPF_NET_BUF_IPV6_MMTU
#define NUM_MPF_NET_BUF_IPV6_MMTU	0	/* IF + 1280	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IPV6_MMTU */

#endif	/* of #if defined(SUPPORT_INET6) */

#ifndef NUM_MPF_NET_BUF_IF_PDU
#define NUM_MPF_NET_BUF_IF_PDU	4	/* IF �ő� PDU �T�C�Y	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IF_PDU */

#if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT)

#ifndef NUM_MPF_NET_BUF_REASSM
#define NUM_MPF_NET_BUF_REASSM	2	/* �č\���o�b�t�@�T�C�Y	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_REASSM */

#endif	/* of #if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT) */

#endif	/* of #ifdef SUPPORT_ETHER */

#ifdef SUPPORT_LOOP

#ifndef NUM_MPF_NET_BUF_CSEG
#define NUM_MPF_NET_BUF_CSEG	2	/* IF + IP + TCP	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_CSEG */

#ifndef NUM_MPF_NET_BUF_64
#define NUM_MPF_NET_BUF_64	0	/* 64 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_64 */

#ifndef NUM_MPF_NET_BUF_128
#define NUM_MPF_NET_BUF_128	0	/* 128 �I�N�e�b�g�A2 �ȏ�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_128 */

#ifndef NUM_MPF_NET_BUF_256
#define NUM_MPF_NET_BUF_256	0	/* 256 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_256 */

#ifndef NUM_MPF_NET_BUF_512
#define NUM_MPF_NET_BUF_512	0	/* 512 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_512 */

#ifndef NUM_MPF_NET_BUF_1024
#define NUM_MPF_NET_BUF_1024	0	/* 1024 �I�N�e�b�g	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_1024 */

#ifndef NUM_MPF_NET_BUF_IF_PDU
#define NUM_MPF_NET_BUF_IF_PDU	4	/* IF �ő� PDU �T�C�Y	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IF_PDU */

#endif	/* of #ifdef SUPPORT_PPP */

/*
 *  �l�b�g���[�N���v���̌v��
 *
 *  �l�b�g���[�N���v���̌v�����s���ꍇ�́Atinet/include/net/net.h
 *  �Œ�`����Ă���v���g�R�����ʃt���O���w�肷��B
 */

#if 1

#ifdef SUPPORT_INET4

#define NET_COUNT_ENABLE	(0			\
				| PROTO_FLG_PPP_HDLC	\
				| PROTO_FLG_PPP_PAP	\
				| PROTO_FLG_PPP_LCP	\
				| PROTO_FLG_PPP_IPCP	\
				| PROTO_FLG_PPP		\
				| PROTO_FLG_LOOP	\
				| PROTO_FLG_ETHER_NIC	\
				| PROTO_FLG_ETHER	\
				| PROTO_FLG_ARP		\
				| PROTO_FLG_IP4		\
				| PROTO_FLG_ICMP4	\
				| PROTO_FLG_UDP		\
				| PROTO_FLG_TCP		\
				| PROTO_FLG_NET_BUF	\
				)

#endif	/* of #ifdef SUPPORT_INET4 */

#ifdef SUPPORT_INET6

#define NET_COUNT_ENABLE	(0			\
				| PROTO_FLG_PPP_HDLC	\
				| PROTO_FLG_PPP_PAP	\
				| PROTO_FLG_PPP_LCP	\
				| PROTO_FLG_PPP_IPCP	\
				| PROTO_FLG_PPP		\
				| PROTO_FLG_LOOP	\
				| PROTO_FLG_ETHER_NIC	\
				| PROTO_FLG_ETHER	\
				| PROTO_FLG_IP6		\
				| PROTO_FLG_ICMP6	\
				| PROTO_FLG_ND6		\
				| PROTO_FLG_UDP		\
				| PROTO_FLG_TCP		\
				| PROTO_FLG_NET_BUF	\
				)

#endif	/* of #ifdef SUPPORT_INET6 */

#else	/* of #if 0 */

#define NET_COUNT_ENABLE	(0			\
				)

#endif	/* of #if 0 */

#endif /* _TINET_CPU_CONFIG_H_ */
