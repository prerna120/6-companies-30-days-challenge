class Solution {
public:
    
    bool isDivisible(string t,string s){
        int i=0,j=0;
        while(j<s.size()){
            if(t[i]!=s[j])
                return false;
            i=(i+1)%t.size(),j++;
        }
        return i==0;
    }
    
    string gcdOfStrings(string str1, string str2) {
        string smallest=str1;
        if(str1.size()>str2.size())
            smallest=str2;
        for(int i=smallest.size();i>0;i--){
            string gcd=smallest.substr(0,i);
            if(isDivisible(gcd,str1) && isDivisible(gcd,str2))
                return gcd;
        }
        return "";
    }
};
