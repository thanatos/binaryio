#ifndef IO_HELPERS_H
#define IO_HELPERS_H

#include <cstdint>

#include "basic.h"

namespace io {
	/*
	 * Reading 
	 */
	/* Unsigned big-endian */
	template<typename InputIterator>
	uint_least8_t read_u8be(InputIterator i) {
		return io::read_big_endian_unsigned_int<1, uint_least8_t>(i);
	}

	template<typename InputIterator>
	uint_least16_t read_u16be(InputIterator i) {
		return io::read_big_endian_unsigned_int<2, uint_least16_t>(i);
	}

	template<typename InputIterator>
	uint_least32_t read_u32be(InputIterator i) {
		return io::read_big_endian_unsigned_int<4, uint_least32_t>(i);
	}

	template<typename InputIterator>
	uint_least64_t read_u64be(InputIterator i) {
		return io::read_big_endian_unsigned_int<8, uint_least64_t>(i);
	}

	/* Unsigned little-endian */
	template<typename InputIterator>
	uint_least8_t read_u8le(InputIterator i) {
		return io::read_little_endian_unsigned_int<1, uint_least8_t>(i);
	}

	template<typename InputIterator>
	uint_least16_t read_u16le(InputIterator i) {
		return io::read_little_endian_unsigned_int<2, uint_least16_t>(i);
	}

	template<typename InputIterator>
	uint_least32_t read_u32le(InputIterator i) {
		return io::read_little_endian_unsigned_int<4, uint_least32_t>(i);
	}

	template<typename InputIterator>
	uint_least64_t read_u64le(InputIterator i) {
		return io::read_little_endian_unsigned_int<8, uint_least64_t>(i);
	}
}

#endif
