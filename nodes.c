#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "graph.h"
#include "nodes.h"
#include "edges.h"

pnode create_node(int node_num){
    pnode n = (pnode)malloc(sizeof(node));
    if(n){
        n->node_num=node_num;
        n->edges=NULL;
        n->next=NULL;
    }
    return n;
}

void add_first(pnode* H, int node_num){
    pnode n = create_node(node_num);
    if(!n){
        printf("no memory!");
        return;
    }
    n->next = *H;
    *H = n;
}

void add_last(pnode* H, int node_num){
    pnode n = create_node(node_num);
    if(!n){
        printf("no memory!");
        return;
    }
    if(!*H){
        *H = n;
        return;
    }
    pnode tmp = *H;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = n;
}

void delete_all_nodes(pnode* H){
    while(*H){
        pnode tmp = *H;
        *H = (*H)->next;
        remove_out_edges_of_node(&(tmp->edges));
        free(tmp);
    }
}

void print_list_nodes(pnode H){
    while(H){
        printf("%d -> ", H->node_num);
        print_list_edges(H->edges);
        H = H->next;
    }
    printf("||\n");
}

void remove_node(pnode* H, int node_num){
    if(!*H)
        return;
    if((*H)->node_num == node_num){
        pnode tmp = *H;
        *H = (*H)->next;
        remove_out_edges_of_node(&(tmp->edges));
        remove_in_edges_of_node(H, tmp->node_num);
        free(tmp);
    }
    pnode tmp = *H;
    while(tmp->next && tmp->next->node_num != node_num)
        tmp = tmp->next;
    if(!tmp->next)
        return;
    pnode tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    remove_out_edges_of_node(&(tmp2->edges));
    remove_in_edges_of_node(H, tmp2->node_num);
    free(tmp2);
}


int contains_node_num(pnode H, int num){
    while(H){
        if (H->node_num == num){
            return 0;
        }
        H = H->next;
    }
    return 1;
}

pnode get_node(pnode H, int num){
    while(H){
        if (H->node_num == num){
            return H;
        }
        H = H->next;
    }
    return NULL;
}