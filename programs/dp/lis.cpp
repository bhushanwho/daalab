#include<bits/stdc++.h> 
using namespace std; 

 
int lis( vector<int>& arr ) {
    int n = arr.size();
    vector<int> dp(n);
    dp[ n-1 ] = 1;

    for( int i = n-2; i >= 0; i-- ) {
        int max_num = 1;
        for( int j = i+1; j < n; j++ ) {
            if( arr[i] < arr[j] ) {
                max_num = max(max_num, 1+dp[j]);
            }
        }
        dp[i] = max_num;
    }

    for( int& i : dp ) {
        cout << i << " ";
    }
    cout << '\n';

    return dp[0];

}

int main() { 
 
    int t;
    cin >> t;

    while( t-- ) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for( int& i : arr ) { cin >> i; }
        lis(arr);
    }
    
    return 0; 
} 
