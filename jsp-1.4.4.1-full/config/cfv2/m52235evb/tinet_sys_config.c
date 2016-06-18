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

/*
 *  JSP-1.4.2 �ȍ~�ŕύX���ꂽ�����݃n���h���ւ̑Ή�
 */

#include <s_services.h>
#include <t_services.h>
#include "kernel_id.h"

#include <tinet_defs.h>
#include <tinet_config.h>

/*
 *  fec_inter_init -- �^�[�Q�b�g�ˑ����̊����݂̏�����
 */

int
memcmp(const void* s1, const void* s2, int n) {
  char* a1 = (char*)s1;
  char* a2 = (char*)s2;
  
  while (n--)
    if (*a1++ != *a2++)
      return *(a1 - 1) - *(a2 - 1);
  return 0;
}


void*
memset(char *s, int c, int n) 
{
  char* p = s;
  while (n--) {
    *p++=c;
  }
  return s;
}


void*
memcpy(void* dest, void* src, int n) {
  char *p1 = dest;
  const char *p2 = src;
  int i;

  for (i = 0; i < n; i++) {
    *(p1++) = *(p2++);
  }

  return dest;
}

void *
memmove (void *d, void *s, int n)
{
    char *dst = d;
    char *src = s;
    void *ret = dst;

    if (src < dst) {
	src += n;
	dst += n;
	while (n--)
	    *--dst = *--src;
    }
    else if (dst < src)
	while (n--)
	    *dst++ = *src++;
    return ret;
}

#if TKERNEL_PRVER >= 0x1042u	/* JSP-1.4.2 �ȍ~ */

/*
 * fec_dis_inter -- �����݂��֎~����B
 */
IPM
fec_dis_inter(void)
{
  IPM	ipm;
  
  syscall(get_ipm(&ipm));
  syscall(chg_ipm(if_fec_handler_intmask));
  return ipm;
}

/*
 *  fec_bus_init -- �^�[�Q�b�g�ˑ����̃o�X�̏�����
 */

void
fec_bus_init (void)
{
}

/*
 *  fec_inter_init -- �^�[�Q�b�g�ˑ����̊����݂̏�����
 */

void
fec_inter_init (void)
{
  int i;
  /* NIC �̊��荞�݂�������B*/
  for (i = TBIT_FEC_XINF; i <= TBIT_FEC_BABR; i++) {
    sil_wrb_mem (MCF_INTC_ICR(MCF_INTC0, i), ((FEC_INT_LEVEL) << 3) | (FEC_INT_PRI));
    if (i < 32)
      sil_wrw_mem (MCF_INTC_IMRL(MCF_INTC0), sil_rew_mem(MCF_INTC_IMRL(MCF_INTC0)) & (~(1 << i)));
    else
      sil_wrw_mem (MCF_INTC_IMRH(MCF_INTC0), sil_rew_mem(MCF_INTC_IMRH(MCF_INTC0)) & (~(1 << (i-32))));
  }
}

#endif	/* of #if TKERNEL_PRVER >= 0x1042u */
