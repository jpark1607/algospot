#include <iostream>
using namespace std;
#define MAXC 100

int triangle[MAXC][MAXC];
int cache[MAXC][MAXC];

int treeSum(int h, int w);

int main(void) {
	int C = 0, c = 0;
  int N = 0, nh = 0, nw = 0; /* nh: n-height, nw: n-weight */

	cin >> C;

	for (c = 0; c < C; c++) {
    cin >> N;

    /* input data until the N - 1 row comes */
    for (nh = 0; nh < N - 1; nh++) {
      for (nw = 0; nw <= nh; nw++) {
        cin >> triangle[nh][nw];
        cache[nh][nw] = 0; /* initalize while getting input triangle value */
      }
    }

    /* input data Nth row with caching */
    for (nw = 0; nw < N; nw++) {
      cin >> triangle[N - 1][nw];
      cache[N - 1][nw] = triangle[N - 1][nw];
    }

	  cout << treeSum(0, 0) << endl;
	}
	return 0;
}

int treeSum(int h, int w) {
  if (cache[h][w] > 0) 
    return cache[h][w];

  int part_sum = triangle[h][w] + max(treeSum(h + 1, w), treeSum(h + 1, w + 1));

  cache[h][w] = part_sum;

  return part_sum;
}
