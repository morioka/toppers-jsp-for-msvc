/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002 by Hokkaido Industrial Research Institute, JAPAN
 *  Copyright (C) 2010 by Cronus Computer Works, JAPAN
 *
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă���
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ���̏����̂����ꂩ�𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
 *  �A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���ė��p�\�ȃo�C�i���R�[�h�i�����P�[�^�u���I�u
 *      �W�F�N�g�t�@�C���⃉�C�u�����Ȃǁj�̌`�ŗ��p����ꍇ�ɂ́C���p
 *      �ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C
 *      ���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���ė��p�s�\�ȃo�C�i���R�[�h�̌`�܂��͋@��ɑg
 *      �ݍ��񂾌`�ŗ��p����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) ���p�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) ���p�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āC��L���쌠�҂ɕ񍐂���
 *        ���ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂�Ɛӂ��邱�ƁD
 *
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂́C
 *  �{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\�����܂߂āC�����Ȃ�ۏ؂��s��
 *  �Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ�������
 *  ���Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 *
 *  @(#) $Id
 */

#ifndef _SH7263_H_
#define _SH7263_H_

#include <sil.h>

/*
 *  �����݃x�N�^�ԍ�
 */
#define INT_IRQ0        64          /* IRQ0 (�O�����荞��) */
#define INT_IRQ1        65          /* IRQ1 (�O�����荞��) */
#define INT_IRQ2        66          /* IRQ2 (�O�����荞��) */
#define INT_IRQ3        67          /* IRQ3 (�O�����荞��) */
#define INT_IRQ4        68          /* IRQ4 (�O�����荞��) */
#define INT_IRQ5        69          /* IRQ5 (�O�����荞��) */
#define INT_IRQ6        70          /* IRQ6 (�O�����荞��) */
#define INT_IRQ7        71          /* IRQ7 (�O�����荞��) */
#define INT_PINT0       80          /* PINT0 (�O�����荞��) */
#define INT_PINT1       81          /* PINT1 (�O�����荞��) */
#define INT_PINT2       82          /* PINT2 (�O�����荞��) */
#define INT_PINT3       83          /* PINT3 (�O�����荞��) */
#define INT_PINT4       84          /* PINT4 (�O�����荞��) */
#define INT_PINT5       85          /* PINT5 (�O�����荞��) */
#define INT_PINT6       86          /* PINT6 (�O�����荞��) */
#define INT_PINT7       87          /* PINT7 (�O�����荞��) */
#define INT_DEI0        108         /* DMAC�`���l��0 �g�����X�t�@�G���h */
#define INT_HEI0        109         /* DMAC�`���l��0 �n�[�t�G���h */
#define INT_DEI1        112         /* DMAC�`���l��1 �g�����X�t�@�G���h */
#define INT_HEI1        113         /* DMAC�`���l��1 �n�[�t�G���h */
#define INT_DEI2        116         /* DMAC�`���l��2 �g�����X�t�@�G���h */
#define INT_HEI2        117         /* DMAC�`���l��2 �n�[�t�G���h */
#define INT_DEI3        120         /* DMAC�`���l��3 �g�����X�t�@�G���h */
#define INT_HEI3        121         /* DMAC�`���l��3 �n�[�t�G���h */
#define INT_DEI4        124         /* DMAC�`���l��4 �g�����X�t�@�G���h */
#define INT_HEI4        125         /* DMAC�`���l��4 �n�[�t�G���h */
#define INT_DEI5        128         /* DMAC�`���l��5 �g�����X�t�@�G���h */
#define INT_HEI5        129         /* DMAC�`���l��5 �n�[�t�G���h */
#define INT_DEI6        132         /* DMAC�`���l��6 �g�����X�t�@�G���h */
#define INT_HEI6        133         /* DMAC�`���l��6 �n�[�t�G���h */
#define INT_DEI7        136         /* DMAC�`���l��7 �g�����X�t�@�G���h */
#define INT_HEI7        137         /* DMAC�`���l��7 �n�[�t�G���h */
#define INT_USBI        140         /* USB�R���g���[�� */
#define INT_LCDCI       141         /* LCD�R���g���[�� */
#define INT_CMI0        142         /* CMT�`���l��0 �R���y�A�}�b�` */
#define INT_CMI1        143         /* CMT�`���l��1 �R���y�A�}�b�` */
#define INT_CMI         144         /* BSC ���t���b�V���^�C�}�R���y�A�}�b�` */
#define INT_ITI         145         /* WDT �C���^�[�o���^�C�}���荞�� */
#define INT_TGI0A       146         /* MTU2 TGRA0 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI0B       147         /* MTU2 TGRB0 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI0C       148         /* MTU2 TGRC0 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI0D       149         /* MTU2 TGRD0 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI0V       150         /* MTU2 TCNT0 �I�[�o�t���[ */
#define INT_TGI0E       151         /* MTU2 TGRE0 �R���y�A�}�b�` */
#define INT_TGI0F       152         /* MTU2 TGRF0 �R���y�A�}�b�` */
#define INT_TGI1A       153         /* MTU2 TGRA1 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI1B       154         /* MTU2 TGRB1 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI1V       155         /* MTU2 TCNT1 �I�[�o�t���[ */
#define INT_TGI1U       156         /* MTU2 TCNT1 �A���_�t���[ */
#define INT_TGI2A       157         /* MTU2 TGRA2 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI2B       158         /* MTU2 TGRA2 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI2V       159         /* MTU2 TCNT2 �I�[�o�t���[ */
#define INT_TGI2U       160         /* MTU2 TCNT2 �A���_�t���[ */
#define INT_TGI3A       161         /* MTU2 TGRA3 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI3B       162         /* MTU2 TGRB3 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI3C       163         /* MTU2 TGRC3 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI3D       164         /* MTU2 TGRD3 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI3V       165         /* MTU2 TCNT3 �I�[�o�t���[ */
#define INT_TGI4A       166         /* MTU2 TGRA4 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI4B       167         /* MTU2 TGRB4 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI4C       168         /* MTU2 TGRC4 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI4D       169         /* MTU2 TGRD4 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI4V       170         /* MTU2 TCNT4 �I�[�o�t���[�^�A���_�t���[ */
#define INT_ADI         171         /* A/D�ϊ��� �ϊ��I�� */
#define INT_IIC3STPI0   172         /* IIC3�`���l��0 ��~�������o */
#define INT_IIC3NAKI0   173         /* IIC3�`���l��0 NACK ���o */
#define INT_IIC3RXI0    174         /* IIC3�`���l��0 ��M�f�[�^�t�� */
#define INT_IIC3TXI0    175         /* IIC3�`���l��0 ���M�f�[�^�G���v�e�B */
#define INT_IIC3TEI0    176         /* IIC3�`���l��0 ���M�I�� */
#define INT_IIC3STPI1   177         /* IIC3�`���l��1 ��~�������o */
#define INT_IIC3NAKI1   178         /* IIC3�`���l��1 NACK ���o */
#define INT_IIC3RXI1    179         /* IIC3�`���l��1 ��M�f�[�^�t�� */
#define INT_IIC3TXI1    180         /* IIC3�`���l��1 ���M�f�[�^�G���v�e�B */
#define INT_IIC3TEI1    181         /* IIC3�`���l��1 ���M�I�� */
#define INT_IIC3STPI2   182         /* IIC3�`���l��2 ��~�������o */
#define INT_IIC3NAKI2   183         /* IIC3�`���l��2 NACK ���o */
#define INT_IIC3RXI2    184         /* IIC3�`���l��2 ��M�f�[�^�t�� */
#define INT_IIC3TXI2    185         /* IIC3�`���l��2 ���M�f�[�^�G���v�e�B */
#define INT_IIC3TEI2    186         /* IIC3�`���l��2 ���M�I�� */
#define INT_IIC3STPI3   187         /* IIC3�`���l��3 ��~�������o */
#define INT_IIC3NAKI3   188         /* IIC3�`���l��3 NACK ���o */
#define INT_IIC3RXI3    189         /* IIC3�`���l��3 ��M�f�[�^�t�� */
#define INT_IIC3TXI3    190         /* IIC3�`���l��3 ���M�f�[�^�G���v�e�B */
#define INT_IIC3TEI3    191         /* IIC3�`���l��3 ���M�I�� */
#define INT_BRI0        192         /* SCIF�`���l��0 �u���[�N���o */
#define INT_ERI0        193         /* SCIF�`���l��0 ��M�G���[ */
#define INT_RXI0        194         /* SCIF�`���l��0 ��M�f�[�^�t�� */
#define INT_TXI0        195         /* SCIF�`���l��0 ���MFIFO�f�[�^�G���v�e�B */
#define INT_BRI1        196         /* SCIF�`���l��1 �u���[�N���o */
#define INT_ERI1        197         /* SCIF�`���l��1 ��M�G���[ */
#define INT_RXI1        198         /* SCIF�`���l��1 ��M�f�[�^�t�� */
#define INT_TXI1        199         /* SCIF�`���l��1 ���MFIFO�f�[�^�G���v�e�B */
#define INT_BRI2        200         /* SCIF�`���l��2 �u���[�N���o */
#define INT_ERI2        201         /* SCIF�`���l��2 ��M�G���[ */
#define INT_RXI2        202         /* SCIF�`���l��2 ��M�f�[�^�t�� */
#define INT_TXI2        203         /* SCIF�`���l��2 ���MFIFO�f�[�^�G���v�e�B */
#define INT_BRI3        204         /* SCIF�`���l��3 �u���[�N���o */
#define INT_ERI3        205         /* SCIF�`���l��3 ��M�G���[ */
#define INT_RXI3        206         /* SCIF�`���l��3 ��M�f�[�^�t�� */
#define INT_TXI3        207         /* SCIF�`���l��3 ���MFIFO�f�[�^�G���v�e�B */
#define INT_SSERI0      208         /* SSU�`���l��0 �G���[ */
#define INT_SSRXI0      209         /* SSU�`���l��0 ��M�f�[�^�t�� */
#define INT_SSTXI0      210         /* SSU�`���l��0 ���M�f�[�^�G���v�e�B/���M�I�� */
#define INT_SSERI1      211         /* SSU�`���l��1 �G���[ */
#define INT_SSRXI1      212         /* SSU�`���l��1 ��M�f�[�^�t�� */
#define INT_SSTXI1      213         /* SSU�`���l��1 ���M�f�[�^�G���v�e�B/���M�I�� */
#define INT_SSI0        214         /* SSI�`���l��0 ���荞�� */
#define INT_SSI1        215         /* SSI�`���l��1 ���荞�� */
#define INT_SSI2        216         /* SSI�`���l��2 ���荞�� */
#define INT_SSI3        217         /* SSI�`���l��3 ���荞�� */
#define INT_ISY         218         /* CD-ROM�f�R�[�_ �����R�[�h�ُ�^�C�~���O */
#define INT_IERR        219         /* CD-ROM�f�R�[�_ ECC�G���[ */
#define INT_IARG        220         /* CD-ROM�f�R�[�_ ITARG���荞�� */
#define INT_ISEC        221         /* CD-ROM�f�R�[�_ �Z�N�^�؂�ւ�� */
#define INT_IBUF        222         /* CD-ROM�f�R�[�_ �o�b�t�@�f�[�^�]����ԑJ�� */
#define INT_IREDAY      223         /* CD-ROM�f�R�[�_ �o�b�t�@�f�[�^�]���v�� */
#define INT_FLSTEI      224         /* NAND�t���b�V���R���g���[�� STEI�v�������荞�� */
#define INT_FLTENDI     225         /* NAND�t���b�V���R���g���[�� �]���I�� */
#define INT_FLTREQ0I    226         /* NAND�t���b�V���R���g���[�� FIFO0�]���v�� */
#define INT_FLTREQ1I    227         /* NAND�t���b�V���R���g���[�� FIFO0�]���v�� */
#define INT_SDHI3       228         /* SD�z�X�g�C���^�[�t�F�[�X SDHI3���荞�� */
#define INT_SDHI0       229         /* SD�z�X�g�C���^�[�t�F�[�X SDHI0���荞�� */
#define INT_SDHI1       230         /* SD�z�X�g�C���^�[�t�F�[�X SDHI1���荞�� */
#define INT_ARM         231         /* RTC �A���[�����荞�� */
#define INT_PRD         232         /* RTC �������荞�� */
#define INT_CUP         233         /* RTC ���グ���荞�� */
#define INT_ERS0        234         /* RCAN�`���l��0 ERS�v�����荞�� */
#define INT_OVR0        235         /* RCAN�`���l��0 OVR�v�����荞�� */
#define INT_RM00        236         /* RCAN�`���l��0 �f�[�^�t���[����M */
#define INT_RM10        237         /* RCAN�`���l��0 �����[�g�t���[����M */
#define INT_SLE0        238         /* RCAN�`���l��0 ���b�Z�[�W���M */
#define INT_ERS1        239         /* RCAN�`���l��1 ERS�v�����荞�� */
#define INT_OVR1        240         /* RCAN�`���l��1 OVR�v�����荞�� */
#define INT_RM01        241         /* RCAN�`���l��1 �f�[�^�t���[����M */
#define INT_RM11        242         /* RCAN�`���l��1 �����[�g�t���[����M */
#define INT_SLE1        243         /* RCAN�`���l��1 ���b�Z�[�W���M */
#define INT_OVF         244         /* SRC �o�̓f�[�^FIFO�I�[�o�[���C�g */
#define INT_ODFI        245         /* SRC �o�̓f�[�^FIFO�t�� */
#define INT_IDEI        246         /* SRC ���̓f�[�^FIFO�G���v�e�B */
#define INT_IEBI        247         /* IEBus�R���g���[�� ���荞�� */

#ifndef _MACRO_ONLY

/*
 *  �������W���[���̃��W�X�^
 */
/* �L���b�V�� */
#define CCR1        ((VW *)0xFFFC1000)  /* �L���b�V�����䃌�W�X�^1 */
#define CCR2        ((VW *)0xFFFC1004)  /* �L���b�V�����䃌�W�X�^2 */

/* �N���b�N���U�� (CPG) */
#define FRQCR       ((VH *)0xFFFE0010)  /* ���g�����䃌�W�X�^ */

/* �o�X�X�e�[�g�R���g���[�� (BSC) */
#define CMNCR       ((VW *)0xFFFC0000)  /* ���ʃR���g���[�����W�X�^ */
#define CS0BCR      ((VW *)0xFFFC0004)  /* �G���A0 �o�X�R���g���[�����W�X�^ */
#define CS1BCR      ((VW *)0xFFFC0008)  /* �G���A1 �o�X�R���g���[�����W�X�^ */
#define CS2BCR      ((VW *)0xFFFC000C)  /* �G���A2 �o�X�R���g���[�����W�X�^ */
#define CS3BCR      ((VW *)0xFFFC0010)  /* �G���A3 �o�X�R���g���[�����W�X�^ */
#define CS4BCR      ((VW *)0xFFFC0014)  /* �G���A4 �o�X�R���g���[�����W�X�^ */
#define CS5BCR      ((VW *)0xFFFC0018)  /* �G���A5 �o�X�R���g���[�����W�X�^ */
#define CS6BCR      ((VW *)0xFFFC001C)  /* �G���A6 �o�X�R���g���[�����W�X�^ */
#define CS7BCR      ((VW *)0xFFFC0020)  /* �G���A7 �o�X�R���g���[�����W�X�^ */
#define CS0WCR      ((VW *)0xFFFC0028)  /* �G���A0 �E�F�C�g�R���g���[�����W�X�^ */
#define CS1WCR      ((VW *)0xFFFC002C)  /* �G���A1 �E�F�C�g�R���g���[�����W�X�^ */
#define CS2WCR      ((VW *)0xFFFC0030)  /* �G���A2 �E�F�C�g�R���g���[�����W�X�^ */
#define CS3WCR      ((VW *)0xFFFC0034)  /* �G���A3 �E�F�C�g�R���g���[�����W�X�^ */
#define CS4WCR      ((VW *)0xFFFC0038)  /* �G���A4 �E�F�C�g�R���g���[�����W�X�^ */
#define CS5WCR      ((VW *)0xFFFC003C)  /* �G���A5 �E�F�C�g�R���g���[�����W�X�^ */
#define CS6WCR      ((VW *)0xFFFC0040)  /* �G���A6 �E�F�C�g�R���g���[�����W�X�^ */
#define CS7WCR      ((VW *)0xFFFC0044)  /* �G���A7 �E�F�C�g�R���g���[�����W�X�^ */
#define SDCR        ((VW *)0xFFFC004C)  /* SDRAM�R���g���[�����W�X�^ */
#define RTCSR       ((VW *)0xFFFC0050)  /* ���t���b�V���^�C�}�R���g���[��/�X�e�[�^�X���W�X�^ */
#define RTCNT       ((VW *)0xFFFC0054)  /* ���t���b�V���^�C�}�J�E���^ */
#define RTCOR       ((VW *)0xFFFC0058)  /* ���t���b�V���^�C���R���X�^���g���W�X�^ */

/* ���荞�݃R���g���[�� (INTC) */
#define ICR0        ((VH *)0xFFFE0800)  /* ���荞�݃R���g���[�����W�X�^0 */
#define ICR1        ((VH *)0xFFFE0802)  /* ���荞�݃R���g���[�����W�X�^1 */
#define ICR2        ((VH *)0xFFFE0804)  /* ���荞�݃R���g���[�����W�X�^2 */
#define IRQRR       ((VH *)0xFFFE0806)  /* IRQ ���荞�ݗv�����W�X�^ */
#define PINTER      ((VH *)0xFFFE0808)  /* PINT ���荞�݃C�l�[�u�����W�X�^ */
#define PIRR        ((VH *)0xFFFE080A)  /* PINT ���荞�ݗv�����W�X�^ */
#define IBCR        ((VH *)0xFFFE080C)  /* �o���N�R���g���[�����W�X�^ */
#define IBNR        ((VH *)0xFFFE080E)  /* �o���N�ԍ����W�X�^ */
#define IPR01       ((VH *)0xFFFE0818)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^01 */
#define IPR02       ((VH *)0xFFFE081A)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^02 */
#define IPR05       ((VH *)0xFFFE0820)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^05 */
#define IPR06       ((VH *)0xFFFE0C00)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^06 */
#define IPR07       ((VH *)0xFFFE0C02)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^07 */
#define IPR08       ((VH *)0xFFFE0C04)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^08 */
#define IPR09       ((VH *)0xFFFE0C06)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^09 */
#define IPR10       ((VH *)0xFFFE0C08)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^10 */
#define IPR11       ((VH *)0xFFFE0C0A)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^11 */
#define IPR12       ((VH *)0xFFFE0C0C)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^12 */
#define IPR13       ((VH *)0xFFFE0C0E)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^13 */
#define IPR14       ((VH *)0xFFFE0C10)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^14 */
#define IPR16       ((VH *)0xFFFE0C12)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^15 */
#define IPR15       ((VH *)0xFFFE0C14)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^16 */
#define IPR17       ((VH *)0xFFFE0C16)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^17 */

/* �R���y�A�}�b�`�^�C�} (CMT) */
#define CMSTR       ((VH *)0xFFFEC000)  /* �R���y�A�}�b�`�^�C�}�X�^�[�g���W�X�^ */
#define CMCSR_0     ((VH *)0xFFFEC002)  /* �`���l��0 �R���y�A�}�b�`�J�E���^�R���g���[��/�X�e�[�^�X���W�X�^ */
#define CMCNT_0     ((VH *)0xFFFEC004)  /* �`���l��0 �R���y�A�}�b�`�J�E���^ */
#define CMCOR_0     ((VH *)0xFFFEC006)  /* �`���l��0 �R���y�A�}�b�`�R���X�^���g���W�X�^ */
#define CMCSR_1     ((VH *)0xFFFEC008)  /* �`���l��1 �R���y�A�}�b�`�J�E���^�R���g���[��/�X�e�[�^�X���W�X�^ */
#define CMCNT_1     ((VH *)0xFFFEC00A)  /* �`���l��1 �R���y�A�}�b�`�J�E���^ */
#define CMCOR_1     ((VH *)0xFFFEC00C)  /* �`���l��1 �R���y�A�}�b�`�R���X�^���g���W�X�^ */

/* �s���t�@���N�V�����R���g���[�� (PFC), I/O�|�[�g */
#define PADRL       ((VH *)0xFFFE3802)  /* �|�[�gA �f�[�^���W�X�^L */
#define PBCRL       ((VH *)0xFFFE3882)  /* �|�[�gB �f�[�^���W�X�^L */
#define PBIORL      ((VH *)0xFFFE3886)  /* �|�[�gB IO���W�X�^L */
#define PBCRL4      ((VH *)0xFFFE3890)  /* �|�[�gB �R���g���[�����W�X�^L4 */
#define PBCRL3      ((VH *)0xFFFE3892)  /* �|�[�gB �R���g���[�����W�X�^L3 */
#define PBCRL2      ((VH *)0xFFFE3894)  /* �|�[�gB �R���g���[�����W�X�^L2 */
#define PBCRL1      ((VH *)0xFFFE3896)  /* �|�[�gB �R���g���[�����W�X�^L1 */
#define PBPRL       ((VH *)0xFFFE389E)  /* �|�[�gB �|�[�g���W�X�^L */
#define IFCR        ((VH *)0xFFFE38A2)  /* IRQOUT�@�\�R���g���[�����W�X�^ */
#define PCCRL       ((VH *)0xFFFE3902)  /* �|�[�gC �f�[�^���W�X�^L */
#define PCIORL      ((VH *)0xFFFE3906)  /* �|�[�gC IO���W�X�^L */
#define PCCRL4      ((VH *)0xFFFE3910)  /* �|�[�gC �R���g���[�����W�X�^L4 */
#define PCCRL3      ((VH *)0xFFFE3912)  /* �|�[�gC �R���g���[�����W�X�^L3 */
#define PCCRL2      ((VH *)0xFFFE3914)  /* �|�[�gC �R���g���[�����W�X�^L2 */
#define PCCRL1      ((VH *)0xFFFE3916)  /* �|�[�gC �R���g���[�����W�X�^L1 */
#define PCPRL       ((VH *)0xFFFE391E)  /* �|�[�gC �|�[�g���W�X�^L */
#define PDCRL       ((VH *)0xFFFE3982)  /* �|�[�gD �f�[�^���W�X�^L */
#define PDIORL      ((VH *)0xFFFE3986)  /* �|�[�gD IO���W�X�^L */
#define PDCRL4      ((VH *)0xFFFE3990)  /* �|�[�gD �R���g���[�����W�X�^L4 */
#define PDCRL3      ((VH *)0xFFFE3992)  /* �|�[�gD �R���g���[�����W�X�^L3 */
#define PDCRL2      ((VH *)0xFFFE3994)  /* �|�[�gD �R���g���[�����W�X�^L2 */
#define PDCRL1      ((VH *)0xFFFE3996)  /* �|�[�gD �R���g���[�����W�X�^L1 */
#define PDPRL       ((VH *)0xFFFE399E)  /* �|�[�gD �|�[�g���W�X�^L */
#define PECRL       ((VH *)0xFFFE3A02)  /* �|�[�gE �f�[�^���W�X�^L */
#define PEIORL      ((VH *)0xFFFE3A06)  /* �|�[�gE IO���W�X�^L */
#define PECRL4      ((VH *)0xFFFE3A10)  /* �|�[�gE �R���g���[�����W�X�^L4 */
#define PECRL3      ((VH *)0xFFFE3A12)  /* �|�[�gE �R���g���[�����W�X�^L3 */
#define PECRL2      ((VH *)0xFFFE3A14)  /* �|�[�gE �R���g���[�����W�X�^L2 */
#define PECRL1      ((VH *)0xFFFE3A16)  /* �|�[�gE �R���g���[�����W�X�^L1 */
#define PEPRL       ((VH *)0xFFFE3A1E)  /* �|�[�gE �|�[�g���W�X�^L */
#define PFCRH       ((VH *)0xFFFE3A80)  /* �|�[�gE �f�[�^���W�X�^H */
#define PFCRL       ((VH *)0xFFFE3A82)  /* �|�[�gE �f�[�^���W�X�^L */
#define PFIORH      ((VH *)0xFFFE3A84)  /* �|�[�gF IO���W�X�^H */
#define PFIORL      ((VH *)0xFFFE3A86)  /* �|�[�gF IO���W�X�^L */
#define PFCRH4      ((VH *)0xFFFE3A88)  /* �|�[�gF �R���g���[�����W�X�^H4 */
#define PFCRH3      ((VH *)0xFFFE3A8A)  /* �|�[�gF �R���g���[�����W�X�^H3 */
#define PFCRH2      ((VH *)0xFFFE3A8C)  /* �|�[�gF �R���g���[�����W�X�^H2 */
#define PFCRH1      ((VH *)0xFFFE3A8E)  /* �|�[�gF �R���g���[�����W�X�^H1 */
#define PFCRL4      ((VH *)0xFFFE3A90)  /* �|�[�gF �R���g���[�����W�X�^L4 */
#define PFCRL3      ((VH *)0xFFFE3A92)  /* �|�[�gF �R���g���[�����W�X�^L3 */
#define PFCRL2      ((VH *)0xFFFE3A94)  /* �|�[�gF �R���g���[�����W�X�^L2 */
#define PFCRL1      ((VH *)0xFFFE3A96)  /* �|�[�gF �R���g���[�����W�X�^L1 */
#define PFPRH       ((VH *)0xFFFE3A9C)  /* �|�[�gE �|�[�g���W�X�^H */
#define PFPRL       ((VH *)0xFFFE3A9E)  /* �|�[�gE �|�[�g���W�X�^L */
#define SCSR        ((VH *)0xFFFE3AA2)  /* SSI�N���b�N�I�����W�X�^ */

/* �����d�̓��[�h */
#define STBCR       ((VB *)0xFFFE0014)  /* �X�^���o�C�R���g���[�����W�X�^ */
#define STBCR2      ((VB *)0xFFFE0018)  /* �X�^���o�C�R���g���[�����W�X�^2 */
#define STBCR3      ((VB *)0xFFFE0408)  /* �X�^���o�C�R���g���[�����W�X�^3 */
#define STBCR4      ((VB *)0xFFFE040C)  /* �X�^���o�C�R���g���[�����W�X�^4 */
#define STBCR5      ((VB *)0xFFFE0410)  /* �X�^���o�C�R���g���[�����W�X�^5 */
#define STBCR6      ((VB *)0xFFFE0414)  /* �X�^���o�C�R���g���[�����W�X�^6 */
#define SYSCR1      ((VB *)0xFFFE0402)  /* �V�X�e���R���g���[�����W�X�^1 */
#define SYSCR2      ((VB *)0xFFFE0404)  /* �V�X�e���R���g���[�����W�X�^2 */
#define SYSCR3      ((VB *)0xFFFE0418)  /* �V�X�e���R���g���[�����W�X�^3 */
#define DSCTR       ((VB *)0xFFFE2800)  /* �f�B�[�v�X�^���o�C�R���g���[�����W�X�^ */
#define DSCTR2      ((VB *)0xFFFE2802)  /* �f�B�[�v�X�^���o�C�R���g���[�����W�X�^2 */
#define DSSSR       ((VH *)0xFFFE2804)  /* �f�B�[�v�X�^���o�C�����v���Z���N�g���W�X�^ */
#define DSFR        ((VH *)0xFFFE2808)  /* �f�B�[�v�X�^���o�C�����G�b�W�Z���N�g���W�X�^ */
#define DSRTR       ((VB *)0xFFFE280C)  /* �ێ��p����RAM�g���~���O���W�X�^ */

/* FIFO�t���V���A���R�~���j�P�[�V�����C���^�[�t�F�[�X (SCIF) */

#define SCIF0_BASE  ((UW)0xFFFE8000)    /* �`���l��0 ���W�X�^�x�[�X�A�h���X */
#define SCIF1_BASE  ((UW)0xFFFE8800)    /* �`���l��1 ���W�X�^�x�[�X�A�h���X */
#define SCIF2_BASE  ((UW)0xFFFE9000)    /* �`���l��2 ���W�X�^�x�[�X�A�h���X */
#define SCIF3_BASE  ((UW)0xFFFE9800)    /* �`���l��3 ���W�X�^�x�[�X�A�h���X */

/*
 * ���荞�݃R���g���[���̏�����
 */
Inline void sh2_init_intcontorller(void)
{
	/* �o���N�ԍ����W�X�^�̐ݒ� */
	sil_wrh_mem(IBNR, 0x0000);		/* BE=00, BOVE=0                         */
									/*  ���ׂĂ̊��荞�݂Ńo���N�g�p�֎~     */
									/*  ���W�X�^�o���N�I�[�o�[�t���[��O�֎~ */
	/* ���荞�ݗD�惌�x���ݒ背�W�X�^�������� */
	sil_wrh_mem (IPR01, 0x0000);
	sil_wrh_mem (IPR02, 0x0000);
	sil_wrh_mem (IPR05, 0x0000);
	sil_wrh_mem (IPR06, 0x0000);
	sil_wrh_mem (IPR07, 0x0000);
	sil_wrh_mem (IPR08, 0x0000);
	sil_wrh_mem (IPR09, 0x0000);
	sil_wrh_mem (IPR10, 0x0000);
	sil_wrh_mem (IPR11, 0x0000);
	sil_wrh_mem (IPR12, 0x0000);
	sil_wrh_mem (IPR13, 0x0000);
	sil_wrh_mem (IPR14, 0x0000);
	sil_wrh_mem (IPR15, 0x0000);
	sil_wrh_mem (IPR16, 0x0000);
	sil_wrh_mem (IPR17, 0x0000);
}

#endif /* _MACRO_ONLY */

#endif /* _SH7263_H_ */
