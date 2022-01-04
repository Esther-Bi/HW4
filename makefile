CC = gcc
AR = ar
ACTIONS = functions.o
FLAGS = -g -Wall
LM = -lm
HEADER_E = edges.h
HEADER_N = nodes.h
HEADER_A = algo.h
HEADER_G = graph.h
HEADER_L = List.h
HEADERS = graph.h edges.h nodes.h algo.h List.h
O = edges.o nodes.o algo.o List.o
MAIN = main.o


all: graph

functions: $(O)

#creat main
graph: $(MAIN) functions
	$(CC) $(FLAGS) -o graph $(MAIN) $(O) $(LM)

algo.o: algo.c $(HEADER_A) $(HEADER_G)
	$(CC) $(FLAGS) -c algo.c

edges.o: edges.c $(HEADER_E) $(HEADER_G)
	$(CC) $(FLAGS) -c edges.c

nodes.o: nodes.c $(HEADER_N) $(HEADER_G)
	$(CC) $(FLAGS) -c nodes.c

List.o: List.c $(HEADER_L) $(HEADER_G)
	$(CC) $(FLAGS) -c List.c

main.o: main.c $(HEADERS)
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a graph