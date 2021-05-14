all: error_prog ok_prog

libmodule_a.a: module_a.o
	ar rcs $@ $<

libmodules.a: modules.o
	ar rcs $@ $<

error_prog: libmodule_a.a libmodules.a main.o
	gcc -static -o $@ main.o libmodule_a.a libmodules.a

# unreferenced symbols from archive does not make it to the output binary, 
# because linker discards them by default.
# See https://stackoverflow.com/questions/1202494/why-doesnt-attribute-constructor-work-in-a-static-library
# and https://stackoverflow.com/questions/805555/ld-linker-question-the-whole-archive-option/842770#842770
# in main.o, only @get_module_by_name for libmodule_a.a if referenced, 
# so symbol @register_self (the constructor) and the static initialized @moduleA is discarded.
# Use --whole-archive to include them
ok_prog: libmodule_a.a libmodules.a main.o
	gcc -static -o $@ main.o -Wl,--whole-archive libmodule_a.a -Wl,--no-whole-archive libmodules.a

.PHONY: clean

clean:
	rm -rf *.o *.a error_prog ok_prog
