#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Basic.h"
void exit(long);
void abort(void);
int main(void);
extern AddTests();
int main(void)
{
//Define the run mode for the basic interface.
//Verbose mode - maximum output of run details.
 CU_BasicRunMode mode = CU_BRM_VERBOSE;
 //Define error action
 //Runs should be continued when an error condition occurs (if possible)
 CU_ErrorAction error_action = CUEA_IGNORE;
 //Initializes the framework test registry
 if (CU_initialize_registry()) {
 printf("\nInitialization of Test Registry failed.");
 }
 else {
 //call add test function
 AddTests();
 //Sets the basic run mode, which controls the output during test runs
 CU_basic_set_mode(mode);
 //Sets the error action
CU_set_error_action(error_action);
 //Runs all tests in all registered suites
 printf("\nTests completed with return value %d.\n",
CU_basic_run_tests());
 //Call this function to clean up
//and release memory used by the framework
 CU_cleanup_registry();
 }
 return 0;
}
void abort(void){}
void exit(long exitcode){}
