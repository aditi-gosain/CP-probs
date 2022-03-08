//https://cses.fi/problemset/task/1634/
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
#define pb push_back
#define mp make_pair
using namespace std;
const int MAX = 1e6;

int32_t main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    vector<int> dp(x + 1, 1e9);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    dp[0] = 0;
    for (int i = 1; i <= x; i++) //dp
    {
        for (int j = 0; j < n; j++) //array
        {
            if (i - coins[j] >= 0)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << endl;
}
