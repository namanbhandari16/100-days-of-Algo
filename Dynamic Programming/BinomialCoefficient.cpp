// Problem Statement - Finding the Binomial Coefficient(nCr) through Dynamic Programming
// Eternal Link - https://en.wikipedia.org/wiki/Binomial_coefficient

#include<bits/stdc++.h>

using namespace std;

int binomialCoeff(int n, int k)
{
	int C[n+1][k+1];
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= min(i, k); j++)
			if (j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = C[i-1][j-1] + C[i-1][j];
	
	return C[n][k];
}

int main()
{
	int n, k;
	cin>>n>>k;
	printf ("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k) );
	return 0;
}
