#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "io.h"


TEST_CASE("Reading unsigned integers", "[read uints]") {
	unsigned char buffer[4] = {0xaa, 0xbb, 0xcc, 0xdd};

	uint32_t read_le_result = io::read_little_endian_unsigned_int<4, uint32_t>(buffer);
	REQUIRE(
		read_le_result == 0xddccbbaaU
	);
	uint32_t read_be_result = io::read_big_endian_unsigned_int<4, uint32_t>(buffer);
	REQUIRE(
		read_be_result == 0xaabbccddU
	);
}


TEST_CASE("Writing unsigned integers", "[write uints]") {
	unsigned char buffer[4] = {0};

	io::write_little_endian_unsigned_int<4>(0x12345678U, buffer);
	REQUIRE(buffer[0] == 0x78);
	REQUIRE(buffer[1] == 0x56);
	REQUIRE(buffer[2] == 0x34);
	REQUIRE(buffer[3] == 0x12);

	io::write_big_endian_unsigned_int<4>(0x12345678U, buffer);
	REQUIRE(buffer[0] == 0x12);
	REQUIRE(buffer[1] == 0x34);
	REQUIRE(buffer[2] == 0x56);
	REQUIRE(buffer[3] == 0x78);
}
