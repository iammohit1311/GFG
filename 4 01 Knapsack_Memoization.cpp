const int D = 1000; // DP - matrix dimension

int t[D][D]; // DP matrix

int Knapsack(int wt[], int val[], int W, int n) {
	// base case
	if (n == 0 || W == 0)
		return 0;
  
  // Check before recursion
	if (t[n][W] != -1)
		return t[n][W];
  
	// else calculate
	else {
		if (wt[n - 1] <= W)
			return t[n][W] = max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1),Knapsack(wt, val, W, n - 1));
		else if (wt[n - 1] > W)
			return t[n][W] = Knapsack(wt, val, W, n - 1);

	}
}
