# Changes you will want to make:
# 1)  Give a name the program you want to create PROGRAM = myprog.
# 2)  Specify all the .cc files after CXX_SRCS
# 3)  If you are using a library (such as math function routines)
#	adjust CXXLIBS (example: CXXLIBS = -lcc -lm)
# 4)  Type the Unix command, "touch .depend.mk"
#     This will be a "hidden file".  To see it type "ls -a" in the shell.

################################################################
#            VARIABLES YOU'LL WANT TO CHANGE                   #
################################################################

PROGRAM = cccfiles

CXX_SRCS = ccc_empl.cpp ccc_shap.cpp ccc_time.cpp ccc_x11.cpp

CXXLIBS = -lX11

################################################################
#          STUFF YOU PROBABLY WANT TO LEAVE ALONE              #
################################################################

CXXINCLUDEPATHS = #-I/Net/solen/home/m/c/mc38/lib/cccfiles

CXX = g++
CC = $(CXX)
LDFLAGS = -g -pipe -L/usr/lib/X11 $(CXX_LIBS)
CXXFLAGS = -g -pipe -Wall $(CXXINCLUDEPATHS)

OBJS = $(CXX_SRCS:.cpp=.o)
DEMANGLER = c++filt

$(PROGRAM) : depend $(OBJS)
#$(CC) $(LDFLAGS) $(OBJS) $(CXXLIBS) -o $(PROGRAM) 2>&1 | $(DEMANGLER)

clean:
	/bin/rm -f *.o $(PROGRAM) .nfs* *~ core \#*\#

depend:
	$(CXX) -MM $(CXX_SRCS) $(CXXINCLUDEPATHS) > .depend.mk

###
include .depend.mk
