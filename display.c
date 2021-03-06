/******************************************************************************
 * File:         display.c
 * Version:      1.4
 * Date:         2018-02-20
 * Author:       M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS exercise 2: syntax check
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "displayFunctions.h"

int main(int argc, char *argv[]) 
{ 
  int niceIncr; 
  unsigned long int numOfTimes;
  char printMethod, printChar;
  ErrCode err;
  
  err = SyntaxCheck(argc, argv);  // Check the command-line parameters
  
if(err != NO_ERR) DisplayError(err);        // Print an error message
  
    printMethod = argv[1][0];
    numOfTimes = strtoul(argv[2], NULL, 10);  // String to unsigned long
    niceIncr = (int) strtoul(argv[3], NULL, 10);
    
switch(fork())
{
case -1:
    printf("fork failed.\n");
    break;

//child process
case 0:
    nice(niceIncr * 1);
    printChar = argv[5][0];
    PrintCharacters(printMethod, numOfTimes, printChar);  // Print character printChar numOfTimes times using method printMethod
    break;
 } 
  printf("\n");  // Newline at end
  return 0;
}
