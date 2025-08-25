#include<iostream>
using namespace std;
//symmetric matrix
int main(){
  int n;
  cout<<"Enter number for rows for symmetric matrix : ";
  cin>>n;
  int arr[n][n];
  for(int i=0; i < n; i++){
    for(int j=0; j < n; j++){
      cout<<"Enter element a"<<i+1<<j+1<<" : ";
      cin>>arr[i][j];
    }
  }
  int size = n*(n+1)/2;
  int ans[size];
  int k = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
      ans[k] = arr[i][j];
      k++;
    }
  }
  cout << "Lower triangular elements rowwise of symmetric matrix : ";
  for(int i=0; i<size; i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}