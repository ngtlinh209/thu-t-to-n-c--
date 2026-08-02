// Hợp nhất hai mảng đã sắp xếp thành một mảng đã sắp xếp trong c++
#include <iostream>
#include <algorithm>
using namespace std;
int main(){  
    int m,n;
    cout<<"Nhập số lượng phần tử cho mảng a và b:";
    cin>>m>>n;
    int a[m], b[n];
    cout<<"Nhập các phần tử trong mảng a:";
    for( int &x:a){
       cin>>x;
    }   
    cout<<"Nhập các phần tử trong mảng b:";
    for(int &i:b){   
        cin>>i;  
    }
    sort(a,a+m);
    sort(b,b+n);
    cout<<"Các phần tử trong hai mảng ban đầu được sắp xếp là :"<<endl;
    for(int x : a){
        cout<<x<<" ";
    }
    cout<<endl;
    for(int z: b){
        cout<<z<<" ";
    }
    cout<<endl;
    // Bắt đầu cài đặt thuật toán hợp nhất hai mảng đã sắp xếp bằng kĩ thuật hai con trỏ ,sắp xếp thep tứ tự bé đến lớn 

    int i=0,j=0,k=0; // con trỏ i đại diện cho mảng a , con trỏ j cho mảng b , con trỏ k cho mảng mới c
    int c[m+n]; // khai báo một mảng có kích thước m+n để hợp nhất hai mảng đã có
    while(i<n && j<m){
        if(a[i]<b[j]){ 
            c[k]=a[i]; // nếu a[i]<b[j] thì sẽ đặt nó vị trí ở trong mảng c và đồng thời con trỏ đó được đi trước nên phải tăng i và tăng k cho lượt sau
            i++;
            k++;
        }
        else{
            c[k]=b[j]; // ngược lại nếu a[i]>b[j] thì ta làm tương tự trên đưa phần tử b[j] vào vị trí k tăng đồng thời j và k
            j++;
            k++;
        }
    }
    // kiếm tra nếu phần tử của một trong hai mảng chưa hết mà mảng kia đã hết phần tử 
    while(i<n){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m){
       c[k]=b[j];
       j++;
       k++;
    }
    // in ra mảng c sau khi đã hợp nhất hai mảng
    cout<<"Hai mảng sau khi hợp nhất thành một mảng đã sắp xếp là:";
    for(int z=0;z<m+n;z++){
        cout<<c[z]<<" ";
    }
    return 0;
}