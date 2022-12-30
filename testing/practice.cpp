#include <iostream>
using namespace std;

struct Matrix {
    int width;
    int height;
    int data[];

};

int main() {
  int width;
  Matrix *mat, d;
  mat = &d;
  mat->width = 200;
  mat ->height = 200;
  cout << mat->height << " " << mat->width << endl;

}
