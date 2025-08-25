#include<iostream>
using namespace std;

int main(){
  int row, colm;
  cout<<"Enter number of rows in matrix : ";
  cin>>row;
  cout<<"Enter number of colms in matrix : ";
  cin>>colm;
  int matrix[row][colm];
  for(int i=0; i<row; i++ ){
    for(int j=0; j<colm; j++){
      cout<<"Enter element a"<<i+1<<j+1<<": ";
      cin>>matrix[i][j];
    }
  }

  cout<<"Matrix : "<<endl;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < colm; j++) {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }

  int sum = 0;
  //summing the rows
  for(int i=0; i<row; i++){
    for(int j=0; j<colm; j++){
      sum += matrix[i][j];
    }
    cout<<"Sum of row "<<i+1<<" :"<<sum<<endl;
    sum = 0;
  }
  //summing the columns
  for(int i=0; i<colm; i++){
    for(int j=0; j<row; j++){
      sum += matrix[j][i];
    }
    cout<<"Sum of colm "<<i+1<<" :"<<sum<<endl;
    sum = 0;
  }
  return 0;
}