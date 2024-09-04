#ifndef BEARSSL_IMPL_SYMCIPHER_DES_TAB_HPP
#define BEARSSL_IMPL_SYMCIPHER_DES_TAB_HPP

/*
 * Copyright (c) 2016 Thomas Pornin <pornin@bolet.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "inner.h"

/*
 * _opt_libs_BearSSL_src_symcipher_des_tab_c_PC2left[x] tells where bit x goes when applying PC-2. 'x' is a bit
 * position in the left rotated key word. Both position are in normal
 * order (rightmost bit is 0).
 */
 inline static const unsigned char _opt_libs_BearSSL_src_symcipher_des_tab_c_PC2left[] = {
	16,  3,  7, 24, 20, 11, 24,
	13,  2, 10, 24, 22,  5, 15,
	23,  1,  9, 21, 12, 24,  6,
	 4, 14, 18,  8, 17,  0, 19
};

/*
 * Similar to _opt_libs_BearSSL_src_symcipher_des_tab_c_PC2left[x], for the right rotated key word.
 */
 inline static const unsigned char _opt_libs_BearSSL_src_symcipher_des_tab_c_PC2right[] = {
	 8, 18, 24,  6, 22, 15,  3,
	10, 12, 19,  5, 14, 11, 24,
	 4, 23, 16,  9, 24, 20,  2,
	24,  7, 13,  0, 21, 17,  1
};

/*
 * S-boxes and PC-1 merged.
 */
 inline static const uint32_t _opt_libs_BearSSL_src_symcipher_des_tab_c_S1[] = {
	0x00808200, 0x00000000, 0x00008000, 0x00808202,
	0x00808002, 0x00008202, 0x00000002, 0x00008000,
	0x00000200, 0x00808200, 0x00808202, 0x00000200,
	0x00800202, 0x00808002, 0x00800000, 0x00000002,
	0x00000202, 0x00800200, 0x00800200, 0x00008200,
	0x00008200, 0x00808000, 0x00808000, 0x00800202,
	0x00008002, 0x00800002, 0x00800002, 0x00008002,
	0x00000000, 0x00000202, 0x00008202, 0x00800000,
	0x00008000, 0x00808202, 0x00000002, 0x00808000,
	0x00808200, 0x00800000, 0x00800000, 0x00000200,
	0x00808002, 0x00008000, 0x00008200, 0x00800002,
	0x00000200, 0x00000002, 0x00800202, 0x00008202,
	0x00808202, 0x00008002, 0x00808000, 0x00800202,
	0x00800002, 0x00000202, 0x00008202, 0x00808200,
	0x00000202, 0x00800200, 0x00800200, 0x00000000,
	0x00008002, 0x00008200, 0x00000000, 0x00808002
};

 inline static const uint32_t _opt_libs_BearSSL_src_symcipher_des_tab_c_S2[] = {
	0x40084010, 0x40004000, 0x00004000, 0x00084010,
	0x00080000, 0x00000010, 0x40080010, 0x40004010,
	0x40000010, 0x40084010, 0x40084000, 0x40000000,
	0x40004000, 0x00080000, 0x00000010, 0x40080010,
	0x00084000, 0x00080010, 0x40004010, 0x00000000,
	0x40000000, 0x00004000, 0x00084010, 0x40080000,
	0x00080010, 0x40000010, 0x00000000, 0x00084000,
	0x00004010, 0x40084000, 0x40080000, 0x00004010,
	0x00000000, 0x00084010, 0x40080010, 0x00080000,
	0x40004010, 0x40080000, 0x40084000, 0x00004000,
	0x40080000, 0x40004000, 0x00000010, 0x40084010,
	0x00084010, 0x00000010, 0x00004000, 0x40000000,
	0x00004010, 0x40084000, 0x00080000, 0x40000010,
	0x00080010, 0x40004010, 0x40000010, 0x00080010,
	0x00084000, 0x00000000, 0x40004000, 0x00004010,
	0x40000000, 0x40080010, 0x40084010, 0x00084000
};

 inline static const uint32_t _opt_libs_BearSSL_src_symcipher_des_tab_c_S3[] = {
	0x00000104, 0x04010100, 0x00000000, 0x04010004,
	0x04000100, 0x00000000, 0x00010104, 0x04000100,
	0x00010004, 0x04000004, 0x04000004, 0x00010000,
	0x04010104, 0x00010004, 0x04010000, 0x00000104,
	0x04000000, 0x00000004, 0x04010100, 0x00000100,
	0x00010100, 0x04010000, 0x04010004, 0x00010104,
	0x04000104, 0x00010100, 0x00010000, 0x04000104,
	0x00000004, 0x04010104, 0x00000100, 0x04000000,
	0x04010100, 0x04000000, 0x00010004, 0x00000104,
	0x00010000, 0x04010100, 0x04000100, 0x00000000,
	0x00000100, 0x00010004, 0x04010104, 0x04000100,
	0x04000004, 0x00000100, 0x00000000, 0x04010004,
	0x04000104, 0x00010000, 0x04000000, 0x04010104,
	0x00000004, 0x00010104, 0x00010100, 0x04000004,
	0x04010000, 0x04000104, 0x00000104, 0x04010000,
	0x00010104, 0x00000004, 0x04010004, 0x00010100
};

 inline static const uint32_t _opt_libs_BearSSL_src_symcipher_des_tab_c_S4[] = {
	0x80401000, 0x80001040, 0x80001040, 0x00000040,
	0x00401040, 0x80400040, 0x80400000, 0x80001000,
	0x00000000, 0x00401000, 0x00401000, 0x80401040,
	0x80000040, 0x00000000, 0x00400040, 0x80400000,
	0x80000000, 0x00001000, 0x00400000, 0x80401000,
	0x00000040, 0x00400000, 0x80001000, 0x00001040,
	0x80400040, 0x80000000, 0x00001040, 0x00400040,
	0x00001000, 0x00401040, 0x80401040, 0x80000040,
	0x00400040, 0x80400000, 0x00401000, 0x80401040,
	0x80000040, 0x00000000, 0x00000000, 0x00401000,
	0x00001040, 0x00400040, 0x80400040, 0x80000000,
	0x80401000, 0x80001040, 0x80001040, 0x00000040,
	0x80401040, 0x80000040, 0x80000000, 0x00001000,
	0x80400000, 0x80001000, 0x00401040, 0x80400040,
	0x80001000, 0x00001040, 0x00400000, 0x80401000,
	0x00000040, 0x00400000, 0x00001000, 0x00401040
};

 inline static const uint32_t _opt_libs_BearSSL_src_symcipher_des_tab_c_S5[] = {
	0x00000080, 0x01040080, 0x01040000, 0x21000080,
	0x00040000, 0x00000080, 0x20000000, 0x01040000,
	0x20040080, 0x00040000, 0x01000080, 0x20040080,
	0x21000080, 0x21040000, 0x00040080, 0x20000000,
	0x01000000, 0x20040000, 0x20040000, 0x00000000,
	0x20000080, 0x21040080, 0x21040080, 0x01000080,
	0x21040000, 0x20000080, 0x00000000, 0x21000000,
	0x01040080, 0x01000000, 0x21000000, 0x00040080,
	0x00040000, 0x21000080, 0x00000080, 0x01000000,
	0x20000000, 0x01040000, 0x21000080, 0x20040080,
	0x01000080, 0x20000000, 0x21040000, 0x01040080,
	0x20040080, 0x00000080, 0x01000000, 0x21040000,
	0x21040080, 0x00040080, 0x21000000, 0x21040080,
	0x01040000, 0x00000000, 0x20040000, 0x21000000,
	0x00040080, 0x01000080, 0x20000080, 0x00040000,
	0x00000000, 0x20040000, 0x01040080, 0x20000080
};

 inline static const uint32_t _opt_libs_BearSSL_src_symcipher_des_tab_c_S6[] = {
	0x10000008, 0x10200000, 0x00002000, 0x10202008,
	0x10200000, 0x00000008, 0x10202008, 0x00200000,
	0x10002000, 0x00202008, 0x00200000, 0x10000008,
	0x00200008, 0x10002000, 0x10000000, 0x00002008,
	0x00000000, 0x00200008, 0x10002008, 0x00002000,
	0x00202000, 0x10002008, 0x00000008, 0x10200008,
	0x10200008, 0x00000000, 0x00202008, 0x10202000,
	0x00002008, 0x00202000, 0x10202000, 0x10000000,
	0x10002000, 0x00000008, 0x10200008, 0x00202000,
	0x10202008, 0x00200000, 0x00002008, 0x10000008,
	0x00200000, 0x10002000, 0x10000000, 0x00002008,
	0x10000008, 0x10202008, 0x00202000, 0x10200000,
	0x00202008, 0x10202000, 0x00000000, 0x10200008,
	0x00000008, 0x00002000, 0x10200000, 0x00202008,
	0x00002000, 0x00200008, 0x10002008, 0x00000000,
	0x10202000, 0x10000000, 0x00200008, 0x10002008
};

 inline static const uint32_t _opt_libs_BearSSL_src_symcipher_des_tab_c_S7[] = {
	0x00100000, 0x02100001, 0x02000401, 0x00000000,
	0x00000400, 0x02000401, 0x00100401, 0x02100400,
	0x02100401, 0x00100000, 0x00000000, 0x02000001,
	0x00000001, 0x02000000, 0x02100001, 0x00000401,
	0x02000400, 0x00100401, 0x00100001, 0x02000400,
	0x02000001, 0x02100000, 0x02100400, 0x00100001,
	0x02100000, 0x00000400, 0x00000401, 0x02100401,
	0x00100400, 0x00000001, 0x02000000, 0x00100400,
	0x02000000, 0x00100400, 0x00100000, 0x02000401,
	0x02000401, 0x02100001, 0x02100001, 0x00000001,
	0x00100001, 0x02000000, 0x02000400, 0x00100000,
	0x02100400, 0x00000401, 0x00100401, 0x02100400,
	0x00000401, 0x02000001, 0x02100401, 0x02100000,
	0x00100400, 0x00000000, 0x00000001, 0x02100401,
	0x00000000, 0x00100401, 0x02100000, 0x00000400,
	0x02000001, 0x02000400, 0x00000400, 0x00100001
};

 inline static const uint32_t _opt_libs_BearSSL_src_symcipher_des_tab_c_S8[] = {
	0x08000820, 0x00000800, 0x00020000, 0x08020820,
	0x08000000, 0x08000820, 0x00000020, 0x08000000,
	0x00020020, 0x08020000, 0x08020820, 0x00020800,
	0x08020800, 0x00020820, 0x00000800, 0x00000020,
	0x08020000, 0x08000020, 0x08000800, 0x00000820,
	0x00020800, 0x00020020, 0x08020020, 0x08020800,
	0x00000820, 0x00000000, 0x00000000, 0x08020020,
	0x08000020, 0x08000800, 0x00020820, 0x00020000,
	0x00020820, 0x00020000, 0x08020800, 0x00000800,
	0x00000020, 0x08020020, 0x00000800, 0x00020820,
	0x08000800, 0x00000020, 0x08000020, 0x08020000,
	0x08020020, 0x08000000, 0x00020000, 0x08000820,
	0x00000000, 0x08020820, 0x00020020, 0x08000020,
	0x08020000, 0x08000800, 0x08000820, 0x00000000,
	0x08020820, 0x00020800, 0x00020800, 0x00000820,
	0x00000820, 0x00020020, 0x08000000, 0x08020800
};

 inline uint32_t
_opt_libs_BearSSL_src_symcipher_des_tab_c_Fconf(uint32_t r0, uint32_t skl, uint32_t skr)
{
	uint32_t r1;

	r1 = (r0 << 16) | (r0 >> 16);
	return
		  _opt_libs_BearSSL_src_symcipher_des_tab_c_S1[((r1 >> 11) ^ (skl >> 18)) & 0x3F]
		| _opt_libs_BearSSL_src_symcipher_des_tab_c_S2[((r0 >> 23) ^ (skl >> 12)) & 0x3F]
		| _opt_libs_BearSSL_src_symcipher_des_tab_c_S3[((r0 >> 19) ^ (skl >>  6)) & 0x3F]
		| _opt_libs_BearSSL_src_symcipher_des_tab_c_S4[((r0 >> 15) ^ (skl      )) & 0x3F]
		| _opt_libs_BearSSL_src_symcipher_des_tab_c_S5[((r0 >> 11) ^ (skr >> 18)) & 0x3F]
		| _opt_libs_BearSSL_src_symcipher_des_tab_c_S6[((r0 >>  7) ^ (skr >> 12)) & 0x3F]
		| _opt_libs_BearSSL_src_symcipher_des_tab_c_S7[((r0 >>  3) ^ (skr >>  6)) & 0x3F]
		| _opt_libs_BearSSL_src_symcipher_des_tab_c_S8[((r1 >> 15) ^ (skr      )) & 0x3F];
}

 inline  void
_opt_libs_BearSSL_src_symcipher_des_tab_c_process_block_unit(uint32_t *pl, uint32_t *pr, const uint32_t *skey)
{
	int i;
	uint32_t l, r;

	l = *pl;
	r = *pr;
	for (i = 0; i < 16; i ++) {
		uint32_t t;

		t = l ^ _opt_libs_BearSSL_src_symcipher_des_tab_c_Fconf(r, skey[(i << 1) + 0], skey[(i << 1) + 1]);
		l = r;
		r = t;
	}
	*pl = r;
	*pr = l;
}

/* see inner.h */
 inline void
br_des_tab_process_block(unsigned num_rounds, const uint32_t *skey, void *block)
{
	unsigned char *buf;
	uint32_t l, r;

	buf = block;
	l = br_dec32be(buf);
	r = br_dec32be(buf + 4);
	br_des_do_IP(&l, &r);
	while (num_rounds -- > 0) {
		_opt_libs_BearSSL_src_symcipher_des_tab_c_process_block_unit(&l, &r, skey);
		skey += 32;
	}
	br_des_do_invIP(&l, &r);
	br_enc32be(buf, l);
	br_enc32be(buf + 4, r);
}

 inline  void
_opt_libs_BearSSL_src_symcipher_des_tab_c_keysched_unit(uint32_t *skey, const void *key)
{
	int i;

	br_des_keysched_unit(skey, key);

	/*
	 * Apply PC-2 to get the 48-bit subkeys.
	 */
	for (i = 0; i < 16; i ++) {
		uint32_t xl, xr, ul, ur;
		int j;

		xl = skey[(i << 1) + 0];
		xr = skey[(i << 1) + 1];
		ul = 0;
		ur = 0;
		for (j = 0; j < 28; j ++) {
			ul |= (xl & 1) << _opt_libs_BearSSL_src_symcipher_des_tab_c_PC2left[j];
			ur |= (xr & 1) << _opt_libs_BearSSL_src_symcipher_des_tab_c_PC2right[j];
			xl >>= 1;
			xr >>= 1;
		}
		skey[(i << 1) + 0] = ul;
		skey[(i << 1) + 1] = ur;
	}
}

/* see inner.h */
 inline unsigned
br_des_tab_keysched(uint32_t *skey, const void *key, size_t key_len)
{
	switch (key_len) {
	case 8:
		_opt_libs_BearSSL_src_symcipher_des_tab_c_keysched_unit(skey, key);
		return 1;
	case 16:
		_opt_libs_BearSSL_src_symcipher_des_tab_c_keysched_unit(skey, key);
		_opt_libs_BearSSL_src_symcipher_des_tab_c_keysched_unit(skey + 32, (const unsigned char *)key + 8);
		br_des_rev_skey(skey + 32);
		memcpy(skey + 64, skey, 32 * sizeof *skey);
		return 3;
	default:
		_opt_libs_BearSSL_src_symcipher_des_tab_c_keysched_unit(skey, key);
		_opt_libs_BearSSL_src_symcipher_des_tab_c_keysched_unit(skey + 32, (const unsigned char *)key + 8);
		br_des_rev_skey(skey + 32);
		_opt_libs_BearSSL_src_symcipher_des_tab_c_keysched_unit(skey + 64, (const unsigned char *)key + 16);
		return 3;
	}
}
#endif
