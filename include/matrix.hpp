#include <fstream>
#include <iostream>

using namespace std;

class Matrix {

private:
	int row, col, **mas;
public:
	Matrix(int length = 4);
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();
	void fill(const char*);
	void show() const;
	int rows();
	int columns();
	Matrix operator+(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
	int operator[](int,int) const;
};
