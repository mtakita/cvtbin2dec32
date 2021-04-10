all: cvtbin2dec32

CSOURCES = cvtbin2dec32.cpp

cvtbin2dec32.o: $(CSOURCES)
	gcc -g -c $^

cvtbin2dec32: $(subst .cpp,.o,$(CSOURCES))
	ld -e main -lc -o $@ -lc cvtbin2dec32.o --dynamic-linker /lib64/ld-linux-x86-64.so.2

clean:
	-rm cvtbin2dec32

.PHONY: all clean
