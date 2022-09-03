assessment: assessment_main.o assessment.o
	g++ -g -std=c++0x -o assessment  assessment.o assessment_main.o

assessment_main.o:	assessment_main.cpp
	g++ -c -std=c++0x -g assessment_main.cpp

assessment.o:	assessment.cpp
	g++ -c -std=c++0x -g assessment.cpp assessment.h

clean:
	rm *.o
