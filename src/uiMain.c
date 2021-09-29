#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


int main(){
  char input[256];
  char *pass = input;
  int token = 1;
  int lists = 1;
  List *history = init_history();
  while(1){

    while(lists){
      puts("-----History-----");
    puts(">Enter input, use !q to break, use !t to switch to Tokenize");
    puts("Enter any string for it to be added to a list. !p to print. ![number] for a specific slot");
    
    
    fgets(input,256,stdin);
    fflush(stdout);
    if(input[0] == '!' && input[1] == 'q'){
      goto done;
    }
    else if(input[0] == '!' && input[1] == 't'){
      history = 0;
      token = 1;
      break;
    }
    else if(input[0] == '!' && input[1] == 'p'){
      puts("-----History-----\n");
      print_history(history);
    }
    else if(input[0] == '!' && input[1] == '['){
      printf("Given item [%c]  ",input[2]);
      char *start = pass+2;
      char *end;
      while(*start){
	if(*start == ']'){
	  --start;
	  end = start;
	  break;
	}
	start++;
      }
      
      if(end == start){
	int index = atoi(start);
	printf("[%d] %s\n",index,get_history(history,index));
      
      }else{
      char *copy = copy_str(start,(end-start));
      int index = atoi(copy);
      
      printf("[%d] %s\n",index,get_history(history,index));
      free(copy);
      }
      
    }
    else{
    pass = input;
    add_history(history,pass);
    printf("Added %s\n",pass);
    }
    
    
    }

     
  }

 done:
  return 0;




}
