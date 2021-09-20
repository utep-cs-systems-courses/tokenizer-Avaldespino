#include <stdlib.h>
#include <stdio.h>

int space_char(char c){
  if(c =='\0')return 0;
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
  printf("Returning false\n");
  return 0;
}

char *word_start(char *str){
  while(*str){
    // printf("word_start %c\n",*str);
    if(non_space_char(*str)==1){
      printf("returning a string = %c,%i\n",*str,non_space_char(*str));
      return str;}
    str++;
  }
  printf("Coming to null");
  return NULL;
}

char *word_terminator(char *word){
  while(*word){
    if(space_char(*word)) return word;
    word++;
  }
  return NULL;
}

int count_words(char *str){
  int counter = 0;
  
  

  while(*str){
    str = word_start(str);
    //printf("str before word term = %c\n",*str);
    if(str == NULL) break;
    counter++;
    str = word_terminator(str);
    //printf("%c",*str);
    if(str == NULL) break;
    
    
   
  }

char *copy_str(char *inStr, short len){}

  return counter;
}
