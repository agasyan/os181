# DEMOS Week06: Forking in C language

OS181 - Operating System 2018 Term (1) 

* * * 
START : Mon Apr 30 12:05:53 WIB 2018

REV00 : Mon Apr 30 12:05:53 WIB 2018
* * *

## Petunjuk Umum:

Sebelum melihat penjelasan sebaiknya sudah menjalankan dan mempelajari Week06 yang ada pada [link](https://github.com/UI-FASILKOM-OS/os181/tree/master/demos) berikut. Baik di komputer pribadi maupun di server kawung.

**Penjalanan Dari File C yang ada pada Week terkait :**
1. Sebelum meng-compile file pastikan semua file yang ingin dijalankan merupakan versi terbaru, untuk mengecek bisa gunakan perintah `git pull` atau mengecek folder extra di badak
2. Masuk ke folder terkait dan jalankan perintah `make`
3. Untuk melihat output program bisa menggunakan perintah `./[nama-file]`

* * *
## Penjelasan Mengenai File - file yang ada pada week06

* * *

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

*Output Penjalanan Pertama :*
>[[[ This is 00-show-pid: PID[114] PPID[17] ]]]

*Output Penjalanan Kedua :*
>[[[ This is 00-show-pid: PID[115] PPID[17] ]]]

*Output Penjalanan Ketiga :*
>[[[ This is 00-show-pid: PID[116] PPID[17] ]]]

**Penjelasan Dari File C :**

Dari penjalanan program C diketahui bahwa PPID atau biasa yang disebut __Parent PID__ akan tetap sama dalam penjalanan program tersebut berkali kali. 

Penjelasan dari fungsi getpid() dan getppid():

>getpid() returns the process ID (PID) of the calling process.  (This
       is often used by routines that generate unique temporary filenames.)

>getppid() returns the process ID of the parent of the calling
       process.  This will be either the ID of the process that created this
       process using fork(), or, if that process has already terminated, the
       ID of the process to which this process has been reparented (either
       init(1) or a "subreaper" process defined via the prctl(2)
       PR_SET_CHILD_SUBREAPER operation).

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