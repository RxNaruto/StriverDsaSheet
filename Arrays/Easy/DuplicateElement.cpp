//incomplete code


#include<iostream>
using namespace std;
void shiftElements(int arr[],int size){
    int end=size-1;
    for(int i=0;i<size;i++){
        arr[i]=arr[i+1];
    }
    arr[end]=NULL;
    end--;

}
void duplicateElement(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                shiftElements(arr,size);

            }
        }
    }
}

int main()
{
    int arr[7]={1,1,2,2,2,3,3};
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    duplicateElement(arr,7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

 return 0;
}