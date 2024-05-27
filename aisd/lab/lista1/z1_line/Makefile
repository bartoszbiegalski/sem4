main: main.o Node.o Line.o
	g++ -std=c++11 -Wall $^ -o $@

main.o: main.cpp Node.h Line.h
	g++ -std=c++11 -Wall -c $< -o $@

Node.o: Node.cpp Node.h
	g++ -std=c++11 -Wall -c $< -o $@

Line.o: Line.cpp Line.h
	g++ -std=c++11 -Wall -c $< -o $@

clean:
	rm -f *.o program
