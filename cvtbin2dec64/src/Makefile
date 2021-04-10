all: cvtbin2dec64

CSOURCES = cvtbin2dec64.cpp

cvtbin2dec64.o: $(CSOURCES)
	gcc -g -c $^

cvtbin2dec64: $(subst .cpp,.o,$(CSOURCES))
	ld -e main -lc -o $@ -lc cvtbin2dec64.o --dynamic-linker /lib64/ld-linux-x86-64.so.2

clean:
	-rm cvtbin2dec64

.PHONY: all clean
