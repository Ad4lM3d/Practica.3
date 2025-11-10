//==================================================================================
//||	         CONFIGURATION OF PORT_A AND PORT_B PARA EL XC8                   ||
//||             ==============================================                   ||
//||                                                                              ||
//||   + Oscillator Type: INTIO2 = Internal Oscilator with I/O on RA6(OSC1) and   ||
//||     RA7(OSC2):                                                               ||
//||     - Configuration bits FOSC3:FOSC0 of CONFIG1H(3:0) = 1000                 ||
//||   + OSCCON(FD3h):                                                            ||
//||     - System Clock Select Bits SCS1:SCS0 = 00 (Primary Oscillator specified  ||
//||       by FOSC3:FOSC0 of CONFIG1H --> INTIO2)                                 ||
//||     - Internal Oscillator Frequency Select Bits IRCF2:IRCF0 = 110 (4 MHz)    ||
//||                                                                              ||
//==================================================================================

#include <xc.h>

//OSCILLATOR SOURCE AND DIGITAL I/O CONFIGURATION BITS
//====================================================
#pragma config	FOSC = INTOSCIO_EC  //CONFIG1H (0-3) = 0010: INTIO2 oscillator, Internal oscillator block, port function on RA6 and RA7.
#pragma config	MCLRE = ON          // CONFIG3H.7 = 1: Pin de RESET habilitado y Entrada RE3 desactivado.
#pragma config	PBADEN = OFF        // CONFIG3H.1 = 0: PORTB.0 -- PORTB.4 as Digital I/O.
#pragma config	LVP = OFF           // CONFIG3H.2 = 0: Single-Supply ICSP disabled  so that PORTB.5 works as Digital I/O.

//PICIT-3 DEBUGGER SETUP CONFIGURATION BITS
//=========================================
#pragma config	WDT = OFF           // CONFIG2H (0) = 0: Watchdog Timer Disabled.

void main(void){

   //CLOCK FREQUENCY CONFIGURATION
   //============================
   OSCCON = 0x60;                       // 4 MHz internal oscillator

   //DISABLE PORT's ANALOG FUNCTIONS
   //===============================
   CMCON = 0xFF;                        // Comparators OFF, to use PORT_Ds LSN
   ADCON1 = 0x0F;                       // All ports as DIGITAL I/O

   //CONFIGURATION OF PORTS A & B
   //============================
   PORTA = 0x00;                        // Initialize PORTA
   LATA = 0x00;			        // Clear PORTA
   TRISA = 0xFF;			// PORTA as Input
   PORTB = 0x00;	                // Initialize PORTB
   LATB = 0x00;			        // Clear PORTB
   TRISB = 0x00;		        // PORTB as Output

   //TURN-ON LED
   //===========
   while(1){PORTB = PORTA;}
}
        