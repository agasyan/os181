# DEMOS Week06: Forking in C language

[Link Solusi Week06](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/Lab06_SOL.md)

OS181 - Operating System 2018 Term (1)

* * *

START : Mon Apr 30 12:05:53 WIB 2018

REV01 : Tue Mei 01 05:30:02 WIB 2018
REV02 : Wed Mei 02 20:49:09 WIB 2018

* * *

## Petunjuk Umum

Sebelum melihat penjelasan sebaiknya sudah menjalankan dan mempelajari Week06 yang ada pada [link](https://github.com/UI-FASILKOM-OS/os181/tree/master/demos) berikut. Baik di komputer pribadi maupun di server kawung.

**Penjalanan Dari File C yang ada pada Week terkait :**

1. Sebelum meng-compile file pastikan semua file yang ingin dijalankan merupakan versi terbaru, untuk mengecek bisa gunakan perintah `git pull` atau mengecek folder extra di badak
2. Masuk ke folder terkait dan jalankan perintah `make`
3. Untuk melihat output program bisa menggunakan perintah `./[nama-file]`
4. Setelah selesai untuk menghapus file yang telah di compile

gunakan perintah `make clean`

* * *

## Penjelasan Mengenai File - file yang ada pada week06

### 00-show-pid.c

**File C :**

```  C
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(void) {
    printf(" [[[ This is 00-show-pid: PID[%d] PPID[%d] ]]]\n", getpid(), getppid());
}
```

**Output Dari File C :**

![00-show-pid.c](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/00-out.JPG)

**Penjelasan Output Dari File C :**

Dari penjalanan program C diketahui bahwa PPID atau biasa yang disebut __Parent PID__ akan tetap sama dalam penjalanan program tersebut berkali kali. 

PID akan terus berubah di tiap penjalanan file yang sudah di - compile dan biasanya nilainya akan naik (_increment_)

Penjelasan dari fungsi getpid() dan getppid():

>getpid() memberikan output berupa PID dari proses yang memanggil fungsi tersebut yang biasa digunakan oleh proses yang PID sering berubah ubah karena itu akibat dari random maupun untuk mengetahui apakah yang jalan adalah anak atau bukan akibat pemanggilan fork()memberikan output berupa PID dari parent yang memanggil fungsi ini. Biasanya merupakan PID dari proses yang memanggil fork() karena proses yang sedang berjalan merupakan anak dari proses tersebut.

* * *

### 01-fork.c

**File C :**

```  C
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void) {
   char *iAM="PARENT";
  
   printf("PID[%d] PPID[%d] (START:%s)\n", getpid(), getppid(), iAM);
   if (fork() > 0) {
      sleep(1);     /* LOOK THIS ************** */
      printf("PID[%d] PPID[%d] (IFF0:%s)\n", getpid(), getppid(), iAM);
   } else {
      iAM="CHILD";
      printf("PID[%d] PPID[%d] (ELSE:%s)\n", getpid(), getppid(), iAM);
   }
   printf("PID[%d] PPID[%d] (STOP:%s)\n", getpid(), getppid(), iAM);
}
```

**Output Dari File C :**

![01-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/01-fork.JPG)

**Penjelasan Output Dari File C :**

Penggambaran fork():

``` bash
106 (PID)
├── line 2 (print-1)
├── line 3 (fork())
├── line 4 (sleep(1))
├── 107 (PID)
│   ├── line 3(apakah dia parent? dengan mengecek return dari fork() lalu masuk else)
│   ├── line 6(iAM="CHILD")
│   ├── line 7 (print-2)
|   └── line 8 (print-3)
├── line 5 (print-4)
└── line 8 (print-5)
```

Pada Output Line pertama akan mencetak printf pertama sebagai
 penanda dia sebagai parent, lalu pid [106] akan membuat child yang
 mempunyai pid [107] akibat dari pemanggilan fungsi fork() dan pid
 [106] dan [107] akan lanjut ke line selanjutnya dimana dicek apakah dia merupakan parent process atau child process dan pid [106] akan berhenti akibat pemanggilan fungsi sleep(1) dan pid[107] akan masuk ke - else dan pid [107] akan melanjutkan semua sampai semua program selesai dan setelah pid[107] selesai pid[106] melanjutkannya karena dalam waktu 1 detik pid [107] sudah selesai mengerjakan _lines of code_ yang perlu dilakukan.

_Penjelasan fungsi fork():_
> fork() berfungsi untuk membuat proses baru dan me-return PID dari Child jika berhasil, dan untuk membedakan sebuah proses apakah dia parent atau child bisa menggunakan PID nya, fork() me-return 0 untuk proses baru yang dibuat dan negatif jika pemanggilan fork() gagal.

_Penjelasan Fungsi Sleep():_

>sleep() membuat fungsi yang memanggil untuk sleep(berhenti) untuk beberapa detik sesuai angka yang diberikan (yang menjadi argumen) kalau disini biasanya selama 1 detik.

* * *

### 02-fork.c

**File C :**

```  C
/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV03 Thu Oct 26 11:27:36 WIB 2017
 * REV01 Wed May  3 20:49:54 WIB 2017
 * START Mon Oct 24 09:42:05 WIB 2016
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void) {
   char *iAM="PARENT";
  
   printf("PID[%d] PPID[%d] (START:%s)\n", getpid(), getppid(), iAM);
   if (fork() > 0) {
      printf("PID[%d] PPID[%d] (IFF0:%s)\n", getpid(), getppid(), iAM);
   } else {
      iAM="CHILD";
      printf("PID[%d] PPID[%d] (ELSE:%s)\n", getpid(), getppid(), iAM);
      sleep(1);     /* LOOK THIS ************** */
   }
   printf("PID[%d] PPID[%d] (STOP:%s)\n", getpid(), getppid(), iAM);
}
```

**Output Dari File C :**

![02-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/02-fork.JPG)

**Penjelasan Output Dari File C :**

Penggambaran fork():

``` bash
108 (PID)
├── line 2 (print-1)
├── line 4 (print-2)
├── 109 (PID)
│   ├── line 3(apakah dia parent? dengan mengecek return dari fork() lalu masuk else)
│   ├── line 6(iAM="CHILD")
│   ├── line 7 (print-3)
|   └── line 8 (sleep)
├── line 10(print-4)
└── 109 (PID(child dari 108))
    └──line 10 (print-5) (setelah melakukan sleep)
```

Disini Parent Process memiliki PID [108] dan pada line ke - 3 saat menjalankan _if-clause_ membandingkannya dengan return nilai dari pemanggilan fungsi fork() yang membuat PID [108] membuat child process yang memiliki PID [109] dimana akan berjalan satu satu tergantung lines dimulai dari parent dan pada line ke 8 ada perintah berupa sleep dimana proses child akan berhenti dan parent akan print line ke - 10 dan tak lama kemudian PID[109] yaitu child dari PID[108] akan mencetak _output_ juga.

* * *

### 03-fork.c

**File C :**

```  C
/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV03 Thu Oct 26 11:27:01 WIB 2017
 * REV01 Wed May  3 20:49:54 WIB 2017
 * START Mon Oct 24 09:42:05 WIB 2016
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void) {
   char *iAM="PARENT";

   printf("PID[%d] PPID[%d] (START:%s)\n", getpid(), getppid(), iAM);
   if (fork() > 0) {
      wait(NULL);     /* LOOK THIS ************** */
      printf("PID[%d] PPID[%d] (IFF0:%s)\n", getpid(), getppid(), iAM);
   } else {
      iAM="CHILD";
      printf("PID[%d] PPID[%d] (ELSE:%s)\n", getpid(), getppid(), iAM);
   }
   printf("PID[%d] PPID[%d] (STOP:%s)\n", getpid(), getppid(), iAM);
}
```

**Output Dari File C :**

![03-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/03-fork.JPG)

**Penjelasan Output Dari File C :**

Penggambaran fork():

``` bash
110 (PID)
├── line 2 (print-1)
├── line 3 (pengecekan retun nilai fork())
├── line 4 (wait(NULL))
├── 111 (PID)
│   ├── line 3(apakah dia parent? dengan mengecek return dari fork() lalu masuk else)
│   ├── line 7(iAM="CHILD")
│   ├── line 8 (print-2)
|   └── line 10 (print-3)
├── line 5(print-4)
└── line 10 (print-5)
```

Hampir sama seperti perintah sleep adalah command wait(NULL) dimana Proses [110] akan berhenti sampai semua child proses selesai menjalankan program C (sampai line terakhir) dan baru parent akan jalan jika semua child sudah selesai menjalankan semua perintah sampai akhir.

* * *

### 04-sleep.c

**File C :**

```  C
/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV02 Mon Oct 30 10:24:44 WIB 2017
 * START Mon Oct 24 13:27:30 WIB 2016
 */

void main(void) {
   int ii;
   printf("Sleeping 3s with fflush(): ");
   fflush(NULL);
   for (ii=0; ii < 3; ii++) {
      sleep(1);
      printf("x ");
      fflush(NULL);
   }
   printf("\nSleeping with no fflush(): ");
   for (ii=0; ii < 3; ii++) {
      sleep(1);
      printf("x ");
   }
   printf("\n");
}
```

**Output Dari File C :**

![04-sleep](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/04-sleep.JPG)

**Penjelasan Output Dari File C :**

Karena data tidak dipindahkan ke console maka perintah sleep hanya dijalankan satu kali karena data yang perlu dijalankan masih berada di buffer atau karena buffer tidak dibersihkan pada _looping_ yang kedua, dengan menggunakan perintah fflush. Untuk lebih jelasnya bisa dilihat bagaimana program `04-sleep` bekerja.

_Penjelasan fflush():_
>fflush() biasanya digunakan hanya untuk output stream. Fungsi dari fflush adalah membersihkan buffer output dan pinda data yang sedang di buffer ke console atau ke disk.

* * *

### 05-fork.c

**File C :**

```  C
/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV04 Wed Nov  1 13:31:31 WIB 2017
 * START Mon Oct 24 09:42:05 WIB 2016
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void) {
   printf("Start:           PID[%d] PPID[%d]\n", getpid(), getppid());
   fflush(NULL);
   if (fork() == 0) {
      /* START BLOCK
      execlp("./00-show-pid", "00-show-pid", NULL);
         END   BLOCK */
      printf("Child:           ");
   } else {
      wait(NULL);
      printf("Parent:          ");
   }
   printf(        "PID[%d] PPID[%d]  <<< <<< <<<\n", getpid(), getppid());
}
```

**Output Dari File C :**

![05-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/05-fork.JPG)

**Penjelasan Output Dari File C :**

Penggambaran fork():

``` bash
113 (PID)
├── line 1 (print-1)
├── line 2 (fflush(NULL))
├── line 3 (if-clause fork() mengakibatkan dibuatnya child dan
            pengecekan nilai return dari pemanggilan fork())
├── line 9(Wait(NULL))
├── 114 (PID)
│   ├── line 7(print "Child: ")
│   └── line 12(print lanjutan dari Child yang berupa PID dan PPID)
├── line 10 (print "Parent :")
└── line 12(print lanjutan dari Parent yang berupa PID dan PPID)
```

Jika ada parent dan child yang berjalan maka parent berjalan lebih dulu dibanding childnya tetapi keduanya berjalan _line by line_. ketika parent _Wait(NULL)_ maka parent akan menunggu semua child process yang berada di bawahnya walaupun itu anaknya dari child process akan menunggu semua sampai selesai baru berjalan lagi programnya setelah Line dari _wait(NULL)_.

* * *

### 06-fork.c

**File C :**

```  C
/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV05 Wed Nov  1 13:34:33 WIB 2017
 * REV00 Mon Oct 24 10:43:00 WIB 2016
 * START 2005
 */

#include <sys/types.h>
#include <sys/wait.h> 
/*************************************************** main ** */
void main(void) {
   pid_t val1, val2, val3;
   val3 = val2 = val1 = 1000;
   printf("PID==%4d ==== ==== ==== ====\n", getpid());
   fflush(NULL);
/* ***** ***** ***** ***** START BLOCK *
   val1 = fork();
   wait(NULL);
   val2 = fork();
   wait(NULL);
   val3 = fork();
   wait(NULL);
   ***** ***** ***** ***** END** BLOCK */
   printf("VAL1=%4d VAL2=%4d VAL3=%4d\n", val1, val2, val3);
}
```

**Output Dari File C :**

![06-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/06-fork.JPG)

**Penjelasan Output Dari File C :**

Pada 06-fork nilai val1,val2, dan val3 akan sama coba hapus start block dan end block untuk melihat perbedaan output dari yang ada diatas.

* * *

### 07-fork.c

**File C :**

```  C
/*
 * (c) 2005-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV06 Wed Nov  1 13:35:19 WIB 2017
 * REV02 Mon Oct 24 10:43:00 WIB 2016
 * REV01 Sun Feb 27 08:31:46 WIB 2011
 * START 2005
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define DISPLAY1 "START * PARENT *** ** PID (%4d) ** **********\n"
#define DISPLAY2 "RANDOM: val1(%4d) -- val2(%4d) -- val3(%4d)\n"
/*************************************************** main ** */
void main(void) {
   pid_t val1, val2, val3;
   printf(DISPLAY1, getpid());
   val1 = fork();
   val2 = fork();
   val3 = fork();
   printf(DISPLAY2, val1, val2, val3);
/* *********** START BLOCK ***
   wait(NULL);
   wait(NULL);
   wait(NULL);
   *********** END * BLOCK *** */
}
```

**Output Dari File C :**

![07-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/07-fork.JPG)

* * *

### 08-fork.c

**File C :**

```  C
/*
 * (c) 2005-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV02 Thu Oct 26 12:27:30 WIB 2017
 * REV01 Mon Oct 24 10:43:00 WIB 2016
 * START 2005
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(void) {
   int ii=0;
   if (fork() == 0) ii++;
   wait(NULL);
   if (fork() == 0) ii++;
   wait(NULL);
   if (fork() == 0) ii++;
   wait(NULL);
   printf ("Result = %d \n",ii);
   exit(0);
}
```

**Output Dari File C :**

![08-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/09-fork.JPG)

* * *

### 09-fork.c

**File C :**

```  C
/*
 * (c) 2015-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * REV03 Mon Oct 30 11:04:10 WIB 2017
 * REV00 Mon Oct 24 10:43:00 WIB 2016
 * START 2015
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main(void) {
   int value;

   value=fork();
   wait(NULL);
   printf("I am PID[%4d] -- The fork() return value is: %4d)\n", getpid(), value);

   value=fork();
   wait(NULL);
   printf("I am PID[%4d] -- The fork() return value is: %4d)\n", getpid(), value);
}
```

**Output Dari File C :**

![09-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/09-fork.JPG)

* * *

### 10-fork.c

**File C :**

```  C
/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV02 Mon Oct 30 20:25:44 WIB 2017
 * START Mon Oct 24 09:42:05 WIB 2016
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void procStatus(int level) {
   printf("L%d: PID[%d] (PPID[%d])\n", level, getpid(), getppid());
   fflush(NULL);
}

int addLevelAndFork(int level) {
   if (fork() == 0) level++;
   wait(NULL);
   return level;
}

void main(void) {
   int level = 0;
   procStatus(level);
   level = addLevelAndFork(level);
   procStatus(level);
}
```

**Output Dari File C :**

![10-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/10-fork.JPG)

* * *

### 11-fork.c

**File C :**

```  C
/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV02 Mon Oct 30 20:27:24 WIB 2017
 * START Mon Oct 24 09:42:05 WIB 2016
 */

#define  LOOP   3
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void procStatus(int level) {
   printf("L%d: PID[%d] (PPID[%d])\n", level, getpid(), getppid());
   fflush(NULL);
}

int addLevelAndFo rk(int level) {
   if (fork() == 0) level++;
   wait(NULL);
   return level;
}

void main(void) {
   int ii, level = 0;
   procStatus(level);
   for (ii=0;ii<LOOP;ii++) {
      level = addLevelAndFork(level);
      procStatus(level);
   }
}
```

**Output Dari File C :**

![11-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/11-fork.JPG)

* * *

### 12-fork.c

**File C :**

```  C
/*
 * (c) 2017 Rahmat M. Samik-Ibrahim -- This is free software
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * Adapted from University of Waterloo Midterm Winter 2012.
 * REV03 Wed Nov  1 13:32:11 WIB 2017
 * START Wed May  3 20:56:05 WIB 2017
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void waitAndPrintPID(void) {
   wait(NULL);
   printf("PID: %d\n", getpid());
   fflush(NULL);
}

void main(int argc, char *argv[]) {
   int rc, status;

   waitAndPrintPID();
   rc = fork();
   waitAndPrintPID();
   if (rc == 0) {
      fork();
      waitAndPrintPID();
      execlp("./00-show-pid", "00-show-pid", NULL);
   }
   waitAndPrintPID();
}
```

**Output Dari File C :**

![12-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/12-fork.JPG)

* * *

### 14-fork.c

**File C :**

```  C
/*
 * (c) 2005-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV03 Mon Oct 30 15:10:10 WIB 2017
 * REV00 Wed May  3 17:07:09 WIB 2017
 *
 * fflush(NULL): flushes all open output streams
 * fork():       creates  a new process by cloning
 * getpid():     get PID (Process ID)
 * wait(NULL):   wait until the child is terminated
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void main(void) {
   int firstPID = (int) getpid();
   int   RelPID;

   fork();
   wait(NULL);
   fork();
   wait(NULL);
   fork();
   wait(NULL);

   RelPID=(int)getpid()-firstPID+1000;
   printf("RelPID: %d\n", RelPID);
   fflush(NULL);
}
```

**Output Dari File C :**

![14-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/14-fork.JPG)

* * *

### 15-fork.c

**File C :**

```  C
/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV03 Wed Nov  1 14:00:40 WIB 2017
 * START Sun Dec 04 00:00:00 WIB 2016
 * wait()     =  suspends until its child terminates. 
 * fflush()   =  flushes the user-space buffers.
 * getppid()  =  get parent PID
 * ASSUME pid >= 1000 && pid > ppid **
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define  NN 2

void main (void) {
   int ii, rPID, rPPID, id1000=getpid();
   for (ii=1; ii<=NN; ii++) {
      fork();
      wait(NULL);
      rPID = getpid()-id1000+1000; /* "relative" */
      rPPID=getppid()-id1000+1000; /* "relative" */
      if (rPPID < 1000 || rPPID > rPID) rPPID=999;
      printf("Loop [%d] - rPID[%d] - rPPID[%4d]\n", ii, rPID, rPPID);
      fflush(NULL);
   }
}
```

**Output Dari File C :**

![15-fork](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/src/images/w06/15-fork.JPG)