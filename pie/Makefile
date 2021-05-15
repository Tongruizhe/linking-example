CC ?= gcc

ifeq ($(PIE), 0)
	CFLAGS = -fno-pie
	LDFLAGS = -no-pie
endif
# else, -fpie and -pie for default

all: test_prog_disa.S

test_prog.S: test_prog.c
	$(CC) -o $@ -S $(CFLAGS) $<

test_prog.o: test_prog.S
	$(CC) -o $@ -c $(CFLAGS) $<

test_prog: test_prog.o
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $<

test_prog_disa.S: test_prog
	objdump -dx $< > $@

.PHONY: clean

clean:
	rm -rf test_prog test_prog.S test_prog.o test_prog_disa.S
