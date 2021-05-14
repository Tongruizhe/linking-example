all: error_prog ok_prog

libmodule_a.a: module_a.o
	ar rcs $@ $<

libmodules.a: modules.o
	ar rcs $@ $<

error_prog: libmodule_a.a libmodules.a main.o
	gcc -static -o $@ main.o libmodule_a.a libmodules.a

ok_prog: libmodule_a.a libmodules.a main.o
	gcc -static -o $@ main.o -Wl,--whole-archive libmodule_a.a -Wl,--no-whole-archive libmodules.a

.PHONY: clean

clean:
	rm -rf *.o *.a error_prog ok_prog
