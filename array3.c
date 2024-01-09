#include<stdio.h>
int main()
{
     int arr[5] = { 10,20,30,40,50}; // arr is one dimensional array which contain 5 element 

    const int brr[4] ={10,20,30,40};
     arr[1] = 21;// allowed
   // brr[1] = 21;  it not allowed bcz const
   printf("Base adress of array : %d\n",arr);
   printf("base adress of first element is: %d\n",&arr[0]);
   printf("adress of second element is : %d\n",&arr[1]);
   printf("first element is: %d\n",arr[0]);
   printf("size of whole array is: %d\n",sizeof(arr));
   printf("size of second element of array : %d\n",sizeof(arr[1]));
   





    return 0;
}