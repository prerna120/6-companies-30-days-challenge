#include <bits/stdc++.h>
using namespace std;

int val(string s,int &i){
    int c=0;
    while(i<s.size() && s[i]>='0' && s[i]<='9'){
        c=c*10+s[i++]-'0';
    }
    i++;
    return c;
}

bool greater_version(string s1,int i,string s2,int j){
    int n=s1.size(),m=s2.size();
    if(i>=n)
        return false;
    if(j>=m)
        return true;
    int c1=val(s1,i),c2=val(s2,j);
    if(c1>c2)
        return true;
    if(c1<c2)
        return false;
    return greater_version(s1,i,s2,j);
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    if(greater_version(s1,0,s2,0))
        cout<<s1;
    else
        cout<<s2;
}
