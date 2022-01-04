#ifndef ALGO_
#define ALGO_

// pnode A(pnode*); // new graph
int A(char str[] , int , pnode*);
// void B(pnode*); // add node and edges. if node appeares, remove out edges only and add new
int B(char str[] , int , pnode*);
// void D(pnode*, int); // delete node
int D(char str[] , int , pnode*);
Node* S_for_tsp(pnode*, int, int); // shortest path , -1 if there isn't one
int S(char str[] , int , pnode*);
// void T(pnode*, int); // tsp, int represents number of cities
int T(char str[] , int , pnode*);

void permute(int*, int, int, int (*)[6], int);
void swap(int*, int *);

#endif