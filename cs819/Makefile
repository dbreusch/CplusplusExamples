#
# A sample makefile for compiling C++ programs, suitable
#   for CS719
#   
#   This is somewhat specialized in that it stores all
#   executables in /usr/tmp
#
#   This makefile allows you to utilize the lib719 utility library
# *********************************************************************
#
#   For this to work, you need the following line in your .login
#
#	setenv ARCH `machine`
#
# *********************************************************************
#
#
# This makefile includes an entry "depend" which will automatically
# generate complete include file dependencies (including nested
# includes.  To update dependencies, simply update the SRCS variable
# (and OBJS) and type "make depend"
#
#
DIR719 = /home/cs/cs719/public
INC719 = $(DIR719)/include
LIB719 = $(DIR719)/lib/$(ARCH)
SRC = .
# 
# The executable is stored /usr/tmp
# but a symbolic link will be made to that file with the
# same name in the current directory.
#
TARGETDIR = /usr/tmp
#
# Use g++ for C++ compilations.

.SUFFIXES: .o .cc .c

CC = g++ 

LDFLAGS = -L$(LIB719)
CFLAGS = -g -I$(INC719)

LIBS =  -l719 -lm -lg++

PROGRAM = ggt

.cc.o:
		$(CC) $(CFLAGS) -c $*.cc

SRCS = $(PROGRAM).cc command.cc graph.cc graphlist.cc node.cc nodelist.cc arc.cc arclist.cc cmdtbl.cc

OBJS = $(PROGRAM).o command.o graph.o graphlist.o node.o nodelist.o arc.o arclist.o cmdtbl.o

$(PROGRAM): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LIBS) -o $(TARGETDIR)/$@.$(USER)

#       delete a link (or file) if it exists
	ln -f -s $(TARGETDIR)/$@.$(USER) $@
#
# make depend
#
# The depend switch varies (unfortunately) for different C compilers.
#        -Em is used by old DEC,
#        -M by Sun, gcc and DEC ANSI
#        -MM same as -M BUT system include files are NOT searched
#               -MM is the only switch that is system independent
#DEPEND = -Em
#DEPEND = -M
DEPEND = -MM
depend:
	sed -e "/^#=====DO NOT DELETE THIS LINE=====/q" Makefile > Makefile.new
	$(CC) $(CFLAGS) $(DEPEND) $(SRCS) >> Makefile.new
	mv Makefile.new Makefile

#=====DO NOT DELETE THIS LINE=====
ggt.o : ggt.cc /home/cs/cs719/public/include/UserInterface.h command.h /home/cs/cs719/public/include/ui.h \
  graphlist.h 
command.o : command.cc graph.h nodelist.h node.h arclist.h arc.h graphlist.h \
  command.h /home/cs/cs719/public/include/ui.h 
graph.o : graph.cc graph.h nodelist.h node.h arclist.h arc.h graphlist.h 
graphlist.o : graphlist.cc graph.h nodelist.h node.h arclist.h arc.h graphlist.h 
node.o : node.cc node.h arclist.h arc.h 
nodelist.o : nodelist.cc nodelist.h node.h arclist.h arc.h 
arc.o : arc.cc arc.h 
arclist.o : arclist.cc arclist.h arc.h 
cmdtbl.o : cmdtbl.cc command.h /home/cs/cs719/public/include/ui.h cmdtbl.h 
