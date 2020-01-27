#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void findFriend(list<pair<int, int> >::iterator iter, list<pair<int, int> >::iterator end_iter);

int C = 0, c = 0; // # of testcase, max 50
int N = 0, n = 0; // # of students, max 10
int M = 0, m = 0; // # of friend pairs, max n * (n - 1) / 2
int f1 = 0, f2 = 0; // # for friend pair idx
bool checked[10] = {false, };
int cnt = 0;

int main(void) {
  cin >> C;

  for (c = 0; c < C; c++) {
    list<pair<int, int> > Pair;
    cin >> N >> M;

    cnt = 0;
    for (n = 0; n < 10; n++)
      checked[n] = false;

    for (m = 0; m < M; m++) {
      cin >> f1 >> f2;
      Pair.push_back(make_pair(f1, f2));
    }

    auto iter = Pair.begin();
    auto end_iter = Pair.end();

    findFriend(iter, end_iter);
    
    cout << cnt << endl;
  }

  return 0;
}


void findFriend(list<pair<int, int> >::iterator iter, list<pair<int, int> >::iterator end_iter) {
  bool found = true;
  
  for (n = 0; n < N; n++) {
    if (checked[n] == false)
      found = false;
  }
  if (found == true) {
    cnt++;
    return;
  }

  for (; iter != end_iter; ++iter) {
    int first = (*iter).first;
    int second = (*iter).second;
    
    if (checked[first] == false && checked[second] == false) {
      checked[first] = true;
      checked[second] = true;
      findFriend(iter, end_iter);
      checked[first] = false;
      checked[second] = false;
    }
  }
  
  return;
}