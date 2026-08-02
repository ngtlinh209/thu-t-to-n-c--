#include <iostream>
#include <set> // khai báo thư viện để dùng
using namespace std;
// insert(): chèn phần tử vào set
// size(): trả về số lượng phần tử trong set 
// erase(): xoá một phần tử trong set
// count(): đếm một tử trong set
// find(): tìm một phần tử trong set
int main(){
    set<int> a={1,1,2,3,4,5,5}; // khởi tạo một set và gán giá trị sẵn ,set là một tâph hợp ko có phần tử lặp lại
    // in ra các phần tử trong set ,do không có thứ tự nên không thể dùng a[i] 

    // xoá phần tử trong set
    cout<<"Set ban đầu là:";
    for(int i : a){
        cout<<i<<" ";
    }
    cout<<"Set lúc sau khi xoá phần tử 3 là là:"<<endl;
    a.erase(3);
    for(int x: a){
        cout<<x<<" ";
    }
    cout<<endl;
    // Nhập vào các phần tử trong set
    set<int> b={};
    cout<<"Nhập vào số phần tử :"<<endl;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int phantu;cin>>phantu;
        b.insert(phantu);
    }

    cout<<"Các phần tử đã nhập là:";
    for(int i : b){
        cout<<i<<" ";
    }
    cout<<endl;
    // Kiểm tra 1 phần tử có trong set không dùng count() hoặc find với find() điều kiện tìm kiếm là find(x) != set.end()
    set<int> c={1,2,3,5,6,};
    if(c.count(2)!=0){
        cout<<"Có phần tử 2 ở trong set";
    }
    else{
        cout<<"Không có phần tử 2 ở trong danh sách";
    }
    return 0;
}