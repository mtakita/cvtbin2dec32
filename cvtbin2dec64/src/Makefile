all: cvtbin2dec

CSOURCES = cvtbin2dec.cpp

cvtbin2dec.o: $(CSOURCES)
	gcc -g -c $^

cvtbin2dec: $(subst .cpp,.o,$(CSOURCES))
	ld -e main -lc -o $@ -lc cvtbin2dec.o --dynamic-linker /lib64/ld-linux-x86-64.so.2

clean:
	-rm cvtbin2dec

.PHONY: all clean
