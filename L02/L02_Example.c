/**
  ******************************************************************************
  * @file    L02_example.c
  * @author  AW           Adrian.Wojcik@put.poznan.pl
  * @version 2.0
  * @date    08-Mar-2022
  * @brief   Intruction #02 tasks solution template
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/* Define --------------------------------------------------------------------*/
#define T '1' /**< True symbol (T / H / 1) */
#define F '0' /**< False symbol (F / L / 0) */

#define NOT   '~' /**< Logisim negation symbol */
#define BLANK ' '

/* Macro ---------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Global variables ----------------------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

/* Function definitions ------------------------------------------------------*/

/**
 * @brief Logic function truth table printing procedure
 * @param[in] fcn   Logic function 
 * @param[in] bits  Input size (number of bits)
 * @return None
 */
void print_truth_table(_Bool fcn(unsigned int), unsigned int bits)
{
  int j;
  printf("    |");
  for(j = 0; j < bits; j++)
    printf(" %c |", (char)j + 'a');
  printf(" %s |\n", "fcn");
    
  unsigned int i;
  for(i = 0; i < (1 << bits); i++)
  {
    printf("%3d |",i);
    for(j = bits-1; j >= 0; j--)
      printf(" %c |", (i & (1 << j)) ? T : F);
    printf("  %c  |\n", fcn(i) ? T : F);
  }
}

/**
 * @brief Saves C-string to text file.
 * @param[in] filename  File name 
 * @param[in] buffer    Input C-string to be saved in text file
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
 * @brief Sum Of Product (SOP) forumla printing procedure
 * @param[in] fcn   Logic function 
 * @param[in] bits  Input size (number of bits)
 * @return None
 */
void print_and_save_sop(_Bool fcn(unsigned int), unsigned int bits)
{
  int j;
  unsigned int i;
  char buffer[4096];
  int len = 0;
  _Bool is_firt = 1;
  for(i = 0; i < (1 << bits); i++)
  {
    if(fcn(i) == 1)
    {
      len += sprintf(buffer+len, "%c(", is_firt ? ' ' : '+');
	  is_firt = 0;
      for(j = bits-1; j > 0; j--)
        len += sprintf(buffer+len,"%c%c * ",   (i & (1 << j)) ? BLANK : NOT, (char)(bits - (j+1)) + 'a');
      len += sprintf(buffer+len,"%c%c)\n", (i & (1 << j)) ? BLANK : NOT, (char)(bits - (j+1)) + 'a');
    }
  }
  printf("%s", buffer);
  save_buffer_to_file("sop.txt", buffer);
}

/**
 * @brief Product Of Sum (POS) forumla printing procedure
 * @param[in] fcn   Logic function 
 * @param[in] bits  Input size (number of bits)
 * @return None
 */
void print_and_save_pos(_Bool fcn(unsigned int), unsigned int bits)
{
  int j;
  unsigned int i;
  char buffer[4096];
  int len = 0;
  _Bool is_firt = 1;
  for(i = 0; i < (1 << bits); i++)
  {
    if(fcn(i) == 0)
    {
      len += sprintf(buffer+len, "%c(", is_firt ? ' ' : '*');
      is_firt = 0;
      for(j = bits-1; j > 0; j--)
        len += sprintf(buffer+len,"%c%c + ",   (i & (1 << j)) ? NOT : BLANK, (char)(bits - (j+1)) + 'a');
      len += sprintf(buffer+len,"%c%c)\n", (i & (1 << j)) ? NOT : BLANK, (char)(bits - (j+1)) + 'a');
    }
  }
  printf("%s", buffer);
  save_buffer_to_file("pos.txt", buffer);
}

/**
 * @brief Logic function <<TODO>>
 * @param[in] x Integer input
 * @return <<TODO>>
 */
_Bool my_fcn(unsigned int x) // <<TODO>> CHANGE NAME FUNCTION!
{
  // USER CODE BEGIN
  return ((x % 3) == 0);
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
  // call example
  puts("Truth table: ");
  print_truth_table(my_fcn, number_of_bits); 
  puts("\nSum of product:");
  print_and_save_sop(my_fcn, number_of_bits);
  puts("\nProduct of sum:");
  print_and_save_pos(my_fcn, number_of_bits);
  return 0;
}

/* Function definitions ------------------------------------------------------*/
