// Mảng động vector c++ có thể thay đổi kích thước tuỳ ý ,thêm ,xoá phần tử
#include <iostream>
#include <vector>
using namespace std;
// push_back() : chèn phần tử vào cuối vector
// size() : số lượng phần tử
// erase() : xoá toàn bộ hoặc xoá mảng theo khoảng bất kì
// reverse() đảo ngược toàn bộ hoặc xoá mảng theoc chiều bất kì 
// insert(k,x): chèn phần tử vào vị trí k trong mảng
int main(){
    vector<int> mang1; // khởi tạo một mảng vector
    int n;
    cout<<"Nhập vào số phần tử của mảng vector:";
    cin>>n;
    for(int i=0;i<n;i++){
        int phantu;
        cout<<"Nhập phần tử thứ "<<i+1<<" ";
        cin>>phantu;
        mang1.push_back(phantu); // puhs_back giống như phương thức append bên python
        
    }
    cout<<"Các phần tử của mạng động là :";
    for(int i=0;i<n;i++){
        cout<<mang1[i]<<" ";
    }
    cout<<endl;
    mang1.pop_back(); // pop_back : xoá phần tử cuối cùng trong mảng
    cout<<"Mảng động sau khi xoá 1 phần tử cuối là :";
    for(int i=0;i<mang1.size();i++){ // <tên mảng>.size(): trả về số lượng phần tử trong mảng
        cout<<mang1[i]<<" ";
    }
    mang1.clear(); // clear() : xoá toàn bộ phần tử trong mảng
    cout<<endl;
    cout<<"Mảng sau khi bị xoá hoàn toàn là:";
    for(int i=0;i<mang1.size();i++){
        cout<<mang1[i]<<" ";
    }




    

    return 0;
}