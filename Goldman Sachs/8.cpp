#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int dp[10001],k=1e9+7;
	
	    int ways(string str){
	        int n=str.size();
	        if(n==0)
	            return 1;
	        if(str[0]==0)
	            return 0;
	        if(n==1)
	            return 1;
	        if(dp[n]!=-1)
	            return dp[n];
	        int temp=0;
	        if(str[n-1]!='0')
	        temp+=ways(str.substr(0,n-1));
	        if((str[n-2]=='1' ) || (str[n-2]=='2' && str[n-1]>='0' && str[n-1]<='6'))
	        temp+=ways(str.substr(0,n-2));
	        return dp[n]=temp%k;
	    }
	
		int CountWays(string str){
		    // Code here
		    if(str[0]=='0')
		        return 0;
		    memset(dp,-1,sizeof(dp));
		    dp[0]=1;
		  //  for(int i=1;i<str.size();i++){
		  //      if(str[i]!='0')
		  //          dp[i]+=dp[i-1];
		  //      if((str[i-1]=='1' ) || (str[i-1]=='2' && str[i]>='0' && str[i]<='6'))
		  //          dp[i]+=((i-2)>=0?dp[i-2]:1);
		  //      dp[i]%=k;
		  //  }
		  //  return dp[str.size()-1];
		  return ways(str);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
