#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define sizemodeval 12

int cria_arquivo(char *arquivo){
  FILE *file;
  file = fopen(arquivo,"w");
  if(file==NULL){
      printf("Erro na criacao do arquivo\n");
      return(1);
  } else {
      fwrite("123456",6,1,file);
  }
  fclose(file);
  return 0;
}

char* permissao(char *file, char* modeval){
  struct stat st;

  memset(modeval,'\0',sizemodeval);
  if(stat(file, &st) == 0){
      mode_t perm = st.st_mode;
      modeval[0] = (perm & S_IRUSR) ? 'r' : '-';
      modeval[1] = (perm & S_IWUSR) ? 'w' : '-';
      modeval[2] = (perm & S_IXUSR) ? 'x' : '-';
      modeval[3] = (perm & S_IRGRP) ? 'r' : '-';
      modeval[4] = (perm & S_IWGRP) ? 'w' : '-';
      modeval[5] = (perm & S_IXGRP) ? 'x' : '-';
      modeval[6] = (perm & S_IROTH) ? 'r' : '-';
      modeval[7] = (perm & S_IWOTH) ? 'w' : '-';
      modeval[8] = (perm & S_IXOTH) ? 'x' : '-';
      modeval[9] = '\0';
      return (char*)modeval;     
  } else{
     return strerror(errno);
  }   
}


void main(){
  printf("Permissao do arquivo\n");
  char modeval[sizemodeval];
  char arquivo[] = {"teste.txt"};
  if(cria_arquivo(arquivo)==0){
     printf("%s\n\n",permissao(arquivo, modeval));
  }
}

