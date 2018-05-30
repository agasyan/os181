/*
 * Copyright (C) 2013-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV01 Tue Feb 27 09:19:16 WIB 2018
 * START 2013
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(void) {
   printf("Process Identifier (PID) [%5.5d] -- Perent PID (PPID[%5.5d])\n", getpid(), getppid());
   sleep(1);
}

