#include<iostream>
#include<vector>
using namespace std;

void createMatrix(vector<vector<int>> &matrix, int row, int colm, char name){
  for(int i=0; i<row; i++){
    for(int j=0; j<colm; j++){
      cout<<"Enter element "<<name<<i+1<<j+1<<" : ";
      cin>>matrix[i][j];
    }
  }
}

void createSparse(vector<vector<int>> &matrix, int row, int colm , vector<vector<int>> &sparse){
  for(int i=0; i < row; i++){
    for(int j=0; j < colm; j++){
      if(matrix[i][j] != 0){
        sparse.push_back({i,j,matrix[i][j]});
      }
    }
  }
}

void productSparse(vector<vector<int>> &A, vector<vector<int>> &B, int rowA, int colmA, int rowB, int colmB,vector<vector<int>> &prod){
  if(colmA != rowB){
    cout<<"Matrices cant be multiplied ! ";
    return;
  }
  vector<vector<int>> temp(rowA, vector<int>(colmB,0));
  //multiply triplets 
  for(int i=0; i<A.size(); i++){
    for(int j=0; j < B.size(); j++){
      if(A[i][1] == B[j][0]){
        int r = A[i][0];
        int c = B[j][1];
        temp[r][c] += A[i][2]*B[j][2];
      }
    }
  }
  
  //convert to sparse 
  for(int i=0; i<rowA; i++){
    for(int j=0; j<colmB; j++){
      if(temp[i][j] != 0){
        prod.push_back({i,j,temp[i][j]});
      }
    }
  }
}

void displaySparse(vector<vector<int>> &sparse , int size , string name){
  cout<<"Sparse matrix "<<name<<" is"<<endl;
  for(int i=0; i<size; i++){
    cout<<sparse[i][0]<<"  "<<sparse[i][1]<<"  "<<sparse[i][2]<<endl;
  }
}


int main(){
  int rowA, colmA, rowB, colmB;
  cout<<"Enter number of rows in matrix A : ";
  cin>>rowA;
  cout<<"Enter number of colms in matrix A : ";
  cin>>colmA;
  vector<vector<int>> matrixA(rowA, vector<int>(colmA));
  createMatrix(matrixA, rowA, colmA, 'A');
  vector<vector<int>> sparseA;
  createSparse(matrixA, rowA, colmA, sparseA);

  cout<<"Enter number of rows in matrix B : ";
  cin>>rowB;
  cout<<"Enter number of colms in matrix B : ";
  cin>>colmB;
  vector<vector<int>> matrixB(rowB, vector<int>(colmB));
  createMatrix(matrixB, rowB, colmB, 'B');
  vector<vector<int>> sparseB;
  createSparse(matrixB, rowB, colmB, sparseB);

  vector<vector<int>> prod;

  productSparse(sparseA, sparseB, rowA, colmA, rowB, colmB,prod);
  displaySparse(prod, prod.size(), "product");
  return 0;
}