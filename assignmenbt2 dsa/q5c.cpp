#include<iostream>
#include<vector>
using namespace std;
//lower triangular matrix
int main(){
  int row;
  cout<<"Enter number of rows/colms for lower triangular matrix :";
  cin>>row;
  vector<int> ans;
  cout<<"Enter lower triangular matrix elements row wise"<<endl;
  for(int i=0; i<row; i++){
    for(int j=0; j<=i; j++){
      int x;
      cin>>x;
      ans.push_back(x);
    }
  }
  cout<<"Lower triangular is : ";
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}