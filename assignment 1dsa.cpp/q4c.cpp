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
  int trans[colm][row];
  //creating transpose
  for(int i = 0; i<colm; i++){
    for(int j=0; j<row; j++){
      trans[i][j] = matrix[j][i];
    }
  }  
  cout<<"Matrix : "<<endl;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < colm; j++) {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"Transpose :"<<endl;
  for(int i = 0; i < colm; i++) {
    for(int j = 0; j < row; j++) {
      cout << trans[i][j] << " ";
    }
    cout<<endl;
  }  
 return 0;
}