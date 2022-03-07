//https://codeforces.com/contest/1648/problem/A


#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long int
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
const int MAX = 1e6;

int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        vector<vector<int>> row(100001), column(100001);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                row[arr[i][j]].pb(i);
                column[arr[i][j]].pb(j);
            }
        }
        
        int ans = 0;
        for (int i = 1; i < 100001; i++)
        {
            sort(row[i].begin(), row[i].end());
            sort(column[i].begin(), column[i].end());

            for (int j = 0; j < row[i].size(); j++)
            {
                ans += ((2 * j + 1 - row[i].size()) * row[i][j]);
            }
            for (int j = 0; j < column[i].size(); j++)
            {
                ans += ((2 * j + 1 - column[i].size()) * column[i][j]);
            }
        }
        cout << ans;
    }
}
