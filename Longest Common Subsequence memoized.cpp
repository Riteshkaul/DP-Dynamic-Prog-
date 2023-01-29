int lcs(string &text1, string &text2,int m,int n,int dp[][1001])
    {
        if(m==0 || n==0)
        {
            return 0;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        if(text1[m-1] == text2[n-1])
        {
            return dp[m][n]= 1+lcs(text1,text2,m-1,n-1,dp);
        }
        else{
            return dp[m][n]=max(lcs(text1,text2,m,n-1,dp),lcs(text1,text2,m-1,n,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        int dp[1001][1001];
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<1001;j++)
            {
                dp[i][j]=-1;
            }
        }
        return lcs(text1,text2,m,n,dp);
    }
