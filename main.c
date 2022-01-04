#include <math.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"
#include "edges.h"
#include "nodes.h"
#include "algo.h"
#include "List.h"

int main(void) {
    char *ptr;
    char *word=malloc(1*sizeof *word);
    char c;
    int numofChars=0;
    c=getchar();
    word[0]=c;
    numofChars++;

    while((c=getchar()) != EOF && c != '\n'){
        numofChars++;
        ptr=realloc(word,numofChars*sizeof *ptr);
        if(ptr!=NULL){
        word=ptr;
        word[numofChars-1]=c;
        }
    }
    numofChars++;
    ptr=realloc(word,numofChars*sizeof *ptr);
    if(ptr!=NULL){
        word=ptr;
        word[numofChars-1]='\0';
    }

    pnode Head = NULL;
    int i=0;
    while (i<strlen(word)) {
        char c = word[i];
        if (c == 'A') {
            i = A(word, i + 2, &Head);
        }
        if (c == 'B') {
            i = B(word, i + 2, &Head);
        }
        if (c == 'D') {
            i = D(word, i + 2, &Head);
        }
        if (c == 'S') {
            i = S(word, i + 2, &Head);
        }
        if (c == 'T') {
            i = T(word, i + 2, &Head);
        }
    }
  free(word); // Freeing word/
  return 0;
}