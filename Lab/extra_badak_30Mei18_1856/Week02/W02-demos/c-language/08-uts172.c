/*
 * Copyright (C) 2017-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV01 Thu Apr 12 19:58:40 WIB 2018
 * START Mon Oct 16 21:15:03 WIB 2017
 */

#include <stdio.h>

char globalChar='a';

char* getGlobal(void) {
   char* charPTR=&globalChar;
   printf("getGlobal1 %c\n", globalChar);
   *charPTR='b';
   printf("getGlobal2 %c\n", *charPTR);
   return charPTR;
}

void main (void) {
   char localChar='c';
   printf("==== main1 %c\n", localChar);
   localChar=*getGlobal();
   printf("==== main2 %c\n", localChar);
}

