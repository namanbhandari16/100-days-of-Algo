#include <bits/stdc++.h> 
#define N 4 
#define M 6 
using namespace std; 
  
int findMaxPath(int mat[][M]) 
{ 
  
    for (int i = 1; i < N; i++) { 
        for (int j = 0; j < M; j++) { 
  
            if (j > 0 && j < M - 1) 
                mat[i][j] += max(mat[i - 1][j], 
                             max(mat[i - 1][j - 1],  
                             mat[i - 1][j + 1])); 
  
            else if (j > 0) 
                mat[i][j] += max(mat[i - 1][j], 
                            mat[i - 1][j - 1]); 
  
            else if (j < M - 1) 
                mat[i][j] += max(mat[i - 1][j], 
                            mat[i - 1][j + 1]); 
  
        } 
    } 
    int res = 0; 
    for (int j = 0; j < M; j++)  
        res = max(mat[N-1][j], res); 
    return res; 
} 
  
int main() 
{ 
      
    int mat1[N][M] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} };
              
    cout << findMaxPath(mat1) << endl; 
    return 0; 
} 