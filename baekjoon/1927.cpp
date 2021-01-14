#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int main() {
	int n, i, j, tmp;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp == 0) {
			if (q.empty())
				printf("0\n");
			else {
				printf("%d\n", q.top());
				q.pop();
			}
		} 
		else {
			q.push(tmp);
		}
	}
	return 0;
}
