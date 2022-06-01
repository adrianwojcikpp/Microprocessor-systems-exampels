/**
  ******************************************************************************
  * @file    timestamp_win_test.c
  * @author  AW           Adrian.Wojcik@put.poznan.pl
  * @version 1.0
  * @date    27-May-2022
  * @brief   Creating timestamp printing feature for Windows
  *
  ******************************************************************************
  */
  
  
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <sys\timeb.h>   //< 
  
/* Public functions prototypes -----------------------------------------------*/  
/**
 * @brief Delay in milliseconds.
 * @param[in] period : delay period in ms
 * @retval None
 */
void delay_ms(unsigned int period);

struct timeb TIMESTAP_Start;
void TIMESTAMP_Init(void);

float TIMESTAMP_GetSeconds(void);
 
/* Main function -------------------------------------------------------------*/
/**
  * @brief  The application entry point.
  * @retval 0 
  */
int main(void)
{
	TIMESTAMP_Init();
	delay_ms(100);
	printf("[%03.04f]\n", TIMESTAMP_GetSeconds());
	delay_ms(100);
	printf("[%03.04f]\n", TIMESTAMP_GetSeconds());
	delay_ms(100);
	printf("[%03.04f]\n", TIMESTAMP_GetSeconds());
	delay_ms(100);
	printf("[%03.04f]\n", TIMESTAMP_GetSeconds());
	delay_ms(100);
	printf("[%03.04f]\n", TIMESTAMP_GetSeconds());
	delay_ms(100);
	printf("[%03.04f]\n", TIMESTAMP_GetSeconds());
	delay_ms(100);
	printf("[%03.04f]\n", TIMESTAMP_GetSeconds());
	delay_ms(100);
	printf("[%03.04f]\n", TIMESTAMP_GetSeconds());
	return 0;
}

/* Public functions ----------------------------------------------------------*/  
void delay_ms(unsigned int period)
{
	struct timeb start, end;
    unsigned int diff;
    ftime(&start);	
	do {
		ftime(&end);
		diff =  (unsigned int)(1000 * (end.time - start.time) + (end.millitm - start.millitm));
	}
	while(diff < period);
}

void TIMESTAMP_Init(void)
{
	ftime(&TIMESTAP_Start);	
}

float TIMESTAMP_GetSeconds(void)
{
	struct timeb TIMESTAP_Now;
	ftime(&TIMESTAP_Now);
	return (1.0f * (TIMESTAP_Now.time - TIMESTAP_Start.time) + 0.001f*(TIMESTAP_Now.millitm - TIMESTAP_Start.millitm));
}