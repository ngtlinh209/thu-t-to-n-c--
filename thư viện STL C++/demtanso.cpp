#include <iostream>
#include <map>
using namespace std;

// áp dụng map để đếm số lần xuất hiện của các  phần tử trong mảng 
int main(){
    int n; cin>>n;
    int*arr=new int[n];
    map<int,int> my_map;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        my_map[arr[i]]++;
    }
    cout<<"Tần số xuất hiện của các phần tử trong mảng là:"<<endl;
    for(pair<int,int> i : my_map){
        cout<<i.first<<": "<<i.second<<endl;
    }
    int max=-1000000;
    int phantu;
    for(pair<int,int> x : my_map){
        if(x.second>max){
            max=x.second;
            phantu=x.first;
        }
    }
    cout<<"Phần tử xuất hiện nhiều nhất trong mảng là:"<<phantu;
    return 0;
} 
