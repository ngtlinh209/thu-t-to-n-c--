#include <iostream>
#include <utility> // thư viện của pair c++
using namespace std;
// pair là một kiểu dữ liệu theo cặp có thể chứa hai phần tử có kiểu dữ liệu khác nhau 


// sử dụng pair với hàm để trả về hai dữ liệu một lúc

pair<int,int> toado(int x,int y){ // kiểu dữ liệu trả về là kiểu pair
    return {x,y};
}

void haigiatri(pair<int,int> p){
     cout<<p.first<<" "<<p.second<<" ";
}


int main(){
    // Khai báo và khởi tạo môjt pair  ,pair<kiểu dữ liệu,kiểu dữ liệu> tên của pair

    pair<int,int> a={1,2}; // khai báo khởi tạo một pair cùng kiểu 
    cout<<"Phần tử đầu tiên của pair a là:"<<a.first<<endl;
    cout<<"Phần tử thứ hai của pair là:"<<a.second<<endl;

    pair <string ,int> tentuoi={"Nguyễn Thùy Linh ",17}; // khai báo khởi tạo một pair khác kiểu
    cout<<"Tôi tên là"<<" "<<tentuoi.first<<" "<<tentuoi.second<<"tuổi"<<endl;

    // so sánh hai pair 
    pair<int, int> a1={1,2};
    pair<int,int> a2={2,1};
    // sẽ so sánh bắt đầu từ phần tử thứ 1 của hai pair nếu băng nhau sẽ so sánh tiếp còn phần tử đầu lớn hơn thì pair đó lớn hơn
    if(a2>a1){
        cout<<"a2 lớn hơn a1";
    }
    cout<<endl;
    // Sử dụng pair với mảng và vector 
    /*
    cout<<"Nhập vào số phần tử :";
    int n; cin>>n;
    pair<int,int> my_pair[n];
    for(int i=0;i<n;i++){
        cin>>my_pair[i].first>>my_pair[i].second;
    }
    cout<<"Các phần tử trong mảng dùng pair là "<<endl;
    for(pair<int,int> x : my_pair){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
    cout<<"Nhập vào số lượng số phần tử của vector dùng pair:";
    int soluong;cin>>soluong;

    vector<pair<int,int>> my_pair2; 
    for(int i=0;i<soluong;i++){
        int x,y; cin>>x>>y;
        my_pair2.push_back({x,y});
    }
    cout<<endl;
    for(int i=0;i<soluong;i++){
       cout<<my_pair2[i].first<<" "<<my_pair2[i].second<<endl;
    }
    cout<<endl;
    */
    // sử dụng và gọi hàm với pair
    int x=6, y=4;
    pair<int,int> toadoxy=toado(x,y);
    cout<<"Toạ độ của và x và y là:"<<endl;
    cout<<toadoxy.first<<" "<<toadoxy.second<<" "<<endl;

    pair<int,int> p={1,2};
    cout<<"Hai giá trị pair của hàm void là:"<<endl;
    haigiatri(p);





    return 0;
}