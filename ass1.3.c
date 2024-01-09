#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct city{
    char name[50];
    int stdcode[30];
};
int readfile(struct city *a);
int lsearch(struct city *a,int n,char x[20]);

int readfile(struct city *a)
{
    int i=0;
    FILE *fp=fopen("city.txt","r");
    if(fp==NULL)
    {
        printf("file is empty\n");
        exit;
    }
      
        while(!feof(fp))
        {
            fscanf(fp,"%s %d",a[i].name,&a[i].stdcode);
            
           
            i++;
        }
        return i;
}
    

int lsearch(struct city *a,int n,char x[20])
{
    for(int i=0;i<n;i++){
        if(strcmp(a[i].name,x)==0){
            return a[i].stdcode;
            exit;
        }

    }
    return 1;
}
    
int main()
{
    struct city x[20];
    char abc[30];
    int n;
    n=readfile (x);
    printf("\n enter the city name\n");
    scanf("%s",abc);
    int result;
    result=lsearch(x,n,abc);
    if(result==1)
    {
        printf("error");
    }
    else{
        printf("std code =%d",result);
    }
}