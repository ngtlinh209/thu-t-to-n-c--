// Sắp xếp chèn : đưa phần tử cần chèn vào vị trí đúng trong c++

#include <iostream>
using namespace std;

void insertion_sort(int arr[],int n){
     for(int i=1;i<n;i++){
        int x=arr[i],pos=i-1;
        while(pos>=0 && x<arr[pos]){  // nếu phần tử đằng trước lớn hơn phần tử hiện tại thì dịch vị trí phần tử đó sang phải 
              arr[pos+1]=arr[pos];
              --pos;
        }
        arr[pos+1]=x;
     }
     
}

int main(){
    int n; cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertion_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}