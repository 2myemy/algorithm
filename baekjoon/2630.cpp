#include <cstdio>
using namespace std;
const int MAX = 129;

int n;
int black = 0;
int white = 0;
int mat[MAX][MAX];

void calc(int size, int startX, int startY) {
	if (size == 1) {
		if (mat[startX][startY]) black++;
		else white++;
		return;
	}
	
	bool same = true;
	int target = mat[startX][startY];
	int i, j;
	
	for (i=startX; i<startX+size; i++){
		for (j=startY; j<startY+size; j++) {
			if (target != mat[i][j]) {
				same = false;
				break;
			}
		}
	}
	
	if (same) {
		if (target) black++;
		else white++;
	}
	else {
		calc(size/2, startX, startY);
		calc(size/2, startX + (size/2), startY);
		calc(size/2, startX, startY + (size/2));
		calc(size/2, startX + (size/2), startY + (size/2));
	}
}

int main() {
	int i, j;
	scanf("%d", &n);
	
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	calc(n, 0, 0);
	printf("%d\n%d", white, black);
	return 0;
}
