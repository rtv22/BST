#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("matrix init without parametrs", "[init wp]") {
	Matrix matrix;
	REQUIRE(matrix.rows() == 4);
	REQUIRE(matrix.columns() == 4);
}

SCENARIO("matrix init with parametrs", "[init withp]") {
	Matrix matrix(6,6);
	REQUIRE(matrix.rows() == 6);
	REQUIRE(matrix.columns() == 6);
}
