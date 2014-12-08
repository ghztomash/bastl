#CPP_FILES_CLASS = $(wildcard` ../*.cpp)
#OBJ_FILES_CLASS = $(addprefix ../obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CPP_FILES = tst.cpp 
#OBJ_FILES = tst_step.o
#LD_FLAGS=
CC_FLAGS=-c -Wall

#test: $(OBJ_FILES) $(OBJ_FILES_CLASS)
#	g++ $(LD_FLAGS) -o $@ $^

.PHONY : check

check : obj/tst.o obj/Tapper.o obj/StepDivider.o obj/StepMultiplier.o obj/StepGenerator.o obj/BastlStepper.o obj/DrumStep.o obj/NoVelocityStepMemory.o obj/Step.o
	g++ -o $@ $^
	./check

obj/tst.o : tst.cpp
	g++ $(CC_FLAGS) -o $@ $<

obj/Tapper.o : ../Tapper.cpp
	g++ $(CC_FLAGS) -o $@ $<

obj/StepDivider.o : ../../bastl-sequencing/StepDivider.cpp
	g++ $(CC_FLAGS) -o $@ $<

obj/StepMultiplier.o : ../../bastl-sequencing/StepMultiplier.cpp
	g++ $(CC_FLAGS) -o $@ $<

obj/StepGenerator.o : ../../bastl-sequencing/StepGenerator.cpp
	g++ $(CC_FLAGS) -o $@ $<
	
obj/BastlStepper.o : ../../bastl-sequencing/BastlStepper.cpp
	g++ $(CC_FLAGS) -o $@ $<
	
obj/DrumStep.o : ../DrumStep.cpp
	g++ $(CC_FLAGS) -o $@ $<
	
obj/Step.o : ../Step.cpp
	g++ $(CC_FLAGS) -o $@ $<
	
obj/NoVelocityStepMemory.o : ../NoVelocityStepMemory.cpp
	g++ $(CC_FLAGS) -o $@ $<


#../obj/%.o: ../%.cpp
#	g++ -I../ -c -o $@ $<
#
#%.o : %.cpp
#	g++ -I../ -c -o $@ $< -I../ISequenceMemory.h

clean:
	-rm -f obj/*.o
	-rm -f test
