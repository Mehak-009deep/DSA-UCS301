#include<iostream>
using namespace std;


int missingNumber(int arr[], int n) {
  int l = 0, h = n - 1;
  int diff = arr[0] - 0;
  while (l <= h) {
    int mid = l + (h - l) / 2;
    if (arr[mid] - mid != diff) {
      if (mid > 0 && arr[mid - 1] - (mid - 1) == diff){
        return mid + diff;
      }
      h = mid - 1;
    }
    else {
      l = mid + 1;
    }
    }
  return -1;
}

int main(){
  int arr[] = {10, 11, 12, 13, 15, 16};
  int n = sizeof(arr)/sizeof(arr[0]);
  int mis = missingNumber(arr,n);
  cout<<"Missing Number is "<<mis<<endl;
  return 0;
}