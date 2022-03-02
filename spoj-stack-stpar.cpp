#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long int
#define ld long double
#define rem 1000000007
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
const int MAX = 1e6;

//https://www.spoj.com/problems/STPAR/

string solve(int n)
{
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> s;
    int c = 1;
    string ans = "yes";
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && c == s.top())
        {
            s.pop();
            c++;
        }
        if (a[i] == c)
            c++;
        else if (!s.empty() && a[i] > s.top())
        {
            ans = "no";
            break;
        }
        else
        {
            s.push(a[i]);
        }
    }
    return ans;
}

int32_t main()
{
    fastio;
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << solve(n) << "\n";
    }
}
