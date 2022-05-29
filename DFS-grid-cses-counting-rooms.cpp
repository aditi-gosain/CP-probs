//https://cses.fi/problemset/task/1192
//Flood fill algorithm

#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long int
#define ld long double
#define MOD 1000000007
#define MAX 100005
#define pb push_back
#define in_range(x, y, n, m) (x>=0 && x<n && y>=0 && y<m)
using namespace std;

vector <vector<char>> room;
vector <vector<bool>> visited;
vector <pair<int,int>> moves={{1,0},{-1,0},{0,1},{0,-1}};
int n, m;

bool isValid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    if(visited[i][j])
        return false;
    return true;
}

void dfs(int i, int j)
{
    visited[i][j]=1;
    for(auto p: moves)
    {
        if(isValid(i+p.first, j+p.second))
        {
            dfs(i+p.first,j+p.second);
        }
    }
}

int32_t main()
{
    int ans=0;
    cin>>n>>m;
    room.resize(n);
    visited.resize(n);

    for(int i=0; i<n; i++)
    {
        room[i].resize(m);
        visited[i].resize(m);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>room[i][j];
            visited[i][j]=0;
            if(room[i][j]=='#')
                visited[i][j]=1;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!visited[i][j])
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans;
}
