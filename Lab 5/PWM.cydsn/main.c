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

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
uint16 PWMCompare; 
PWM_1_Start(); 
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        PWMCompare = PWMCompare + 1; 
        if(PWMCompare >= 1000){
            PWMCompare = 0;
            
        }
        PWM_1_WriteCompare(PWMCompare);
        CyDelay(1);
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
