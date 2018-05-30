/*
 * Copyright (C) 2013-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV02 Tue Feb 27 09:17:15 WIB 2018
 * START 2013
 */

#define LINETXT "==========\n"
#define OLOOPTXT "OL [%4.4d]\n"
#define OLOOP  4
#define ILOOP  3

#include <stdio.h>
void main(void) {
   int ii, jj;
   printf(LINETXT);
   for (ii=0; ii<OLOOP; ii++) {
      printf(OLOOPTXT, ii);
      for (jj=0; jj<ILOOP; jj++) {
         printf("    IL[%d]\n",jj);
      }
   }
   printf(LINETXT);
}

