#include <iostream>
#include <vector>

using namespace std;

void coinchange( vector<int> coins, int w ) {
// coins should be sorted
        int n = coins.size();
        vector<vector<int>> dp( n, vector<int>( w+1 ) );

        for( int i = 0; i < n; i++ ) {
                dp[i][0] = 0;
        }

        for( int i = 1; i <= w; i++ ) {
                if( i < coins[0] ) { dp[0][i] = 1e9; } // not possible
                else dp[0][i] = 1 + dp[0][ i - coins[0] ];
        }

        for( int i = 1; i < n; i++ ) {
                for( int j = 1; j <= w; j++ ) {
                        if( j < coins[i] ) {
                                dp[i][j] = dp[i-1][j];
                        }
                        else {
                                dp[i][j] = min( dp[i-1][j], 1+dp[i][j - coins[i]] );
                        }
                }
        }

        for( int i = 0; i < n; i++ ) {
                for( int j = 0; j <= w; j++ )
                        cout << dp[i][j] << " ";
                cout << '\n';
        }

}

int main() {

        int w, n;
        cin >> w >> n;

        vector<int> coins(n);
        for( int i = 0; i < n; i++ ) cin >> coins[i];

        coinchange( coins, w );

        return 0;
}