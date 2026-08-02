#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> arr;
    vector<int>::iterator x; // khai báo biến iterator hoạt động gần giống con trỏ dùng dê duyệt qua các giá trị trong vector hay set,map mà không cần quan tâm đến kiểu dư liệu
    for(int i=1;i<11;i++){
        arr.push_back(i);
    }
    // in ra mảng bằng iterator 
// arr.begin() : là điểm đầu tiên trong mảng ,arr.end() là điểm kết thúc khi in phải thêm * để lấy giá trị 
    cout<<"Mảng được xuất ra bằng iterator là:";
    for(x=arr.begin() ; x!=arr.end();x++){
        cout<<*x<<" ";
    }
    cout<<endl;

    // Phương thức erase(): dùng để xoá một khoảng  giá trị hoặc một giá trị nhất đinh trong mảng ,cần có điểm và bắt đầu và kết thúc

    arr.erase(arr.begin()+3); // xoá phần tử có chỉ số index 3 tức số 4
    cout<<"Sau khi xoá 1 phần tử bằng erase là:";
    for(x=arr.begin() ; x!=arr.end();x++){
        cout<<*x<<" ";
    }
    cout<<endl;
    arr.erase(arr.begin(),arr.begin()+4); // xoá một khoảng phần tử từ vị trí index 0 đến vị trí index 4
    for(x=arr.begin() ; x!=arr.end();x++){
        cout<<*x<<" ";
    }

    // Phương thức reverse(): đảo ngược toàn bộ hoặc một khoảng trong mảng cần dùng thêm thư viện algorithm
    vector<int> arr2;
    for(int i=5;i<16;i++){
        arr2.push_back(i);
    }
    cout<<"Mảng khi chưa bị đảo ngược là:"<<endl;
    cout<<endl;
    for(int x: arr2){
        cout<<x<<" ";
    }
    cout<<endl;
    reverse(arr2.begin(),arr2.begin()+3); // đảo ngược mảng từ vị trí 0 cho đến vị trí index 3
    cout<<"Mảng sau khi bị đảo ngược từ chỉ số 0 đến 3 là:"<<endl;
    for(int i :arr2){
       cout<<i<<" ";
    }







    
    








    return 0;
}