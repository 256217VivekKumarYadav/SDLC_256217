/**
 * @file test_up_down.c
 * @author Praveen Kumar G - 99004437(praveen.kumar5@ltts.com)
 * @brief Unit Testing for Matrix Line input option
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "unity_internals.h"
#include "unity.h"
#include "matrix.h"

/* Required by the unity test framework */
void setUp(){}

/* Required by the unity test framework */
void tearDown(){}


int test_matrix_line_opt(t_struct *s, int key, int *i)
{
    TEST_ASSERT_EQUAL(Warning: Out of range., test_matrix_line_opt( 0 ,0, 0));
    //TEST_ASSERT_EQUAL(3, pack_nb( 0 ,3, 1));
    //TEST_ASSERT_EQUAL(12,pack_nb( 1 ,2, 2));
    //TEST_ASSERT_EQUAL(" ",pack_nb( 1 ,0x107 ,1));
    //TEST_ASSERT_EQUAL(" ",pack_nb( 10 ,0x107 ,2));
}
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  //RUN_TEST(test_mainmenu);
  RUN_TEST(test_matrix_line_opt);
  

  /* Close the Unity Test Framework */
  return UNITY_END();
}
