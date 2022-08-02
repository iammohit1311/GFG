int knapSack(int W, int wt[], int val[], int n) 
    { 
       int t[n + 1][W + 1]; // DP matrix

	     for (int i = 0; i < n+1; i++)
		     for (int j = 0; j < W+1; j++)
			     if (i == 0 || j == 0) // base case // filling 1st row and 1st column of the matrix with zero as per the base condition of the recursive solution 
				     t[i][j] = 0;
	
	     for(int i=1; i<n+1; i++)
	         for(int j=1; j<W+1; j++)
	             if (wt[i - 1] <= j) { // current wt can fit in bag // this is for the choice diagram of the recursive solution
				           t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], // take current wt // and after taking weight substract the inserted weight from the final weight 
                                   t[i - 1][j]); // skip current wt
			     }
			         else // current wt doesn't fit in bag
				         t[i][j] = t[i - 1][j]; // move to next

	    return t[n][W];
    }
