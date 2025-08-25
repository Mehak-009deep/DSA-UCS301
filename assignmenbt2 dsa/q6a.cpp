#include<iostream>
using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

int main(){
  int row, colm;
  cout<<"Enter number of rows : ";
  cin>>row;
  cout<<"Entr number of columns : ";
  cin>>colm;
  int size = 0;
  int arr[row][colm];
  for(int i=0; i<row ; i++){
    for(int j=0; j<colm; j++){
      cout<<"Enter element a"<<i+1<<j+1<<" : ";
      cin>>arr[i][j];
      if(arr[i][j] != 0){
        size++;
      }
    }
  }
  //creating sparse matrix 
  int sparse[size][3];
  int k = 0;
  for(int i=0; i<row ; i++){
    for(int j=0; j<colm; j++){
      if(arr[i][j] != 0){
        sparse[k][0] = i;
        sparse[k][1] = j;
        sparse[k][2] = arr[i][j];
        k++;
      }
    }
  }
  cout<<"Original sparse matrix : \n";
  for(int i=0; i<size; i++){
    cout<<sparse[i][0]<<" "<<sparse[i][1]<<" "<<sparse[i][2]<<endl;
  }
  //transpose sparse matrix 
  for(int i=0; i<size; i++){
    swap(sparse[i][0], sparse[i][1]);
  }
  //sorting row wise then  column wise 
  for(int i=0; i<size-1 ; i++){
    for(int j=0; j<size-i-1; j++){
      if(sparse[j][0] > sparse[j+1][0] || (sparse[j][0] == sparse[j+1][0] && sparse[j][1] > sparse[j+1][1])){
        swap(sparse[j][0], sparse[j+1][0]);
        swap(sparse[j][1], sparse[j+1][1]);
        swap(sparse[j][2], sparse[j+1][2]);
      }
    }
  }
  cout<<"Transpose of sparse matrix : \n";
  for(int i=0; i<size; i++){
    cout<<sparse[i][0]<<" "<<sparse[i][1]<<" "<<sparse[i][2]<<endl;
  }
  return 0;
}