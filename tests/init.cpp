#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("matrix init without parametrs", "[init wp]") {
	matrix_t matrix;
	REQUIRE(matrix.rows() == 0);
	REQUIRE(matrix.columns() == 0);
}
