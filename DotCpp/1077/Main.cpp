#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

const int MAXN = 33;

struct Node {
	int a[MAXN], len;
	void clear() {
		len = 0;
	}
	void print() {
		//cout<<len<<endl;
		for(int i = 0; i < len; ++i) printf("%d", a[i]);
		printf("\n");
	}
	bool operator < (const Node &rhs) const {
		if(len != rhs.len) return len < rhs.len;
		for(int i = 0; i < len; ++i)
			if(a[i] != rhs.a[i]) return a[i] < rhs.a[i];
		return false;
	}
};

int fx[] = {1, 0, -1, 0};
int fy[] = {0, 1, 0, -1};

Node ans, now, tmp;
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool vis2[MAXN][MAXN];
int n, m;
int can[MAXN];

int maxlen(int x, int y) {
	queue<int> que; que.push(x * MAXN + y);
	int ret = 1;
	can[0] = mat[x][y] - '0';
	memset(vis2, 0, sizeof(vis2));
	vis2[x][y] = 1;
	while(!que.empty()) {
		int tmp = que.front(); que.pop();
		int nx = tmp / MAXN, ny = tmp % MAXN;
		for(int i = 0; i < 4; ++i) {
			int px = nx + fx[i], py = ny + fy[i];
			if(!isdigit(mat[px][py]) || vis[px][py] || vis2[px][py]) continue;
			vis2[px][py] = true;
			can[ret++] = mat[px][py] - '0';
			que.push(px * MAXN + py);
		}
	}
	return ret;
}

void dfs(int x, int y) {
	now.a[now.len++] = mat[x][y] - '0';
	vis[x][y] = true;
	for(int i = 0; i < 4; ++i) {
		int px = x + fx[i], py = y + fy[i];
		if(!isdigit(mat[px][py]) || vis[px][py]) continue;
		int wantlen = maxlen(px, py);
		if(now.len + wantlen < ans.len) continue;
		if(now.len + wantlen == ans.len) {
			sort(can, can + wantlen);
			tmp = now;
			for(int i = wantlen - 1; i >= 0; --i) tmp.a[tmp.len++] = can[i];
			if(tmp < ans) continue;
		}
		dfs(px, py);
	}
	if(ans < now) ans = now;
	--now.len;
	vis[x][y] = false;
}

int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n + m == 0) break;
		memset(mat, 0, sizeof(mat));
		for(int i = 1; i <= n; ++i) scanf("%s", &mat[i][1]);
		ans.clear(); now.clear();
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j)
				if(isdigit(mat[i][j])) dfs(i, j);
		}
		ans.print();
	}
}