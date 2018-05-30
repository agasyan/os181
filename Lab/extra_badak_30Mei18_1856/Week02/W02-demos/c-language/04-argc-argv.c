/*
 * Copyright (C) 2016-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV01 Mon Sep 18 09:16:59 WIB 2017
 * START Tue Sep 13 12:11:09 WIB 2016
 */

#include <stdio.h>
void main(int argc, char *argv[]) {
   int ii;
   printf("The value of argc    is %d\n", argc);
   printf("=============================================\n");
   for (ii=argc-1; ii >= 0; ii--) {
      printf("The value of argv[%d] is %s\n", ii, argv[ii]);
   }
   printf("=============================================\n");
}

