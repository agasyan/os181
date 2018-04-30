# DEMOS Week06: Forking in C language

[Link Solusi Week06](https://github.com/agasyan/os181/blob/master/Lab/Solusi_Lab/Lab06_SOL.md)

OS181 - Operating System 2018 Term (1) 

* * * 
START : Mon Apr 30 12:05:53 WIB 2018

REV00 : Mon Apr 30 12:05:53 WIB 2018
* * *    

### Petunjuk Umum:

Sebelum melihat penjelasan sebaiknya sudah menjalankan dan mempelajari Week06 yang ada pada [link](https://github.com/UI-FASILKOM-OS/os181/tree/master/demos) berikut. Baik di komputer pribadi maupun di server kawung.

**Penjalanan Dari File C yang ada pada Week terkait :**
1. Sebelum meng-compile file pastikan semua file yang ingin dijalankan merupakan versi terbaru, untuk mengecek bisa gunakan perintah `git pull` atau mengecek folder extra di badak
2. Masuk ke folder terkait dan jalankan perintah `make`
3. Untuk melihat output program bisa menggunakan perintah `./[nama-file]`

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

*Output Penjalanan Pertama :*
>[[[ This is 00-show-pid: PID[114] PPID[17] ]]]

*Output Penjalanan Kedua :*
>[[[ This is 00-show-pid: PID[115] PPID[17] ]]]

*Output Penjalanan Ketiga :*
>[[[ This is 00-show-pid: PID[116] PPID[17] ]]]

**Penjelasan Output Dari File C :**

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
```
PID[123] PPID[17] (START:PARENT)
PID[124] PPID[123] (ELSE:CHILD)
PID[124] PPID[123] (STOP:CHILD)
PID[123] PPID[17] (IFF0:PARENT)
PID[123] PPID[17] (STOP:PARENT)
```

**Penjelasan Output Dari File C :**

Pada Output Line pertama akan mencetak printf pertama sebagai
 penanda dia sebagai parent, lalu pid [123] akan membuat child yang 
 mempunyai pid [124] akibat dari pemanggilan fungsi fork() dan pid 
 [124] akan lanjut ke - else dan pid 124 akan stop ketika selesai 
 ditunjukkan dengan output line ke-3. pid [123] akan menunggu
 pid[124] selesai dikarenakan setelah membuat Child ia akan menunggu
 yang ditunjukan dengan pemanggilan sleep(1) yang akan membuat 
 pid 123 berhenti selama 1 detik, dimana dalam 1 detik tersebut 
 pid[124] telah selesai menjalankan semua line program. setelah
 menunggu 1 detik maka pid [123] akan menyelsaikan penjalanan semua
 line program.

_Penjelasan fungsi fork():_
>System call fork() is used to create processes. It takes no
 arguments and returns a process ID. The purpose of fork() is to
  create a new process, which becomes the child process of the 
  caller. After a new child process is created, both processes 
  will execute the next instruction following the fork() system
   call. Therefore, we have to distinguish the parent from the 
   child. This can be done by testing the returned value of fork(): 

>If fork() returns a negative value, the creation of a child process was unsuccessful. 

>fork() returns a zero to the newly created child process. 

>fork() returns a positive value, the process ID of the child 
process, to the parent. The returned process ID is of type pid_t
 defined in sys/types.h. Normally, the process ID is an integer.
  Moreover, a process can use function getpid() to retrieve the 
  process ID assigned to this process. 

_Penjelasan Fungsi Sleep:_
>sleep() causes the calling thread to sleep either until the number 
of real-time seconds specified in seconds have elapsed or until a 
signal arrives which is not ignored.
