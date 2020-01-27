#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int C = 0, c = 0;
  string str;

  cin >> C;

  for (c = 0; c < C; c++) {
    cin >> str;
    cout << "Hello, " << str << "!" << endl;
  }
    
  return 0;
}
