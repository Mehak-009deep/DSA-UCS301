#include<iostream>
using namespace std;

int main(){
  string s;
  cout<<"Enter a string : ";
  getline(cin, s);
  int n = s.length();
  for(int i = 0; i<n; i++){
    for(int j=0; j<n-i-1; j++){
      if(s[j] > s[j+1]){
        swap(s[j],s[j+1]);
      }
    }
  }
  cout<<"Sorted string is : "<<endl<<s;
  return 0;
}