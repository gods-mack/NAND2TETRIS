
output: test.o pass1.o test.o
	g++ test.o pass1.o -o output



test.o: test.cpp code.h symbolTable.h
	g++ -c test.cpp

pass1.o: pass1.cpp pass1.h
	g++ -c pass1.cpp

clean:
	rm *.o output			