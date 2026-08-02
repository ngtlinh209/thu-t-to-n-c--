// Sắp xếp nổi bọt có độ phức tạp O(n^2) về thời gian và O(1) về không gian
#include <iostream>
using namespace std;
void bubble_sort(int arr[],int n){
       for(int i=0;i<n-1;i++){ // vòng lặp i đếm số lần chạy hết mảng

         for(int j=0;j<n-i-1;j++){ // vòng lặp j chỉ chạy đến trước các phần tử đã sắp xếp 
            if(arr[j]>arr[j+1]){ // sắp xếp giảm dần bằng bubble sort 
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
         }
       }
       for(int i=0;i<n;i++){
           cout<<arr[i]<<" ";
       }
}

int main(){         
    int n; cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubble_sort(arr,n);
    return 0;
}

