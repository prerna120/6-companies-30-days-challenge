/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool check(int i,int j,int l,vector<vector<int>>& g){
        int n=g[i][j];
        for(int a=i;a<i+l;a++){
            for(int b=j;b<j+l;b++){
                if(g[a][b]!=n)
                    return false;
            }
        }
        return true;
    }
    Node* construct(int i,int j,int l,vector<vector<int>>& grid){
        if(l==1 || check(i,j,l,grid))return new Node(grid[i][j],1);
            l/=2;
        return new Node(1,0,construct(i,j,l,grid),construct(i,j+l,l,grid),
                                    construct(i+l,j,l,grid),construct(i+l,j+l,l,grid));
        
    }
    Node* construct(vector<vector<int>>& grid) {
        int l=grid.size();
        return construct(0,0,l,grid);
    }
};
