#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){

    string my_string="Hello from C++";
    cout<<"Phần tử đầu tiên trong chuỗi là:"<<my_string[0]<<endl; // giống như python sẽ trả về vị trí theo <tên chuỗi>[vị trí]
    cout<<"Số phần tử hay chiều dài của chuỗi là :"<<my_string.length()<<endl; //trả về số lượng phần tử trong chuỗi bao gồm cả dấu cách
    cout<<"Phần tử đầu tiên đến phần tử thứ 3 trong chuỗi là:"<<my_string.substr(0,3)<<endl; //substr giống như cắt chuỗi bên python sustr(vị trí đầu , vị trí trí muốn cắt ra)

    // nối và cộng chuỗi
    string mot="Python and";
    string hai ="C++";
    string ba =mot+hai;
    cout<<"Sau khi cộng hai chuỗi là:"<<ba<<endl;

    // cách chuyển đổi từ chuỗi sang số nguyên ,sử dụng stoi()
    string n="100";
    string s="100";
    int n1=stoi(n);
    int s1=stoi(s);
    cout<<"Sau khi chuyển hai chuỗi sang số ta có thể cộng số nguyên có kết quả là :"<<n1+s1<<endl;
    
    // cách chuyển từ số nguyên sang string 
    int a=100,b=100;
    string a1=to_string(a);
    string b1=to_string(b);
    cout<<"Hai số nguyên cộng lại sau khi đổi sang kiểu string là:"<<a1+b1<<endl;



    // Thêm và chèn chuỗi vào chuỗi ban đầu
    string my_string1 ="Hello tôi tên là";
    my_string1.push_back('A'); // chèn một phần kiểu char vào cuối chuỗi
    cout<<my_string1<<endl;
    my_string1.insert(0,"linh"); // chèn một chuỗi vào vị trí index mong muốn 
    cout<<my_string1<<endl;

    // Đảo ngược và xoá chuỗi theo một khoảng mong muốn
    string my_string2="Holla";
    string my_string3="Hallo";
    cout<<"Chuỗi ban đầu là:"<<my_string2<<endl;

    reverse(my_string2.begin(),my_string2.end()); //đảo ngược toàn bộ chuỗi nếu muốn toàn bộ sử dụng giống như bên vector
    cout<<"Chuỗi sau khi đảo ngược từ đầu đến cuối là:"<<my_string2<<endl;

    my_string3.erase(2,3); // xoá phần tử 3 phần tử bắt đầu từ vị trí thứ 2
    cout<<"Chuỗi sau khi xoá là:"<<my_string3;



    return 0;

}
