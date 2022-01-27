

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    void swaps(int i,string &ans,int k,string &s){
        int n=s.size();
        if(k==0 || i==n){
            bool b=false;
            for(int i=0;i<n;i++){
                if(ans[i]<s[i]){
                    b=true;
                    break;
                }
                else if(ans[i]>s[i])
                    break;
            }
            if(b)
                ans=s;
            return;
        }
        for(int j=n-1;j>i;j--){
            if(s[i]>=s[j])
                continue;
            char c=s[i];
            s[i]=s[j];
            s[j]=c;
            k--;
            // cout<<s<<endl;
            swaps(i+1,ans,k,s);
            c=s[i];
            s[i]=s[j];
            s[j]=c;
            k++;
            // cout<<s<<endl;
        }
        swaps(i+1,ans,k,s);
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
        string ans=str;
        swaps(0,ans,k,str);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
