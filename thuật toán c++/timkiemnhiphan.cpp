#include <iostream>
#include <algorithm>
using namespace std;

// tìm kiếm nhị phân thông thường
bool timkiem_nhiphan(int arr[],int n, int x){
     int l=0,r=n-1;
     while(l<=r){
       int  mid=(l+r)/2;
       if(arr[mid]==x){
          return true;
       }
       else if(arr[mid]>x){
            r=mid-1;
       }
       else{
          l=mid+1;
       }
     }
     return false;
}

// tìm kiếm vị trí đầu tiên của phần tử trong mảng bằng tìm kiếm nhị phân
int first(int arr[],int n,int x){
        int l=0,r=n-1;
        int result=-1; // không tìm thấy sẽ mặc địng trả về -1
        while(l<=r){
            int m=(l+r)/2;
            if(arr[m]==x){
                result=m;
                r=m-1;
            }
            else if(arr[m]>x){
                 r=m-1;
            }
            else{
                l=m+1;
            }

        }
        return result;
}

// tìm kiếm vị trí cuối cùng của một phần tử trong mảng
int last(int arr[], int n, int x){
    int l=0,r=n-1;
    int result=-1;
    while(l<=r){
        int giua=(l+r)/2;
        if(arr[giua]==x){
            result=giua;
            l=giua+1;
        }
        else if(arr[giua]>x){
            r=giua-1;
        }
        else{
            l=giua+1;
        }
    }
    return result;
}
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n); // sắp xếp mảng
    int x; cin>>x;
    if(timkiem_nhiphan(arr,n,x)){
        cout<<"Tìm thấy phần tử trong mảng";
    }
    else{
        cout<<"Không tìm thấy";
    }
    cout<<endl;
     int a=first(arr,n,x);
     int b=last(arr,n,x);
    cout<<"Vị trí xuất hiện đầu tiên của phần tử "<<x<<" "<<"trong mảng là:";
    cout<<a<<endl;
    cout<<"Vị trí xuất hiện cuối cùng của phần tử "<<x<<"là:";
    cout<<b;
    return 0;
}