#include<iostream>
#include<string>
using namespace std;

int main(){
  string s1, s2;
  cout<<"Enter string 1"<<endl;
  getline(cin, s1);
  cout<<"Enter string 2"<<endl;
  getline(cin , s2);
  cout<<"Concatenated strings : "<<endl;
  string result = s1 + " " + s2;
  cout<<result;
  return 0;
}