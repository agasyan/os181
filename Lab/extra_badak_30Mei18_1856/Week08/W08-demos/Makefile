# REV03 Tue May  1 20:35:45 DST 2018
# START Wed Apr 18 20:55:24 WIB 2018

CC=gcc
CFLAGS=-std=gnu99 -pthread

P20=20-parent
P21=21-child
P22=22-hello-goodbye
P23=23-kirim-ambil
P24=24-producer-consumer


EXECS= \
        $(P20) \
        $(P21) \
        $(P22) \
        $(P23) \
        $(P24) \


DEMOFILES=\
	demo-file1.txt \
        

all:  $(EXECS)

$(EXECS): %: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
demo:
	bash .shsh

