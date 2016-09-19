SHELL = /bin/sh
GCC = /usr/bin/gcc
CFLAGS= -D$(GXT_DEBUG) -Wall -fmax-errors=5

# Install paths according to GNU make standards
prefix = /usr/local
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
includedir = $(prefix)/include
#TODO make local object directory a config choice
objdir = ~/Code/Obj

all: $(objdir)/libgxtut.a
$(objdir)/libgxtut.a: $(objdir)/ut_date.o
	ar rs $(objdir)/libgxtut.a $(objdir)/ut_*.o
$(objdir)/ut_date.o: ut_date.c
	$(GCC) $(CFLAGS) -c $^ -o $@

clean:
	@rm *~

install: $(includedir)/ut_date.h $(includedir)/ut_error.h
$(includedir)/ut_date.h: ut_date.h
	sudo cp $^ $(includedir)
$(includedir)/ut_error.h: ut_error.h
	sudo cp $^ $(includedir)

uninstall:
	sudo rm $(includedir)/ut_date.h
	sudo rm $(includedir)/ut_error.h
