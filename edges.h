#ifndef EDGES_
#define EDGES_

pedge create_edge(int,pnode);
void add_edge_first(pedge*, int, pnode);
void add_edge_last(pedge*, int, pnode);
void print_list_edges(pedge);
// void remove_edge(pedge*, int);
void remove_out_edges_of_node(pedge*);
void remove_in_edges_of_node(pnode*, int);

#endif