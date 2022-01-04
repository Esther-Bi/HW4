#ifndef MY_HEADER
#define MY_HEADER

Node* create_weight_node(int);
Node* min_node(Node**);
void add(Node**, int);
void deletel(Node**);
void print_list(Node*);
void remove_node_L(Node**, int);
void change_data(Node**, int, int);
void change_father(Node**, int, int);
int get_data(Node**, int);

#endif