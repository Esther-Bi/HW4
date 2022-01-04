#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "graph.h"
#include "List.h"

Node* create_weight_node(int id){
    Node* n = (Node*)malloc(sizeof(Node));
    if(n){
        n->id = id;
        n->data = INT_MAX;
        n->father = INT_MAX;
        n->next = NULL;
    }
    return n;
}

Node* min_node(Node** H){
    int val = (*H)->data;
    Node* ans = *H;
    Node* tmp = ans->next;
    while(tmp){
        if ((tmp->data)<val){
            ans = tmp;
            val = tmp->data;
        }
        tmp = tmp->next;
    }
    return ans;
}

int get_data(Node** H, int node_num){
    Node* ans = *H;
    while(ans && ans->id != node_num){
        ans = ans->next;
    }
    if (!ans){
        return INT_MAX;
    }
    return ans->data;
}

void change_data(Node** H, int node_num, int new_data){
    Node* ans = *H;
    while(ans && ans->id != node_num){
        ans = ans->next;
    }
    if (!ans){
        return;
    }
    ans->data = new_data;
}

void change_father(Node** H, int node_num, int new_father){
    Node* ans = *H;
    while(ans && ans->id != node_num){
        ans = ans->next;
    }
    if (!ans){
        return;
    }
    ans->father = new_father;
}

void add(Node** H, int id){
    Node* n = create_weight_node(id);
    if(!n){
        printf("no memory!");
        return;
    }
    n->next = *H;
    *H = n;
}

void deletel(Node** H){
    while(*H){
        Node* tmp = *H;
        *H = (*H)->next;
        free(tmp);
    }
}

void print_list(Node* H){
    while(H){
        printf("id : %d , data : %d , father : %d -> ", H->id ,H->data , H->father);
        H = H->next;
    }
    printf("||\n");
}

void remove_node_L(Node** H, int id){
    if(!*H)
        return;
    if((*H)->id == id){
        Node *tmp = *H;
        *H = (*H)->next;
        free(tmp);
        return;
    }
    Node* tmp = *H;
    while(tmp->next && tmp->next->id != id)
        tmp = tmp->next;
    if(!tmp->next)
        return;
    Node *tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
}