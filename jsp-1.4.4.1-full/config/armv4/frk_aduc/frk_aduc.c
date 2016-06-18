/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2006 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2006 by Logic Research Co., Ltd.
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
 */

/*
 * FRK_ADuC �����@�\�p�h���C�o
 */

#include <s_services.h>
#include "frk_aduc.h"


/*
 * �V���A��I/O�|�[�g�������u���b�N
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{(VP)COMRX, (VP)COMDIV0, (VP)COMDIV1,
	 (VP)COMIEN0, (VP)COMIID0, (VP)COMCON0,
	 (VP)COMSTA0, IRQ_UART}
};


/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
SIOPCB  siopcb_table[TNUM_SIOP];



/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)  ((UINT)((siopid) - 1))
#define get_siopcb(siopid)  (&(siopcb_table[INDEX_SIOP(siopid)]))



/*
 * ��������M������?
 */ 
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
	return(((sil_rew_mem((VP)(siopcb->siopinib->line_status)) & COMSTA0_DR)!=0));
}


/*
 * �����𑗐M�ł��邩?
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
	return((sil_rew_mem((VP)(siopcb->siopinib->line_status)) & COMSTA0_TEMT)!=0);
}


/*
 *  ��M���������̎��o��
 */
Inline UB
uart_getchar(SIOPCB *siopcb)
{
	return(sil_rew_mem((VP)(siopcb->siopinib->uart_data)));
}


/*
 *  ���M���镶���̏�������
 */
Inline void
uart_putchar(SIOPCB *siopcb, UB c)
{
    sil_wrw_mem((VP)(siopcb->siopinib->uart_data), c);
}


/*
 *  ���M�����݋���
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->int_enable),
            (sil_rew_mem((VP)(siopcb->siopinib->int_enable)) | COMIEN0_ETBEI));
}


/*
 *  ���M�����݋֎~
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->int_enable),
        (sil_rew_mem((VP)(siopcb->siopinib->int_enable)) & ~COMIEN0_ETBEI));
}


/*
 *  ��M�����݋���
 */
Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->int_enable),
        (sil_rew_mem((VP)(siopcb->siopinib->int_enable)) | COMIEN0_ERBFI));
}

/*
 *  ��M�����݋֎~
 */
Inline void
uart_disable_rcv(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->int_enable),
        (sil_rew_mem((VP)(siopcb->siopinib->int_enable)) & ~COMIEN0_ERBFI));
}



/*
 * �J�[�l���N�����̃��O�o�͗p�̏�����
 */
void
init_uart(void){
    /* Disable Interrupt */
    sil_wrw_mem((VP)COMIEN0, 0);
    /* 9600bps */
    sil_wrw_mem((VP)COMCON0, COMCON0_DLAB);
    sil_wrw_mem((VP)COMDIV0, COMDIV0_BR9600); 
    sil_wrw_mem((VP)COMDIV1, COMDIV1_BR9600);
    /* 8Data, 1Stop, No Parity */
    sil_wrw_mem((VP)COMCON0, (COMCON0_STOP|COMCON0_WLS_8b));
    /* Enabel Receive Interrupt */
    sil_wrw_mem((VP)COMIEN0, (COMIEN0_ERBFI|COMIEN0_ETBEI));      
}


/*
 *  �I���`�b�v��UART����̃|�[�����O�o��
 */
void
uart_putc(char c)
{
    int i;

    while((sil_rew_mem((VP)COMSTA0) & COMSTA0_TEMT)!=COMSTA0_TEMT);
  
    sil_wrw_mem((VP)COMTX, (VW)c);
}


/*
 *  SIO�h���C�o�̏��������[�`��
 *  1�|�[�g�����Ȃ����߁C���܂�Ӗ��͂Ȃ�
 */
void
uart_initialize()
{
    SIOPCB  *siopcb;
    UINT    i;

    /*
     *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
     */
    for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
        siopcb->siopinib = &(siopinib_table[i]);
        siopcb->openflag = FALSE;
        siopcb->sendflag = FALSE;
    }
}


/*
 * �I�[�v�����Ă���|�[�g�����邩
 */
BOOL
uart_openflag(void)
{
    return(siopcb_table[0].openflag);
}


/*
 * �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
    int i;
    
    SIOPCB      *siopcb;
    const SIOPINIB  *siopinib;

    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;

    /* Disable Interrupt */
    sil_wrw_mem((VP)siopinib->int_enable, 0);
    /* 9600bps */
    sil_wrw_mem((VP)siopinib->line_control, COMCON0_DLAB);
    sil_wrw_mem((VP)siopinib->divisor_lo, COMDIV0_BR9600); 
    sil_wrw_mem((VP)siopinib->divisor_hi, COMDIV1_BR9600);
    
    /* 8Data, 1Stop, No Parity */
    sil_wrw_mem((VP)siopinib->line_control, (COMCON0_STOP|COMCON0_WLS_8b));

    /*
     * �����݊֘A�̐ݒ�
     */
    sil_wrw_mem((VP)siopinib->int_enable, (COMIEN0_ERBFI|COMIEN0_ETBEI));	/* Enable Interrupt */
    sil_wrw_mem((VP)IRQEN, siopinib->irq_bit);	/*Enable interrupt register*/
    
    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;

    return(siopcb);    
}


/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
uart_cls_por(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->line_control),
        (sil_rew_mem((VP)(siopcb->siopinib->line_control))|COMCON0_BRK)); /* Disable Interrupt */
    
    siopcb->openflag = FALSE;
}


/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
uart_snd_chr(SIOPCB *siopcb, char c)
{
    if (uart_putready(siopcb)){
        uart_putchar(siopcb, c);
        return(TRUE);
    }
    return(FALSE);
}


/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
uart_rcv_chr(SIOPCB *siopcb)
{
    if (uart_getready(siopcb)) {
        return((INT)(UB) uart_getchar(siopcb));
    }
    return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    switch (cbrtn) {
        case SIO_ERDY_SND:
            uart_enable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            uart_enable_rcv(siopcb);
            break;
    }
}


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    switch (cbrtn) {
        case SIO_ERDY_SND:
            uart_disable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            uart_disable_rcv(siopcb);
            break;
    }
}


/*
 *  �V���A��I/O�|�[�g�ɑ΂��銄���ݏ���
 */
static void
uart_isr_siop(SIOPCB *siopcb)
{
	volatile UW	iid;

    if (uart_getready(siopcb)) {
        /*
         *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
         */
        uart_ierdy_rcv(siopcb->exinf);
    }
    if (uart_putready(siopcb)) {
		iid = sil_rew_mem((VP)COMIID0);
        /*
         *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
         */
        uart_ierdy_snd(siopcb->exinf);
    }
}


/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
void
uart_isr()
{
    uart_isr_siop(&(siopcb_table[0]));
}

