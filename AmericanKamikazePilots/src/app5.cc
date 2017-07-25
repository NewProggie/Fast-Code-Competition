#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  // precompute a table with two digit pairs
  char tab[100][2];

  tab[0][0] = '0';
  tab[0][1] = '0';

  for (int i = 1; i < 100; i++) {
    if (i < 10) {
      tab[i][0] = '0';
    } else {
      tab[i][0] = '0' + i / 10;
    }
    tab[i][1] = '0' + i % 10;
  }

  if (argc != 2) {
    std::exit(1);
  }

  int n = std::atoi(argv[1]);

  const int buf_size = 10;
  char buffer[buf_size];
  buffer[buf_size - 1] = 0;

  for (int i = 0; i < n; ++i) {
    char *b = &buffer[0] + buf_size - 1;
    int j = i;

    while (j >= 100) {
      b -= 2;
      int k = j % 100;
      b[0] = tab[k][0];
      b[1] = tab[k][1];

      j = j / 100;
    }
    while (j >= 10) {
      b--;
      int last = j % 10;
      *b = last + '0';

      j = j / 10;
    }
    b--;
    *b = j + '0';
    fputs(b, stdout);
  }

  return 0;
}