#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "graph.h"
#include "edges.h"

pedge create_edge(int weight, pnode endpoint){
    pedge e = (pedge)malloc(sizeof(edge));
    if(e){
        e->weight=weight;
        e->endpoint=endpoint;
        e->next=NULL;
    }
    return e;
}

void add_edge_first(pedge* H, int weight, pnode endpoint){
    pedge n = create_edge(weight, endpoint);
    if(!n){
        printf("no memory!");
        return;
    }
    n->next = *H;
    *H = n;
}

void add_edge_last(pedge* H, int weight, pnode endpoint){
    pedge n = create_edge(weight, endpoint);
    if(!n){
        printf("no memory!");
        return;
    }
    if(!*H){
        *H = n;
        return;
    }
    pedge tmp = *H;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = n;
}

void remove_out_edges_of_node(pedge* H){
    while(*H){
        pedge tmp = *H;
        *H = (*H)->next;
        free(tmp);
    }
}

void print_list_edges(pedge H){
    printf("edges:\n");
    while(H){
        printf("end: %d , weight: %d-> ", H->endpoint->node_num , H->weight);
        H = H->next;
    }
    printf("||\n");
}

void remove_in_edges_of_node(pnode* H, int node_num){
    if(!*H)
        return;
    pnode pointer = *H;
    while(pointer){
        if (pointer->node_num != node_num){
            if(pointer->edges && pointer->edges->endpoint->node_num == node_num){
                pedge tmp = pointer->edges;
                pointer->edges = (pointer->edges)->next;
                free(tmp);
                pointer = pointer->next;
                continue;
            }
            if(pointer->edges) {
                pedge tmp = pointer->edges;
                while(tmp->next && tmp->next->endpoint->node_num != node_num){
                    tmp = tmp->next;
                }
                if(tmp->next){
                    pedge tmp2 = tmp->next;
                    tmp->next = tmp->next->next;
                    free(tmp2);
                }
            }
        }
        pointer = pointer->next;
    }
}