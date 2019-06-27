/*
 *  COPYRIGHT (c) 1989-2012.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <rtems.h>
#include <tmacros.h>

#include <ndbm.h>
#include <stdio.h>
#include <fcntl.h>

#define NAME       "Arturo Crespo"
#define PHONE_NO   "723-9273"
#define DB_NAME    "phones"

const char rtems_test_name[] = "HELLO WORLD";

static rtems_task Init(
  rtems_task_argument ignored
)
{
  rtems_print_printer_fprintf_putc(&rtems_test_printer);
  TEST_BEGIN();
  printf( "Hello World\n" );

          DBM *db;
          datum name = {NAME, sizeof (NAME)};
          datum put_phone_no = {PHONE_NO, sizeof (PHONE_NO)};
          datum get_phone_no;
   
          // Open the database and store the record
          db = dbm_open(DB_NAME, 0600, O_RDWR | O_CREAT);
          dbm_store(db, name, put_phone_no, DBM_INSERT);
   
          // Retrieve the record
          get_phone_no = dbm_fetch(db, name);
          printf("\nName: %s, \nPhone Number: %s", (char *)name.dptr, (char *)get_phone_no.dptr);

          // Close the database
          dbm_close(db);


  TEST_END();
  rtems_test_exit( 0 );
}


/* NOTICE: the clock driver is explicitly disabled */
#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_SIMPLE_CONSOLE_DRIVER

#define CONFIGURE_MAXIMUM_TASKS            1

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_INIT_TASK_ATTRIBUTES RTEMS_FLOATING_POINT

#define CONFIGURE_INITIAL_EXTENSIONS RTEMS_TEST_INITIAL_EXTENSION

#define CONFIGURE_INIT
#include <rtems/confdefs.h>
