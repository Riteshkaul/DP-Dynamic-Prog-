int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0)
                {
                    dp[i][j]=INT_MAX-1;
                }
                if(j==0)
                {
                    dp[i][j]=0;
                }
                if(i==1)
                {
                    if(j%coins[i-1]==0)
                    {
                        dp[i][j]=j/coins[i-1];
                    }
                    else{
                        dp[i][j]=INT_MAX-1;
                    }
                }
            }
        }
        // dp[0][0]=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                }
                else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[n][amount]==INT_MAX-1)
        {
            return -1;
        }
        else{
            return dp[n][amount];
        }
    }
