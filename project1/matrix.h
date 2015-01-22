// File: matrix.h
// Author: Matthew Leeds
// Last Edit: 2015-01-20

#include <string>
#include <fstream>

using namespace std;

class Matrix {
    public:
        Matrix(int size);
        Matrix(int size, unsigned int seed);
        Matrix(ifstream& inFile, int size);
        ~Matrix();
        int findMaxMagnitude() const;
        void zeroFillExtras();
        Matrix* addSquareSubmatrices(int n, int rowStart, int colStart, int rowStart2, int colStart2);
        friend ostream& operator<<(ostream& os, const Matrix& m);
        friend Matrix* operator*(const Matrix& m1, const Matrix& m2);
        friend Matrix* operator+(const Matrix& m1, const Matrix& m2);
        friend Matrix* operator-(const Matrix& m1, const Matrix& m2);

    private:
        int** _matrix;
        int _size;
        int _originalSize;
        int _numMultiplications;
        int _numAdditions;
};
