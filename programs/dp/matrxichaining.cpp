#include<bits/stdc++.h> 
using namespace std; 

int matrixChaining( int n, vector<int> dims ) {

    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    for( int i = 0; i < n; i++ ) {
        dp[i][i] = 0;
    }


    for( int l = 1; l < n; l++ ) {
        for( int i = 0; i < n-l; i++ ) {
            int j = i + l;
            for( int k = i; k < j; k++ ) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i]*dims[k+1]*dims[j+1];
                dp[i][j] = min( dp[i][j], cost );
            }
        }
    }

    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            if( dp[i][j] == 1e9 ) cout << ' ' << '\t';
            else cout << dp[i][j] << '\t';
        }
        cout << '\n';
    }

    return dp[0][n-1];
    
}

int main() { 

    int n;
    cin >> n;

    vector<int> dims( n+1 );
    for( int& i : dims ) { cin >> i; }
    
    matrixChaining( n, dims );
    
    return 0; 
} 
