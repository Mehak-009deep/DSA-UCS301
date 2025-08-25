#include <iostream>
#include<vector>
using namespace std;

void createArr(vector<int> &arr, int &n){
  arr.clear();
  cout<<"Enter size of arr : ";
  cin>>n;
  int element;
  for(int i = 0 ; i<n; i++){
    cout<<"Enter element "<<i+1<<" : ";
    cin>>element;
    arr.push_back(element);
  }
}

void display(vector<int> &arr, int n){
  if(n == 0){
    cout<<"Array is empty!"<<endl;
    return;
  }
  cout<<"Array is : ";
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void insert(vector<int> &arr, int &n){
  int pos, val;
  cout<<"Enter position : ";
  cin>>pos;
  cout<<"Enter value you wanna insert :";
  cin>>val;
  arr.insert(arr.begin() + pos - 1, val);
  n++;
}

void deleteElement(vector<int> &arr, int & n){
  int pos;
  cout<<"Enter position you wanna delete element : ";
  cin>>pos;
  if(pos > n || pos < 0 ){
    cout<<"This cant be deleted ";
    return;
  }
  arr.erase(arr.begin() + pos - 1);
  n--;
}

void linearSearch(vector<int> arr, int n){
  int val;
  cout<<"Enter value you wanna search :";
  cin>>val;
  for(int i=0; i<n; i++){
    if(arr[i] == val){
      cout<<"Value is found at index "<<i;
      break;
    }
    if(i==n-1 && arr[i] != val){
      cout<<"Value not found !";
    }
  }
}



int main(){
  vector<int> arr;
  int n = 0;
  int choice;

  do{
    cout<<"Menu"<<endl;
    cout<<"1. Create"<<endl;
    cout<<"2. Display"<<endl;
    cout<<"3. Insert"<<endl;
    cout<<"4. Delete"<<endl;
    cout<<"5. Linear Search"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"Enter choice"<<endl;
    cin>>choice;
    switch(choice){
      case 1 : createArr(arr, n);
      break;
      case 2 : display(arr,n);
      break;
      case 3 : insert(arr,n);
      break;
      case 4 : deleteElement(arr, n);
      break;
      case 5 : linearSearch(arr, n);
      break;
      case 6 : cout<<"Exiting the menu driven programme";
      break;
      default : cout<<"Invalid Choice";
      break;
    }
  }
  while(choice != 6);
  return 0;
}