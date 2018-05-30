/*
 * Copyright (C) 2017-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV01 Thu Apr 12 20:46:48 WIB 2018
 * START Mon Oct 16 21:15:03 WIB 2017
 */

#include <stdio.h>

char* stringChar="HALLO";
char* stringPTR;

void main (void) {
    stringPTR=stringChar;
    printf ("ADDR1: %p VAL: %p STR: %s\n", &stringChar, stringChar, stringChar);
    printf ("ADDR2: %p VAL: %p STR: %s\n", &stringPTR,  stringPTR, stringPTR);
    while (*(++stringPTR) != 0 ) {
         printf ("ADDR3: %p VAL: %p STR: %s\n", &stringPTR,  stringPTR, stringPTR);
    }
    printf ("End of String = %p\n", stringPTR);
}

