test1: test1.o Node.o CycleLine.o
	g++ -std=c++11 -Wall $^ -o $@

test1.o: test1.cpp Node.h CycleLine.h
	g++ -std=c++11 -Wall -c $< -o $@

Node.o: Node.cpp Node.h
	g++ -std=c++11 -Wall -c $< -o $@

CycleLine.o: CycleLine.cpp CycleLine.h
	g++ -std=c++11 -Wall -c $< -o $@

clean:
	rm -f *.o program
