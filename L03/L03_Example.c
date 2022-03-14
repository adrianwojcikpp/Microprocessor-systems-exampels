/**
  ******************************************************************************
  * @file    L03_example.c
  * @author  AW           Adrian.Wojcik@put.poznan.pl
  * @version 2.0
  * @date    14-Mar-2022
  * @brief   Instruction #03 tasks solution template
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define --------------------------------------------------------------------*/
#define T '1' /**< True symbol (T / H / 1) */
#define F '0' /**< False symbol (F / L / 0) */

#define NOT   '~' /**< Logisim negation symbol */
#define BLANK ' '

#define PROD '*' /**< Logisim Evolution product symbol */
//#define PROD ' ' /**< Logisim product symbol */

/* Macro ---------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Global variables ----------------------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

/* Function definitions ------------------------------------------------------*/

/**
 * @brief Saves C-string to text file.
 * @param[in] filename : File name 
 * @param[in] buffer   : Input C-string to be saved in text file
 * @return None
 */
void save_buffer_to_file(char* filename, char* buffer)
{
  FILE *hFile;
  hFile = fopen(filename,"w");
  if(hFile == NULL)
  {
    printf("Cannot open '%s' file for writing.", filename);
    return;
  }
  fprintf(hFile,"%s", buffer);
  fclose(hFile);
}

/**
 * @brief Logic function truth table printing procedure
 * @param[in] fcn      : Logic function 
 * @param[in] bits     : Input size (number of bits)
 * @param[in] filename : Result file name
 * @return None
 */ 
void print_truth_table(_Bool fcn(unsigned int), unsigned int bits, char* filename)
{
  char buffer[4096];
  int len = 0;
  
  // print table header
  for(int j = 0; j < bits; j++)
    len += sprintf(buffer+len," %c ", (char)j + 'a');
  len += sprintf(buffer+len,"| %s \n", "x");

  // print table body
  for(unsigned int i = 0; i < (1 << bits); i++)
  {
    // print logic function values
    for(int j = bits-1; j >= 0; j--)
      len += sprintf(buffer+len," %c ", (i & (1 << j)) ? T : F);
    len += sprintf(buffer+len,"| %c \n", fcn(i) ? T : F);
  }
  
  printf("%s", buffer);
  save_buffer_to_file(filename, buffer);
}

/**
 * @brief Sum Of Product (SOP) formula printing procedure
 * @param[in] fcn      : Logic function 
 * @param[in] bits     : Input size (number of bits)
 * @param[in] filename : Result file name
 * @return None
 */
void print_and_save_sop(_Bool fcn(unsigned int), unsigned int bits, char* filename)
{
  char buffer[4096];
  int len = 0;
  _Bool is_firt = 1;
  for(unsigned int  i = 0; i < (1 << bits); i++)
  {
    if(fcn(i) == 1)
    {
      len += sprintf(buffer+len, "%c(", is_firt ? ' ' : '+');
      is_firt = 0;
      int j;
      for(j = bits-1; j > 0; j--)
        len += sprintf(buffer+len, "%c%c%c", (i & (1 << j)) ? BLANK : NOT, (char)(bits - (j+1)) + 'a', PROD);
      len += sprintf(buffer+len, "%c%c)\n",  (i & (1 << j)) ? BLANK : NOT, (char)(bits - (j+1)) + 'a');
    }
  }
  printf("%s", buffer);
  save_buffer_to_file(filename, buffer);
}

/**
 * @brief Product Of Sum (POS) formula printing procedure
 * @param[in] fcn      : Logic function 
 * @param[in] bits     : Input size (number of bits)
 * @param[in] filename : Result file name
 * @return None
 */
void print_and_save_pos(_Bool fcn(unsigned int), unsigned int bits, char* filename)
{
  char buffer[4096];
  int len = 0;
  _Bool is_firt = 1;
  for(unsigned int i = 0; i < (1 << bits); i++)
  {
    if(fcn(i) == 0)
    {
      len += sprintf(buffer+len, "%c(", is_firt ? ' ' : PROD);
      is_firt = 0;
      int j;
      for(j = bits-1; j > 0; j--)
        len += sprintf(buffer+len, "%c%c + ", (i & (1 << j)) ? NOT : BLANK, (char)(bits - (j+1)) + 'a');
      len += sprintf(buffer+len, "%c%c)\n",   (i & (1 << j)) ? NOT : BLANK, (char)(bits - (j+1)) + 'a');
    }
  }
  printf("%s", buffer);
  save_buffer_to_file(filename, buffer);
}

/**
 * @brief 2-bit number comparator
 * @param[in] x two 2-bit integer input (bits AB and CD)
 * @return 1 if input is valid; 0 otherwise
 */
_Bool two_bit_comparator(unsigned int x) 
{
  // USER CODE BEGIN
  unsigned int ab = (x / 4) % 4;
  unsigned int cd = (x / 1) % 4;
  return ( cd >= ab );
  // USER CODE END
}

/**
 * @brief Logic function checking whether 
 *        LED line input is valid
 * @details LED line structure:
 * 
 *          [    ] A (MSB)
 *          [    ] B 
 *          [    ] C 
 *          [    ] D
 *          [    ] E (LSB)
 *
 *          Valid inputs:
 * 
 *          [    ] A    [    ] A    [    ] A 
 *          [    ] B    [    ] B    [    ] B
 *          [    ] C    [    ] C    [    ] C
 *          [    ] D    [    ] D    [####] D
 *          [    ] E    [####] E    [####] E 
 *
 *          [    ] A    [    ] A    [####] A 
 *          [    ] B    [####] B    [####] B
 *          [####] C    [####] C    [####] C
 *          [####] D    [####] D    [####] D
 *          [####] E    [####] E    [####] E 
 *
 * @param[in] x 5-bit integer input (bits ABDCE)
 * @return 1 if input is valid; 0 otherwise
 */
_Bool is_led_line_input_valid(unsigned int x) 
{
  // USER CODE BEGIN
  unsigned int a = (x / 16) % 2;
  unsigned int b = (x / 8) % 2;
  unsigned int c = (x / 4) % 2;
  unsigned int d = (x / 2) % 2;
  unsigned int e = (x / 1) % 2;
  return ( (e >= d) && (d >= c) && (c >= b) && (b >= a));
  // USER CODE END
}

/**
 * @brief Logic function checking whether 
          number is divisible by 3
 * @param[in] x Integer input 
 * @return 1 if is divisible by 3; 0 otherwise
 */
_Bool is_divisible_by_3(unsigned int x) 
{
  // USER CODE BEGIN
  return ( x % 3 == 0 );
  // USER CODE END
}

/* Main function -------------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval 0 
  */
int main(void)
{
  int number_of_bits = 5;
  _Bool (*fcn)(unsigned int) = &is_divisible_by_3;
  
  puts("\n\nTASK #1 -------------------------------------------------------------------------- ");
  puts("Truth table: ");
  print_truth_table(fcn, number_of_bits, "tt_task_1.txt"); 
  puts("\nSum of product:");
  print_and_save_sop(fcn, number_of_bits, "sop_task_1.txt");
  puts("\nProduct of sum:");
  print_and_save_pos(fcn, number_of_bits, "pos_task_1.txt");
  
  number_of_bits = 5;
  fcn = &is_led_line_input_valid;
  
  puts("\n\nTASK #2 -------------------------------------------------------------------------- ");
  puts("Truth table: ");
  print_truth_table(fcn, number_of_bits, "tt_task_2.txt"); 
  puts("\nSum of product:");
  print_and_save_sop(fcn, number_of_bits, "sop_task_2.txt");
  puts("\nProduct of sum:");
  print_and_save_pos(fcn, number_of_bits, "pos_task_2.txt");
  
  number_of_bits = 4;
  fcn = &two_bit_comparator;
  
  puts("\n\nTASK #3 -------------------------------------------------------------------------- ");
  puts("Truth table: ");
  print_truth_table(fcn, number_of_bits, "tt_task_3.txt"); 
  puts("\nSum of product:");
  print_and_save_sop(fcn, number_of_bits, "sop_task_3.txt");
  puts("\nProduct of sum:");
  print_and_save_pos(fcn, number_of_bits, "pos_task_3.txt");

  return 0;
}

/* Function definitions ------------------------------------------------------*/
