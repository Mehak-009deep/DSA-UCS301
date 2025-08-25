#include<iostream>
using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void sortArray(vector<int> &arr, int n){
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-1-i; j++){
      if(arr[j]> arr[j+1]){
        swap(arr[j], arr[j+1]);
      }
    }
  }
}

void removeDuplicates(vector<int> &arr, int &n){
  int i = 0;
  while(i<n-1) {
    if (arr[i] == arr[i + 1]) {
      arr.erase(arr.begin()+i);
      n--;
    }
    i++;
  }
}

int main(){
  int n;
  cout<<"Enter number of elements in array : ";
  cin>>n;
  cout<<"Enter Array Elememnts : ";
  vector<int> arr;
  for(int i=0; i<n; i++){
    int x;
    cin>>x;
    arr.push_back(x);
  }
  sortArray(arr,n);
  removeDuplicates(arr,n);
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}