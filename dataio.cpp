#include <climits>
#include <fstream>
#include <iostream>
#include <istream>
#include <limits>
#include <string>

using std::cin;
using std::cout;
using std::string;

unsigned char read_0_1() {
  while (true) {
    std::string enter;
    getline(cin, enter);
    if (enter == "0" || enter == "1") {
      return enter[0];
    } else {
      cout << "Ошибка ввода.\nПовторите ввод: ";
    }
  }
}
unsigned read_uint(string data) {
  unsigned num;
  string enter;
  bool isnum = true;
  while (true) {
    if (data == "") {
      getline(cin, enter);
      if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Ошибка ввода данных.\n";
        isnum = false;
      }
    } else {
      enter = data;
    }
    for (unsigned int i = 0; enter[i]; i++) {
      if (!isdigit(enter[i])) {
        isnum = false;
        cout << "Недопустимый символ: " << enter[i] << " (" << i << ")\n";
      }
    }
    if (isnum) {
      num = atoi(enter.c_str());
      return num;
    } else {
      cout << "При вводе допущена ошибка.\n";
      isnum = true;
    }
    if (data != "") {
      return 0;
    } else {
      cout << "Повторите ввод: ";
    }
  }
}
int *read_arr(unsigned n, string data) {

  string enter = "";
  int *arr = new int[n];
  bool err = false;
  unsigned iter = 0;

  while (true) {
    if (data == "") {
      getline(cin, enter);
    } else {
      enter = data;
    }
    enter += '\n';
    string buf = "";

    for (unsigned i = 0; i < enter.length(); i++) {

      if (enter[i] == '-') {
        if (buf == "") {
          buf += enter[i];
        } else {
          err = true;
          cout << "Недопустимый символ: " << enter[i] << '(' << i << ")\n";
        }
      } else if (isdigit(enter[i])) {
        if (buf == "0") {
          err = true;
          cout << "Недопустимый символ: " << enter[i] << '(' << i << ")\n";
        }
        if (enter[i] == '0' && buf == "-") {
          buf = "0";
        } else {
          buf += enter[i];
        }
      } else if (enter[i] == ' ' || enter[i] == '\n') {
        if (buf != "") {
          if (iter > n - 1) {
            err = true;
            cout << "Введенное кол-во данных не соответствует " << n << '\n';
            break;
          }
          arr[iter] = stoi(buf);
          buf = "";
          iter++;
        } else {
        }
      } else {
        err = true;
        cout << "Недопустимый символ: " << enter[i] << '(' << i << ")\n";
      }
    }
    if (iter != n) {
      err = true;
      cout << "Введенное кол-во данных не соответствует " << n << '\n';
    }
    if (err) {
      if (data != "") {
        return new int[1]{INT_MIN};
      } else {
        enter = "";
        err = false;
        iter = 0;
        cout << "Повторите ввод: ";
      }
    } else {
      return arr;
    }
  }
}