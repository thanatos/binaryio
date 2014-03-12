#ifndef IO_H
#define IO_H


namespace io {
	template<size_t size, typename T, typename InputIterator>
	T read_big_endian_unsigned_int(InputIterator i) {
		T n = 0;
		for(size_t idx = 0; idx < size; ++idx) {
			n = (n << 8) | static_cast<T>(*i);
			++i;
		}

		return n;
	}

	template<size_t size, typename T, typename OutputIterator>
	void write_big_endian_unsigned_int(const T &n, OutputIterator i) {
		for(size_t idx = 0; idx < size; ++idx) {
			unsigned int shift = (size - idx - 1) * 8;
			*i = static_cast<unsigned char>((n >> shift) & 0xffU);
			++i;
		}
	}

	template<size_t size, typename T, typename InputIterator>
	T read_little_endian_unsigned_int(InputIterator i) {
		T n = 0;
		for(size_t idx = 0; idx < size; ++idx) {
			n |= static_cast<T>(*i) << (8 * idx);
			++i;
		}
		return n;
	}

	template<size_t size, typename T, typename OutputIterator>
	void write_little_endian_unsigned_int(T n, OutputIterator i) {
		for(size_t idx = 0; idx < size; ++idx) {
			*i = static_cast<unsigned char>(n & 0xffU);
			n >>= 8;
			++i;
		}
	}
}

#endif
