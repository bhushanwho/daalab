#include<bits/stdc++.h> 
using namespace std; 

void backtrack( int row, int n, vector<int>& cols, vector<int>& diag1, 
                vector<int>& diag2, vector<vector<int>>& res, vector<int>& sol ) {

    if( row == n ) {
        res.push_back( sol );
        return;
    }

    for( int col = 0; col < n; col++ ) {
        if( cols[col] || diag1[row - col + n - 1] || diag2[row + col] ) continue;

        cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 1;
        sol[row] = col;

        backtrack( row + 1, n, cols, diag1, diag2, res, sol );

        cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 0;
    }
}

void nQueens( int n ) {
    vector<vector<int>> res;
    vector<int> sol(n);
    vector<int> cols(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);

    backtrack( 0, n, cols, diag1, diag2, res, sol );

    for( auto& x : res ) {
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < n; j++ ) {
                cout << (x[i] == j ? "Q " : ". ");
            }
            cout << '\n';
        }
        cout << '\n';
    }
}

int main() { 
    int n;
    cin >> n;

    nQueens( n );
 
    return 0; 
} 