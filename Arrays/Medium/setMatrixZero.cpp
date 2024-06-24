#include<iostream>
using namespace std;
void setMatrixZero(int arr[][4]){
     int row[3]={0};
     int col[4]={0};
     for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
     }
     for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(row[i] || col[j]){
                arr[i][j]=0;
            }
        }
     }
}
void printing(int arr[][4]){
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int arr[3][4]={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setMatrixZero(arr);
    printing(arr);
 return 0;
}