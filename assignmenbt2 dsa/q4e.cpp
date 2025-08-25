#include<iostream>
using namespace std;

int main(){
  string s;
  cout<<"Enter a string : ";
  getline(cin, s);

  int n = s.length();
  for(int i=0; i<n; i++){
    if(s[i] >= 65 && s[i] <= 90){
      s[i] = s[i] + 32;
    }
  }

  cout<<"String after conversion : ";
  cout<<s;
  return 0;
}