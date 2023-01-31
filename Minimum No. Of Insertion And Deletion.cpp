int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m=str1.length();
	    int n=str2.length();
	    int dp[m+1][n+1];
	    for(int i=0;i<=m;i++)
	    {
	        for(int j=0;j<=n;j++)
	        {
	            if(i==0 || j==0)
	            {
	                dp[i][j]=0;
	            }
	        }
	    }
	    for(int i=1;i<=m;i++)
	    {
	        for(int j=1;j<=n;j++)
	        {
	            if(str1[i-1]==str2[j-1])
	            {
	                dp[i][j]=1+dp[i-1][j-1];
	            }
	            else{
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    int a=m-dp[m][n];
	    int b=n-dp[m][n];
	    return a+b;
	} 
