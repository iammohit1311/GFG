int countSubset(int arr[], int n, int sum)
	{
        int dp[n+1][sum+1];
        dp[0][0] = 1;
        
        for(int j=1; j<sum+1; j++) dp[0][j] = 0; // only 1st row init
        for(int i=1; i<n+1; i++)
        for(int j=0; j<sum+1; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            else dp[i][j] = dp[i-1][j];
        }
        return dp[n][sum];
	}
