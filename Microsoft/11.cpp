#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.

bool static comp(string a,string b){
    if(a.size()==b.size()){
        int i=0;
        while(i<a.size()){
            if(a[i]<b[i])
                return true;
            else if(a[i]>b[i])
                return false;
            i++;
        }
        return true;
    }
    return a.size()<b.size();
}

void solve(string &s,int N,vector<string>&ans,int value){
    if(value>N)
        return;
    ans.push_back(s);
    value<<=1;
    s.push_back('0');
    solve(s,N,ans,value);
    s.pop_back();
    s.push_back('1');
    value+=1;
    solve(s,N,ans,value);
    s.pop_back();
}

vector<string> generate(int N)
{
	// Your code here
	vector<string>ans;
	string s="";
	s.push_back('1');
	solve(s,N,ans,1);
	sort(ans.begin(),ans.end(),comp);
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
