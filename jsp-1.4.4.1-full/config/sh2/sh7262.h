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

#ifndef _SH7262_H_
#define _SH7262_H_

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
#define INT_DEI8        140         /* DMAC�`���l��8 �g�����X�t�@�G���h */
#define INT_HEI8        141         /* DMAC�`���l��8 �n�[�t�G���h */
#define INT_DEI9        144         /* DMAC�`���l��9 �g�����X�t�@�G���h */
#define INT_HEI9        145         /* DMAC�`���l��9 �n�[�t�G���h */
#define INT_DEI10       148         /* DMAC�`���l��10 �g�����X�t�@�G���h */
#define INT_HEI10       149         /* DMAC�`���l��10 �n�[�t�G���h */
#define INT_DEI11       152         /* DMAC�`���l��11 �g�����X�t�@�G���h */
#define INT_HEI11       153         /* DMAC�`���l��11 �n�[�t�G���h */
#define INT_DEI12       156         /* DMAC�`���l��12 �g�����X�t�@�G���h */
#define INT_HEI12       157         /* DMAC�`���l��12 �n�[�t�G���h */
#define INT_DEI13       160         /* DMAC�`���l��13 �g�����X�t�@�G���h */
#define INT_HEI13       161         /* DMAC�`���l��13 �n�[�t�G���h */
#define INT_DEI14       164         /* DMAC�`���l��14 �g�����X�t�@�G���h */
#define INT_HEI14       165         /* DMAC�`���l��14 �n�[�t�G���h */
#define INT_DEI15       168         /* DMAC�`���l��15 �g�����X�t�@�G���h */
#define INT_HEI15       169         /* DMAC�`���l��15 �n�[�t�G���h */
#define INT_USBI        170         /* USB�R���g���[�� */
#define INT_VIVSYNCJ    171         /* �r�f�I�f�B�X�v���C�R���g���[��3 VSYNC�������ꌟ�o */
#define INT_VBUFFER     172         /* �r�f�I�f�B�X�v���C�R���g���[��3 �o�b�t�@�G���[ */
#define INT_VIFIELDE    173         /* �r�f�I�f�B�X�v���C�R���g���[��3 �t�B�[���h�������݊��� */
#define INT_VOLINE      174         /* �r�f�I�f�B�X�v���C�R���g���[��3 ���C�����荞�� */
#define INT_CMI0        175         /* CMT�`���l��0 �R���y�A�}�b�` */
#define INT_CMI1        176         /* CMT�`���l��1 �R���y�A�}�b�` */
#define INT_CMI         177         /* BSC ���t���b�V���^�C�}�R���y�A�}�b�` */
#define INT_ITI         178         /* WDT �C���^�[�o���^�C�}���荞�� */
#define INT_TGI0A       179         /* MTU2 TGRA0 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI0B       180         /* MTU2 TGRB0 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI0C       181         /* MTU2 TGRC0 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI0D       182         /* MTU2 TGRD0 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI0V       183         /* MTU2 TCNT0 �I�[�o�t���[ */
#define INT_TGI0E       184         /* MTU2 TGRE0 �R���y�A�}�b�` */
#define INT_TGI0F       185         /* MTU2 TGRF0 �R���y�A�}�b�` */
#define INT_TGI1A       186         /* MTU2 TGRA1 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI1B       187         /* MTU2 TGRB1 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI1V       188         /* MTU2 TCNT1 �I�[�o�t���[ */
#define INT_TGI1U       189         /* MTU2 TCNT1 �A���_�t���[ */
#define INT_TGI2A       190         /* MTU2 TGRA2 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI2B       191         /* MTU2 TGRA2 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI2V       192         /* MTU2 TCNT2 �I�[�o�t���[ */
#define INT_TGI2U       193         /* MTU2 TCNT2 �A���_�t���[ */
#define INT_TGI3A       194         /* MTU2 TGRA3 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI3B       195         /* MTU2 TGRB3 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI3C       196         /* MTU2 TGRC3 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI3D       197         /* MTU2 TGRD3 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI3V       198         /* MTU2 TCNT3 �I�[�o�t���[ */
#define INT_TGI4A       199         /* MTU2 TGRA4 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI4B       200         /* MTU2 TGRB4 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI4C       201         /* MTU2 TGRC4 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI4D       202         /* MTU2 TGRD4 �C���v�b�g�L���v�`���^�R���y�A�}�b�` */
#define INT_TGI4V       203         /* MTU2 TCNT4 �I�[�o�t���[�^�A���_�t���[ */
#define INT_CMF1        204         /* PWM�`���l��1 �R���y�A�}�b�`�t���O */
#define INT_CMF2        205         /* PWM�`���l��2 �R���y�A�}�b�`�t���O */
#define INT_ADI         206         /* A/D�ϊ��� �ϊ��I�� */
#define INT_SSIF0       207         /* SSI�`���l��0 SSIF0 */
#define INT_SSIRXI0     208         /* SSI�`���l��0 SSIRXI0 */
#define INT_SSITXI0     209         /* SSI�`���l��0 SSITXI0 */
#define INT_SSII1       210         /* SSI�`���l��1 SSII1 */
#define INT_SSIRTI1     211         /* SSI�`���l��1 SSIRTI1 */
#define INT_SSII2       212         /* SSI�`���l��2 SSII2 */
#define INT_SSIRTI2     213         /* SSI�`���l��2 SSIRTI2 */
#define INT_SSII3       214         /* SSI�`���l��3 SSII2 */
#define INT_SSIRTI3     215         /* SSI�`���l��3 SSIRTI2 */
#define INT_SPDIFI      216         /* SPDIF�C���^�[�t�F�[�X���荞�� */
#define INT_IIC3STPI0   217         /* IIC3�`���l��0 ��~�������o */
#define INT_IIC3NAKI0   218         /* IIC3�`���l��0 NACK ���o */
#define INT_IIC3RXI0    219         /* IIC3�`���l��0 ��M�f�[�^�t�� */
#define INT_IIC3TXI0    220         /* IIC3�`���l��0 ���M�f�[�^�G���v�e�B */
#define INT_IIC3TEI0    221         /* IIC3�`���l��0 ���M�I�� */
#define INT_IIC3STPI1   222         /* IIC3�`���l��1 ��~�������o */
#define INT_IIC3NAKI1   223         /* IIC3�`���l��1 NACK ���o */
#define INT_IIC3RXI1    224         /* IIC3�`���l��1 ��M�f�[�^�t�� */
#define INT_IIC3TXI1    225         /* IIC3�`���l��1 ���M�f�[�^�G���v�e�B */
#define INT_IIC3TEI1    226         /* IIC3�`���l��1 ���M�I�� */
#define INT_IIC3STPI2   227         /* IIC3�`���l��2 ��~�������o */
#define INT_IIC3NAKI2   228         /* IIC3�`���l��2 NACK ���o */
#define INT_IIC3RXI2    229         /* IIC3�`���l��2 ��M�f�[�^�t�� */
#define INT_IIC3TXI2    230         /* IIC3�`���l��2 ���M�f�[�^�G���v�e�B */
#define INT_IIC3TEI2    231         /* IIC3�`���l��2 ���M�I�� */
#define INT_BRI0        232         /* SCIF�`���l��0 �u���[�N���o */
#define INT_ERI0        233         /* SCIF�`���l��0 ��M�G���[ */
#define INT_RXI0        234         /* SCIF�`���l��0 ��M�f�[�^�t�� */
#define INT_TXI0        235         /* SCIF�`���l��0 ���MFIFO�f�[�^�G���v�e�B */
#define INT_BRI1        236         /* SCIF�`���l��1 �u���[�N���o */
#define INT_ERI1        237         /* SCIF�`���l��1 ��M�G���[ */
#define INT_RXI1        238         /* SCIF�`���l��1 ��M�f�[�^�t�� */
#define INT_TXI1        239         /* SCIF�`���l��1 ���MFIFO�f�[�^�G���v�e�B */
#define INT_BRI2        240         /* SCIF�`���l��2 �u���[�N���o */
#define INT_ERI2        241         /* SCIF�`���l��2 ��M�G���[ */
#define INT_RXI2        242         /* SCIF�`���l��2 ��M�f�[�^�t�� */
#define INT_TXI2        243         /* SCIF�`���l��2 ���MFIFO�f�[�^�G���v�e�B */
#define INT_BRI3        244         /* SCIF�`���l��3 �u���[�N���o */
#define INT_ERI3        245         /* SCIF�`���l��3 ��M�G���[ */
#define INT_RXI3        246         /* SCIF�`���l��3 ��M�f�[�^�t�� */
#define INT_TXI3        247         /* SCIF�`���l��3 ���MFIFO�f�[�^�G���v�e�B */
#define INT_BRI4        248         /* SCIF�`���l��4 �u���[�N���o */
#define INT_ERI4        249         /* SCIF�`���l��4 ��M�G���[ */
#define INT_RXI4        250         /* SCIF�`���l��4 ��M�f�[�^�t�� */
#define INT_TXI4        251         /* SCIF�`���l��4 ���MFIFO�f�[�^�G���v�e�B */
#define INT_BRI5        252         /* SCIF�`���l��5 �u���[�N���o */
#define INT_ERI5        253         /* SCIF�`���l��5 ��M�G���[ */
#define INT_RXI5        254         /* SCIF�`���l��5 ��M�f�[�^�t�� */
#define INT_TXI5        255         /* SCIF�`���l��5 ���MFIFO�f�[�^�G���v�e�B */
#define INT_BRI6        256         /* SCIF�`���l��6 �u���[�N���o */
#define INT_ERI6        257         /* SCIF�`���l��6 ��M�G���[ */
#define INT_RXI6        258         /* SCIF�`���l��6 ��M�f�[�^�t�� */
#define INT_TXI6        259         /* SCIF�`���l��6 ���MFIFO�f�[�^�G���v�e�B */
#define INT_BRI7        260         /* SCIF�`���l��7 �u���[�N���o */
#define INT_ERI7        261         /* SCIF�`���l��7 ��M�G���[ */
#define INT_RXI7        262         /* SCIF�`���l��7 ��M�f�[�^�t�� */
#define INT_TXI7        263         /* SCIF�`���l��7 ���MFIFO�f�[�^�G���v�e�B */
#define INT_SIOFI       264         /* SIOF���荞�� */
#define INT_SPEI0       265         /* SPI�`���l��0 �G���[ */
#define INT_SPRI0       266         /* SPI�`���l��0 ��M�o�b�t�@�t�� */
#define INT_SPTI0       267         /* SPI�`���l��0 ���M�G���v�e�B*/
#define INT_SPEI1       268         /* SPI�`���l��1 �G���[ */
#define INT_SPRI1       269         /* SPI�`���l��1 ��M�o�b�t�@�t�� */
#define INT_SPTI1       270         /* SPI�`���l��1 ���M�G���v�e�B*/
#define INT_ERS0        271         /* RCAN�`���l��0 ERS�v�����荞�� */
#define INT_OVR0        272         /* RCAN�`���l��0 OVR�v�����荞�� */
#define INT_RM00        273         /* RCAN�`���l��0 �f�[�^�t���[����M */
#define INT_RM10        274         /* RCAN�`���l��0 �����[�g�t���[����M */
#define INT_SLE0        275         /* RCAN�`���l��0 ���b�Z�[�W���M */
#define INT_ERS1        276         /* RCAN�`���l��1 ERS�v�����荞�� */
#define INT_OVR1        277         /* RCAN�`���l��1 OVR�v�����荞�� */
#define INT_RM01        278         /* RCAN�`���l��1 �f�[�^�t���[����M */
#define INT_RM11        279         /* RCAN�`���l��1 �����[�g�t���[����M */
#define INT_SLE1        280         /* RCAN�`���l��1 ���b�Z�[�W���M */
#define INT_IEBI        281         /* IEBus�R���g���[�����荞�� */
#define INT_ISY         282         /* CD-ROM�f�R�[�_ �����R�[�h�ُ�^�C�~���O */
#define INT_IERR        283         /* CD-ROM�f�R�[�_ ECC�G���[ */
#define INT_IARG        284         /* CD-ROM�f�R�[�_ ITARG�G���[���荞�� */
#define INT_ISEC        285         /* CD-ROM�f�R�[�_ �Z�N�^�؂�ւ�� */
#define INT_IBUF        286         /* CD-ROM�f�R�[�_ �o�b�t�@�f�[�^�]����ԑJ�� */
#define INT_IREDAY      287         /* CD-ROM�f�R�[�_ �o�b�t�@�f�[�^�]���v�� */
#define INT_FLSTEI      288         /* NAND�t���b�V���R���g���[�� STEI�v�������荞�� */
#define INT_FLTENDI     289         /* NAND�t���b�V���R���g���[�� �]���I�� */
#define INT_FLTREQ0I    290         /* NAND�t���b�V���R���g���[�� FIFO0�]���v�� */
#define INT_FLTREQ1I    291         /* NAND�t���b�V���R���g���[�� FIFO0�]���v�� */
#define INT_SDHI3       292         /* SD�z�X�g�C���^�[�t�F�[�X SDHI3���荞�� */
#define INT_SDHI0       293         /* SD�z�X�g�C���^�[�t�F�[�X SDHI0���荞�� */
#define INT_SDHI1       294         /* SD�z�X�g�C���^�[�t�F�[�X SDHI1���荞�� */
#define INT_ARM         296         /* RTC �A���[�����荞�� */
#define INT_PRD         297         /* RTC �������荞�� */
#define INT_CUP         298         /* RTC ���グ���荞�� */
#define INT_OVF0        299         /* SRC�`���l��0 �o�̓f�[�^FIFO�I�[�o�[���C�g */
#define INT_UDF0        300         /* SRC�`���l��0 �o�̓f�[�^FIFO�A���_�[�t���[ */
#define INT_CEF0        301         /* SRC�`���l��0 �ϊ������I�� */
#define INT_ODFI0       302         /* SRC�`���l��0 �o�̓f�[�^FIFO�t�� */
#define INT_IDEI0       303         /* SRC�`���l��0 �o�̓f�[�^FIFO�G���v�e�B */
#define INT_OVF1        304         /* SRC�`���l��1 �o�̓f�[�^FIFO�I�[�o�[���C�g */
#define INT_UDF1        305         /* SRC�`���l��1 �o�̓f�[�^FIFO�A���_�[�t���[ */
#define INT_CEF1        306         /* SRC�`���l��1 �ϊ������I�� */
#define INT_ODFI1       307         /* SRC�`���l��1 �o�̓f�[�^FIFO�t�� */
#define INT_IDEI1       308         /* SRC�`���l��1 �o�̓f�[�^FIFO�G���v�e�B */
#define INT_DCUEI       310         /* �f�R���v���b�V�������j�b�g DCUEI���荞�� */
#define INT_OFFI        311         /* �f�R���v���b�V�������j�b�g OFFI���荞�� */
#define INT_IFEI        312         /* �f�R���v���b�V�������j�b�g IFEI���荞�� */

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
#define ACSWR       ((VW *)0xFFFC180C)  /* AC�����؂�ւ����W�X�^ */
#define ACKEYR      ((VB *)0xFFFC1BFC)  /* AC�����؂�ւ��L�[���W�X�^ */

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
#define IPR18       ((VH *)0xFFFE0C18)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^18 */
#define IPR19       ((VH *)0xFFFE0C1A)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^19 */
#define IPR20       ((VH *)0xFFFE0C1C)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^20 */
#define IPR21       ((VH *)0xFFFE0C1E)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^21 */
#define IPR22       ((VH *)0xFFFE0C20)  /* ���荞�ݗD�惌�x���ݒ背�W�X�^22 */

/* �R���y�A�}�b�`�^�C�} (CMT) */
#define CMSTR       ((VH *)0xFFFEC000)  /* �R���y�A�}�b�`�^�C�}�X�^�[�g���W�X�^ */
#define CMCSR_0     ((VH *)0xFFFEC002)  /* �`���l��0 �R���y�A�}�b�`�J�E���^�R���g���[��/�X�e�[�^�X���W�X�^ */
#define CMCNT_0     ((VH *)0xFFFEC004)  /* �`���l��0 �R���y�A�}�b�`�J�E���^ */
#define CMCOR_0     ((VH *)0xFFFEC006)  /* �`���l��0 �R���y�A�}�b�`�R���X�^���g���W�X�^ */
#define CMCSR_1     ((VH *)0xFFFEC008)  /* �`���l��1 �R���y�A�}�b�`�J�E���^�R���g���[��/�X�e�[�^�X���W�X�^ */
#define CMCNT_1     ((VH *)0xFFFEC00A)  /* �`���l��1 �R���y�A�}�b�`�J�E���^ */
#define CMCOR_1     ((VH *)0xFFFEC00C)  /* �`���l��1 �R���y�A�}�b�`�R���X�^���g���W�X�^ */

/* �s���t�@���N�V�����R���g���[�� (PFC), I/O�|�[�g */
#define PAIOR0      ((VH *)0xFFFE3812)  /* �|�[�gA IO���W�X�^0 */
#define PADR1       ((VH *)0xFFFE3814)  /* �|�[�gA �f�[�^���W�X�^1 */
#define PADR0       ((VH *)0xFFFE3816)  /* �|�[�gA �f�[�^���W�X�^0 */
#define PAPR0       ((VH *)0xFFFE381A)  /* �|�[�gA �|�[�g���W�X�^0 */
#define PBCR5       ((VH *)0xFFFE3824)  /* �|�[�gB �R���g���[�����W�X�^5 */
#define PBCR4       ((VH *)0xFFFE3826)  /* �|�[�gB �R���g���[�����W�X�^4 */
#define PBCR3       ((VH *)0xFFFE3828)  /* �|�[�gB �R���g���[�����W�X�^3 */
#define PBCR2       ((VH *)0xFFFE382A)  /* �|�[�gB �R���g���[�����W�X�^2 */
#define PBCR1       ((VH *)0xFFFE382C)  /* �|�[�gB �R���g���[�����W�X�^1 */
#define PBCR0       ((VH *)0xFFFE382E)  /* �|�[�gB �R���g���[�����W�X�^0 */
#define PBIOR1      ((VH *)0xFFFE3830)  /* �|�[�gB IO���W�X�^1 */
#define PBIOR0      ((VH *)0xFFFE3832)  /* �|�[�gB IO���W�X�^0 */
#define PBDR1       ((VH *)0xFFFE3834)  /* �|�[�gB �f�[�^���W�X�^1 */
#define PBDR0       ((VH *)0xFFFE3836)  /* �|�[�gB �f�[�^���W�X�^0 */
#define PBPR1       ((VH *)0xFFFE3838)  /* �|�[�gB �|�[�g���W�X�^1 */
#define PBPR0       ((VH *)0xFFFE383A)  /* �|�[�gB �|�[�g���W�X�^1 */
#define PCCR2       ((VH *)0xFFFE384A)  /* �|�[�gC �R���g���[�����W�X�^2 */
#define PCCR1       ((VH *)0xFFFE384C)  /* �|�[�gC �R���g���[�����W�X�^1 */
#define PCCR0       ((VH *)0xFFFE384E)  /* �|�[�gC �R���g���[�����W�X�^0 */
#define PCIOR0      ((VH *)0xFFFE3852)  /* �|�[�gC IO���W�X�^0 */
#define PCDR0       ((VH *)0xFFFE3856)  /* �|�[�gC �f�[�^���W�X�^0 */
#define PCPR0       ((VH *)0xFFFE385A)  /* �|�[�gC �|�[�g���W�X�^1 */
#define PDCR3       ((VH *)0xFFFE3868)  /* �|�[�gD �R���g���[�����W�X�^3 */
#define PDCR2       ((VH *)0xFFFE386A)  /* �|�[�gD �R���g���[�����W�X�^2 */
#define PDCR1       ((VH *)0xFFFE386C)  /* �|�[�gD �R���g���[�����W�X�^1 */
#define PDCR0       ((VH *)0xFFFE386E)  /* �|�[�gD �R���g���[�����W�X�^0 */
#define PDIOR0      ((VH *)0xFFFE3872)  /* �|�[�gD IO���W�X�^0 */
#define PDDR0       ((VH *)0xFFFE3876)  /* �|�[�gD �f�[�^���W�X�^0 */
#define PDPR0       ((VH *)0xFFFE387A)  /* �|�[�gD �|�[�g���W�X�^1 */
#define PECR1       ((VH *)0xFFFE388C)  /* �|�[�gD �R���g���[�����W�X�^1 */
#define PECR0       ((VH *)0xFFFE388E)  /* �|�[�gD �R���g���[�����W�X�^0 */
#define PEIOR0      ((VH *)0xFFFE3892)  /* �|�[�gD IO���W�X�^0 */
#define PEDR0       ((VH *)0xFFFE3896)  /* �|�[�gD �f�[�^���W�X�^0 */
#define PEPR0       ((VH *)0xFFFE389A)  /* �|�[�gD �|�[�g���W�X�^1 */
#define PFCR3       ((VH *)0xFFFE38A8)  /* �|�[�gF �R���g���[�����W�X�^3 */
#define PFCR2       ((VH *)0xFFFE38AA)  /* �|�[�gF �R���g���[�����W�X�^2 */
#define PFCR1       ((VH *)0xFFFE38AC)  /* �|�[�gF �R���g���[�����W�X�^1 */
#define PFCR0       ((VH *)0xFFFE38AE)  /* �|�[�gF �R���g���[�����W�X�^0 */
#define PFIOR0      ((VH *)0xFFFE38B2)  /* �|�[�gF IO���W�X�^0 */
#define PFDR0       ((VH *)0xFFFE38B6)  /* �|�[�gF �f�[�^���W�X�^0 */
#define PFPR0       ((VH *)0xFFFE38BA)  /* �|�[�gF �|�[�g���W�X�^1 */
#define PGCR7       ((VH *)0xFFFE38C0)  /* �|�[�gG �R���g���[�����W�X�^5 */
#define PGCR6       ((VH *)0xFFFE38C2)  /* �|�[�gG �R���g���[�����W�X�^5 */
#define PGCR5       ((VH *)0xFFFE38C4)  /* �|�[�gG �R���g���[�����W�X�^5 */
#define PGCR4       ((VH *)0xFFFE38C6)  /* �|�[�gG �R���g���[�����W�X�^4 */
#define PGCR3       ((VH *)0xFFFE38C8)  /* �|�[�gG �R���g���[�����W�X�^3 */
#define PGCR2       ((VH *)0xFFFE38CA)  /* �|�[�gG �R���g���[�����W�X�^2 */
#define PGCR1       ((VH *)0xFFFE38CC)  /* �|�[�gG �R���g���[�����W�X�^1 */
#define PGCR0       ((VH *)0xFFFE38CE)  /* �|�[�gG �R���g���[�����W�X�^0 */
#define PGIOR1      ((VH *)0xFFFE38D0)  /* �|�[�gG IO���W�X�^1 */
#define PGIOR0      ((VH *)0xFFFE38D2)  /* �|�[�gG IO���W�X�^0 */
#define PGDR1       ((VH *)0xFFFE38D4)  /* �|�[�gG �f�[�^���W�X�^1 */
#define PGDR0       ((VH *)0xFFFE38D6)  /* �|�[�gG �f�[�^���W�X�^0 */
#define PGPR1       ((VH *)0xFFFE38D8)  /* �|�[�gG �|�[�g���W�X�^1 */
#define PGPR0       ((VH *)0xFFFE38DA)  /* �|�[�gG �|�[�g���W�X�^1 */
#define PHCR1       ((VH *)0xFFFE38EC)  /* �|�[�gH �R���g���[�����W�X�^1 */
#define PHCR0       ((VH *)0xFFFE38EE)  /* �|�[�gH �R���g���[�����W�X�^0 */
#define PHPR0       ((VH *)0xFFFE38FA)  /* �|�[�gH �|�[�g���W�X�^1 */
#define PJCR2       ((VH *)0xFFFE390A)  /* �|�[�gJ �R���g���[�����W�X�^2 */
#define PJCR1       ((VH *)0xFFFE390C)  /* �|�[�gJ �R���g���[�����W�X�^1 */
#define PJCR0       ((VH *)0xFFFE390E)  /* �|�[�gJ �R���g���[�����W�X�^0 */
#define PJIOR0      ((VH *)0xFFFE3912)  /* �|�[�gJ IO���W�X�^0 */
#define PJDR0       ((VH *)0xFFFE3916)  /* �|�[�gJ �f�[�^���W�X�^0 */
#define PJPR0       ((VH *)0xFFFE391A)  /* �|�[�gJ �|�[�g���W�X�^1 */
#define PKCR2       ((VH *)0xFFFE392A)  /* �|�[�gK �R���g���[�����W�X�^2 */
#define PKCR1       ((VH *)0xFFFE392C)  /* �|�[�gK �R���g���[�����W�X�^1 */
#define PKCR0       ((VH *)0xFFFE392E)  /* �|�[�gK �R���g���[�����W�X�^0 */
#define PKIOR0      ((VH *)0xFFFE3932)  /* �|�[�gK IO���W�X�^0 */
#define PKDR0       ((VH *)0xFFFE3936)  /* �|�[�gK �f�[�^���W�X�^0 */
#define PKPR0       ((VH *)0xFFFE393A)  /* �|�[�gK �|�[�g���W�X�^1 */

/* �����d�̓��[�h */
#define STBCR1      ((VB *)0xFFFE0014)  /* �X�^���o�C�R���g���[�����W�X�^1 */
#define STBCR2      ((VB *)0xFFFE0018)  /* �X�^���o�C�R���g���[�����W�X�^2 */
#define STBCR3      ((VB *)0xFFFE0408)  /* �X�^���o�C�R���g���[�����W�X�^3 */
#define STBCR4      ((VB *)0xFFFE040C)  /* �X�^���o�C�R���g���[�����W�X�^4 */
#define STBCR5      ((VB *)0xFFFE0410)  /* �X�^���o�C�R���g���[�����W�X�^5 */
#define STBCR6      ((VB *)0xFFFE0414)  /* �X�^���o�C�R���g���[�����W�X�^6 */
#define STBCR7      ((VB *)0xFFFE0418)  /* �X�^���o�C�R���g���[�����W�X�^7 */
#define STBCR8      ((VB *)0xFFFE041C)  /* �X�^���o�C�R���g���[�����W�X�^8 */
#define SWRSTCR     ((VB *)0xFFFE0430)  /* �\�t�g�E�F�A���Z�b�g�R���g���[�����W�X�^8 */
#define SYSCR1      ((VB *)0xFFFE0400)  /* �V�X�e���R���g���[�����W�X�^1 */
#define SYSCR2      ((VB *)0xFFFE0404)  /* �V�X�e���R���g���[�����W�X�^2 */
#define SYSCR3      ((VB *)0xFFFE0420)  /* �V�X�e���R���g���[�����W�X�^3 */
#define SYSCR4      ((VB *)0xFFFE0424)  /* �V�X�e���R���g���[�����W�X�^4 */
#define SYSCR5      ((VB *)0xFFFE0428)  /* �V�X�e���R���g���[�����W�X�^5 */
#define RRAMKP      ((VB *)0xFFFE6800)  /* �ێ��p����RAM �ێ��G���A�w�背�W�X�^ */
#define DSCTR       ((VB *)0xFFFE6802)  /* �f�B�[�v�X�^���o�C�R���g���[�����W�X�^ */
#define DSSSR       ((VH *)0xFFFE6804)  /* �f�B�[�v�X�^���o�C�����v���Z���N�g���W�X�^ */
#define DSESR       ((VH *)0xFFFE6806)  /* �f�B�[�v�X�^���o�C�����G�b�W�Z���N�g���W�X�^ */
#define DSFR        ((VH *)0xFFFE6808)  /* �f�B�[�v�X�^���o�C�����v���t���O���W�X�^ */
#define XTALCTR     ((VB *)0xFFFE6810)  /* XTAL�������U��Q�C���R���g���[�����W�X�^ */

/* FIFO�t���V���A���R�~���j�P�[�V�����C���^�[�t�F�[�X (SCIF) */

#define SCIF0_BASE  ((UW)0xFFFE8000)    /* �`���l��0 ���W�X�^�x�[�X�A�h���X */
#define SCIF1_BASE  ((UW)0xFFFE8800)    /* �`���l��1 ���W�X�^�x�[�X�A�h���X */
#define SCIF2_BASE  ((UW)0xFFFE9000)    /* �`���l��2 ���W�X�^�x�[�X�A�h���X */
#define SCIF3_BASE  ((UW)0xFFFE9800)    /* �`���l��3 ���W�X�^�x�[�X�A�h���X */
#define SCIF4_BASE  ((UW)0xFFFEA000)    /* �`���l��4 ���W�X�^�x�[�X�A�h���X */
#define SCIF5_BASE  ((UW)0xFFFEA800)    /* �`���l��5 ���W�X�^�x�[�X�A�h���X */
#define SCIF6_BASE  ((UW)0xFFFEB000)    /* �`���l��6 ���W�X�^�x�[�X�A�h���X */
#define SCIF7_BASE  ((UW)0xFFFEB800)    /* �`���l��7 ���W�X�^�x�[�X�A�h���X */

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
	sil_wrh_mem (IPR18, 0x0000);
	sil_wrh_mem (IPR19, 0x0000);
	sil_wrh_mem (IPR20, 0x0000);
	sil_wrh_mem (IPR21, 0x0000);
	sil_wrh_mem (IPR22, 0x0000);
}

#endif /* _MACRO_ONLY */

#endif /* _SH7262_H_ */
