#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "graph.h"
#include "edges.h"
#include "nodes.h"
#include "algo.h"
#include "List.h"
int TSP_distance = INT_MAX;


int A(char word[] , int index , pnode* H){
    delete_all_nodes(H);
    int k=0;
    int f=index;
    while (word[f]!=' ' && f<strlen(word)){
        f++;
        k++;
    }
    char curr[] = "000000000" ;
    int b=strlen(curr)-1;
    for (int j=index+k ; j>=index ; j--){
        curr[b]=word[j];
        b--;
    }
    int num_of_nodes = atoi(curr);
    index = f+1; // index is now 'n'
    *H = NULL;
    int i=0;
    while (i<num_of_nodes){
        if (word[index]=='n'){
            index += 2;
            k=0;
            f=index;
            while (word[f]!=' ' && f<strlen(word)){
                f++;
                k++;
            }
            char current[] = "000000000";
            b=strlen(current)-1;
            for (int j=index+k ; j>=index ; j--){
                current[b]=word[j];
                b--;
            }
            int node_id = atoi(current);
            if (contains_node_num(*H,node_id) == 1){
                add_first(H,node_id);
            }
            index = f+1;
            while (word[index]!='n' && f<strlen(word) && word[index]!='A' && word[index]!='B' && word[index]!='D' && word[index]!='S' && word[index]!='T'){
                k=0;
                f=index;
                while (word[f]!=' ' && f<strlen(word)){
                    f++;
                    k++;
                }
                char current1[] = "000000000" ;
                b=strlen(current1)-1;
                for (int j=index+k ; j>=index ; j--){
                    current1[b]=word[j];
                    b--;
                }
                int dest = atoi(current1);
                index = f+1;

                k=0;
                f=index;
                while (word[f]!=' ' && f<strlen(word)){
                    f++;
                    k++;
                }
                char current2[] = "000000000";
                b=strlen(current2)-1;
                for (int j=index+k ; j>=index ; j--){
                    current2[b]=word[j];
                    b--;
                }
                int weight = atoi(current2);
                index = f+1;
                if (contains_node_num(*H,dest) == 1){
                    add_first(H,dest);
                }
                add_edge_first(&(get_node(*H,node_id)->edges), weight, get_node(*H,dest));
            }
        }
        i++;
    }
    return index;
}

int B(char word[] , int index , pnode* H){
    int k=0;
    int f=index;
    while (word[f]!=' ' && f<strlen(word)){
        f++;
        k++;
    }
    char current[] = "000000000";
    int b=strlen(current)-1;
    for (int j=index+k ; j>=index ; j--){
        current[b]=word[j];
        b--;
    }
    index = f+1;
    int num_of_node = atoi(current);
    if (contains_node_num(*H,num_of_node) == 1){
        add_first(H,num_of_node);
    }
    else{
        pnode tmp = get_node(*H, num_of_node);
        remove_out_edges_of_node(&(tmp->edges));
    }
    while (index<strlen(word) && word[index]!='A' && word[index]!='B' && word[index]!='D' && word[index]!='S' && word[index]!='T'){
        int dest;
        int weight;
        k=0;
        f=index;
        while (word[f]!=' ' && f<strlen(word)){
            f++;
            k++;
        }
        char current1[] = "000000000" ;
        b=strlen(current1)-1;
        for (int j=index+k ; j>=index ; j--){
            current1[b]=word[j];
            b--;
        }
        dest = atoi(current1);
        index = f+1;

        k=0;
        f=index;
        while (word[f]!=' ' && f<strlen(word)){
            f++;
            k++;
        }
        char current2[] = "000000000";
        b=strlen(current2)-1;
        for (int j=index+k ; j>=index ; j--){
            current2[b]=word[j];
            b--;
        }
        weight = atoi(current2);
        index = f+1;
        if (contains_node_num(*H,dest) == 1){
            add_first(H,dest);
        }
        add_edge_first(&(get_node(*H,num_of_node)->edges), weight, get_node(*H,dest));
    }
    return index;
}

int D(char word[] , int index , pnode* H){
    int k=0;
    int f=index;
    while (word[f]!=' ' && f<strlen(word)){
        f++;
        k++;
    }
    char current[] = "000000000";
    int b=strlen(current)-1;
    for (int j=index+k ; j>=index ; j--){
        current[b]=word[j];
        b--;
    }
    index = f+1;
    int node_id = atoi(current);
    remove_node(H, node_id);
    return index;
}

int S(char word[] , int index , pnode* H){
    int k=0;
    int f=index;
    while (word[f]!=' ' && f<strlen(word)){
        f++;
        k++;
    }
    char current[] = "000000000";
    int b=strlen(current)-1;
    for (int j=index+k ; j>=index ; j--){
        current[b]=word[j];
        b--;
    }
    index = f+1;
    int src = atoi(current);

    k=0;
    f=index;
    while (word[f]!=' ' && f<strlen(word)){
        f++;
        k++;
    }
    char current1[] = "000000000";
    b=strlen(current1)-1;
    for (int j=index+k ; j>=index ; j--){
        current1[b]=word[j];
        b--;
    }
    index = f+1;
    int dest = atoi(current1);

    Node *Q = NULL;
    Node *ans = NULL;
    pnode tmp = *H;
    add(&Q,tmp->node_num);
    add(&ans,tmp->node_num);
    if (tmp->node_num == src){
        change_data(&Q,src,0);
        change_data(&ans,src,0);
    }
    while(tmp->next){
        tmp = tmp->next;
        add(&Q,tmp->node_num);
        add(&ans,tmp->node_num);
        if (tmp->node_num == src){
            change_data(&Q,src,0);
            change_data(&ans,src,0);
        }
    }
    while (Q){
        Node* u = min_node(&Q);
        int du = get_data(&ans,u->id);
        if (du==INT_MAX){
            remove_node_L(&Q, u->id);
            continue;
        }
        pnode curr = get_node(*H,u->id);
        pedge pointer = curr->edges;
        while (pointer){
            int dv = get_data(&ans,pointer->endpoint->node_num);
            int w = pointer->weight;
            if (dv > du + w){
                change_data(&ans,pointer->endpoint->node_num,du + w);
                change_data(&Q,pointer->endpoint->node_num,du + w);
                change_father(&ans,pointer->endpoint->node_num,u->id);
                change_father(&Q,pointer->endpoint->node_num,u->id);
            }
            pointer=pointer->next;
        }
        remove_node_L(&Q, u->id);
    }
    int for_return = get_data(&ans,dest);
    if (for_return == INT_MAX){
        printf("Dijsktra shortest path: %d \n" , -1);
    }
    else {
        printf("Dijsktra shortest path: %d \n" , for_return);
    }
    deletel(&ans);
    return index;
}


Node* S_for_tsp(pnode* H , int src , int dest){
    Node *Q = NULL;
    Node *ans = NULL;
    if(!*H)
        return NULL;
    pnode tmp = *H;
    add(&Q,tmp->node_num);
    add(&ans,tmp->node_num);
    if (tmp->node_num == src){
        change_data(&Q,src,0);
        change_data(&ans,src,0);
    }
    while(tmp->next){
        tmp = tmp->next;
        add(&Q,tmp->node_num);
        add(&ans,tmp->node_num);
        if (tmp->node_num == src){
            change_data(&Q,src,0);
            change_data(&ans,src,0);
        }
    }
    while (Q){
        Node* u = min_node(&Q);
        int du = get_data(&ans,u->id);
        if (du==INT_MAX){
            remove_node_L(&Q, u->id);
            continue;
        }
        pnode curr = get_node(*H,u->id);
        pedge pointer = curr->edges;
        while (pointer){
            int dv = get_data(&ans,pointer->endpoint->node_num);
            int w = pointer->weight;
            if (dv > du + w){
                change_data(&ans,pointer->endpoint->node_num,du + w);
                change_data(&Q,pointer->endpoint->node_num,du + w);
                change_father(&ans,pointer->endpoint->node_num,u->id);
                change_father(&Q,pointer->endpoint->node_num,u->id);
            }
            pointer=pointer->next;
        }
        remove_node_L(&Q, u->id);
    }
    return ans;
}

int T(char word[] , int index , pnode* H){
    TSP_distance = INT_MAX;
    int k=0;
    int f=index;
    while (word[f]!=' ' && f<strlen(word)){
        f++;
        k++;
    }
    char current[] = "000000000";
    int b=strlen(current)-1;
    for (int j=index+k ; j>=index ; j--){
        current[b]=word[j];
        b--;
    }
    index = f+1;
    int num_of_nodes = atoi(current);

    int for_permute[6] = {0};
    int cities_mat[6][6] = {0};
    Node* cities = NULL;

    for (int m=0 ; m<num_of_nodes ; m++){
        k=0;
        f=index;
        while (word[f]!=' ' && f<strlen(word)){
            f++;
            k++;
        }
        char current[] = "000000000";
        int b=strlen(current)-1;
        for (int j=index+k ; j>=index ; j--){
            current[b]=word[j];
            b--;
        }
        index = f+1;
        int city_num = atoi(current);
        add(&cities,city_num);
    }
    for (int i=0 ; i<num_of_nodes ; i++){
        for_permute[i] = i;
        for (int j=0 ; j<num_of_nodes ; j++){
            cities_mat[i][j] = INT_MAX;
        }
    }
    Node* tmp = cities;
    k = 0;
    while(tmp){
        Node* for_dest = cities;
        Node* after_dijkstra = S_for_tsp(H , tmp->id , 0);
        for (int i = 0 ; i<num_of_nodes ; i++){
            int tmp_dest = for_dest->id;
            int dv = get_data(&after_dijkstra,tmp_dest);
            cities_mat[k][i] = dv;
            for_dest = for_dest->next;
        }
        k++;
        tmp = tmp->next;
        deletel(&after_dijkstra);
    }
    permute(for_permute, 0, num_of_nodes-1, cities_mat, num_of_nodes);
    if (TSP_distance == INT_MAX){
        printf("TSP shortest path: %d \n" , -1);
    }
    else{
        printf("TSP shortest path: %d \n" , TSP_distance);
    }
    deletel(&cities);
    return index;
}


void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *a, int l, int r , int cities_mat[][6] , int num_of_nodes){
    int i;
    if (l == r){
        int src = a[0];
        int sum = 0;
        for (int i=1 ; i<num_of_nodes ; i++){
            int dest = a[i];
            if (sum != INT_MAX){
                if (cities_mat[src][dest] != INT_MAX){
                    sum = sum + (cities_mat[src][dest]);
                }
                else{
                    sum = INT_MAX;
                }
            }
            src = dest;
        }
        if (sum<TSP_distance){
            TSP_distance = sum;
        }
    }
    else{
        for (i = l; i <= r; i++){
            swap((a+l), (a+i));
            permute(a, l+1, r, cities_mat, num_of_nodes);
            swap((a+l), (a+i));
        }
    }
}