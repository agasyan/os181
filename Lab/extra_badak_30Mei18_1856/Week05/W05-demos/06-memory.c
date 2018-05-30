/*
 * Copyright (C) 2016-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV04 Mon Mar 12 17:33:30 WIB 2018
 * START Mon Oct  3 09:26:51 WIB 2016
 */

#define MSIZE0 0x10000
#define MSIZE1 0x10008
#define MSIZE2 0x10009
#define MSIZE3 0x1000A
#define MSIZE4 0x20978
#define MSIZE5 0x20979
#define MSIZE6 0x2097A
#define MSIZE7 0xF0000
#define MSIZE8 0x10000
#define MSIZE9 0x1000
#define LINE   75
#define MAXSTR 80
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

void printLine(int line) {
   while(line-- > 0) putchar('x');
   putchar('\n');
   fflush(NULL);
}

void main (void) {
   int   msize[] = {MSIZE0, MSIZE1, MSIZE2, MSIZE3, MSIZE4, 
                    MSIZE5, MSIZE6, MSIZE7, MSIZE8, MSIZE9};
   int   ii, jj;
   int   myPID   = (int) getpid();
   char  strSYS1[MAXSTR], strOUT[MAXSTR];
   char* chrStr  = strSYS1;
   char* chrPTR; 

   printLine(LINE);
   sprintf(strSYS1, "top -b -n 1 -p%d | tail -5", myPID);
   system (strSYS1);
   sprintf(strSYS1, "top -b -n 1 -p%d | tail -1", myPID);
   for (ii=0; ii< (sizeof(msize)/sizeof(int)); ii++){
      chrStr = malloc(msize[ii]);
      fgets(strOUT, sizeof(strOUT)-1, popen(strSYS1, "r"));
      strOUT[(int) strlen(strOUT)-1]='\0';
      printf("%s [%X]\n", strOUT, msize[ii]);
      free(chrStr);
   }
   for (ii=0; ii< (sizeof(msize)/sizeof(int)); ii++){
      chrPTR = chrStr = malloc(msize[ii]);
      for (jj=0;jj<msize[ii];jj++)
         *chrPTR++='x';
      fgets(strOUT, sizeof(strOUT)-1, popen(strSYS1, "r"));
      strOUT[(int) strlen(strOUT)-1]='\0';
      printf("%s [%X]\n", strOUT, msize[ii]);
      free(chrStr);
   }
}

