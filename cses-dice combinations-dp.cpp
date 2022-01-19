//https://cses.fi/problemset/task/1633/
#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long int
#define ld long double
#define mod 1000000007
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
const ld eps = 1e-6;
const int MAX = 1e6;

vector<int> dp;

int32_t main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) //number to be summed
    {
        for (int j = 1; j <= 6 && i - j >= 0; j++) //number on dice
        {
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }
    cout << dp[n] << endl;
}
