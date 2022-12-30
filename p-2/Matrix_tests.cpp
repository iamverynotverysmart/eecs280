// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"


using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);
  Matrix_print(mat, cout);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(matrixborders){
  Matrix *mat = new Matrix;
  const int width = 5;
  const int height = 8;
  const int value = 72;
  Matrix_init(mat, 5, 8);
  Matrix_fill(mat, value);
  Matrix_print(mat, cout);
  Matrix_fill_border(mat, 71);
  cout << "-----------------------------" << endl;
  Matrix_print(mat, cout);
  cout << "-----------------------------" << endl;
  int * ptr = Matrix_at(mat, 2, 1);
  *ptr = 27;
  cout << Matrix_column(mat, ptr) << endl;
  cout << Matrix_row(mat, ptr) << endl;
  Matrix_print(mat, cout);
  
  cout << "---------------------------" << endl;
  cout << Matrix_max(mat) << endl;
  cout << Matrix_column_of_min_value_in_row(mat, 3, 2, 4) << endl;
  cout << Matrix_min_value_in_row(mat, 3, 2, 4) << endl;

  delete mat;


}
TEST(weirdcombinations) {
  Matrix *mat = new Matrix;
  const int width = 1;
  const int height = 1;
  const int value = 0;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_print(mat, cout);
  cout << "-------------------------" << "\n" << endl;
  Matrix_fill_border(mat, 1);
  Matrix_print(mat, cout);
  delete mat;
  

}

TEST(lasttwofunctins) {
  Matrix* mat = new Matrix;
  delete mat;
}
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
