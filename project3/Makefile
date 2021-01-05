IDIR =$(dir $(lastword $(MAKEFILE_LIST)))include
MDIR =$(dir $(lastword $(MAKEFILE_LIST)))modules/

CXX=g++
CXXFLAGS= -g -Wall -MMD -I$(IDIR)

LIBS=-lm

OBJ = main.o $(MDIR)class.o $(MDIR)corridor.o $(MDIR)floor.o \
$(MDIR)person.o $(MDIR)room.o $(MDIR)school.o $(MDIR)stairs.o \
$(MDIR)student.o $(MDIR)teacher.o $(MDIR)yard.o $(MDIR)senior.o $(MDIR)junior.o

EXEC= main

ARGS = 1 1 2 3 5 < names.txt

$(EXEC)/%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

run: $(OBJ)
	$(CXX) -o $(EXEC) $^ $(CXXFLAGS) $(LIBS)
	./$(EXEC) $(ARGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXEC)

valgrind: $(OBJ)
	$(CXX) -o $(EXEC) $^ $(CXXFLAGS) $(LIBS)
	valgrind ./$(EXEC) $(ARGS)