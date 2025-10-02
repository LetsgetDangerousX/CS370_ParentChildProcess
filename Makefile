#list of files
C_SRCS = Generator.c OddEven.c PerfectSquare.c Factorial.c
C_OBJS = Generator.o OddEven.o PerfectSquare.o Factorial.o
#C_HEADERS

OBJS = ${C_OBJS}
EXE1 = Generator
EXE2 = OddEven
EXE3 = PerfectSquare
EXE4 = Factorial

#compiler and loader commands and flags
GCC = gcc
GCC_FLAGS = -std=c11 -g -Wall -c -I.
LD_FLAGS  = -std=c11 -g -Wall -I.

#compile .c files to .o files
.c.o:
	$(GCC) $(GCC_FLAGS) $<

#target is the executable
all: $(EXE1) $(EXE2) $(EXE3) $(EXE4)
$(EXE1): Generator.o
	$(GCC) $(LD_FLAGS) Generator.o -o $(EXE1)
$(EXE2): OddEven.o  
	$(GCC) $(LD_FLAGS) OddEven.o   -o $(EXE2)
$(EXE3): PerfectSquare.o
	$(GCC) $(LD_FLAGS) PerfectSquare.o  -o $(EXE3) -lm
$(EXE4): Factorial.o  
	$(GCC) $(LD_FLAGS) Factorial.o   -o $(EXE4)


#recomplie c objects if headers change
$(C_OBJS): ${C_HEADERS}

#cleanup directory

clean:
	rm -f *.o $(EXE1) $(EXE2) $(EXE3) $(EXE4)

package:
	zip -r Amber-Ferrell-HW2.zip Generator.c OddEven.c PerfectSquare.c Factorial.c Makefile README.txt