#include<iostream>
using namespace std;

int main(){
  int rowsA, colmsA;
  cout<<"Enter number of rows in matrix A : ";
  cin>>rowsA;
  cout<<"Enter number of colms in matrix A : ";
  cin>>colmsA;
  int matrixA[rowsA][colmsA];
  for(int i=0; i<rowsA; i++ ){
    for(int j=0; j<colmsA; j++){
      cout<<"Enter element a"<<i+1<<j+1<<": ";
      cin>>matrixA[i][j];
    }
  }

  int rowsB, colmsB;
  cout<<"Enter number of rows in matrix B : ";
  cin>>rowsB;
  cout<<"Enter number of colms in matrix B : ";
  cin>>colmsB;
  int matrixB[rowsB][colmsB];
  for(int i=0; i<rowsB; i++ ){
    for(int j=0; j<colmsB; j++){
      cout<<"Enter element b"<<i+1<<j+1<<": ";
      cin>>matrixB[i][j];
    }
  }

  if(rowsB != colmsA){
    cout<<"Matrix cant be multiplied";
    return 0;
  }

  int ans[rowsA][colmsB];
  for(int i=0; i<rowsA; i++){
    for(int j=0; j<colmsB; j++){
      ans[i][j] = 0;
    }
  }

  for(int i=0; i<rowsA; i++){
    for(int j=0; j<colmsB; j++){
      for(int k = 0; k <colmsA; k++){
        ans[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }


  cout << "Resultant Matrix after multiplication:\n";
  for(int i = 0; i < rowsA; i++) {
    for(int j = 0; j < colmsB; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}