#include <iostream>
#include <algorithm>
using namespace std;
// CÁCH SỬ DỤNG HÀM SORT VỚI VECTOR , MẢNG VÀ DÙNG TRONG CÁC CÁCH DÙNG TRONG TRƯỜNG HỢP PHÔT BIẾN
// COMPERATOR : HÀM SẮP XẾP TỰ ĐINH NGHĨA ĐC TRUYỀN VÀO SORT,cách sử dụng sort của vectỏ và mảng gần giống nhau

// sort(a,a+n) : sắp xếp mang theo thứ tự tăng dần 
// sort(a,a+n,greater<int>()) : sắp xếp theo thứ tự giảm dần
// sort(a+x,a+y) : sắp xếp mảng từ vị trí x cho đến vị trí y-1

/* Hàm tự định ngĩa sắp xếp comperator( ở đây có thể dùng hàm này thay cho greater <int> để sắp xếp giảm dần
hoặc các cánh sắp xếp khác như sắp xếp theo chiều dài của từ ,trị tuyệt đối ,...

*/
bool sosanh(int a, int b){
    return a<b;
}
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    sort(arr,arr+n); // sắp xếp theo chiều tăng dần trong mảng
    
    cout<<"Mảng sắp xếp theo chiều tăng dần là:";
    for(auto x : arr){
        cout<<x<<" ";
    }
    //sort(arr,arr+n,greater<int>()); // sắp xếp theo chiều giảm dần trong mảng

    sort(arr,arr+n,sosanh); // không cần cặp ngoặc vuông của hàm
    cout<<endl;
    cout<<"Mảng sắp xếp theo chiều giảm dần là";
    for(auto i: arr){
        cout<<i<<" ";
    }

    return 0;
}
