#INCLUDE <P16F877A.INC> 

CONT EQU 0x20
cont1 equ 0x21
__CONFIG _XT_OSC & _WDT_OFF

ORG 0X00
nop
nop
GOTO INICIO
nop

INICIO
clrf cont1
BANKSEL TRISB

clrf TRISD

BCF TRISB,0
MOVLW B'10100000'
MOVWF INTCON
BANKSEL OPTION_REG
MOVLW B'00000111'
MOVWF OPTION_REG

banksel CONT
MOVLW D'8'
MOVWF CONT
CLRF TMR0
FIM GOTO FIM
END
