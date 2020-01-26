#include <iostream>
using namespace std;




int main(void) {
  int C = 0, c = 0; // # of testcase, max 50
  int N = 0, n = 0; // # of students, max 10
  int M = 0, m = 0; // # of friend pairs, max n * (n - 1) / 2
  int f1 = 0, f2 = 0; // # for friend pair idx
  bool friendPair[10][10] = {{0, }, };
  int i, j;


  /* Get # of testcases */
  cin >> C;

  for (c = 0; c < C; c++) {
    /* Get # of students and # of friend pairs */
    cin >> N >> M;

    for (m = 0; m < M; m++) {
      /* Get index of friend pair and set flag on friendPair[][] */
      cin >> f1 >> f2;
      friendPair[f1][f2] = 1;

    }

        

    /*
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        cout << friendPair[i][j] << " ";
      }
      cout << endl;
    }
    */
  }

  return 0;
}
