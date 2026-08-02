// Hàm hỗ trợ tìm kiếm nhị phân có sẵn trong c++
#include <iostream>
#include <algorithm> // phải khai báo thư viện này 
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n;i++){
        int phantu; cin>>phantu;
        arr.push_back(phantu);
    }
    // đối vs mảng : binary_search(a+x,a+y, key ) : sẽ tìm kiếm trong khoảng a[x] đến a[y-1]
    // đối vs vector : binart_search(v.begin+3; v.begin+7) : sẽ tìm kiếm trong khoảng v[3] đến v[6]
    int target; cin>>target;
    sort(arr.begin(),arr.end());
    if(binary_search(arr.begin(),arr.end(),target)){ // sử dụng hàm binary_search(vị trí đầu , vị trí cuối trong mảng,phần tử tìm kiếm)
        cout<<"Có tìm thấy phần tử này trong mảng";
    }
    else{
        cout<<"Không tìm thấy";
    }

    return 0;
}

