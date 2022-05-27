//BFS on a grid + tracing path

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

char mp[1005][1005];
int dis[1005][1005];


vector <vector<pair<int,int>>> path; //for storing parent of each cell

bool bfs(int n, int m, pair<int, int> start, pair<int, int> finish)
{
    queue <pair<int, int>> q;
    q.push(start);
    bool f=0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int l1[]={1, -1, 0, 0};
        int l2[]={0, 0, 1, -1};
        for(int i=0; i<4; i++)
        {
            int a = x+l1[i];
            int b = y+l2[i];
            if(in_range(a, b, n, m) && mp[a][b]!='#' && dis[a][b]>dis[x][y]+1)
            {
                dis[a][b]=dis[x][y]+1;
                q.push({a,b});
                path[a][b]={x,y};
            }
            if(a==finish.first && b==finish.second)
            {
                f=1;
            }
        }
    }
    return f;
}

int32_t main()
{
    int n, m;
    cin>>n>>m;
    path.resize(n);
	for(int i = 0; i < n; ++i)
	{
		path[i].resize(m);
	}
    pair<int,int> start;
    pair<int,int> finish;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>mp[i][j];
            dis[i][j]=INT_MAX;
            path[i][j]={-1,-1};
            if(mp[i][j]=='A')
            {
                start={i,j};
                dis[i][j]=0;
            }
            if(mp[i][j]=='B')
                finish={i,j};
        }
    }

    bool tmp = bfs(n, m, start, finish);
    if(tmp)
    {
        cout<<"YES"<<endl;
        cout<<dis[finish.first][finish.second]<<endl;
        vector<pair<int,int>> ans;
        pair<int,int> p = finish;
        while(p.first != start.first or p.second != start.second)
        {
            int tmpX = p.first-path[p.first][p.second].first;
            int tmpY = p.second-path[p.first][p.second].second;
            ans.pb({tmpX,tmpY});
            p=path[p.first][p.second];
        }
        reverse(ans.begin(), ans.end());
	for(auto c: ans)
	{
		if(c.first == 1 and c.second ==0)
		{
			cout << 'D';
		}
		else if(c.first == -1 and c.second ==0)
		{
			cout << 'U';
		}
		else if(c.first == 0 and c.second == 1)
		{
			cout << 'R';
		}
		else if(c.first == 0 and c.second == -1)
		{
			cout << 'L';
		}
	}
    }
    else
    {
        cout<<"NO";
    }
}

