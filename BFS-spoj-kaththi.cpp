//0-1 BFS is used.
//https://www.spoj.com/problems/KATHTHI/
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

char mat[1000][1000];
int dis[1000][1000];

deque<pair<int, int>> dq;
void bfs(int startX, int startY, int r, int c)
{
	dis[startX][startY] = 0;
	dq.push_front({startX, startY});
	while (!dq.empty())
	{
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();
		int a[] = {-1, 1, 0, 0}; //Used to move in all 4 directions
		int b[] = {0, 0, -1, 1}; //Used to move in all 4 directions
		for (int i = 0; i < 4; i++)
		{
			int tmpX = x + a[i];
			int tmpY = y + b[i];
			if (in_range(tmpX, tmpY, r, c))
			{
				if (mat[tmpX][tmpY] == mat[x][y] && dis[tmpX][tmpY] > dis[x][y]) //Weight = 0
				{
					dq.push_front({tmpX, tmpY}); //Pushed to front of queue since it is preferred
					dis[tmpX][tmpY] = dis[x][y];
				}
				else if (mat[tmpX][tmpY] != mat[x][y]) //Weight = 1
				{
					if (dis[tmpX][tmpY] > dis[x][y] + 1)
					{
						dq.push_back({tmpX, tmpY}); //Pushed to back of queue
						dis[tmpX][tmpY] = dis[x][y] + 1;
					}
				}
			}
		}
	}
}
int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int r, c;
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> mat[i][j];
				dis[i][j] = INT_MAX;
			}
		}
		bfs(0, 0, r, c);
		cout << dis[r - 1][c - 1] << endl;
	}
	return 0;
}
