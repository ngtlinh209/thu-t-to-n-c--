// Thuật toán sắp xếp trộn
#include <iostream>
using namespace std;
// Phần đầu tiên của thuật toán sắp xếp trộn ,có vai trò sắp xếp mảng giống như thuật toán hợp nhất hai mảng đã sắp xếp
void merge(int a[],int l, int m,int r){
    // ở đây m : là mid vị trí ở giữa mảng , l=0 vị trị đầu tiên trong mảng , r là vị trí cuối cùng trong mảng 
    // mảng b chứa r+1 phần tử tức là lấy vị trí cuối cùng +1 sẽ ra số phần tử trong mảng 
       int* b=new int[r+1]; 
       int i=l,j=m+1,k=l;
       while(i<=m && j<=r){  // từ l cho tới m được tính là mảng bên trái ,từ m+1 cho tới r được tính là mảng bên phải 
          if(a[i]<a[j]){
              b[k]=a[i];
              i++;
              k++; 
          }
          else{
            b[k]=a[j];
            j++;
            k++;
          }
       }
       while(i<=m){
          b[k]=a[i];
          i++;
          k++;
       }
       while(j<=r){
          b[k]=a[j];
          j++;
          k++;
       }
       for(int i=l;i<=r;i++){
         a[i]=b[i];
       }
}
// phần thứ hai thuật toán sắp xếp trộn ,có vai trò chia đôi mảng lớn thành các mảng nhỏ hơn 
void merge_sort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    int n; cin>>n;
    int*a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    merge_sort(a,0,n-1);
    for( int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}