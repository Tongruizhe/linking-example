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
# in main.o, the only referenced symbol is @get_module_by_name, defined in libmodules.a
# (more specifically, modules.o in libmodueles.a), and the linker finds that all symbol is resolved
# and libmodules_a.a is not needed => libmodules_a.a is discarded

# Use --whole-archive to include the libmoduels_a.a to force copy the definitions to output binary

# Use the alogrithm discrible in CSAPP
# depedency is main.o -> libmodules.a, libmodule_a.a -> libmodules.a
# after linker processing main.o: U - get_module_by_name
# after linker processing libmodules.a: U is empty
# libmodules_a.a is omitted.....

ok_prog: libmodule_a.a libmodules.a main.o
	gcc -static -o $@ main.o -Wl,--whole-archive libmodule_a.a -Wl,--no-whole-archive libmodules.a

.PHONY: clean

clean:
	rm -rf *.o *.a error_prog ok_prog
