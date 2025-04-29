#include <iostream>
#include <vector>

using namespace std;

void backtrack( int m, int n, int k, vector<int>& set, int sum,
								 vector<int>& sol, vector<vector<int>>& res ) {

        if( k == set.size() || m > sum || n == 0 ) { return; }
        if( m == sum ) {
                res.push_back( sol );
                return;
        }

        sol[k] = 1;
        backtrack( m+set[k], n-set[k], k+1, set, sum, sol, res );

        sol[k] = 0;
        backtrack( m, n-set[k], k+1, set, sum, sol, res );

}

vector<vector<int>> subsetSum( vector<int>& set, int sum ) {
        int initSum = 0;
        for( int& i : set ) initSum += i;

        vector<vector<int>> res;
        vector<int> sol(set.size());

        backtrack( 0, initSum, 0, set, sum, sol, res );
        return res;
}

int main() {
        int n, sum;
        cin >> n >> sum;
        vector<int> set(n);

        for( int& i : set ) { cin >> i; }

        for( auto& sol : subsetSum( set, sum ) ) {
                cout << "[ ";
                for( int i = 0; i < sol.size(); i++ ) { if( sol[i] ) cout << set[i] << ' '; }
                cout << "]\n";
        }
}      