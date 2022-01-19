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
const ld eps = 1e-6;
const int MAX = 1e6;

vector<int> h;
vector<int> dp;

int32_t main()
{
    int n, k;
    cin >> n >> k;
    h.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    { // i represents the stone the frog is currently at.
        for (int j = i + 1; j <= i + k; j++)
        {              // j represents a potential stone for the frog to jump to.
            if (j < n) // We have to check if the stone we want to jump to is not out of bounds.
                // Storing the total minimum cost to reach stone j from stone i.
                dp[j] = min(dp[j], dp[i] + abs(h[j] - h[i]));
        }
    }
    cout << dp[n - 1];
}
