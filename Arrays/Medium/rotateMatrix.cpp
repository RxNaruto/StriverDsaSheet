#include<iostream>
using namespace std;
void rotateMatrix(int arr[4][4]){
    int newMat[4][4]={0};
    for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
        newMat[j][3-i] = arr[i][j];
       }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<newMat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int arr[4][4]={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotateMatrix(arr);
 return 0;
}