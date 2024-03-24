CC=g++
C_FLAGS=-g -Wall
TEST=$(wildcard test_scripts/*.txt)

SRC_FILES=$(filter-out $(wildcard main.cc),$(wildcard *.cc))
OBJ_FILES=$(wildcard *.o)
APP=chess

custom_tests:
	$(CC) $(C_FLAGS) $(SRC_FILES) main.cc -o $(APP)

instructor_tests:
	$(CC) $(C_FLAGS) $(SRC_FILES) $(OBJ_FILES) -o $(APP)

run:
	./$(APP) $(TEST)

valgrind:
	valgrind --leak-check=full --track-origins=yes ./$(APP) $(TEST)

gdb:
	gdb ./$(APP)

clean:
	rm -f $(APP) output.txt

# Instructor use only
generate:
	$(CC) $(C_FLAGS) Instr*.cc test_scripts/randStepGen.cc -o randStepGen
	./randStepGen
	rm randStepGen

object:
	$(CC) -c $(C_FLAGS) main.cc Instr*.cc
	ld -r *.o -o instructor.o
	mv instructor.o ../student_files
	rm -f *.o
