/*
 * Copyright (C) 2016-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV01 Tue Feb 27 09:16:26 WIB 2018
 * START Thu Sep 15 11:47:10 WIB 2016
 */

#include <stdio.h>

void main (void) {
   int   ii=3;
   int   jj[]={1,2,3,4,5};
   char  cc='A';
   char  dd[]="This is a string";

   printf("Hello -- ");
   printf("This is a TEST\n");

   printf("The value of ii     is %d\n", ii);
   printf("The value of jj[0]  is %d\n", jj[0]);
   printf("The value of jj[4]  is %d\n", jj[4]);
   printf("The value of jj[%d]  is %d\n", ii, jj[ii]);
  
   printf("The value of cc     is %c\n", cc);
   printf("The value of dd[0]  is %c\n", dd[0]);
   printf("The value of dd[%d]  is %c\n", ii, dd[ii]);

   printf("The value of dd is  %s\n", dd);

}

