/**
  ******************************************************************************
  * @file    display_control.c
  * @author  AW           Adrian.Wojcik@put.poznan.pl
  * @author
  * @author
  * @version 2.0
  * @date	 02-Jun-2022
  * @brief	 Display control library
  *
  ******************************************************************************
  */
 
/* Includes ------------------------------------------------------------------*/
#include "display_control.h"
#include <stdio.h>

/* Exported variables --------------------------------------------------------*/
/**
  * @brief Start of program execution timestamp
  */
struct timeb timestamp_start;

/**
  * @brief Log file handler
  */
FILE* logfile;

/* Private function prototypes -----------------------------------------------*/
/**
 *
 */
void display_debug_print(DISP_HandleTypeDef* hdisp); 

/**
 *
 */
void display_debug_log(DISP_HandleTypeDef* hdisp); 

/* Public function -----------------------------------------------------------*/
/**
 *
 */
void display_decimal(DISP_HandleTypeDef* hdisp, unsigned int number)
{
	display_debug_print(hdisp);
	for(int i = 0; i < 8; i++)
	{
		/* USER CODE Begin */
		
		// TODO: implement required logic 
		HAL_GPIO_WritePin(hdisp->Port, hdisp->DATA1_Pin,  (i%2));
		HAL_GPIO_WritePin(hdisp->Port, hdisp->DATA2_Pin, !(i%2));
		HAL_GPIO_WritePin(hdisp->Port, hdisp->DATA3_Pin,  (i%2));
		HAL_GPIO_WritePin(hdisp->Port, hdisp->DATA4_Pin, !(i%2));
		
		/* USER CODE End */
		
		HAL_GPIO_WritePin(hdisp->Port, hdisp->CLOCK_Pin, GPIO_PIN_RESET);
		HAL_Delay(hdisp->ClockPeriod/2);
		display_debug_print(hdisp);
		display_debug_log(hdisp);
		
		HAL_GPIO_WritePin(hdisp->Port, hdisp->CLOCK_Pin, GPIO_PIN_SET);
		HAL_Delay(hdisp->ClockPeriod/2);
		display_debug_print(hdisp);
		display_debug_log(hdisp);
	}
	
	HAL_GPIO_WritePin(hdisp->Port, hdisp->CLOCK_Pin, GPIO_PIN_RESET);
	HAL_Delay(hdisp->ClockPeriod/2);
	display_debug_print(hdisp);
	display_debug_log(hdisp);
}

/**
 *
 */
void logfile_init(char* filename)
{
   logfile = fopen(filename,"w");
   if(logfile == NULL)
      printf("Cannot open log file!");               
}

/**
 *
 */
void logfile_deinit()
{
	fclose(logfile);
}	

/**
 *
 */
void timestamp_init(void)
{
	ftime(&timestamp_start);	
}

/* Private function ----------------------------------------------------------*/
/**
 *
 */
float timestamp_get_seconds(void)
{
	struct timeb timestamp_now;
	ftime(&timestamp_now);
	return (1.0f * (timestamp_now.time - timestamp_start.time) + 0.001f*(timestamp_now.millitm - timestamp_start.millitm));
}

/**
 *
 */
void display_debug_print(DISP_HandleTypeDef* hdisp)
{	
	static _Bool isfirst = 1;
	if(isfirst)
		puts(" TIME  | CLOCK | DATA1 | DATA2 | DATA3 | DATA4 |");
	isfirst = 0;
	printf("%06.03f |   %u   |   %u   |   %u   |   %u   |   %u   |\n", 
		timestamp_get_seconds(),
		HAL_GPIO_ReadPin(hdisp->Port, hdisp->CLOCK_Pin),
		HAL_GPIO_ReadPin(hdisp->Port, hdisp->DATA1_Pin),
		HAL_GPIO_ReadPin(hdisp->Port, hdisp->DATA2_Pin),
		HAL_GPIO_ReadPin(hdisp->Port, hdisp->DATA3_Pin),
		HAL_GPIO_ReadPin(hdisp->Port, hdisp->DATA4_Pin));
}

/**
 *
 */
void display_debug_log(DISP_HandleTypeDef* hdisp)
{
	static _Bool isfirst = 1;
	if(isfirst)
		fprintf(logfile, "TIME,CLOCK,DATA1,DATA2,DATA3,DATA4\n");
	isfirst = 0;
	fprintf(logfile, "%06.03f,%u,%u,%u,%u,%u\n", 
		timestamp_get_seconds(),
		HAL_GPIO_ReadPin(hdisp->Port, hdisp->CLOCK_Pin),
		HAL_GPIO_ReadPin(hdisp->Port, hdisp->DATA1_Pin),
		HAL_GPIO_ReadPin(hdisp->Port, hdisp->DATA2_Pin),
		HAL_GPIO_ReadPin(hdisp->Port, hdisp->DATA3_Pin),
		HAL_GPIO_ReadPin(hdisp->Port, hdisp->DATA4_Pin));
}

