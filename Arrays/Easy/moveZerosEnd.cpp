#include<iostream>
using namespace std;
void moveZeroesToEnd(int arr[],int size){
   
   int zeros=0;
   for(int i=0;i<size;i++){
      if(arr[i]==0){
         zeros++;
      }

   }
   int n=size-zeros;
   int arr2[n];
   int count=0;
   for(int i=0;i<size;i++){
      if(arr[i]!=0){
         arr2[count]=arr[i];
         count++;

      }

   }
   for(int i=0;i<size;i++){
      arr[i]=arr2[i];
   }
   for(int i=n;i<size;i++){
      arr[i]=0;
   }
}
int main()
{
   int arr[7]={0,2,0,5,0,1,4};
   for(int i=0;i<7;i++){
      cout<<arr[i];
   }
   cout<<endl;
   moveZeroesToEnd(arr,7);
  for(int i=0;i<7;i++){
      cout<<arr[i];
   }
 return 0;
}