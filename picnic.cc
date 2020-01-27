#include <iostream>
#include <list>
using namespace std;

bool findFriend(list<pair<int, int>>::iterator iter);

int N = 0, n = 0; // # of students, max 10
int M = 0, m = 0; // # of friend pairs, max n * (n - 1) / 2
int f1 = 0, f2 = 0; // # for friend pair idx
bool checked[10] = {false, };
  
int main(void) {
  int C = 0, c = 0; // # of testcase, max 50
  int cnt = 0;
  /* Get # of testcases */
  cin >> C;

  for (c = 0; c < C; c++) {
    list<pair<int, int>> Pair;
    /* Get # of students and # of friend pairs */
    cin >> N >> M;

    cnt = 0;
    for (n = 0; n < 10; n++)
      checked[n] = false;

    for (m = 0; m < M; m++) {
      cin >> f1 >> f2;
      Pair.push_back(make_pair(f1, f2));
    }

    auto begin_iter = Pair.begin();
    for (m = 0; m < M; m++) {
      if (findFriend(begin_iter) == true)
        cnt++;
    }
    
    
  }

  return 0;
}


bool findFriend(list<pair<int, int>>::iterator iter) {
  bool found = true;
  for (n = 0; n < N; n++) {
    if (checked[n] == false)
      found = false;
  }
  if (found == true)
    return true;

  /* go find */

  /* check result */
  if (findFriend(iter) == true)
    return true;
  else
    return false;
  
}