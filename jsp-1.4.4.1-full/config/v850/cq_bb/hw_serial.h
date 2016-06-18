/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2007-2010 by Monami Software Limited Partnership, JAPAN.
 * 
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
 * �^�[�Q�b�g�ˑ��V���A��I/O���W���[���iD70F3716GC �����񓯊��V���A��ch0�p�j
 *   �f�[�^�t�H�[�}�b�g��8bit data, non-parity, 1stop-bit�Œ�
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>

/*
 *  �V���A���|�[�g�̏������u���b�N
 */

typedef struct sio_port_initialization_block {
} SIOPINIB;

/*
 *  �V���A���|�[�g�̐���u���b�N
 */
typedef struct sio_port_control_block {
	const SIOPINIB	*inib;		/* �������u���b�N	*/
	VP_INT		exinf;		/* �g�����		*/
	BOOL		openflag;	/* �I�[�v���ς݃t���O	*/
	int			port_id;	/* �|�[�g�ԍ�(0�`) */
} SIOPCB;

extern SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO ID ����Ǘ��u���b�N�ւ̕ϊ��}�N��
 */

#define INDEX_SIO(sioid)	((UINT)((sioid) - 1))
#define get_siopcb(sioid)	(&(siopcb_table[INDEX_SIO(sioid)]))

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */

#define SIO_ERDY_SND		1u			/* ���M�\�R�[���o�b�N			*/
#define SIO_ERDY_RCV		2u			/* ��M�ʒm�R�[���o�b�N			*/


/*
 *  �V���A���|�[�g�̃n�[�h�E�F�A�ˑ����̒�`
 */

#define SERIAL_PORT				(CONSOLE_PORTID-1)		/* �V�X�e���̃|�[�g�ԍ� */
#define SERIAL_INT_PRIORITY		3	/* ���荞�ݗD��x */
#define SERIAL_CLKDIV			0x01	/* clk = fxx/2     */
#define SERIAL_COMPAREVALUE		0x82	/* 38400bps */
//#define SERIAL_CLKDIV			0x00	/* clk = fxx/1     */
//#define SERIAL_COMPAREVALUE		0x57	/* 115200bps */


#define FLG_RECEIVED 1

extern volatile unsigned int _serial_flag;


/*
 *  �V���A��I/O�̊����݃n���h���̃x�N�^�ԍ�
 */
#define INHNO_SERIAL_IN		(0x35)
#define INHNO_SERIAL_OUT	(0x36)

/*
 *  �჌�x���|�[�g���Ǘ��u���b�N�̏����l
 */

#define NUM_PORT	1	/* �T�|�[�g����V���A���|�[�g�̐� */

/*
 *  �V���A��I/O�|�[�g�̏�����
 */
Inline BOOL
hw_port_initialize(int port_id)
{
#ifndef DEBUGGER
	while( (sil_reb_mem((VP)UA0STR) & 0x80) ) ;

	/* �񓯊��V���A���ʐM�H�̏����� */

	/* �|�[�g���J���� */
	if (port_id == 0) {
		sil_wrh_mem((VP)PMC3, sil_reh_mem((VP)PMC3) | 0x0300);
		sil_wrh_mem((VP)PFC3, sil_reh_mem((VP)PFC3) & ~0x0300);
	} else {

	}

	/* �{�[���[�g������̏����� */
	sil_wrb_mem((VP)UA0CTL1, SERIAL_CLKDIV);
	sil_wrb_mem((VP)UA0CTL2, SERIAL_COMPAREVALUE);

	sil_wrb_mem((VP)UA0CTL0, 0x80);	/* enable ASIO */

	__asm("nop; nop");

	/* �p���e�B�Ȃ��E8�r�b�g�E�X�g�b�v1�r�b�g�ELSB�t�@�[�X�g */
	sil_wrb_mem((VP)UA0CTL0, sil_reb_mem((VP)UA0CTL0) | 0x12);

	__asm("nop; nop");

	sil_wrb_mem((VP)UA0CTL0, sil_reb_mem((VP)UA0CTL0) | 0x60);	/* Tx, Rx enable */

	/* �����ݐ��� */
	sil_wrb_mem((VP)UA0RIC, SERIAL_INT_PRIORITY);
	sil_wrb_mem((VP)UA0TIC, SERIAL_INT_PRIORITY);
#endif
	return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g�̏I��
 */
Inline void
hw_port_terminate(int port_id)
{
	sil_wrb_mem((VP)UA0RIC, sil_reb_mem((VP)UA0RIC) | 0x40);
	sil_wrb_mem((VP)UA0TIC, sil_reb_mem((VP)UA0TIC) | 0x40);

	sil_wrb_mem((VP)UA0CTL0, 0x10);	/* Tx, Rx disable */
}

/*
 *  �V���A���|�[�g�����݃T�[�r�X���[�`���i�O���Q�Ɓj
 */
extern void	serial_handler_in(int portid);
extern void	serial_handler_out(int portid);

/*
 *  ��������M�������H
 */
Inline BOOL
hw_port_getready(int port_id)
{
	return ((_serial_flag & FLG_RECEIVED) != 0);
}


/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
hw_port_putready(int port_id)
{
	return ((sil_reb_mem((VP)UA0STR) & 0x80) == 0);
}


/*
 *  ��M���������̎��o��
 */
Inline unsigned char
hw_port_getchar(int port_id)
{
	_serial_flag &= ~FLG_RECEIVED;
	return sil_reb_mem((VP)UA0RX);
}

/*
 *  ���M���镶���̏�������
 */
Inline void
hw_port_putchar(int port_id, unsigned char c)
{
	sil_wrb_mem((VP)UA0TX, c);
}

/*
 *  ���M���镶���̏������݁i���M�\�ɂȂ�܂ő҂j
 */
Inline void
hw_port_wait_putchar(int port_id, unsigned char c)
{
	while( !hw_port_putready(port_id) ) ;
	hw_port_putchar(port_id, c);
}

/*
 *  ���M����֐�
 */
Inline void
hw_port_sendstart(int port_id)
{
}

Inline void
hw_port_sendstop(int port_id)
{
}

extern void	sio_ierdy_rcv(VP_INT exinf);
extern void	sio_ierdy_snd(VP_INT exinf);

Inline void
hw_port_handler_in(int port_id)
{
	UB tmp;

	if((sil_reb_mem((VP)UA0STR) & 0x07) == 0) {
		_serial_flag |= FLG_RECEIVED;
		sio_ierdy_rcv(siopcb_table[port_id].exinf);	
	} else {
		/* �G���[������΃f�[�^��j�� */
		tmp = sil_reb_mem((VP)UA0RX);
	}
}

Inline void
hw_port_handler_out(int port_id)
{
	if(hw_port_putready(port_id)) {
		sio_ierdy_snd(siopcb_table[port_id].exinf);
	}
}

/***********************************************************************************/

/*
 *  sio_initialize -- �V���A���|�[�g�h���C�o�̏�����
 */
Inline void
sio_initialize (void)
{
	int ix;

	/* SIO �Ǘ��u���b�N�̏����� */
	for (ix = TNUM_PORT; ix -- > 0; ) {
		siopcb_table[ix].openflag = FALSE;
	}
}

/*
 *  sio_opn_por -- �|�[�g�̃I�[�v��
 */
Inline SIOPCB *
sio_opn_por(ID sioid, VP_INT exinf)
{
	SIOPCB	*pcb;

	pcb = get_siopcb(sioid);
	pcb->inib     = NULL;
	pcb->exinf    = exinf;
	pcb->openflag = TRUE;
	pcb->port_id  = sioid-1;
	hw_port_initialize(pcb->port_id);
	return pcb;
}

/*
 *  sio_snd_chr -- �������M
 */
Inline BOOL
sio_snd_chr(SIOPCB *pcb, INT chr)
{
#if 0
	if (hw_port_putready(pcb->port_id)) {
		hw_port_putchar(pcb->port_id, (UB)chr);
		return TRUE;
	} else {
		return FALSE;
	}
#else
	/* �{���́A���̂悤�ɂ���ׂ������A */
	/* syslog�o�͂��~�܂��Ă��܂����߁A */
	/* �b�菈�u */
	while(!hw_port_putready(pcb->port_id)) ;
	hw_port_putchar(pcb->port_id, (UB)chr);
	return TRUE;
#endif
}

/*
 *  sio_rcv_chr -- ������M
 */
Inline INT
sio_rcv_chr(SIOPCB *pcb)
{
	if (hw_port_getready(pcb->port_id))
		return hw_port_getchar(pcb->port_id);
	else
		return -1;
}

/*
 *  sio_ena_cbr -- �V���A�� I/O ����̃R�[���o�b�N�̋���
 */
Inline void
sio_ena_cbr(SIOPCB *pcb, UINT cbrtn)
{
}

/*
 *  sio_dis_cbr -- �V���A�� I/O ����̃R�[���o�b�N�̋֎~
 */
Inline void
sio_dis_cbr(SIOPCB *pcb, UINT cbrtn)
{
}

/*
 *  sio_cls_por -- �|�[�g�̃N���[�Y
 */
Inline void
sio_cls_por(SIOPCB *pcb)
{
	sio_dis_cbr(pcb, SIO_ERDY_SND);
	sio_dis_cbr(pcb, SIO_ERDY_RCV);
	pcb->openflag = FALSE;
}

Inline void
sio_in_handler(void)
{
	hw_port_handler_in(0);
}

Inline void
sio_out_handler(void)
{
	hw_port_handler_out(0);
}


#endif /* _HW_SERIAL_H_ */
