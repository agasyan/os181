/*
 * Copyright (C) 2013-2018 CC BY-SA 3.0 adapted from https://stackoverflow.com/
 *            questions/5656530/how-to-use-shared-memory-with-linux-in-c
 * Copyright (C) 2018 Rahmat M. Samik-Ibrahim (slightly modified)
 * You are free to SHARE (copy and redistribute the material in any medium or 
 * format) and to ADAPT (remix, transform, and build upon the material for any 
 * purpose, even commercially).  This program is distributed in the hope that 
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV01 Mon Apr 23 11:52:29 WIB 2018
 * REV00 Wed Apr 18 19:50:01 WIB 2018
 * START Xxx Xxx XX XX:XX:XX WIB 2015
 */


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>

char parent_message[] = "You say Hello";  // parent process will write this message
char child_message[]  = "And I say Goodbye"; // child process will then write this one

int main() {
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_ANONYMOUS | MAP_SHARED;
  char* shmem = mmap(NULL, 128, protection, visibility, 0, 0);
  memcpy(shmem, parent_message, sizeof(parent_message));
  int pid = fork();
  if (pid == 0) {
    printf("Child read:  %s\n", shmem);
    memcpy(shmem, child_message, sizeof(child_message));
    printf("Child wrote: %s\n", shmem);
  } else {
    printf("Parent read: %s\n", shmem);
    sleep(1);
    printf("After 1s, parent read: %s\n", shmem);
  }
}

