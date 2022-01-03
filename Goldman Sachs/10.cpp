#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>v;
  priority_queue<int>q;
  for(int i=0;i<n;i++){
    cin>>v[i];
    q.push(v[i]);
  }
  for(int i=0;i<10;i++){
    cout<<i+1<<" Maximun element is"<<q.top()<<endl;
    q.pop();
  }
}
