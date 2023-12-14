#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


char* cat(char *str1, char *str2) {
    char *s = (char*) malloc(strlen(str1) + strlen(str2) + 1);
    if (s != NULL) {
        strcpy(s, str1);
        strcat(s, str2);
        
    }
    return s;
}




int main(){
/*
    char s1[] = "Bil 214";
    char *s2 = (char*) malloc(strlen(s1) + 1);
    if (s2 != NULL) {

        strcpy(s2, s1);
        printf("%s\n", s2);
        char *s3 = cat(s1, s2);
        printf("S1 : %s\n",s1);
        if (s3 != NULL) {
            printf("%s\n", s3);
            free(s3);
            s3 = NULL;
        }
        free(s2);
        s2 = NULL;
    }
*/
/*
    char str1[20] = "Oruç";
    char str2[20] = "Erdem";
    printf("\n%s",cat(str1,str2));
    */

   /*
   char s1[5] = "Namx";
   char *s2 = "Here";
   printf("%s\n",strncpy(s1,s2,2));
   printf("%s\n",s1);

   size_t sayi = 1023;
   printf("%d",sayi);
   */

  char sentence []= "I know that I can do everything that I desire";
  printf("%s\n",sentence);
  char *sen = sentence;
  
  char *tokenPtr = strtok(sen," ");
  while(tokenPtr != NULL){
    printf("%s\n",tokenPtr);
    tokenPtr = strtok(NULL," ");
  } 
  



  

}