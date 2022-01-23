const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/

bool find_missing(int i,string s,int prev,int &missing){
    int n=s.size();
    if(i==n)
        return missing!=-1;
    int nxt=prev+1;
    string next=to_string(nxt),nxt_next=to_string(nxt+1);
    int l=next.size(),nl=nxt_next.size();
    if(s.substr(i,l)==next)
        return find_missing(i+l,s,nxt,missing);
    if(s.substr(i,nl)==nxt_next && missing==-1){
        missing=nxt;
        return find_missing(i+nl,s,nxt+1,missing);
    }
    return false;
}
int missingNumber(const string& str)
{
    // Code here
    int n=str.size();
    for(int l=1;l<=min(6,n/2);l++){
        int prev=stoi(str.substr(0,l));
        int missing=-1;
        if(find_missing(l,str,prev,missing) && missing!=-1)
            return missing;
    }
    return -1;
}
