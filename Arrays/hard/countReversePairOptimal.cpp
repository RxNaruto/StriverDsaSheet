#include<iostream>
using namespace std;

int countPairs(int arr[],int l,int mid,int h){
    int right = mid+1;
    int count=0;
    for(int i=l;i<=mid;i++){


        while(right<=h && arr[i]>2*arr[right]){
            right++;
            
        }
        count+=(right-(mid+1));
    }
    return count;
}
void merge(int arr[],int l,int mid,int h){
 
    int n1 = mid-l+1;
    int n2 = h-mid;

    int a1[n1];
    int a2[n2];

    for(int i=0;i<n1;i++){
        a1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        a2[i]=arr[mid+i+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            arr[k]=a1[i];
            i++;k++;
        }
        else{
            arr[k]=a2[j];
            j++;k++;
        }

    }
    while(i<n1){
        arr[k]=a1[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=a2[j];
        j++;k++;
    }
      
      

}
int mergeSort(int arr[],int l,int h){
    
        int count=0;
        if(l>=h){
            return count;
        }
        int mid = (l+h)/2;
        count+=mergeSort(arr, l,mid);
        count+=mergeSort(arr,mid+1,h);
        count+=countPairs(arr,l,mid,h);
        merge(arr,l,mid,h);
        return count;
 
}
int countReversePairs(int arr[],int n){
    return mergeSort(arr,0,n-1);


}
int main()
{
    int arr[]={3,2,1,4};
    cout<<countReversePairs(arr,3);
    
 return 0;
}