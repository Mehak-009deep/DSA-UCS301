#include<iostream>
using namespace std;

int recursiveBin(int arr[], int l, int h, int key){
  int mid = l + (h-l)/2;
  if(l>h)return -1;
  else if(key == arr[mid]){
    return mid;
  }
  else if(key < arr[mid]){
    return recursiveBin(arr,l,mid-1,key);
  }
  else{
    return recursiveBin(arr,mid+1,h,key);
  }
}

int main(){
  int n;
  cout<<"Enter number of elements : ";
  cin>>n;
  int arr[n];
  cout<<"Enter elements in sorted order : ";
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  int val;
  cout<<"Enter number you wanna search : ";
  cin>>val;
  int ans = recursiveBin(arr, 0, n-1, val);
  if(ans == -1){
    cout<<"Value not found ";
  }
  else{
    cout<<"Value found at index "<<ans;
  }
  return 0;
}