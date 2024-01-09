#include<stdio.h>
void DisplayExamTime(int istandard)
{
  switch(istandard)
  {
    case 1:
    printf("your exam is at 8 am\n");
    break;
    case 2:
    printf("your exam is at 9 am\n");
    break;
    case 3

  }
    
}
int main()
{
    int ivalue = 0;
    printf("Enter your standard \n");
    scanf("%d",&ivalue);

    DisplayExamTime(ivalue);
    return 0;
}