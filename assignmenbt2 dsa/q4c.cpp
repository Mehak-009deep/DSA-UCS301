#include<iostream>
using namespace std;

int main(){
  string s;
  cout<<"Enter a string : ";
  getline(cin, s);

  int n = s.length();
  for(int i=0; i<n; i++){
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
      s.erase(i,1);
      n--;
    }
  }

  cout<<"String after removing the vowel :\n";
  cout<<s;
  return 0;
}