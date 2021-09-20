#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"


int main(){
  char input[256];
  char *pass = input;
  while(1){

    
 puts(">Enter input, use q to break");
    fgets(input,256,stdin);
    fflush(stdout);
    if(input[0] == 'q'){
      break;
    }
    puts(input);
    pass = input;
    char  *start = word_start(pass);
    // char *end = word_terminator(start);
    // printf("Here is char* end= %c\n", *end);

    // printf("Word count = %i\n",count_words(start));
     char **tokens = tokenize(pass);
  }
  return 0;




}
