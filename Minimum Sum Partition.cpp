int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int range=0;
	    int mn=INT_MAX;
	    for(int i=0;i<n;i++)
	    {
	        range+=arr[i];
	        
	    }
	    bool dp[n+1][range+1];
	    for(int i=0;i<n+1;i++)
	    {
	        for(int j=0;j<range+1;j++)
	        {
	            if(i==0)
	            {
	                dp[i][j]=false;
	            }
	            if(j==0)
	            {
	                dp[i][j]=true;
	            }
	        }
	    }
	    for(int i=1;i<n+1;i++)
	    {
	        for(int j=1;j<range+1;j++)
	        {
	            if(arr[i-1]<=j)
	            {
	                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
	            }
	            else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    for(int i=range/2;i>=0;i--)
	    {
	        if(dp[n][i]==true)
	        {
	           // mn=min(mn,range-2*i);
	           mn=range-2*i;
	            break;
	        }
	    }
	    return mn;
	} 
