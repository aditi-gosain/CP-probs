//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/jump-k-forward-250d464b/

#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long int
#define ld long double
#define rem 1000000007
#define fi first
#define se second
#define MAX 1000000000
#define pb push_back
#define mp make_pair
using namespace std;
const ld eps = 1e-6;

vector<int> dp;

int32_t main()
{
    int n, k;
    cin >> n >> k;
    dp.resize(n);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if ((i - j) >= 0)
            {
                dp[i] += dp[i - j];
                dp[i] %= rem;
                // cout << "i: " << i << " j: " << j << " dp[j]: " << dp[j] << "\n";
            }
        }
    }
    cout << dp[n - 1];
}
