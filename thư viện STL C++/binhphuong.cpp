#include <iostream>
#include <map>
#include <cmath>
using namespace std;
void binhphuong(int n){
       map<int,int> binhphuong;
       for(int i=1;i<=n;i++){
            binhphuong[i]=pow(i,2);
       }
       for(pair<int,int> x : binhphuong){
            cout<<x.first<<":"<<x.second<<endl;
       }
}
int main(){
     int n; cin>>n; 
     cout<<"Bảng bình phương từ 1 cho đến n là:"<<endl;
     binhphuong(n);
     
    return 0;
}
