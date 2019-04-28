/**
 *  @file
 *  @brief Test suite for inttypes.h methods
 */

/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (C) 2019, Vaibhav Gupta
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <rtems/test.h>
#include <inttypes.h>
#include <stdio.h>
#include <errno.h>
#include <tmacros.h>
#include <stdint.h>
#include <stddef.h>

const char rtems_test_name[] = "PSXINTTYPE 01";

/* forward declarations to avoid warnings */
rtems_task Init(rtems_task_argument ignored);

rtems_task Init(rtems_task_argument ignored)
{
  int       base     = 10;
  char     *nptr1    = "123abc";
  char     *endptr1  = NULL;
  wchar_t  *nptr2    = L"-123junk";
  wchar_t  *endptr2  = NULL;
  intmax_t  status1;
  uintmax_t status2;
 

  TEST_BEGIN();

  puts( "\nChecking invalid base value" );
  rtems_test_assert( base >=2 && base <= 36 );
 
  /*Test for strtoimax  */
  puts( "Strtoimax Testcases...." );
  puts( "Generating Status" );
  status1 = strtoimax( nptr1, &endptr1, base );

  rtems_test_assert( status1 != 0);
  rtems_test_assert( base != EINVAL);
 
  puts( "Checking Garbage end of endptr" ); 
  rtems_test_assert( *endptr1 != '\0' );
 
  puts( "Checking Underflow Case" );
  rtems_test_assert( status1 >= INTMAX_MIN );
 
  puts( "Checking Overflow Case" );
  rtems_test_assert( status1 <= INTMAX_MAX ) ;
 
  printf( "status = %jd \n" , status1 );
 
  /*Test for strtoumax  */
  puts( "Strtoumax Testcases...." );
  puts( "Generating Status" );
  status2 = strtoumax( nptr1, &endptr1, base );
 
  rtems_test_assert( status2 != 0);
  rtems_test_assert( base != EINVAL);

  puts( "Checking Garbage end of endptr" ); 
  rtems_test_assert( *endptr1 != '\0' );
 
  puts( "Checking Overflow Case" );
  rtems_test_assert( status2 <= UINTMAX_MAX );
 
  printf( "status = %ju \n", status2 );
 
  /*Test for wcstoimax  */
  puts( "Wcstoimax Testcases...." );
  puts( "Generating Status" );
  status1 = wcstoimax( nptr2, &endptr2, base );
 
  rtems_test_assert( status1 != 0);
  rtems_test_assert( base != EINVAL);
 
  puts( "Checking Garbage end of endptr" ); 
  rtems_test_assert( *endptr2 != '\0' );
 
  puts( "Checking Underflow Case" );
  rtems_test_assert( status1 >= INTMAX_MIN );
 
  puts( "Checking Overflow Case" );
  rtems_test_assert( status1 <= INTMAX_MAX ) ;
 
  printf( "status = %jd \n", status1 );

  /*Test for wcstoumax  */
  puts( "wcstoumax Testcases...." );
  puts( "Generating Status" );
  status2 = wcstoumax( nptr2, &endptr2, base );
 
  rtems_test_assert( status2 != 0);
  rtems_test_assert( base != EINVAL);

  puts( "Checking Garbage end of endptr" ); 
  rtems_test_assert( *endptr2 != '\0' );
 
  puts( "Checking Overflow Case" );
  rtems_test_assert( status2 <= UINTMAX_MAX );
 
  printf( "status = %ju \n", status2 );
 

  TEST_END();
  rtems_test_exit(0);

}

/* NOTICE: the clock driver is explicitly disabled */

#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER

#define CONFIGURE_MAXIMUM_TASKS            1

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_INITIAL_EXTENSIONS RTEMS_TEST_INITIAL_EXTENSION

#define CONFIGURE_INIT
#include <rtems/confdefs.h>
