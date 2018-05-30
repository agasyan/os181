/*
 Copyright 2018 Rahmat M. Samik-Ibrahim
 You are free to SHARE (copy and 
 redistribute the material in any medium
 or format) and to ADAPT (remix, 
 transform, and build upon the material 
 for any purpose, even commercially).
 This program is distributed in the hope 
 that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied 
 warranty of MERCHANTABILITY or FITNESS 
 FOR A PARTICULAR PURPOSE.

 * REV02 Wed May  2 11:30:19 WIB 2018
 * REV01 Wed Apr 18 19:50:01 WIB 2018
 * START Thu Mar 30 16:56:54 WIB 2017

 * fd2 = dup(fd1)  duplicates fd1 to fd2
 * O_RDWR   Open the file so that it can 
            be read from and written to.
 * O_TRUNC  Initially clear all data from 
            the file.
 * O_CREAT  If the file does not exist, 
            create it. 
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define FLAGS O_RDWR|O_TRUNC|O_CREAT
#define FILE "61-open-dup-demo.txt"

static char* str1 = "AAAAAAAAAA";
static char* str2 = "BBBBB";

void main(void) {
   int fd1, fd2, fd3;
   /* STDIN=0, STDOUT=1, STDERR=2,
      fd1,fd2,fd3  will be 3,4,and 5 */
   fd1=open(FILE, FLAGS, 0644);
   fd2=open(FILE, FLAGS, 0644);
   fd3=dup(fd1);
   dprintf(fd1,"%s",        str1);
   dprintf(fd2,"X%dX%dX%dX",fd1,fd2,fd3);
   dprintf(fd3,"%s",        str2);
   close(fd1);
   close(fd2);
   close(fd3);
}

