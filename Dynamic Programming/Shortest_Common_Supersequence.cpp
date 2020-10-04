/*   Author - Anshul Pandey (https://github.com/Anshul275)   */

/* 
    Note - 
        LCS = Longest Common Subsequence
        SCS = Shortest Common Supersequence
*/

#include <bits/stdc++.h>
using namespace std;

//Function for printing the Shortest Common Supersequence
void print_SCS(string str1, string str2){
    int m = str1.length();
    int n = str2.length();
    
    int i,j; //Variables used for iteration
    
    /*
    Logic :
        Length of the SCS = (Sum of lengths of given two strings) - (Length of LCS of two given strings)
    */
    
    // LCS Code -
    int dp[m+1][n+1];
    //Initializing the matrix
    for(i=0; i<=m; i++)     dp[i][0]=0;
    for(j=0; j<=n; j++)     dp[0][j]=0;
    //Driver Code
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    //Length of SCS = (m + n) - dp[m][n]

    //SCS Code
    string s = "";
    i=m; j=n;
    while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
            s = str1[i-1] + s;
            i--;
            j--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j]){
                s = str2[j-1] + s;
                j--;
            }
            else{
                s = str1[i-1] + s;
                i--;
            }
        }
    }
    
    //If (either of i or j)!=0 then there must be some characters which must be added to the string
    while(i>0){
        s = str1[i-1] + s;
        i--;
    }
    while(j>0){
        s = str1[j-1] + s;
        j--;
    }
    
    cout<<"Shortest string that has both str1 and str2 as subsequences : "<<s;
}

int main(){
    //Input the strings  str1 & str2
    string str1,str2;
    cin>>str1>>str2;
    
    //Printing the shortest possible string
    print_SCS(str1, str2);
    return 0;
}

/*
SAMPLE INPUT - 
    acbcf
    abcdaf
SAMPLE OUTPUT - 
    Shortest string that has both str1 and str2 as subsequences : acbcdaf
*/