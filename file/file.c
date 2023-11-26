#include<stdio.h>

struct Student{

    int id;
    char *name;
    int age;
    int gpa;
};

typedef struct Student Student;

void printPerson(Student *student){

    printf("Name : %s\n ",student->name);
    printf("ID : %d\n",student->id);
    printf("Age : %d\n",student->age);
    printf("GPA : %d\n",student->gpa);

}

void printFileContent(char *file_name, FILE *file_pointer){

    file_pointer = fopen(file_name,"r");

    if(file_pointer == NULL){
        perror("file_pointer");
    }
    else{

        while(feof(file_pointer) == 0){

            char ch = fgetc(file_pointer);
            if(ch != EOF)
                printf("%c",ch);

        }

        fclose(file_pointer);

    }

}

void copyFileContentToAnotherFile(char *file_name_in,FILE *fp_in, char *file_name_out, FILE *fp_out){

    fp_in = fopen(file_name_in,"r");
    if(fp_in == NULL){
        perror("fp_in");
    }
    else{

        fp_out = fopen(file_name_out,"w");
        if(fp_out == NULL){
            perror("fp_out");
        }
        else{

            char ch = fgetc(fp_in);

            while(ch != EOF){
                fputc(ch,fp_out);
                ch = fgetc(fp_in);
            }

            fclose(fp_out);

        }



        fclose(fp_in);
    }

    printf("\n");
    printf("\n");

}




int main(){

    char *file_name_in = "sample.txt";
    FILE *file_pointer_in;
    FILE *file_pointer_out;
    char *file_name_out = "sample_out.txt";

    printFileContent(file_name_in,file_pointer_in);
    copyFileContentToAnotherFile(file_name_in,file_pointer_in,file_name_out,file_pointer_out);
    printFileContent(file_name_out,file_pointer_out);

    


    return 0;
}