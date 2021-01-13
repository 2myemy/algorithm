#include <iostream>
using namespace std;

int n, m;
int cnt = 0;
int adj[101][101];
bool visited[101];

void DFS(int idx) {
	int i;
	for(i=1; i<=n; i++) {
		if (adj[idx][i] && !visited[i]) {
			visited[i] = 1;
			cnt++;
			DFS(i);
		}
	}
}

int main() {
	int i, a, b;
	cin >> n;
	cin >> m;
	for (i=0; i<m; i++) {
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	
	visited[1] = 1;
	DFS(1);
	cout << cnt;
	return 0;
}
