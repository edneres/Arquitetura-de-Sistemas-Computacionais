/*
   Fazer um c�digo em C para fazer com que o timer2 opere como temporizador 
   cujo o tempo de estouro desse timer seja de 50 us. 
   A cada 100 us, o estado do pino RB0 da porta B � invertido de estado.   

   >> 50us = 0,00005s
   >> 100us = 0,0001s

   >> ciclo de m�quina = 4 / Fosc -> ciclo de m�quina = 4 / 20MHz 
     -> 1 ciclo de m�quina = 0,2us <-
   >> tempo = ciclo de m�quina * prescaler * potscaler * (PR2+1) -> 50us = 0,2us * prescaler * potscaler * (PR2 + 1)
        250 = prescaler * potscaler * (PR2 + 1) -> valor menor que 255, logo, � precisa do PRE. e do POS
         250 = (PR2 + 1)* 1 * 1
     -> PR2 = 249 <- 
*/


#include <16F877A.h>
#include "reg_16f.h"

void main()
{

/*
   TOUTPS3 (Bit de Sele��o da P�s-escala da Sa�da do Timer2)
      - 0 (+ significativo)

   TOUTPS2 (Bit de Sele��o da P�s-escala da Sa�da do Timer2)
      - 0

   TOUTPS1 (Bit de Sele��o da P�s-escala da Sa�da do Timer2)
      - 0

   TOUTPS0 (Bit de Sele��o da P�s-escala da Sa�da do Timer2)
      - 0

   TMR2ON (Bit de Acionamento do Timer2)
      - 1

   T2CKPS1 (Bit de Sele��o da Pr�-escala do Clock do Timer2)
      - 0

   T2CKPS0 (Bit de Sele��o da Pr�-escala do Clock do Timer2)
      - 0 (- significativo)
   
   >> T2CON = 0b001000; << Postcaler 1:1, Timer2 ligado e Prescaler 1:1


   Como PR2 = 249 (em decimal), logo, em bin�rio:
   >> PR2 = 0b11111001; <<   
   [Mas poderia deixar em decimal tamb�m!]


   1 ciclo de m�quina leva 0,2us e a cada 100us o pino RB0 da porta B tem que ser invertido de estado
      100us = x * ciclo de m�quina = x * 0,2us
          x = 100us / 0,2us
       -> x = 500 <- 
*/


   unsigned int8 aux = 0; 

   setup_timer_2(T2_DIV_BY_1, 249, 1); 
   set_timer2(0); // Inicializa o timer2 em 0

   TRISB = 0;
   PORTB = 0;
   
   output_bit(PIN_B0, 0);

   while (TRUE)
   {
      if (TMR2IF == 1) // Flag de overflow do Timer2
      {
         aux++;
         TMR2IF = 0;
      }

      if (aux == 2)
      {
         aux = 0;
         output_toggle(PIN_B0);
      }
   }
}
