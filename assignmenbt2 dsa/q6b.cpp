#include<iostream>
#include<vector>
using namespace std;

void createMatrix(vector<vector<int>> &matrix, int row, int colm, char name, int &size){
  for(int i=0; i<row; i++){
    for(int j=0; j<colm; j++){
      cout<<"Enter element "<<name<<i+1<<j+1<<" : ";
      cin>>matrix[i][j];
      if(matrix[i][j] != 0){
        size++;
      }
    }
  }
}

void createSparse(vector<vector<int>> &matrix, int row, int colm , vector<vector<int>> &sparse){
  int k = 0;
  for(int i=0; i < row; i++){
    for(int j=0; j < colm; j++){
      if(matrix[i][j] != 0){
        sparse[k][0] = i;
        sparse[k][1] = j;
        sparse[k][2] = matrix[i][j];
        k++;
      }
    }
  }
}

void displaySparse(vector<vector<int>> sparse , int size , char name){
  cout<<"Sparse matrix"<<name<<"is"<<endl;
  for(int i=0; i<size; i++){
    cout<<sparse[i][0]<<"  "<<sparse[i][1]<<"  "<<sparse[i][2]<<endl;
  }
}

void addSparse(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> &sum, int sizeA, int sizeB){
  int i = 0, j = 0;
  //comparing 
  while(i < sizeA && j < sizeB){
    if(A[i][0] == B[j][0] && A[i][1] == B[j][1]){
      int add = A[i][2] + B[j][2];
      if(add != 0){
        sum.push_back({A[i][0], A[i][1], add});
      }
      i++;
      j++;
    }
    else if(A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])){
      sum.push_back(A[i]);
      i++;
    }
    else {
      sum.push_back(B[j]);
      j++;
    }
  }
  //remaining 
  while(i < sizeA){
    sum.push_back(A[i]);
    i++;
  }
  while(j < sizeB){
    sum.push_back(B[j]);
    j++;
  }
}

int main(){
  int row, colm;
  cout<<"Enter number of rows : ";
  cin>>row;
  cout<<"Entr number of columns : ";
  cin>>colm;
  int sizeA = 0, sizeB = 0;

  vector<vector<int>> matrixA(row, vector<int>(colm));
  vector<vector<int>> matrixB(row, vector<int>(colm));
  createMatrix(matrixA, row, colm, 'A', sizeA);
  createMatrix(matrixB, row, colm, 'B', sizeB);
  
  vector<vector<int>> sparseA(sizeA, vector<int>(3));
  vector<vector<int>> sparseB(sizeB, vector<int>(3));
  createSparse(matrixA, row, colm, sparseA);
  createSparse(matrixB, row, colm, sparseB);

  displaySparse(sparseA, sizeA, 'A');
  displaySparse(sparseB, sizeB, 'B');

  vector<vector<int>> sum;
  addSparse(sparseA, sparseB, sum, sizeA, sizeB);
  displaySparse(sum, sum.size(),'sum');
 return 0;
}