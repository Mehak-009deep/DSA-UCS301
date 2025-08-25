#include<iostream>
using namespace std;

int main(){
  int arr[] = {8,7,2,6,4,5,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  //Reversing the array 
  for(int i=0; i<n/2; i++){
    int temp = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = temp;
  }
  cout<<"Reversed Array is : ";
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}