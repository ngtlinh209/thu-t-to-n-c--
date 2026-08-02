#include <iostream>
#include <map>
using namespace std;
// Map giống dictonary bên python nhưng khác là có thứ tự và không trùng lặp key
// insert({}) : chèn vào một cặp key value
// size() : trả về số lượng key hoặc value 
// erase(): xoá đi một key trong map
// count() : đếm số lần xuất hiện của một key trong map 
// find() : kiểm tra xem có xuất hiện key trong map không
int main(){
    map<string,int> mp; // khởi tạo một Map với string là kiểu dữ liệu của key ,int là của value 
    mp["Cam"]=10; // Gán giá trị và cập nhật luôn phần tử vào trong map
    mp["Ổi"]=20;
    mp["Dâu"]=5;
    mp.insert({"Sầu riêng",2}); // chèn một cặp key value vào trong map 

    // in ra các cặp gía trị trong map
    cout<<"Các cặp giá trị ở trong map là:"<<endl; //
    for(pair<string,int> x: mp){
        cout<<x.first<<":"<<x.second<<endl;
    }
    cout<<endl;
    cout<<"Có"<<" "<<mp.size()<<" "<<"key trong map"<<endl;

    // Nhập tìm kiếm ,xuất ,xoá các phần tử trong map
    cout<<"Nhập số cặp giá trị:";
    int n; cin>>n;
    map<string,string> my_map;
    cout<<"Nhập vào các cặp giá trị:"<<endl;
    for(int i=0;i<n;i++){
        string key ,value; cin>>key>>value;
        my_map.insert({key,value});
    } 
    cout<<"Các giá trị đã nhập là:"<<endl;
    for(pair<string,string> x : my_map){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
    cout<<"Hãy nhập một từ muốn kiểm tra: ";
    string tu; cin>>tu;
    if(my_map.count(tu)!=0){
        cout<<"Từ bạn tìm có ở trong map";
    }
    else{
        cout<<"Từ bạn tìm không có ở trong map";
    }
    cout<<endl;
    cout<<"Hãy nhập vào một từ muốn xoá :";
    string tu1; cin>>tu1;
    if(my_map.count(tu1)!=0){
        my_map.erase(tu1);
        cout<<"Map sau khi xoá phần tử(key) là:"<<endl;
        for(pair<string ,string> i : my_map){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
    else{
        cout<<"Trong map không có từ này";
    }
    return 0;
}