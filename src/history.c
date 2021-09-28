#include <stdlib.h>
#include <stdio.h>
#include <tokenizer.h>

List* init_history(){
  List* list = (List*)malloc(sizeof(List));

  return list;

}
void add_history(List *list, char *str){
Item node = NULL;
node = malloc(sizeof(*Item));

int id = 0;
if(list.root == NULL){
node.id = id;
list.root = node;
}

}
