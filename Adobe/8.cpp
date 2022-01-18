 #include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        /*You are required to complete this method */
    int atoi(string str)
    {
        int power=str.size()-1,ans=0,flag=0;
        for(int i=0;i<str.size();i++){
            if((str[i]<'0' || str[i]>'9') && str[i]!='-' )
                return -1;
            if(str[i]=='-')
                flag=1;
            else
                ans+=(str[i]-'0')*pow(10,power);
            power--;
        }
        if(flag==1)
            return -ans;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
