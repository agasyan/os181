# REV11 Wed Apr 18 20:54:00 WIB 2018
# REV03 Thu Mar  9 21:18:27 WIB 2017
# START Tue Sep 13 11:44:18 WIB 2016

CC=gcc
CFLAGS=-std=gnu99 -pthread

P10=10-server
P11=11-client
P12=12-clisvr
P50=50-get-put
P51=51-get-put-loop
P52=52-open-close
P53=53-file-pointer
P54=54-write
P55=55-write
P56=56-copy
P57=57-dup
P58=58-dup2
P59=59-io
P60=60-readwrite
P61=61-open-dup
P62=62-os172
P63=63-os171-dup
P64=64-os161


EXECS= \
        $(P10) \
        $(P11) \
        $(P12) \
        $(P50) \
        $(P51) \
        $(P52) \
        $(P53) \
        $(P54) \
        $(P55) \
        $(P56) \
        $(P57) \
        $(P58) \
        $(P59) \
        $(P60) \
        $(P61) \
        $(P62) \
        $(P63) \
        $(P64) \


DEMOFILES=\
	demo-file1.txt \
	demo-file2.txt \
	demo-file3.txt \
	demo-file4.txt \
	demo-file5.txt \
	demo-file6.txt \
	demo-file7.txt \
	demo-file8.txt \
	demo-file9.txt \
	demo-fileA.txt \
	demo-copy.txt  \
        $(P61)-demo.txt \
        $(P62)-demo.txt \
        $(P63)-demo.txt \
        $(P64)-demo.txt \
        

all:  $(EXECS)

$(EXECS): %: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
demo:
	bash .shsh


