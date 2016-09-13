#include <stdio.h>
#include<stdlib.h>
#define size 5
typedef struct Sarray {
    int arr[size];
}Sarray;
void OutData();
int *return1( int *array);
int *return2(int *array);
int *return3(int *point,int *array);
Sarray return4StructArray(Sarray newarr,int array[],int Size);
Sarray *ret5StructArray(Sarray *poi,int array[],int Size);
void printarray(int *array);
int summArray(int *start,int *end);

int main()
{
    OutData();
    return 0;
}
void OutData(){
    int i;
    int array [size]={1,2,3,4,5};
    return1(array);
    printarray(array);

    return2(array);
    printarray(array);

    int *point=(int*)malloc(size*sizeof(int));
    point=return3(point,array);
    printarray(point);

    int summ;
    summ=summArray(array,array+size);
    printf("Summ array=%d",summ);

    // Transfer an array as a parameter through the structure
    Sarray newarr;
    Sarray returnarr;
    printf("\nSize struct newarr=%d byte",sizeof(newarr));
    returnarr=return4StructArray(newarr,array,size);
    returnarr.arr[4]=100;
    for(i=0;i<size;i++){
        printf("%d ",returnarr.arr[i]);
    }

    Sarray *poin;
    Sarray *newpoin;
    poin=&returnarr;
    printf("\nPoint to struct=%d byte",sizeof(poin));

    newpoin=ret5StructArray(poin,array,size);
    newpoin->arr[0]=0;
    for(i=0;i<size;i++){
        printf("%d ",newpoin->arr[i]);
    }
}
int *return1(int *array){
    array[1]=4;
    return array;
}

int *return2(int *array){
    int *point;
    point=array;
    *(point+2)=12;
    point[4]=0;
    return point;
}

int *return3(int *point,int *array){
    point=array;
    point[0]=6;
    return point;
}

int summArray(int *start,int *end){
    int summ=0;
    while(start<end){
        summ+=*start;
        start++;
    }
    return summ;

}

Sarray return4StructArray(Sarray newarr,int array[],int Size){
    printf("\nSize struct newarr in funkcion=%d byte",sizeof(newarr));
    int i;
    for(i=0;i<Size;i++){
        newarr.arr[i]=array[i];
    }
    printf("\n");

    return newarr;
}

Sarray * ret5StructArray(Sarray *point,int array[],int Size){
    printf("\nPoint to struct in funkcion=%d byte",sizeof(point));
    int i;
    for(i=0;i<Size;i++){
        point->arr[i]=array[i];
        point++;
    }
    printf("\n");
    point-=Size;
    return point;
}

void printarray(int *array){
    int i;
    printf("After funkcion New array: ");
    for (i=0;i<size;i++){
        printf ("%d ",array[i]);
    }
    printf("\n");

}