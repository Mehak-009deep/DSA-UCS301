#include<iostream>
using namespace std;
//tridiagonal matrix
int main(){
  int n;
  cout<<"Enter number for rows for square matrix : ";
  cin>>n;
  int arr[n][n];
  for(int i=0; i < n; i++){
    for(int j=0; j < n; j++){
      cout<<"Enter element a"<<i+1<<j+1<<" : ";
      cin>>arr[i][j];
    }
  }
  int ans[3*n-2];
  int k = 0;
  for(int i=0; i<n ; i++){
    for(int j=0; j<n ; j++){
      if(i == j || i == j+1 || i == j-1){
        ans[k] = arr[i][j];
        k++;
      }
    }
  }
  cout<<"Tridaigonal elements row wise : "<<endl;
  for(int i=0; i < 3*n - 2; i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}