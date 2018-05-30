/*
 * Copyright (C) 2015-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06 Tue Apr 17 09:30:55 WIB 2018
 * REV02 Tue Apr 18 15:28:19 WIB 2017
 * REV01 Wed Nov  2 11:49:30 WIB 2016
 * START Xxx Sep 30 XX:XX:XX UTC 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"

#define  LOOP0      5
#define  LOOP1 500900
#define  LOOP2 500000

volatile int loop = LOOP0;
int          share;

void* thread1 (void* a) {
   int ii, jj=0;
   printf("I am a thread no 1\n");
   sleep(1);
   share = 1000;
   while (loop > 0) {
      for (ii=0;ii<LOOP1;ii++) 
         jj++;
      share++;
   }
}

void* thread2 (void* a) {
   int ii, jj=0;
   printf("I am a thread no 2\n");
   sleep(1);
   share = 2000;
   while (loop > 0) {
      for (ii=0;ii<LOOP2;ii++) 
         jj++;
      share--;
   }
}

void* thread3 (void* a) {
   printf("I am a thread no 3\n");
   sleep(1);
   while (loop-- > 0) {
      sleep(2);
      printf("SHARE = %4.4d\n", share);
   }
}

void main(void) {
   daftar_trit   (thread1);
   daftar_trit   (thread2);
   daftar_trit   (thread3);
   jalankan_trit ();
   printf        ("I am MAIN\n");
   beberes_trit  ("Done...");
}

