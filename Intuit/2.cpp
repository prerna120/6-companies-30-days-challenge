#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

    bool dfs(int i,int j,vector<vector<char>>&board,int k,string &word){
        if(k==word.size())
            return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[i].size() || board[i][j]!=word[k])
            return false;
        board[i][j]='0';
        bool b=false;
        for(int t=0;t<4;t++){
            b=b||dfs(i+dx[t],j+dy[t],board,k+1,word);
        }
        board[i][j]=word[k];
        return b;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j] && dfs(i,j,board,0,word))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
