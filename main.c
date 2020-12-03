#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *arr[5];

char ** parse_args(char * line){
  char ** ans = arr;
  char * token;
  char * p = line;
  int i = 0;
  while (p != NULL){
    token = strsep(&p, " ");
    ans[i] = token;
    i++;
  }
  ans[i] = NULL;
  return ans;
}

int main(){
  char line[100] = "ls -a -l";
  char ** args = parse_args(line);
  execvp(args[0], args);
  return 0;
}
