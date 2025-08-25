#include<iostream>
using namespace std;

int main(){
  int row;
  cout<<"Enter number of rows/colms for daigonal matrix :";
  cin>>row;
  vector<vector<int>> matrix(row, vector<int> (row));
  vector<int> ans;
  cout<<"Enter matrix elements "<<endl;
  for(int i=0; i<row; i++){
    for(int j=0; j<row; j++){
      cin>>matrix[i][j];
    }
  }
  for(int i=0; i<row; i++){
    ans.push_back(matrix[i][i]);
  }
  cout<<"Daigonal is : ";
  for(int i=0; i<row; i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}