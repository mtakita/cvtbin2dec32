all: cvtd2b

CSOURCES = cvtd2b.cpp

cvtd2b.o: $(CSOURCES)
	gcc -g -c $^

cvtd2b: $(subst .cpp,.o,$(CSOURCES))
	ld -e main -lc -o $@ -lc cvtd2b.o --dynamic-linker /lib64/ld-linux-x86-64.so.2

clean:
	-rm cvtd2b

.PHONY: all clean
