#include <iostream> 
#include <map>
using namespace std;
// Tìm giao của hai mảng 
int main(){
     int n;cin>>n;
     int*a=new int[n];
     int*b=new int[n];
     map<int,int> my_map1;
     map<int,int> my_map2;
     cout<<"Nhập phần tử cho mảng a:";
     for(int i=0 ;i<n;i++){
        cin>>a[i];
        my_map1[a[i]]=1;
     }
     cout<<"Nhập phần tử cho mảng b:";
     for(int i=0;i<n;i++){
        cin>>b[i];
        my_map2[b[i]]=1;
     }
     for(pair<int,int> x : my_map2){
        if(my_map1[x.first]==1){
             my_map2[x.first]=2;
        }
     }
     cout<<"Các phần tử xuất hiện ở cả hai mảng là:";
     for(pair<int,int> i : my_map2){
        if(my_map2[i.first]==2){
              cout<<i.first<<" ";
        }
     }


}