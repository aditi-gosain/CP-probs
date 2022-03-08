//https://www.youtube.com/watch?v=_RtghJnM1Qo

//Nearest Smaller Element on Left

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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        stack<int> s;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && s.top() > a[i])
            {
                s.pop();
            }
            if (!s.empty() && a[i] > s.top())
                cout << s.top() << " ";
            else
                cout << -1 << " ";
            s.push(a[i]);
        }
    }
}

//Nearest Greater Element on Left

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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        stack<int> s;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && a[i] > s.top())
                s.pop();
            if (!s.empty() && s.top() > a[i])
                cout << s.top() << " ";
            else
                cout << -1 << " ";
            s.push(a[i]);
        }
    }
}


//Nearest Smaller Element on Right

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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() > a[i])
                s.pop();
            if (!s.empty() && a[i] > s.top())
                ans[i] = s.top();
            else
                ans[i] = -1;
            s.push(a[i]);
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
    }
}

//Nearest Greater Element on Right
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() < a[i])
                s.pop();
            if (!s.empty() && a[i] < s.top())
                ans[i] = s.top();
            else
                ans[i] = -1;
            s.push(a[i]);
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
    }
}




