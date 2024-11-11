#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b){
    double a1 = (double)a.value/a.weight;
    double a2 = (double)b.value/b.weight;
    return a1>a2;


}
double fractionalKnapsack(vector<Item>items, int W){
    int size = items.size();
    sort(items.begin(),items.end(),compare);
    
    double currentVal = 0.0;
    for(int i=0;i<size;i++){
        if(items[i].weight<=W){
            currentVal += items[i].value;
            W=W-items[i].weight;

            
        }
        else{
            currentVal += (double(items[i].value)/items[i].weight)*W;
            break;
        }
    }
    return currentVal;
}
int main()
{
    vector<Item> items = {{100, 20}, {60, 10}, {120, 30}};
    int W = 50; 
    double maxValue = fractionalKnapsack(items, W);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    
 return 0;
}