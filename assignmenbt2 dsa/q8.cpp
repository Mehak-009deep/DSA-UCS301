#include<iostream>
#include<set>
using namespace std;

int main(){
  int n;
  cout<<"Enter the length of array : ";
  cin>>n;
  int arr[n];
  cout<<"Enter array elements \n";
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  //counting elements 
  set<int> s;
  for(int i=0; i<n; i++){
    s.insert(arr[i]);
  }
  cout<<"Number of unique elements are "<<s.size();
  return 0;
}