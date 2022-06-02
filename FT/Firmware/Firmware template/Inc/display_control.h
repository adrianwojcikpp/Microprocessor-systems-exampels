/**
  ******************************************************************************
  * @file    display_control.h
  * @author  AW           Adrian.Wojcik@put.poznan.pl
  * @version 2.0
  * @date	 02-Jun-2022
  * @brief	 Display control library
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DISPLAY_CONTROL_H
#define __DISPLAY_CONTROL_H
  
/* Includes ------------------------------------------------------------------*/
#include "hal_gpio.h"
#include <sys/timeb.h> 
#include <stdio.h>
#include <stdlib.h>

/* Exported variables --------------------------------------------------------*/
/**
  * @brief Start of program execution timestamp
  */
extern struct timeb timestamp_start;

/**
  * @brief Log file handler
  */
extern FILE* logfile;

/* Typedef -------------------------------------------------------------------*/
typedef struct {
	GPIO_TypeDef* Port;
	uint16_t CLOCK_Pin;
	uint16_t DATA1_Pin;
	uint16_t DATA2_Pin;
	uint16_t DATA3_Pin;
	uint16_t DATA4_Pin;
	uint32_t ClockPeriod; 
} DISP_HandleTypeDef;

/* Public function prototypes ------------------------------------------------*/

/**
 *
 */
void display_decimal(DISP_HandleTypeDef* hdisp, unsigned int number);

/**
 *
 */
void timestamp_init(void);  

/**
 *
 */
void logfile_init(char* filename);  

/**
 *
 */
void logfile_deinit();  

#endif // __DISPLAY_CONTROL_H