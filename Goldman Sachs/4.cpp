#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  char c=src[0];
  int count=1;
  string ans="";
  for(int i=1;i<src.size();i++){
        if(src[i]==c)
            count++;
        else{
            ans.push_back(c);
            ans.push_back((count+'0'));
            c=src[i];
            count=1;
        }
  }
  ans.push_back(c);
  ans.push_back((count+'0'));
  return ans;
}     
