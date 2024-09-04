#ifndef BEARSSL_IMPL_SYMCIPHER_AES_BIG_DEC_HPP
#define BEARSSL_IMPL_SYMCIPHER_AES_BIG_DEC_HPP

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
 * Inverse S-box (used in key schedule for decryption).
 */
 inline static const unsigned char _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[] = {
	0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E,
	0x81, 0xF3, 0xD7, 0xFB, 0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87,
	0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB, 0x54, 0x7B, 0x94, 0x32,
	0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
	0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49,
	0x6D, 0x8B, 0xD1, 0x25, 0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16,
	0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92, 0x6C, 0x70, 0x48, 0x50,
	0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
	0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05,
	0xB8, 0xB3, 0x45, 0x06, 0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02,
	0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B, 0x3A, 0x91, 0x11, 0x41,
	0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
	0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8,
	0x1C, 0x75, 0xDF, 0x6E, 0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89,
	0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B, 0xFC, 0x56, 0x3E, 0x4B,
	0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
	0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59,
	0x27, 0x80, 0xEC, 0x5F, 0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D,
	0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF, 0xA0, 0xE0, 0x3B, 0x4D,
	0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
	0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63,
	0x55, 0x21, 0x0C, 0x7D
};

 inline static const uint32_t _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSsm0[] = {
	0x51F4A750, 0x7E416553, 0x1A17A4C3, 0x3A275E96, 0x3BAB6BCB, 0x1F9D45F1,
	0xACFA58AB, 0x4BE30393, 0x2030FA55, 0xAD766DF6, 0x88CC7691, 0xF5024C25,
	0x4FE5D7FC, 0xC52ACBD7, 0x26354480, 0xB562A38F, 0xDEB15A49, 0x25BA1B67,
	0x45EA0E98, 0x5DFEC0E1, 0xC32F7502, 0x814CF012, 0x8D4697A3, 0x6BD3F9C6,
	0x038F5FE7, 0x15929C95, 0xBF6D7AEB, 0x955259DA, 0xD4BE832D, 0x587421D3,
	0x49E06929, 0x8EC9C844, 0x75C2896A, 0xF48E7978, 0x99583E6B, 0x27B971DD,
	0xBEE14FB6, 0xF088AD17, 0xC920AC66, 0x7DCE3AB4, 0x63DF4A18, 0xE51A3182,
	0x97513360, 0x62537F45, 0xB16477E0, 0xBB6BAE84, 0xFE81A01C, 0xF9082B94,
	0x70486858, 0x8F45FD19, 0x94DE6C87, 0x527BF8B7, 0xAB73D323, 0x724B02E2,
	0xE31F8F57, 0x6655AB2A, 0xB2EB2807, 0x2FB5C203, 0x86C57B9A, 0xD33708A5,
	0x302887F2, 0x23BFA5B2, 0x02036ABA, 0xED16825C, 0x8ACF1C2B, 0xA779B492,
	0xF307F2F0, 0x4E69E2A1, 0x65DAF4CD, 0x0605BED5, 0xD134621F, 0xC4A6FE8A,
	0x342E539D, 0xA2F355A0, 0x058AE132, 0xA4F6EB75, 0x0B83EC39, 0x4060EFAA,
	0x5E719F06, 0xBD6E1051, 0x3E218AF9, 0x96DD063D, 0xDD3E05AE, 0x4DE6BD46,
	0x91548DB5, 0x71C45D05, 0x0406D46F, 0x605015FF, 0x1998FB24, 0xD6BDE997,
	0x894043CC, 0x67D99E77, 0xB0E842BD, 0x07898B88, 0xE7195B38, 0x79C8EEDB,
	0xA17C0A47, 0x7C420FE9, 0xF8841EC9, 0x00000000, 0x09808683, 0x322BED48,
	0x1E1170AC, 0x6C5A724E, 0xFD0EFFFB, 0x0F853856, 0x3DAED51E, 0x362D3927,
	0x0A0FD964, 0x685CA621, 0x9B5B54D1, 0x24362E3A, 0x0C0A67B1, 0x9357E70F,
	0xB4EE96D2, 0x1B9B919E, 0x80C0C54F, 0x61DC20A2, 0x5A774B69, 0x1C121A16,
	0xE293BA0A, 0xC0A02AE5, 0x3C22E043, 0x121B171D, 0x0E090D0B, 0xF28BC7AD,
	0x2DB6A8B9, 0x141EA9C8, 0x57F11985, 0xAF75074C, 0xEE99DDBB, 0xA37F60FD,
	0xF701269F, 0x5C72F5BC, 0x44663BC5, 0x5BFB7E34, 0x8B432976, 0xCB23C6DC,
	0xB6EDFC68, 0xB8E4F163, 0xD731DCCA, 0x42638510, 0x13972240, 0x84C61120,
	0x854A247D, 0xD2BB3DF8, 0xAEF93211, 0xC729A16D, 0x1D9E2F4B, 0xDCB230F3,
	0x0D8652EC, 0x77C1E3D0, 0x2BB3166C, 0xA970B999, 0x119448FA, 0x47E96422,
	0xA8FC8CC4, 0xA0F03F1A, 0x567D2CD8, 0x223390EF, 0x87494EC7, 0xD938D1C1,
	0x8CCAA2FE, 0x98D40B36, 0xA6F581CF, 0xA57ADE28, 0xDAB78E26, 0x3FADBFA4,
	0x2C3A9DE4, 0x5078920D, 0x6A5FCC9B, 0x547E4662, 0xF68D13C2, 0x90D8B8E8,
	0x2E39F75E, 0x82C3AFF5, 0x9F5D80BE, 0x69D0937C, 0x6FD52DA9, 0xCF2512B3,
	0xC8AC993B, 0x10187DA7, 0xE89C636E, 0xDB3BBB7B, 0xCD267809, 0x6E5918F4,
	0xEC9AB701, 0x834F9AA8, 0xE6956E65, 0xAAFFE67E, 0x21BCCF08, 0xEF15E8E6,
	0xBAE79BD9, 0x4A6F36CE, 0xEA9F09D4, 0x29B07CD6, 0x31A4B2AF, 0x2A3F2331,
	0xC6A59430, 0x35A266C0, 0x744EBC37, 0xFC82CAA6, 0xE090D0B0, 0x33A7D815,
	0xF104984A, 0x41ECDAF7, 0x7FCD500E, 0x1791F62F, 0x764DD68D, 0x43EFB04D,
	0xCCAA4D54, 0xE49604DF, 0x9ED1B5E3, 0x4C6A881B, 0xC12C1FB8, 0x4665517F,
	0x9D5EEA04, 0x018C355D, 0xFA877473, 0xFB0B412E, 0xB3671D5A, 0x92DBD252,
	0xE9105633, 0x6DD64713, 0x9AD7618C, 0x37A10C7A, 0x59F8148E, 0xEB133C89,
	0xCEA927EE, 0xB761C935, 0xE11CE5ED, 0x7A47B13C, 0x9CD2DF59, 0x55F2733F,
	0x1814CE79, 0x73C737BF, 0x53F7CDEA, 0x5FFDAA5B, 0xDF3D6F14, 0x7844DB86,
	0xCAAFF381, 0xB968C43E, 0x3824342C, 0xC2A3405F, 0x161DC372, 0xBCE2250C,
	0x283C498B, 0xFF0D9541, 0x39A80171, 0x080CB3DE, 0xD8B4E49C, 0x6456C190,
	0x7BCB8461, 0xD532B670, 0x486C5C74, 0xD0B85742
};

 inline  unsigned
_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(unsigned x)
{
	x <<= 1;
	return x ^ ((unsigned)(-(int)(x >> 8)) & 0x11B);
}

 inline  unsigned
_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul9(unsigned x)
{
	return x ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(x)));
}

 inline  unsigned
_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mulb(unsigned x)
{
	unsigned x2;
	
	x2 = _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(x);
	return x ^ x2 ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(x2));
}

 inline  unsigned
_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_muld(unsigned x)
{
	unsigned x4;

	x4 = _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(x));
	return x ^ x4 ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(x4);
}

 inline  unsigned
_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mule(unsigned x)
{
	unsigned x2, x4;

	x2 = _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(x);
	x4 = _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(x2);
	return x2 ^ x4 ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul2(x4);
}

/* see inner.h */
 inline unsigned
br_aes_big_keysched_inv(uint32_t *skey, const void *key, size_t key_len)
{
	unsigned num_rounds;
	int i, m;

	/*
	 * Sub-keys for decryption are distinct from encryption sub-keys
	 * in that InvMixColumns() is already applied for the inner
	 * rounds.
	 */
	num_rounds = br_aes_keysched(skey, key, key_len);
	m = (int)(num_rounds << 2);
	for (i = 4; i < m; i ++) {
		uint32_t p;
		unsigned p0, p1, p2, p3;
		uint32_t q0, q1, q2, q3;

		p = skey[i];
		p0 = p >> 24;
		p1 = (p >> 16) & 0xFF;
		p2 = (p >> 8) & 0xFF;
		p3 = p & 0xFF;
		q0 = _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mule(p0) ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mulb(p1) ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_muld(p2) ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul9(p3);
		q1 = _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul9(p0) ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mule(p1) ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mulb(p2) ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_muld(p3);
		q2 = _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_muld(p0) ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul9(p1) ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mule(p2) ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mulb(p3);
		q3 = _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mulb(p0) ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_muld(p1) ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mul9(p2) ^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_mule(p3);
		skey[i] = (q0 << 24) | (q1 << 16) | (q2 << 8) | q3;
	}
	return num_rounds;
}

 inline uint32_t
_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_rotr(uint32_t x, int n)
{
	return (x << (32 - n)) | (x >> n);
}

#define _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt0(x)   (_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSsm0[x])
#define _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt1(x)   (_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_rotr(_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSsm0[x], 8))
#define _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt2(x)   (_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_rotr(_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSsm0[x], 16))
#define _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt3(x)   (_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_rotr(_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSsm0[x], 24))

/* see bearssl.h */
 inline void
br_aes_big_decrypt(unsigned num_rounds, const uint32_t *skey, void *data)
{
	unsigned char *buf;
	uint32_t s0, s1, s2, s3;
	uint32_t t0, t1, t2, t3;
	unsigned u;

	buf = data;
	s0 = br_dec32be(buf);
	s1 = br_dec32be(buf + 4);
	s2 = br_dec32be(buf + 8);
	s3 = br_dec32be(buf + 12);
	s0 ^= skey[(num_rounds << 2) + 0];
	s1 ^= skey[(num_rounds << 2) + 1];
	s2 ^= skey[(num_rounds << 2) + 2];
	s3 ^= skey[(num_rounds << 2) + 3];
	for (u = num_rounds - 1; u > 0; u --) {
		uint32_t v0 = _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt0(s0 >> 24)
			^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt1((s3 >> 16) & 0xFF)
			^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt2((s2 >> 8) & 0xFF)
			^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt3(s1 & 0xFF);
		uint32_t v1 = _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt0(s1 >> 24)
			^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt1((s0 >> 16) & 0xFF)
			^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt2((s3 >> 8) & 0xFF)
			^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt3(s2 & 0xFF);
		uint32_t v2 = _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt0(s2 >> 24)
			^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt1((s1 >> 16) & 0xFF)
			^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt2((s0 >> 8) & 0xFF)
			^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt3(s3 & 0xFF);
		uint32_t v3 = _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt0(s3 >> 24)
			^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt1((s2 >> 16) & 0xFF)
			^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt2((s1 >> 8) & 0xFF)
			^ _opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iSboxExt3(s0 & 0xFF);
		s0 = v0;
		s1 = v1;
		s2 = v2;
		s3 = v3;
		s0 ^= skey[u << 2];
		s1 ^= skey[(u << 2) + 1];
		s2 ^= skey[(u << 2) + 2];
		s3 ^= skey[(u << 2) + 3];
	}
	t0 = ((uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[s0 >> 24] << 24)
		| ((uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[(s3 >> 16) & 0xFF] << 16)
		| ((uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[(s2 >> 8) & 0xFF] << 8)
		| (uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[s1 & 0xFF];
	t1 = ((uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[s1 >> 24] << 24)
		| ((uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[(s0 >> 16) & 0xFF] << 16)
		| ((uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[(s3 >> 8) & 0xFF] << 8)
		| (uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[s2 & 0xFF];
	t2 = ((uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[s2 >> 24] << 24)
		| ((uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[(s1 >> 16) & 0xFF] << 16)
		| ((uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[(s0 >> 8) & 0xFF] << 8)
		| (uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[s3 & 0xFF];
	t3 = ((uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[s3 >> 24] << 24)
		| ((uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[(s2 >> 16) & 0xFF] << 16)
		| ((uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[(s1 >> 8) & 0xFF] << 8)
		| (uint32_t)_opt_libs_BearSSL_src_symcipher_aes_big_dec_c_iS[s0 & 0xFF];
	s0 = t0 ^ skey[0];
	s1 = t1 ^ skey[1];
	s2 = t2 ^ skey[2];
	s3 = t3 ^ skey[3];
	br_enc32be(buf, s0);
	br_enc32be(buf + 4, s1);
	br_enc32be(buf + 8, s2);
	br_enc32be(buf + 12, s3);
}
#endif
