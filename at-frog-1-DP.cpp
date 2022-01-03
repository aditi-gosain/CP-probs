/*Iterative solution*/
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

vector<int> h;
vector<int> dp;

int32_t main()
{
    int n;
    cin >> n;
    h.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i < n; i++)
    {
        int lastcost = dp[i - 1] + abs(h[i] - h[i - 1]);
        int lastlastcost = dp[i - 2] + abs(h[i] - h[i - 2]);
        dp[i] = min(lastcost, lastlastcost);
    }
    cout << dp[n - 1];
}
