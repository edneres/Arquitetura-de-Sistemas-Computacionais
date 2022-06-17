/*
Fazer um c�digo em C para fazer com que o timer0 opere como contador por borda de descida. 
A cada 10 contagens o estado do pino RA0 da porta A � invertido de estado.
*/

#include <16F877A.h>
#include "reg_16f.h"

void main()
{
	unsigned int8 cont = 0;
	
	TRISA = 0x00; // TRISA como saida

/*
	RBPU (+ significativo)
		0
	
	INTERDEG
		0
	
	T0CS - Define a fonte de clock do TIMER0:
		1 - Externa (PINO RA4/T0CKIN) - Modo contador;
	
	T0SE - Sele��o da borda de transi��o do pino RA4/T0CKIN
		1 - transi��o nivel alto-baixo (transi��o negativa);
		
	PSA - Habilita��o do prescaler (no modo CONTADOR � comum desabilitar);
		1 - Desabilitado;
	
	PS2, PS1, PS0 - Sele��o do prescaler (somente no modo temporizador);
		0 (PS2)
		0 (PS1)
		0 (PS0) (- significativo)
			> 00111000
*/
	OPTION_REG = 0b00111000; // Modo contador (seta o bit 5: T0CS) > clk externo (pino RA4/T0CKIN)
	
	TMR0 = 0; // Inicializa o registro TMR0 com o valor 0.
	output_bit (pin_A0, 0); // Inicializa o valor do pino em 0
 
	while (TRUE)
	{
		cont++;

		if (cont == 10)
		{
			output_toggle (pin_A0); // Inverte o estado do pino RA0 a cada 10 pulsos/contagem
	  		cont = 0;
			TMR0 = 0;
		}
	}
}

/*
#include <16F877A.h>
#include <reg_16f.h>
/*
	> f = 1/T >> T = 1/f (maior f, menor T - mais r�pido; menor f, maior T - menos r�pido)
	> Timer1: 16 bits
	> clk = 20MHz (cristal/interno) >> Temporizador
	> Ciclo de m�quina = 4/clk = 4/20000000Hz = 0,0000002s = 0,2us
	> Tempo do estouro = TMR1 * prescaler * ciclo de m�quina =  65536*1*0,2us = 13,12ms
*/

void main()
{
	TRISC = 0;
	T1CON = 0b00000000; // Sem divis�o de frequ�ncia, sincronia com o clk, bit ignorado, clk interno, TMR1 desabiitado
}
*/