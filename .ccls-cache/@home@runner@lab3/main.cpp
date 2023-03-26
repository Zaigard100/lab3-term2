#include "dataio.h"
#include "functions.h"
#include <climits>
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::string;

int main() {
  std::ifstream fin("in.txt");
  std::ofstream fout("out.txt");
  unsigned char inl;
  unsigned char outl;
  unsigned m{0};
  int *a;
  bool err = false;
  int **matrix;
  while (true) {
    if (fin.is_open() && fout.is_open()) {
      cout << "Ввод с консоли (0) или с файл(1): ";
      inl = read_0_1();
      cout << "Вывод в консоли (0) или в файл(1): ";
      outl = read_0_1();
      int *arr;
      int n;
      if (inl == '0') {

        cout << "Введите m: ";
        m = read_uint("");

        a = new int[m];
        matrix = new int *[m];

        cout << "Введите " << m << " элементов: ";
        arr = read_arr(m, "");
        for (unsigned i = 0; i < m; i++) {
          a[i] = arr[i];
        }

        cout << "\nВведите матрицу порядка " << m << " :\n";
        for (unsigned i = 0; i < m; i++) {
          arr = read_arr(m, "");
          matrix[i] = arr;
        }
      } else if (inl == '1') {

        string str_line;
        getline(fin, str_line);
        m = read_uint(str_line);

        a = new int[m];
        matrix = new int *[m];
        getline(fin, str_line);
        arr = read_arr(m, str_line);
        if (arr[0] == INT_MIN) {
          err = true;
          break;
        }
        for (unsigned i = 0; i < m; i++) {
          a[i] = arr[i];
        }

        for (unsigned i = 0; i < m; i++) {
          getline(fin, str_line);
          arr = read_arr(m, str_line);
          matrix[i] = arr;
        }
      }

      a = mark(a, m);
      matrix = matrix_task(matrix, a, m);
      n = matrix_negativ(matrix, a, m);
      if (err) {
        cout << "Ошибка ввода";
        break;
      }

      if (outl == '0') {

        cout << "а) \n";
        for (unsigned i = 0; i < m; i++) {
          for (unsigned j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
          }
          cout << '\n';
        }

        cout << "б) " << n << '\n';

      } else if (outl == '1') {

        fout << "а) \n";
        for (unsigned i = 0; i < m; i++) {
          for (unsigned j = 0; j < m; j++) {
            fout << matrix[i][j] << " ";
          }
          fout << '\n';
        }

        fout << "б) " << n << '\n';
      }

    } else {
      cout << "Не удалось открыть файл(ы)!\n";
      break;
    }

    if (inl == '0') {
      cout << "Хотите продолжить(0/1): ";
      inl = read_0_1();
      if (inl == '0') {
        break;
      }
    } else if (inl == '1') {
      break;
    }

    if (err) {
      cout << "Ошибка ввода";
      break;
    }
  }
  fin.close();
  fout.close();
}
