/**
  ******************************************************************************
  * @file    L04_example_02.cpp
  * @author  AW           Adrian.Wojcik@put.poznan.pl
  * @version 2.0
  * @date    14-Mar-2022
  * @brief   Instruction #04 tasks solution example
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <cstdint>
#include <bitset>

/* Define --------------------------------------------------------------------*/

/* Macro ---------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/
typedef void (*reg_output_func)(uint32_t*, uint32_t);
typedef bool (*reg_input_func)(uint32_t*, uint32_t);

/* Global variables ----------------------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/

// Unit tests prototypes 
int unit_test_set_bit(reg_output_func set_bit);
int unit_test_reset_bit(reg_output_func reset_bit);
int unit_test_toggle_bit(reg_output_func toggle_bit);
int unit_test_read_bit(reg_input_func read_bit);

/* Function definitions ------------------------------------------------------*/

/**
 * @brief Register manipulation: setting selected bit in 32-bit register
 * @param[in] reg Register address
 * @param[in] bit Bit number to set [0-31]
 */
void reg_set_bit(uint32_t* reg, uint32_t bit)
{
/* USER CODE BEGIN: reg_set_bit */
std::bitset<32> bits(*reg);
bits.set(bit, true);
*reg = static_cast<uint32_t>(bits.to_ulong());
/* USER CODE END: reg_set_bit */
}

/**
 * @brief Register manipulation: resetting selected bit in 32-bit register
 * @param[in] reg Register address
 * @param[in] bit Bit number to reset [0-31]
 */
void reg_reset_bit(uint32_t* reg, uint32_t bit)
{
/* USER CODE BEGIN: reg_reset_bit */
std::bitset<32> bits(*reg);
bits.set(bit, false);
*reg = static_cast<uint32_t>(bits.to_ulong());
/* USER CODE END: reg_reset_bit */
}

/**
 * @brief Register manipulation: toggling selected bit in 32-bit register
 * @param[in] reg Register address
 * @param[in] bit Bit number to toggle [0-31]
 */
void reg_toggle_bit(uint32_t* reg, uint32_t bit)
{
/* USER CODE BEGIN: reg_toggle_bit */
std::bitset<32> bits(*reg);
bits.flip(bit);
*reg = static_cast<uint32_t>(bits.to_ulong());
/* USER CODE END: reg_toggle_bit */
}

/**
 * @brief Register manipulation: reading selected bit in 32-bit register
 * @param[in] reg Register address
 * @param[in] bit Bit number to read [0-31]
 * @return Selected bit value [0/1]
 */
bool reg_read_bit(uint32_t* reg, uint32_t bit)
{
bool retval;
/* USER CODE BEGIN: reg_read_bit */
std::bitset<32> bits(*reg);
retval = bits[bit];
/* USER CODE END: reg_read_bit */
return retval;
}

/* Main function -------------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval 0 
  */
int main()
{
    /* Execute unit test #1: reg_set_bit function */ 
    std::cout << "Unit test #1: reg_set_bit ";
    if(unit_test_set_bit(reg_set_bit) == 0)
      std::cout <<  "succeeded." << std::endl;
    else
      printf("failed.\n");
    
    /* Execute unit test #2: reg_reset_bit function */ 
    std::cout << "Unit test #2: reg_reset_bit ";
    if(unit_test_reset_bit(reg_reset_bit) == 0)
      std::cout <<  "succeeded." << std::endl;
    else
      printf("failed.\n");
    
    /* Execute unit test #3: reg_toggle_bit function */ 
    std::cout << "Unit test #3: reg_toggle_bit ";
    if(unit_test_toggle_bit(reg_toggle_bit) == 0)
      std::cout <<  "succeeded." << std::endl;
    else
      printf("failed.\n");
    
    /* Execute unit test #4 reg_red_bit function */ 
    std::cout << "Unit test #4: reg_red_bit ";
    if(unit_test_read_bit(reg_read_bit) == 0)
      std::cout <<  "succeeded." << std::endl;
    else
      printf("failed.\n");
    
    return 0;
}

/* Function definitions ------------------------------------------------------*/

/* Unit tests implementation */
int unit_test_set_bit(reg_output_func set_bit)
{
  uint32_t input = 0x00000000;
  uint32_t output = 0xFFFFFFFF;
  for(uint8_t i = 0; i < 32; i++)
    set_bit(&input, i);
  if(input == output)
    return 0;  // Success
   else
    return -1; // Fail 
}

int unit_test_reset_bit(reg_output_func reset_bit)
{
  uint32_t input = 0xFFFFFFFF;
  uint32_t output = 0xFFFF0000;
  for(uint8_t i = 0; i < 16; i++)
    reset_bit(&input, i);
  if(input == output)
    return 0;  // Success
   else
    return -1; // Fail 
}

int unit_test_toggle_bit(reg_output_func toggle_bit)
{
  uint32_t input = 0x0000AAAA;
  uint32_t output = 0x00005555;
  for(uint8_t i = 0; i < 16; i++)
    toggle_bit(&input, i);
  if(input == output)
    return 0;  // Success
   else
    return -1; // Fail 
}

int unit_test_read_bit(reg_input_func read_bit)
{
  uint32_t input = 0xABCDEF89;
  uint32_t output = 0x00000000;
  uint32_t output_ref = 0xABCDEF89;
  for(uint8_t i = 0; i < 32; i++)
    output |= ((uint32_t)read_bit(&input, i) << i);
  if(output == output_ref)
    return 0;  // Success
   else
    return -1; // Fail 
}