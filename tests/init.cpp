#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("matrix init without parametrs", "[init wp]") {
	Matrix matrix;
	REQUIRE(matrix.rows() == 4);
	REQUIRE(matrix.columns() == 4);
	
	for (int i=0;i<matrix.rows(); i++) {
		for (int j = 0; j<matrix.columns();j++) {
			REQUIRE(matrix[i][j] == 0);
		}
	}
}

SCENARIO("matrix init with parametrs", "[init withp]") {
	Matrix matrix(6,6);
	REQUIRE(matrix.rows() == 6);
	REQUIRE(matrix.columns() == 6);
	
	for (int i=0;i<matrix.rows(); i++) {
		for (int j = 0; j<matrix.columns();j++) {
			REQUIRE(matrix[i][j] == 0);
		}
	}
}

SCENARIO("matrix init copy", "[init copy]") {
	Matrix matrix(6,6);
	Matrix matrix1(matrix);
	REQUIRE(matrix1.rows() == matrix.rows());
	REQUIRE(matrix1.columns() == matrix.columns());
	
	for (int i=0;i<matrix.rows(); i++) {
		for (int j = 0; j<matrix.columns();j++) {
			REQUIRE(matrix[i][j] == matrix1[i][j]);
		}
	}
}

SCENARIO("matrix fill", "[fill]") {
	Matrix matrix(2,2);
	ofstream test1("test1.txt");
	test1 << "1 2 3 4";
	test1.close();
	REQUIRE(matrix[0][0] == 1);
	REQUIRE(matrix[0][1] == 2);
	REQUIRE(matrix[1][0] == 3);
	REQUIRE(matrix[1][1] == 4);
}

SCENARIO("matrix sum", "[sum]") {
	Matrix matrix(2,2);
	Matrix matrix1(2,2);
	



