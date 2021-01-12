#include<iostream>
#include<string>
#include<queue>
using namespace std;

int n, m;
int mat[101][101];
int dist[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

void BFS(int a, int b) {
	int i;
	
    q.push(make_pair(a, b));
	dist[a][b]++;
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			else if (mat[nx][ny] == 1 && dist[nx][ny] == 0) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
		
	}
}

int main() {
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (j = 0; j < m; j++) mat[i][j] = str[j] - '0';
	}
	
	for (i = 0; i < n; i++) {
		for (j=0; j<m; j++) {
			dist[i][j] = 0;
		}
	}
	
	BFS(0,0);
	
	cout << dist[n-1][m-1];
	
	return 0;
}
