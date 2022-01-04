#ifndef NODES_
#define NODES_

pnode create_node(int);
void add_first(pnode*, int);
void add_last(pnode*, int);
void delete_all_nodes(pnode*);
void print_list_nodes(pnode H);
void remove_node(pnode*, int);
int contains_node_num(pnode, int);
pnode get_node(pnode, int);

#endif