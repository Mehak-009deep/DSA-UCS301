#include<iostream>
#include<vector>
using namespace std;
//upper triangular matrix
int main(){
  int row;
  cout<<"Enter number of rows/colms for upper triangular matrix :";
  cin>>row;
  vector<int> ans;
  cout<<"Enter upper triangular matrix elements row wise"<<endl;
  for(int i=0; i<row; i++){
    for(int j=i; j<row; j++){
      int x;
      cin>>x;
      ans.push_back(x);
    }
  }
  cout<<"Upper triangular is : ";
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}