#include <iostream>
using namespace std;
char mat[3000][3000];

void star(int n, int x, int y) {
  if ((x/n) % 3 == 1 && (y/n) % 3 == 1) {
    cout << ' ';
  } else {
    if (n/3 == 0) {
    cout << '*';
    } else {
      star(n/3, x, y);
    } 
  }

}

int main() {
  int n, i, j;
  cin >> n;
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      star(n, i, j);
    }
    cout << '\n';
  }

  return 0;
}
