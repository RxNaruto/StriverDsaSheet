#include<iostream>
using namespace std;
int count=0;
void merge(int arr[],int l,int mid,int h){
    int n1 = mid-l+1;
    int n2 = h-mid;

    int a1[n1];
    int a2[n2];

    for(int i=0;i<n1;i++){
        a1[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        a2[j]=arr[mid+j+1];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            arr[k]=a1[i];
            i++;
            k++;
        }
        else{
            arr[k]=a2[j];
            j++;
            k++;
            count+=(mid-l+1);
        }
    }
    while(i<n1){
        arr[k]=a1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=a2[j];
        j++;
        k++;

    }
}
void mergeSort(int arr[],int l,int h){
    if(l<h){
        int mid =(l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int countInversion(int arr[],int size){
    mergeSort(arr,0,size-1);
    return count;
}
int main()
{
    int arr[]={5,4,3,2,1};
  cout<<countInversion(arr,5);
 return 0;
}