//Bipartite Graph

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
#define MAX 1000000
#define pb push_back
#define mp make_pair
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
 
vector<bool> vis;
vector <vector <int>> adj;
vector <int> teamNum;
 
bool dfs(int node, int currTeam)
{
    vis[node]=true;
    teamNum[node]=currTeam;
    for(auto child:adj[node])
    {
        if(teamNum[child]==teamNum[node])
            return false;
        if(!vis[child])
        {
            bool temp = dfs(child,3-currTeam);
            if(temp==false)
                return false;
        }
    }
    return true;
}
 
int32_t main()
{
    int n, m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    teamNum.resize(n+1);
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            bool tmp = dfs(i,1);
            if(tmp==false)
            {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int j=1; j<=n; j++)
        cout<<teamNum[j]<<" "; 
}
