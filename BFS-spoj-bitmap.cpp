//Multisource BFS
//https://www.spoj.com/problems/BITMAP/

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
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

using namespace std;

queue<pair<int, int>> mq;
void bfs(char mat[182][182], int dis[182][182], int x, int y, int r, int c)
{
	int i, j, a, b;
	dis[x][y] = 0; // (x,y) are coordinates of source node; distance for source node = 0;
	mq.push({x, y});
	while (!mq.empty())
	{
		i = mq.front().first;
		j = mq.front().second;
		mq.pop();
		int aa[] = {-1, 1, 0, 0};
		int bb[] = {0, 0, -1, 1};
		for (int k = 0; k < 4; k++)
		{
			a = i + aa[k]; // To move in all 4 directions
			b = j + bb[k]; // To move in all 4 directions
			if (in_range(a, b, r, c) && dis[a][b] > dis[i][j] + 1 && mat[a][b] == '0')
			{
				mq.push({a, b});
				dis[a][b] = dis[i][j] + 1;
			}
		}
	}
}
int32_t main()
{
	char mat[182][182], ch;
	int t, r, c, dis[182][182];
	cin >> t;
	while (t--)
	{
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> mat[i][j];
				dis[i][j] = INT_MAX;
			}
			// cin >> ch;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (mat[i][j] == '1')
					bfs(mat, dis, i, j, r, c);
			}
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				printf("%d ", dis[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
