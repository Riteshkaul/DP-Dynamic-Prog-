int solve(int arr[] , int i,int j,vector<vector<int>>&dp)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mn=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int tempans = solve(arr,i,k,dp) + solve(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
            mn=min(mn,tempans);
        }
        return dp[i][j]=mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(101,vector<int>(101,-1));
        int i=1 , j=N-1;
        return solve(arr,i,j,dp);
    }
