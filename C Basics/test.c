#define MAX_OCCURENCE 10
#define MAX_INT_NUMBER 10
#include <stdio.h>
#include <string.h>
#include <stddef.h> 

void printArray(int arr[], int);
void printMatrix(int arr[][MAX_INT_NUMBER], int, int);
void removeCharacters(char*, char**);
void initializeAddr(char**, int);

int numbers[][MAX_INT_NUMBER] = { {6,7,8,9,0,10,-10,-5,2,-3}, {5,6,7,8,9,0,-4,-3,-2,-1}, {1,2,3,4,5,6,7,8,9,0} };
char *compare[] = {"First str is LOWER", "They are EQUAL", "First str is GREATER"};
char str[1000], str2[100], s[20];
int x, y, z, size, addNum, mulNum, *ptr, nums[100];
char c, *cPtr, *addr[MAX_OCCURENCE];

int soru01(char s[], unsigned int x){

    int size = 0;
    int copy_x = x;
    while (copy_x != 0)
    {
        size++;
        copy_x /= 10;   
    }
    
    for(int i=size -1; i>=0; i--){
        s[i] = (char)((x % 10) + '0');
        x/=10;
    }

    s[size] = '\0';
	
	return size;
}

void soru02(char s[], unsigned int depth){

    int index = 0;
    for(int i=1; i<= depth; i++){

        for(int k=1; k<=i; k++){

            if(i != k){
                s[index++] = '*';
                s[index++] = ' ';
            }
            else
                s[index++] = '*';

        }

        if(i != depth)
            s[index++] = '\n'; 

    }

    s[index] = '\0';
	
}

void soru03(char s[], unsigned int depth){

    int value = 1;
    int index = 0;
    int copy_val = 0;
    int size=0;

    for(int i=1; i<= depth; i++){
        for(int k=1; k<=i; k++){

            size = 0;
            copy_val = value;
            while (copy_val != 0)
            {
                size++;
                copy_val /= 10;   
            }      

            char c[size];
            soru01(c,value);

            for(int j=0; j<size; j++)
                s[index++] = c[j];
            
            if(i != k){
                s[index++] = ' ';
            }
            

            value++;
        }

        if(i!= depth)
            s[index++] = '\n';

    }

    s[index] = '\0';
	
}

void soru04(int x, int y, int *addPtr, int *mulPtr){

    *addPtr = x + y;
    *mulPtr = x*y;
	
}

int* soru05(int *p1, int *p2, int *p3){

    if(p3 == NULL){
        return (*p1 <= *p2 ? p1 : p2);
    }
    else{
        if(*p1 <= *p2 && *p1 <= *p3)
            return p1;
        else if(*p2 <= *p1 && *p2 <= *p3)
            return p2;
        else
            return p3;
    }
	
}

void soru06(int *p1, int *p2, int *p3){

}

void soru07(char *s, int *sizePtr){

    *sizePtr = 0;

    if(s == NULL){
        return;
    }
    
    while (*s != '\0')
    {
        *sizePtr = *sizePtr + 1;
        s++;   
    }

    *sizePtr = *sizePtr + 1;

}

char* soru08(char *s, char c){

    if(s == NULL)
        return NULL;
    
    while (s != NULL)
    {
        if(*s == c)
            return s;
        
        s++;
    }
    
	
	return NULL;	
}

int soru09(char *s1, char *s2){

    while (*s1 != '\0' && *s2 != "\0")
    {
        if(*s1 != *s2){
            if(*s1 < *s2)
                return -1;
            else 
                return 1;
        }

        s1++;
        s2++;
    }

    if(*s1 == '\0' && *s2 == '\0')
        return 0;
    else if(*s1 != '\0' && *s2 == '\0')
        return 1;
    else
        return -1;
    
	
	return 0;	// Not correct. You can delete this line. 
}

void soru10(int nums[][MAX_INT_NUMBER], const unsigned int row_size, const unsigned int col_size, const unsigned int value){

    int *start = &nums[0][0];
    int *end = &nums[row_size-1][col_size];

    while (start != end)
    {
        *start = value;
        start++;
    }
    
}

void soru11(int nums[][MAX_INT_NUMBER], const unsigned int i, const unsigned int col_size, int *minPtr){

    int *start = &nums[i][0];
    int *end = &nums[i][col_size];
    *minPtr = nums[i][0];
    
    while (start != end)
    {
        if(*start <= *minPtr){
            *minPtr = *start;
        }
        start++;
    }
    
	
}

int soru12(char **s, const unsigned int i){

    char *word = s[i];
    char *c = word;

    while (*c != '\0')
    {
        *ptr = *ptr + 1;
        c++;
    }

    return c - word;
    
}

void soru13(int A1[], int A2[], const unsigned int size1, const unsigned int size2, int *B){

    int *ptr1=A1;
    int *ptr2 =A2;

    while (ptr1 != &A1[size1] && ptr2 != &A2[size2])
    {
        if(*ptr1 <= *ptr2){
            *B = *ptr1;
            B++;
            ptr1++;
        }
        else{
            *B = *ptr2;
            B++;
            ptr2++;
        }
    }

    while (ptr1 != &A1[size1])
    {
        *B = *ptr1;
        B++;
        ptr1++;
    }

    while (ptr2 != &A2[size2])
    {
        *B = *ptr2;
        B++;
        ptr2++;
    }
    
    
	
}

int soru14(int A[], const unsigned int size, int even[], int odd[]){

    int *evenPtr = even;
    int *oddPtr = odd;
    int *start = A;
    int *end = &A[size];

    while (start != end)
    {
        if(*start % 2 == 0){
            *evenPtr = *start;
            evenPtr++;
        }
        else{
            *oddPtr = *start;
            oddPtr++;
        }
        start++;
    }
    
	return (evenPtr - even);
}
	

void soru15(char **addr, char *p, char c){

    addr[0] = p;
    addr = addr + 1;

    while (*p != '\0')
    {
        if(*p == c){
            *addr = p;
            addr = addr + 1;
        }
        p++;
    }
    
    *addr = p;
    
}



int main(int argc, char* argv[]) {
    /*
	

	

	

	

	

	

	

	
*/
    char c = '\0';
    char *p = &c;
    printf("%p",p);

    char *a[] = {"hdbjs","bjdscbdf","oruç","çakır"};
    char **b = a;
    b[0] = "hc";

    printf("%s",a[0]);

    int i=0;
    while (i<4)
    {
        i++;
        printf("%s",*b);
        printf("\n");
        b++;
        /* code */
    }

    int arr[] = {1,1,1,1,1,220440,40,10,04,014,10,401,4014,104};
    printf("ARRSIZE %d\n",sizeof(arr) / sizeof(int));
    
    


    printf("----------------------------------------soru01----------------------------------------\n");
	x=0; size=soru01(s, x); printf("x:%-10d s:%-10s size:%d\n", x, s, size);
	x=1234567890; size=soru01(s, x); printf("x:%-10d s:%-10s size:%d\n", x, s, size);
	x=97531; size=soru01(s, x); printf("x:%-10d s:%-10s size:%d\n", x, s, size);

    printf("\n----------------------------------------soru02----------------------------------------\n");
	soru02(str, 15); printf("%s\n", str); printf("Number of characters: %lu\n", strlen(str));
	soru02(str, 10); printf("%s\n", str); printf("Number of characters: %lu\n", strlen(str));

    printf("\n----------------------------------------soru03----------------------------------------\n");
	soru03(str, 15); printf("%s\n", str); printf("Number of characters: %lu\n", strlen(str));
	soru03(str, 10); printf("%s\n", str); printf("Number of characters: %lu\n", strlen(str));

    printf("\n----------------------------------------soru04----------------------------------------\n");
	x=10; y=15; soru04(x, y, &addNum, &mulNum); printf("x:%d y:%d add:%d mul:%d\n", x, y, addNum, mulNum);
	x=120; y=-5; soru04(x, y, &addNum, &mulNum); printf("x:%d y:%d add:%d mul:%d\n", x, y, addNum, mulNum);

    printf("\n----------------------------------------soru05----------------------------------------\n");
	printf("Address of x:%p\nAddress of y:%p\nAddress of z:%p\nExpected Addresses:\n", &x, &y, &z);
	x=10; y=10; z=5; ptr=soru05(&x, &y, NULL); printf("x:%p\n", ptr);
	x=10; y=7; z=5; ptr=soru05(&x, &y, NULL); printf("y:%p\n", ptr);
	x=10; y=7; z=7; ptr=soru05(&x, &y, &z); printf("y:%p\n", ptr);
	x=10; y=7; z=5; ptr=soru05(&x, &y, &z); printf("z:%p\n", ptr);
	x=1; y=7; z=5; ptr=soru05(&x, &y, &z); printf("x:%p\n", ptr);

    printf("\n----------------------------------------soru06----------------------------------------\n");
	x=7; y=10; z=5; soru06(&x, &y, NULL); printf("x:%d y:%d z:%d\n", x, y, z);
	x=8; y=7; z=5; soru06(&x, &y, NULL); printf("x:%d y:%d z:%d\n", x, y, z);
	x=8; y=7; z=5; soru06(&x, &y, &z); printf("x:%d y:%d z:%d\n", x, y, z);
	x=8; y=5; z=5; soru06(&x, &y, &z); printf("x:%d y:%d z:%d\n", x, y, z);
	x=1; y=5; z=3; soru06(&x, &y, &z); printf("x:%d y:%d z:%d\n", x, y, z);
	x=5; y=1; z=3; soru06(&x, &y, &z); printf("x:%d y:%d z:%d\n", x, y, z);

    printf("\n----------------------------------------soru07----------------------------------------\n");
	strcpy(s, "C Program"); soru07(s, &size); printf("s:%s size:%d\n", s, size);
	strcpy(s, "Bil214"); soru07(s, &size); printf("s:%s size:%d\n", s, size);
	strcpy(s, "\0"); soru07(s, &size); printf("s:%s size:%d\n", s, size);
	soru07(NULL, &size); printf("s:%p size:%d\n", NULL, size);

    printf("\n----------------------------------------soru08----------------------------------------\n");
	c='g'; strcpy(s, "System Programming"); cPtr=soru08(s, c); printf("c:%c s:%s offset:%lu\n", c, s, cPtr-s);
	s[8]='\0'; cPtr=soru08(s, c); printf("c:%c s:%s cPtr:%p\n", c, s, cPtr);
	c=' '; cPtr=soru08(s, c); printf("c:%c s:%s offset:%lu\n", c, s, cPtr-s);
	c='S'; cPtr=soru08(NULL, c); printf("c:%c s:%p cPtr:%p\n", c, NULL, cPtr);
	
    printf("\n----------------------------------------soru09----------------------------------------\n");
	strcpy(str, "Bil 214AC"); strcpy(str2, "Bil 214B"); printf("s1:%s \ts2:%s \t%s\n", str, str2, compare[soru09(str, str2)+1]);
	strcpy(str, "Bil 214BD0"); strcpy(str2, "Bil 214BD"); printf("s1:%s \ts2:%s \t%s\n", str, str2, compare[soru09(str, str2)+1]);
	strcpy(str, "Bil 214"); strcpy(str2, "Bil 214"); printf("s1:%s \ts2:%s \t%s\n", str, str2, compare[soru09(str, str2)+1]);
	strcpy(str, "Bil 214_"); strcpy(str2, "Bil 2149"); printf("s1:%s \ts2:%s \t%s\n", str, str2, compare[soru09(str, str2)+1]);
	strcpy(str, ""); strcpy(str2, ""); printf("s1:%s \ts2:%s \t%s\n", str, str2, compare[soru09(str, str2)+1]);


    printf("\n----------------------------------------soru10----------------------------------------\n");
	{ int nums[4][MAX_INT_NUMBER]; soru10(nums, 4, MAX_INT_NUMBER, 13); printMatrix(nums, 4, MAX_INT_NUMBER); };
	{ int nums[6][MAX_INT_NUMBER]; soru10(nums, 6, MAX_INT_NUMBER, -5); printMatrix(nums, 6, MAX_INT_NUMBER); };

    int d = 10;
    ptr = &d;
    printf("\n----------------------------------------soru11----------------------------------------\n");
	for (int i=0; i<3; i++){
		printf("Numbers:"); printArray(numbers[i], MAX_INT_NUMBER);
		soru11(numbers, i, MAX_INT_NUMBER, ptr); printf("\tmin:%d\n", *ptr);
	
    }

    printf("\n----------------------------------------soru12----------------------------------------\n");
	for (int i=0; i<3; i++){
		size=soru12(compare, i); printf("compare[%d]:%s \tsize:%d\n", i, compare[i], size);
	}

    printf("\n----------------------------------------soru13----------------------------------------\n");
	int A1[] = {1,2,2,3,3,5,6,8,11,15,20,30};
	int A2[] = {-1,0,1,3,4,6,7,10,13,18,25};
	soru13(A1, A2, 12, 11, nums);
	printf("A1: "); printArray(A1, 12); printf("\n");
	printf("A2: "); printArray(A2, 11); printf("\n");
	printf("combined: "); printArray(nums, 23); printf("\n");

	printf("\n----------------------------------------soru14----------------------------------------\n");
	printf("A: "); printArray(nums, 23); printf("\n");
	size = soru14(nums, 23, A1, A2);
	printf("even: "); printArray(A1, size); printf("\n");
	printf("odd: "); printArray(A2, 23-size); printf("\n");


	printf("\n----------------------------------------soru15----------------------------------------\n");
	strcpy(str2, ""); strcpy(str, "Bil 214 System Programming Course is OK"); initializeAddr(addr, MAX_OCCURENCE);
	c=' '; soru15(addr, str, c); removeCharacters(str2, addr); printf("str: %s\nstr2: %s\n", str, str2);
	strcpy(str2, ""); strcpy(str, "Bil 214 System Programming Course is the best course ever"); initializeAddr(addr, MAX_OCCURENCE);
	c=' '; soru15(addr, str, c); removeCharacters(str2, addr); printf("str: %s\nstr2: %s\n", str, str2);
	strcpy(str2, ""); strcpy(str, "Bil-214-System-Programming-Course-is-OK"); initializeAddr(addr, MAX_OCCURENCE);
	c='-'; soru15(addr, str, c); removeCharacters(str2, addr); printf("str: %s\nstr2: %s\n", str, str2);

	return 0;
}

void printArray(int arr[], int size){
	for (int i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
}

void printMatrix(int arr[][MAX_INT_NUMBER], int row_size, int col_size){
	for (int i=0; i<row_size; i++){
		for (int j=0; j<col_size; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}	
}

void initializeAddr(char **addr, int size){
	for (int i=0; i<size; i++){
		*addr = NULL;
		addr++;
	}
}

void removeCharacters(char *s, char **addr){
	int size=0;
	strncpy(s, *addr, (*(addr+1))-(*addr));
	size += ((*(addr+1))-(*addr));
	addr++;
	while (*(addr+1) != NULL){
		strncpy(s+size, (*addr)+1, (*(addr+1))-((*addr)+1));
		size += (*(addr+1))-((*addr)+1);
		addr++;
	}
	s[size] = '\0';
}


