@c
@c  COPYRIGHT (c) 1988-1998.
@c  On-Line Applications Research Corporation (OAR).
@c  All rights reserved.
@c
@c  $Id$
@c

@chapter Building the Sample Application

@section Unpack the sample application 

Use the following command to unarchive the sample application:

@example
cd tools
tar xzf ../arc/hello_world_c.tgz
@end example

@section Set the environment variable RTEMS_MAKEFILE_PATH 

It must point to the appropriate directory containing RTEMS build for our
target and board support package combination. 

@example
export RTEMS_MAKEFILE_PATH = \
<INSTALLATION_POINT>/rtems/<BOARD_SUPPORT_PACKAGE>
@end example

Where:

<INSTALLATION_POINT> and <BOARD_SUPPORT_PACKAGE> are those used when
configuring and installing RTEMS.

@section Build the Sample Application

Use the following command to start the build of the sample application: 

@example
cd tools/hello_world_c
gmake
@end example

If no errors are detected during the sample application build, it is
reasonable to assume that the build of the GNU C/C++ Cross Compiler Tools
for RTEMS and RTEMS itself for the selected host and target
combination was done properly. 

@section Application executable 

If the sample application has successfully been build, then the application
executable is placed in the following directory: 

@example
tools/simple_app/o-<BOARD_SUPPORT_PACKAGE>/<filename>.exe
@end example

How this executable is downloaded to the target board is very dependent
on the BOARD_SUPPORT_PACKAGE selected.
