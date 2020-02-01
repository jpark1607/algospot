#include <iostream>

using namespace std;

enum class checkType {
  TYPE1 = 1,  /* R (กๆ) U (ก่) */
  TYPE2 = 2,  /* L (ก็) U (ก่) */
  TYPE3 = 3,  /* L (ก็) D (ก้) */
  TYPE4 = 4   /* R (กๆ) D (ก้) */
};

typedef enum class checkType checkType;

void findCase (int pos_h, int pos_w);
bool checkPos (int pos_h, int pos_w, checkType type);

int C = 0, c = 0; // # of testcase, max 30
int H = 0, h = 0; // # of heignt, max 20
int W = 0, w = 0; // # of weight, max 20
char board[22][22] = {"", };
int cnt = 0;

int main(void) {
  cin >> C;

  for (c = 0; c < C; c++) {
    char str[21] = "";
    
    cin >> H >> W;

    cnt = 0;
    /* board initialize */
    for (h = 0; h < H + 2; h++) {
      for (w = 0; w < W + 2; w++) {
        board[h][w] = '#';
      }
    }

    for (h = 1; h < H + 1; h++) {
      cin >> str;
      memcpy (board[h] + 1, str, W);
    }

    findCase (1, 1);
    cout << cnt << endl;
  }
  

  return 0;
}

bool checkPos (int pos_h, int pos_w, checkType type) {
  switch (type) {
  case checkType::TYPE1:
    if (board[pos_h - 1][pos_w] == '.' && board[pos_h][pos_w + 1] == '.')
      return true;
    break;
  case checkType::TYPE2:
    if (board[pos_h - 1][pos_w] == '.' && board[pos_h][pos_w - 1] == '.')
      return true;
    break;
  case checkType::TYPE3:
    if (board[pos_h + 1][pos_w] == '.' && board[pos_h][pos_w - 1] == '.')
      return true;
    break;
  case checkType::TYPE4:
    if (board[pos_h + 1][pos_w] == '.' && board[pos_h][pos_w + 1] == '.')
      return true;
    break;
  }
  return false;
}



void findCase (int pos_h, int pos_w) {
  while (board[pos_h][pos_w] != '.') {
    /* reached to the end */
    if (pos_h == H && pos_w == W + 1) {
      for (h = 1; h < H + 1; h++) {
        for (w = 1; w < W + 1; w++) {
          if (board[h][w] == '.')
            break;
        }
        if (board[h][w] == '.')
          break;
      }
      if (h == H && w == W + 1)
        cnt++;

      return;
    }


    if (pos_w == W + 1) {
      pos_w = 1;
      pos_h = pos_h + 1;
    }
    else {
      pos_w += 1;
    }
  }

	

  while (pos_h != H || pos_w != W + 1) {
    if (board[pos_h][pos_w] == '#') {
      if (pos_w == W + 1) {
        pos_w = 1;
        pos_h = pos_h + 1;
      }
      else {
        pos_w += 1;
      }
      continue;
    }
    board[pos_h][pos_w] = '#';
    if (checkPos(pos_h, pos_w, checkType::TYPE1)) {
      board[pos_h - 1][pos_w] = '#';
      board[pos_h][pos_w + 1] = '#';
      findCase(pos_h, pos_w + 1);
      board[pos_h - 1][pos_w] = '.';
      board[pos_h][pos_w + 1] = '.';
    }

    if (checkPos(pos_h, pos_w, checkType::TYPE2)) {
      board[pos_h - 1][pos_w] = '#';
      board[pos_h][pos_w - 1] = '#';
      findCase(pos_h, pos_w + 1);
      board[pos_h - 1][pos_w] = '.';
      board[pos_h][pos_w - 1] = '.';
    }

    if (checkPos(pos_h, pos_w, checkType::TYPE3)) {
      board[pos_h + 1][pos_w] = '#';
      board[pos_h][pos_w - 1] = '#';
      findCase(pos_h, pos_w + 1);
      board[pos_h + 1][pos_w] = '.';
      board[pos_h][pos_w - 1] = '.';
    }

    if (checkPos(pos_h, pos_w, checkType::TYPE4)) {
      board[pos_h + 1][pos_w] = '#';
      board[pos_h][pos_w + 1] = '#';
      findCase(pos_h, pos_w + 1);
      board[pos_h + 1][pos_w] = '.';
      board[pos_h][pos_w + 1] = '.';
    }

    board[pos_h][pos_w] = '.';
    
    if (pos_w == W + 1) {
      pos_w = 1;
      pos_h = pos_h + 1;
    }
    else {
      pos_w += 1;
    }
  }

  return;
}
