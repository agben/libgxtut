# This makefile has been generated by clice - the command line coding ecosystem
#	more details at www.benningtons.net
# built on 14042017 at 2336

# Shell command variables
SHELL = /bin/sh
GCC = /usr/bin/gcc
CFLAGS= -D$(GXT_DEBUG) -std=gnu11 -Wall -fmax-errors=5 -fPIC

# Install paths according to GNU make standards
prefix = /usr/local
bindir = $(prefix)/bin
includedir = $(prefix)/include
completedir = /etc/bash_completion.d
objdir = $(GXT_CODE_OBJECT)

# This project's executable programs
all:	\
	$(objdir)/libgxtut.a 

# Tidy-up.
clean:
	-rm *~

# Install project for operational use
install:	\
	$(includedir)/ut_date.h $(includedir)/ut_error.h 
$(includedir)/ut_date.h: ut_date.h
	sudo cp $^ $@
$(includedir)/ut_error.h: ut_error.h
	sudo cp $^ $@

# Remove project from operational use
uninstall:
	sudo rm $(includedir)/ut_date.h
	sudo rm $(includedir)/ut_error.h

# Functions and their dependencies

$(objdir)/libgxtut.a: $(objdir)/ut_date.o 
	ar rs $(objdir)/libgxtut.a $(objdir)/ut_date.o
$(objdir)/ut_date.o: ut_date.c $(includedir)/ut_date.h 
	$(GCC) $(CFLAGS) -c $< -o $@
