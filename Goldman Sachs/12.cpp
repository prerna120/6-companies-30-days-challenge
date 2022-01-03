#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  long long int squares=0;
  for(int i=1;i<=n;i++){
    squares+=i*i;
  }
  cout<<squares;
}
