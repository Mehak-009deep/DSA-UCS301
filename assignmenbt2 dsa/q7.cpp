#include<iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter number of elemnts in array : ";
  cin>>n;
  int arr[n];
  cout<<"Enter array elements : ";
  for(int i=0; i<n ; i++){
    cin>>arr[i];
  }
  int cnt = 0;
  //counting inverse pairs 
  for(int i=0; i<n-1; i++){
    for(int j = i+1; j<n; j++){
      if(arr[i] > arr[j]){
        cnt ++;
      }
    }
  }
  cout<<"Number of inversion pairs are "<<cnt;
  return 0;
}