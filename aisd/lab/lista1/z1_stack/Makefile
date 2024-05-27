main: main.o Node.o Stack.o
	g++ -std=c++11 -Wall $^ -o $@

main.o: main.cpp Node.h Stack.h
	g++ -std=c++11 -Wall -c $< -o $@

Node.o: Node.cpp Node.h
	g++ -std=c++11 -Wall -c $< -o $@

Stack.o: Stack.cpp Stack.h
	g++ -std=c++11 -Wall -c $< -o $@

clean:
	rm -f *.o program
