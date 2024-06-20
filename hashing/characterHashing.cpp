#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    char a;
    cout<<"Enter the character"<<endl;
    cin>>a;

    int arr[26]={0};
    for(int i=0;i<s.size();i++){
        arr[s[i]-'a']++;
        
    }
    cout<<arr[a-'a'];
 return 0;
}