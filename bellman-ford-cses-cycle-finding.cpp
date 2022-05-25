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
#define MAX 1000000000
#define pb push_back
#define mp make_pair
using namespace std;

int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector <pair<int,pair<int,int>>> edges;
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        edges.pb({a,{b,c}});
    }
    int dp[n+1];
    int parent[n+1];
    for(int i=0; i<=n; i++)
        dp[i]=INT_MAX;
    dp[1]=0;
    int x;
    for(int i=1; i<=n; i++)
    {
        x=-1;
        for(auto e:edges)
        {
            int u = e.first;
            int v = e.second.first;
            int w = e.second.second;
            if(dp[u]+w<dp[v])
            {
                dp[v]=dp[u]+w;
                parent[v]=u;
                x=v;
            }
        }
    }
    if(x==-1)
        cout<<"NO";
    else
    {
        for(int i=1; i<=n; i++)
        {
            x=parent[x];
        }
        vector <int> ans;
        for(int node=x;; node=parent[node])
        {
            ans.pb(node);
            if(node==x&&ans.size()>1)
                break;
        }
        reverse(ans.begin(),ans.end());
        cout<<"YES"<<endl;
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
    }
}
