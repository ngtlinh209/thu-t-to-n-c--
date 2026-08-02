#include <iostream>
#include <cmath>
using namespace std;

// THUẬT TOÁN SÀNG SỐ NGUYÊN TỐ
// b1 tạo một mảng có n+1 phần tử 
// b2 mặc định tất cả các số là số nguyên tố
// b3 loại bỏ các bội của các số là số nguyên tố ,vì bội của một số chắc chắn không phải số nguyên tố

int arr[10000001];
void sangsonguyento(){
    for(int i=0;i<=1000000;i++){
        arr[i]=1;
    }
    arr[0]=arr[1]=0; // gán cho 0 và 1 không phải số nguyên tố 
    for(long long i=2;i<=sqrt(1000000);i++){ // cho chạy các số từ 2 cho đến căn của n và loại bỏ dần các bội của số này 
       if(arr[i]) 
          for(long long  j=i*i;j<=10000001;j+=i){ // duyệt các bội của i
               arr[j]=0; 
       }
    }
}

int main(){
    long long count=0;
     cout<<"Nhập vào n:";
     int n;cin>>n;
     sangsonguyento();
     for(long long  i=1;i<=n;i++){
        if(arr[i]){
            count+=1;
            cout<<i<<" ";
        }
     }
     cout<<endl;
     cout<<"Có "<<count<<" "<<"số nguyên tố";
    return 0;
}