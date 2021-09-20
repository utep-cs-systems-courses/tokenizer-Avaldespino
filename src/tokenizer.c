#include <stdlib.h>
#include <stdio.h>

int space_char(char c){
  if(c == '\t' || c == ' '){
    // printf("Space_char = %c\n",c);
    return 1;}
  return 0;

}
int non_space_char(char c){
  // printf("non_space = %c\n",c);
  if(!space_char(c)){
    // printf("Returning non space true\n");
    return 1;}
  printf("Got white space char\n");
  return 0;
}

char *word_start(char *str){
  if(!str) return NULL;
  while(*str){
    // printf("word_start %c\n",*str);
    if(non_space_char(*str)){
      //printf("returning a string = %c,%i\n",*str,non_space_char(*str));
      return str;}
    str++;
  }
  printf("Coming to null\n");
  char *null = '\0'; 
  return null;
}

char *word_terminator(char *word){
  if(!word) return NULL;
  while(*word){
    if(space_char(*word)) return word;
    word++;
  }
  return '\0';
}


int count_words(char *str){
  int counter = 0;
    while(*str){
    str = word_start(str);
    printf("str before word term = %c\n",*str);
    if(str == NULL) break;
    counter++;
    str = word_terminator(str);
    
    if(str == NULL) break;
    printf("%c",*str);
    }
    return counter;
}

char *copy_str(char *inStr, short len){

  char* new_string = (char*)malloc(len+1);

  while((*inStr++ = *new_string++)!= '\0');
  new_string[len+1]='\0';
  return new_string;

}
 char **tokenize(char* str){
   //printf("Made it into tokenize\n");
   int words = count_words(str);
   // printf("Count words is:%i\n",words);
   char **tokens = (char**)malloc((words+1)*sizeof(char*));
   //printf("Step 1 passed\n");
   char *start_word=word_start(str);
   char *end_word;
   // printf("Step 2 passed\n");
   int i = 0;
   while(i<words){
     // printf("Inside loop:%i\n",i);
    
     end_word = word_terminator(start_word);
     //  printf("after end word\n");
     tokens[i] = copy_str(start_word,(end_word - start_word));
     start_word = word_start(end_word);
     // printf("After start word, start = %c\n",*start_word);
     i++;
   }
   tokens[words] = '\0';
 }


 void print_tokens(char **tokens){

 }

 void free_tokens(char **tokens){}
