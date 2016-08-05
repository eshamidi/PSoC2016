/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

void main(void)
{
UART_1_Start(); 
uint32 rxData;
int delaytime = 1000;
char buf[15];
strcpy(buf, "Hello world \n \r");
UART_1_UartPutString(buf);
for(;;){
/* Check if data is available in the UART buffer.
The function returns an ASCII char where 1 to 255 are
valid and 0 indicates that an error occurred or no data
was present in the UART’s receive buffer. */
rxData = UART_1_UartGetChar();
if(rxData){
/* Echo character back to terminal. */
UART_1_UartPutChar(rxData);
/* Processing code goes here. */
if(rxData == 65) /*1 Hz -A */
{
   delaytime = 1000;
}
if(rxData == 66)/*2 Hz- B */
{
   delaytime = 500;
}
if(rxData == 67)/*3 Hz - C*/
{
   delaytime = 333;
}
if(rxData == 68)/*4 Hz - D*/
{
   delaytime = 250;
}
if(rxData == 69)/*5 Hz - E*/
{
   delaytime = 200;
}


} /* End if */
LED_PIN_Write(~LED_PIN_Read());
 CyDelay(delaytime);


} /* End for */


}
