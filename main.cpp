#include <bits/stdc++.h>

#include "bitmap_image.hpp"

using namespace std;

struct Based {
  int w[10000];
  int mem = 10000;

 public:
  Based() {
    for (int i = 0; i < mem; i++) {
      w[i] = 0;
    }
  }

  void operator=(int value) {
    string s = to_string(value);
    for (int i = 0; i < s.length(); i++) {
      if (i < s.length() && s[i] >= '0' && s[i] <= '9') {
        w[i] = (s[i] - '0');
      } else {
        break;
      }
    }
  }

  void operator=(string value) {
    string s = value;
    for (int i = 0; i < s.length(); i++) {
      if (i < s.length() && s[i] >= '0' && s[i] <= '9') {
        w[i] = (s[i] - '0');
      } else {
        break;
      }
    }
  }

  Based operator+(Based value) {
    Based ans;
    int reminder = 0;
    for (int i = 9999; i >= 0; i--) {
      if (w[i] + value[i] + reminder < 10) {
        ans[i] = w[i] + value[i] + reminder;
        reminder = 0;
      } else {
        ans[i] = (w[i] + value[i] + reminder) % 10;
        reminder = 1;
      }
    }

    return ans;
  }

  Based operator-(Based value) {
    Based ans;
    Based error;
    for (int i = 9999; i >= 0; i--) {
      if (w[i] >= value.w[i]) {
        ans[i] = w[i] - value.w[i];
      } else {
        for (int j = i - 1; j >= 0; j--) {
          if (w[j] != 0) {
            w[j] -= 1;
            ans[i] = 10 + w[i] - value.w[i];
            break;
          } else if (j == 0 && w[j] == 0) {
            error = 436788;
            return (error);
          } else if (w[j] == 0) {
            w[j] = 9;
          }
        }
      }
    }

    return ans;
  }

  bool operator>(Based value) {
    int flag = 0;
    bool thing = false;
    for (int i = 0; i < mem; i++) {
      if (w[i] > value[i]) {
        thing = true;
        flag = 1;
        break;
      } else if (w[i] < value[i]) {
        thing = false;
        flag = 1;
        break;
      }
    }

    if (flag == 1) {
      return thing;
    } else {
      return false;
    }
  }

  bool operator<(Based value) {
    int flag = 0;
    bool thing = false;
    for (int i = 0; i < mem; i++) {
      if (w[i] < value[i]) {
        thing = true;
        flag = 1;
        break;
      } else if (w[i] > value[i]) {
        thing = false;
        flag = 1;
        break;
      }
    }

    if (flag == 1) {
      return thing;
    } else {
      return false;
    }
  }

  int& operator[](int index) { return w[index]; }
} p1;

std::ostream& operator<<(std::ostream& output, Based Based) {
  for (int i = 0; i < 10000; i++) {
    output << Based[i];
  }
  return output;
}

Based long_division(int a, int b) {
  Based save;
  int p = 0, reminder = 0, ops = 0;
  string s = to_string(a);

  while (ops <= 10000) {
    if (p < s.length()) {
      if (reminder * 10 + (s[p] - '0') >= b) {
        reminder += (s[p] - '0');
        save[ops] = reminder / b;
        reminder %= b;
        ops++;
      } else if (reminder * 10 + (s[p] - '0') < b && p == s.length() - 1) {
        save[ops] = 0;
        reminder += (s[p] - '0');
        reminder *= 10;
        ops++;
      } else {
        reminder += (s[p] - '0');
        reminder *= 10;
      }
    } else {
      if (reminder * 10 >= b) {
        save[ops] = reminder / b;
        reminder %= b;
        reminder *= 10;
        ops++;
      } else {
        reminder *= 10;
        ops++;
      }
    }
    p++;
  }

  return (save);
}

Based long_multiplication(Based b, int chad) {
  vector<string> lines;
  Based ans;
  string s = to_string(chad), sum;

  for (int i = s.length() - 1; i >= 0; i--) {
    int current_digit = s[i] - '0';
    int line = 0, reminder = 0;
    string s = string(s.length() - i + 1, '0'), line_s;

    for (int i = 9999; i >= 0; i--) {
      int curr = b[i] * current_digit + reminder;
      string current = to_string(curr);
      if (current.length() > 1) {
        reminder = current[0] - '0';
        line_s = current[1] + line_s;
      } else if (current.length() > 1 && i == 0) {
        line_s = current + line_s;
      } else {
        reminder = 0;
        line_s = current[0] + line_s;
      }
    }
    lines.push_back(line_s);
  }

  sum = lines[0];

  for (int i = 1; i < lines.size(); i++) {
    int rem = 0;
    string f;
    for (int j = 0; j < lines.size(); j++) {
      if (j < sum.length()) {
        if ((lines[i][j] - '0') + (sum[j] - '0') + rem <= 9) {
          f[j] = lines[i][j] + sum[j];
        } else {
          rem = 1;
          f[j] = lines[i][j] + sum[j] - 10;
        }
      } else {
        if ((lines[i][j] - '0') + rem <= 9) {
          f[j] = lines[i][j];
        } else {
          rem = 1;
          f[j] = lines[i][j] - 10;
        }
      }
    }
  }

  ans = sum;
  return (ans);
}

string Decimal_to_binary(int a) {
  string s;
  while (a > 0) {
    int reminder = a % 2;
    char c = reminder + 48;
    s = c + s;
    a /= 2;
  }

  if (s.length() >= 4) {
    return s;
  } else {
    int f = s.length();
    for (int i = f; i < 4; i++) {
      s = '0' + s;
    }

    return s;
  }
}

int main() {
  string s = "test";
  string def = "test";

  cout << "Enter name of your photo:" << '\n';
  cin >> s;

  Based pi_fourth, pi;
  pi_fourth = 1;
  int flag = 0;
  int randomArr[16], randomArrBinary[64];

  for (int i = 1; i < 35000; i++) {
    int h = 2 * i + 1;
    if (flag == 0) {
      pi_fourth = pi_fourth - long_division(1, h);
      flag = 1;
    } else if (flag == 1) {
      pi_fourth = pi_fourth + long_division(1, h);
      flag = 0;
    }
  }
  pi = long_multiplication(pi_fourth, 4);

  srand(time(0));

  for (int i = 0; i < 16; i++) {
    int rand_index = (rand() % 10000);
    randomArr[i] = pi[rand_index];
  }

  for (int i = 0; i < 16; i++) {
    int p = 0;
    string s = Decimal_to_binary(randomArr[i]);
    for (int j = 4 * i; j < 4 * i + 4; j++) {
      randomArrBinary[j] = (s[p] - '0');
      p++;
    }
    p = 0;
  }

  // It's Bitmap time <3 :)

  bitmap_image image(128, 128);

  image.set_all_channels(255, 255, 255);
  image_drawer draw(image);

  draw.pen_width(1);
  draw.pen_color(0, 127, 255);

  for (int i = 0; i < 64; i++) {
    if (randomArrBinary[i] == 1) {
      int y = (i / 8) * 16;
      int x = (i % 8) * 16;
      for (int j = x; j <= x + 16; j++) {
        draw.vertical_line_segment(y, y + 16, j);
      }
    }
  }

  if (s.length() == 0) {
    def += ".png";
    image.save_image(def);
  } else {
    s += ".png";
    image.save_image(s);
  }

  return 0;
}