#ifndef BEARSSL_IMPL_EC_EC_PRIME_I31_HPP
#define BEARSSL_IMPL_EC_EC_PRIME_I31_HPP

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
 * Parameters for supported curves (field modulus, and 'b' equation
 * parameter; both values use the 'i31' format, and 'b' is in Montgomery
 * representation).
 */

 inline static const uint32_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P256_P[] = {
	0x00000108,
	0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x00000007,
	0x00000000, 0x00000000, 0x00000040, 0x7FFFFF80,
	0x000000FF
};

 inline static const uint32_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P256_R2[] = {
	0x00000108,
	0x00014000, 0x00018000, 0x00000000, 0x7FF40000,
	0x7FEFFFFF, 0x7FF7FFFF, 0x7FAFFFFF, 0x005FFFFF,
	0x00000000
};

 inline static const uint32_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P256_B[] = {
	0x00000108,
	0x6FEE1803, 0x6229C4BD, 0x21B139BE, 0x327150AA,
	0x3567802E, 0x3F7212ED, 0x012E4355, 0x782DD38D,
	0x0000000E
};

 inline static const uint32_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P384_P[] = {
	0x0000018C,
	0x7FFFFFFF, 0x00000001, 0x00000000, 0x7FFFFFF8,
	0x7FFFFFEF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF,
	0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF,
	0x00000FFF
};

 inline static const uint32_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P384_R2[] = {
	0x0000018C,
	0x00000000, 0x00000080, 0x7FFFFE00, 0x000001FF,
	0x00000800, 0x00000000, 0x7FFFE000, 0x00001FFF,
	0x00008000, 0x00008000, 0x00000000, 0x00000000,
	0x00000000
};

 inline static const uint32_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P384_B[] = {
	0x0000018C,
	0x6E666840, 0x070D0392, 0x5D810231, 0x7651D50C,
	0x17E218D6, 0x1B192002, 0x44EFE441, 0x3A524E2B,
	0x2719BA5F, 0x41F02209, 0x36C5643E, 0x5813EFFE,
	0x000008A5
};

 inline static const uint32_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P521_P[] = {
	0x00000219,
	0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF,
	0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF,
	0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF,
	0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF,
	0x01FFFFFF
};

 inline static const uint32_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P521_R2[] = {
	0x00000219,
	0x00001000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000
};

 inline static const uint32_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P521_B[] = {
	0x00000219,
	0x540FC00A, 0x228FEA35, 0x2C34F1EF, 0x67BF107A,
	0x46FC1CD5, 0x1605E9DD, 0x6937B165, 0x272A3D8F,
	0x42785586, 0x44C8C778, 0x15F3B8B4, 0x64B73366,
	0x03BA8B69, 0x0D05B42A, 0x21F929A2, 0x2C31C393,
	0x00654FAE
};

typedef struct {
	const uint32_t *p;
	const uint32_t *b;
	const uint32_t *R2;
	uint32_t p0i;
} _opt_libs_BearSSL_src_ec_ec_prime_i31_c_curve_params;

 inline const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_curve_params *
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_id_to_curve(int curve)
{
	static const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_curve_params pp[] = {
		{ _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P256_P, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P256_B, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P256_R2, 0x00000001 },
		{ _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P384_P, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P384_B, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P384_R2, 0x00000001 },
		{ _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P521_P, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P521_B, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P521_R2, 0x00000001 }
	};

	return &pp[curve - BR_EC_secp256r1];
}

#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_I31_LEN   ((BR_MAX_EC_SIZE + 61) / 31)

/*
 * Type for a point in Jacobian coordinates:
 * -- three values, x, y and z, in Montgomery representation
 * -- affine coordinates are X = x / z^2 and Y = y / z^3
 * -- for the point at infinity, z = 0
 */
typedef struct {
	uint32_t c[3][_opt_libs_BearSSL_src_ec_ec_prime_i31_c_I31_LEN];
} _opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian;

/*
 * We use a custom interpreter that uses a dozen registers, and
 * only six operations:
 *    _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSET(d, a)       copy a into d
 *    _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MADD(d, a)       d = d+a (modular)
 *    _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(d, a)       d = d-a (modular)
 *    _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(d, a, b)    d = a*b (Montgomery multiplication)
 *    _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MINV(d, a, b)    invert d modulo p; a and b are used as scratch registers
 *    _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MTZ(d)           clear return value if d = 0
 * Destination of _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL (d) must be distinct from operands (a and b).
 * There is no such constraint for _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB and _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MADD.
 *
 * Registers include the operand coordinates, and temporaries.
 */
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSET(d, a)      (0x0000 + ((d) << 8) + ((a) << 4))
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MADD(d, a)      (0x1000 + ((d) << 8) + ((a) << 4))
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(d, a)      (0x2000 + ((d) << 8) + ((a) << 4))
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(d, a, b)   (0x3000 + ((d) << 8) + ((a) << 4) + (b))
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MINV(d, a, b)   (0x4000 + ((d) << 8) + ((a) << 4) + (b))
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_MTZ(d)          (0x5000 + ((d) << 8))
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_ENDCODE         0

/*
 * Registers for the input operands.
 */
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x    0
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1y    1
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1z    2
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2x    3
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2y    4
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2z    5

/*
 * Alternate names for the first input operand.
 */
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Px     0
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Py     1
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Pz     2

/*
 * Temporaries.
 */
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1     6
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2     7
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3     8
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4     9
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t5    10
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t6    11
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t7    12

/*
 * Extra scratch registers available when there is no second operand (e.g.
 * for "double" and "affine").
 */
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t8     3
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t9     4
#define _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t10    5

/*
 * Doubling formulas are:
 *
 *   s = 4*x*y^2
 *   m = 3*(x + z^2)*(x - z^2)
 *   x' = m^2 - 2*s
 *   y' = m*(s - x') - 8*y^4
 *   z' = 2*y*z
 *
 * If y = 0 (P has order 2) then this yields infinity (z' = 0), as it
 * should. This case should not happen anyway, because our curves have
 * prime order, and thus do not contain any point of order 2.
 *
 * If P is infinity (z = 0), then again the formulas yield infinity,
 * which is correct. Thus, this code works for all points.
 *
 * Cost: 8 multiplications
 */
 inline static const uint16_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_code_double[] = {
	/*
	 * Compute z^2 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1).
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Pz, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Pz),

	/*
	 * Compute x-z^2 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2) and then x+z^2 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1).
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSET(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Px),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MADD(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Px),

	/*
	 * Compute m = 3*(x+z^2)*(x-z^2) (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1).
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSET(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MADD(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MADD(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3),

	/*
	 * Compute s = 4*x*y^2 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2) and 2*y^2 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3).
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Py, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Py),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MADD(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Px, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MADD(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2),

	/*
	 * Compute x' = m^2 - 2*s.
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_Px, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_Px, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_Px, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2),

	/*
	 * Compute z' = 2*y*z.
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Py, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Pz),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSET(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_Pz, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MADD(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_Pz, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4),

	/*
	 * Compute y' = m*(s - x') - 8*y^4. Note that we already have
	 * 2*y^2 in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3.
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_Px),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_Py, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_Py, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_Py, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4),

	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_ENDCODE
};

/*
 * Addtions formulas are:
 *
 *   u1 = x1 * z2^2
 *   u2 = x2 * z1^2
 *   s1 = y1 * z2^3
 *   s2 = y2 * z1^3
 *   h = u2 - u1
 *   r = s2 - s1
 *   x3 = r^2 - h^3 - 2 * u1 * h^2
 *   y3 = r * (u1 * h^2 - x3) - s1 * h^3
 *   z3 = h * z1 * z2
 *
 * If both P1 and P2 are infinity, then z1 == 0 and z2 == 0, implying that
 * z3 == 0, so the result is correct.
 * If either of P1 or P2 is infinity, but not both, then z3 == 0, which is
 * not correct.
 * h == 0 only if u1 == u2; this happens in two cases:
 * -- if s1 == s2 then P1 and/or P2 is infinity, or P1 == P2
 * -- if s1 != s2 then P1 + P2 == infinity (but neither P1 or P2 is infinity)
 *
 * Thus, the following situations are not handled correctly:
 * -- P1 = 0 and P2 != 0
 * -- P1 != 0 and P2 = 0
 * -- P1 = P2
 * All other cases are properly computed. However, even in "incorrect"
 * situations, the three coordinates still are properly formed field
 * elements.
 *
 * The returned flag is cleared if r == 0. This happens in the following
 * cases:
 * -- Both points are on the same horizontal line (same Y coordinate).
 * -- Both points are infinity.
 * -- One point is infinity and the other is on line Y = 0.
 * The third case cannot happen with our curves (there is no valid point
 * on line Y = 0 since that would be a point of order 2). If the two
 * source points are non-infinity, then remains only the case where the
 * two points are on the same horizontal line.
 *
 * This allows us to detect the "P1 == P2" case, assuming that P1 != 0 and
 * P2 != 0:
 * -- If the returned value is not the point at infinity, then it was properly
 * computed.
 * -- Otherwise, if the returned flag is 1, then P1+P2 = 0, and the result
 * is indeed the point at infinity.
 * -- Otherwise (result is infinity, flag is 0), then P1 = P2 and we should
 * use the 'double' code.
 *
 * Cost: 16 multiplications
 */
 inline static const uint16_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_code_add[] = {
	/*
	 * Compute u1 = x1*z2^2 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1) and s1 = y1*z2^3 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3).
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2z, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2z),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2z, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1y, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4),

	/*
	 * Compute u2 = x2*z1^2 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2) and s2 = y2*z1^3 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4).
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1z, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1z),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t5, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1z, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2y, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t5),

	/*
	 * Compute h = u2 - u1 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2) and r = s2 - s1 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4).
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3),

	/*
	 * Report cases where r = 0 through the returned flag.
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MTZ(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4),

	/*
	 * Compute u1*h^2 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t6) and h^3 (in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t5).
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t7, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t6, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t7),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t5, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t7, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2),

	/*
	 * Compute x3 = r^2 - h^3 - 2*u1*h^2.
	 * _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1 and _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t7 can be used as scratch registers.
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t5),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t6),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t6),

	/*
	 * Compute y3 = r*(u1*h^2 - x3) - s1*h^3.
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t6, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1y, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t6),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t5, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1y, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1),

	/*
	 * Compute z3 = h*z1*z2.
	 */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1z, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2z),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1z, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2),

	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_ENDCODE
};

/*
 * Check that the point is on the curve. This code snippet assumes the
 * following conventions:
 * -- Coordinates x and y have been freshly decoded in P1 (but not
 * converted to Montgomery coordinates yet).
 * -- _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2y and _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2z are set to, respectively, R^2, b*R and 1.
 */
 inline static const uint16_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_code_check[] = {

	/* Convert x and y to Montgomery representation. */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2x),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1y, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2x),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSET(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSET(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1y, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2),

	/* Compute x^3 in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1. */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2),

	/* Subtract 3*x from _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1. */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x),

	/* Add b. */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MADD(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2y),

	/* Compute y^2 in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2. */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1y, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1y),

	/* Compare y^2 with x^3 - 3*x + b; they must match. */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSUB(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MTZ(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1),

	/* Set z to 1 (in Montgomery representation). */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1z, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2z),

	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_ENDCODE
};

/*
 * Conversion back to affine coordinates. This code snippet assumes that
 * the z coordinate of P2 is set to 1 (not in Montgomery representation).
 */
 inline static const uint16_t _opt_libs_BearSSL_src_ec_ec_prime_i31_c_code_affine[] = {

	/* Save z*R in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1. */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSET(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1z),

	/* Compute z^3 in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2. */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1z, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1z),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1z, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2z),

	/* Invert to (1/z^3) in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2. */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MINV(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t4),

	/* Compute y. */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSET(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1y),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1y, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3),

	/* Compute (1/z^2) in _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3. */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t1),

	/* Compute x. */
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MSET(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x),
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_MMUL(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t2, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_t3),

	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_ENDCODE
};

 inline  uint32_t
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_run_code(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian *P1, const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian *P2,
	const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_curve_params *cc, const uint16_t *code)
{
	uint32_t r;
	uint32_t t[13][_opt_libs_BearSSL_src_ec_ec_prime_i31_c_I31_LEN];
	size_t u;

	r = 1;

	/*
	 * Copy the two operands in the dedicated registers.
	 */
	memcpy(t[_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x], P1->c, 3 * _opt_libs_BearSSL_src_ec_ec_prime_i31_c_I31_LEN * sizeof(uint32_t));
	memcpy(t[_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P2x], P2->c, 3 * _opt_libs_BearSSL_src_ec_ec_prime_i31_c_I31_LEN * sizeof(uint32_t));

	/*
	 * Run formulas.
	 */
	for (u = 0;; u ++) {
		unsigned op, d, a, b;

		op = code[u];
		if (op == 0) {
			break;
		}
		d = (op >> 8) & 0x0F;
		a = (op >> 4) & 0x0F;
		b = op & 0x0F;
		op >>= 12;
		switch (op) {
			uint32_t ctl;
			size_t plen;
			unsigned char tp[(BR_MAX_EC_SIZE + 7) >> 3];

		case 0:
			memcpy(t[d], t[a], _opt_libs_BearSSL_src_ec_ec_prime_i31_c_I31_LEN * sizeof(uint32_t));
			break;
		case 1:
			ctl = br_i31_add(t[d], t[a], 1);
			ctl |= NOT(br_i31_sub(t[d], cc->p, 0));
			br_i31_sub(t[d], cc->p, ctl);
			break;
		case 2:
			br_i31_add(t[d], cc->p, br_i31_sub(t[d], t[a], 1));
			break;
		case 3:
			br_i31_montymul(t[d], t[a], t[b], cc->p, cc->p0i);
			break;
		case 4:
			plen = (cc->p[0] - (cc->p[0] >> 5) + 7) >> 3;
			br_i31_encode(tp, plen, cc->p);
			tp[plen - 1] -= 2;
			br_i31_modpow(t[d], tp, plen,
				cc->p, cc->p0i, t[a], t[b]);
			break;
		default:
			r &= ~br_i31_iszero(t[d]);
			break;
		}
	}

	/*
	 * Copy back result.
	 */
	memcpy(P1->c, t[_opt_libs_BearSSL_src_ec_ec_prime_i31_c_P1x], 3 * _opt_libs_BearSSL_src_ec_ec_prime_i31_c_I31_LEN * sizeof(uint32_t));
	return r;
}

 inline  void
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_set_one(uint32_t *x, const uint32_t *p)
{
	size_t plen;

	plen = (p[0] + 63) >> 5;
	memset(x, 0, plen * sizeof *x);
	x[0] = p[0];
	x[1] = 0x00000001;
}

 inline  void
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_zero(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian *P, const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_curve_params *cc)
{
	memset(P, 0, sizeof *P);
	P->c[0][0] = P->c[1][0] = P->c[2][0] = cc->p[0];
}

 inline void
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_double(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian *P, const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_curve_params *cc)
{
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_run_code(P, P, cc, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_code_double);
}

 inline uint32_t
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_add(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian *P1, const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian *P2, const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_curve_params *cc)
{
	return _opt_libs_BearSSL_src_ec_ec_prime_i31_c_run_code(P1, P2, cc, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_code_add);
}

 inline  void
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_mul(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian *P, const unsigned char *x, size_t xlen,
	const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_curve_params *cc)
{
	/*
	 * We do a simple double-and-add ladder with a 2-bit window
	 * to make only one add every two doublings. We thus first
	 * precompute 2P and 3P in some local buffers.
	 *
	 * We always perform two doublings and one addition; the
	 * addition is with P, 2P and 3P and is done in a temporary
	 * array.
	 *
	 * The addition code cannot handle cases where one of the
	 * operands is infinity, which is the case at the start of the
	 * ladder. We therefore need to maintain a flag that controls
	 * this situation.
	 */
	uint32_t qz;
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian P2, P3, Q, T, U;

	memcpy(&P2, P, sizeof P2);
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_double(&P2, cc);
	memcpy(&P3, P, sizeof P3);
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_add(&P3, &P2, cc);

	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_zero(&Q, cc);
	qz = 1;
	while (xlen -- > 0) {
		int k;

		for (k = 6; k >= 0; k -= 2) {
			uint32_t bits;
			uint32_t bnz;

			_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_double(&Q, cc);
			_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_double(&Q, cc);
			memcpy(&T, P, sizeof T);
			memcpy(&U, &Q, sizeof U);
			bits = (*x >> k) & (uint32_t)3;
			bnz = NEQ(bits, 0);
			CCOPY(EQ(bits, 2), &T, &P2, sizeof T);
			CCOPY(EQ(bits, 3), &T, &P3, sizeof T);
			_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_add(&U, &T, cc);
			CCOPY(bnz & qz, &Q, &T, sizeof Q);
			CCOPY(bnz & ~qz, &Q, &U, sizeof Q);
			qz &= ~bnz;
		}
		x ++;
	}
	memcpy(P, &Q, sizeof Q);
}

/*
 * Decode point into Jacobian coordinates. This function does not support
 * the point at infinity. If the point is invalid then this returns 0, but
 * the coordinates are still set to properly formed field elements.
 */
 inline  uint32_t
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_decode(_opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian *P, const void *src, size_t len, const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_curve_params *cc)
{
	/*
	 * Points must use uncompressed format:
	 * -- first byte is 0x04;
	 * -- coordinates X and Y use unsigned big-endian, with the same
	 *    length as the field modulus.
	 *
	 * We don't support hybrid format (uncompressed, but first byte
	 * has value 0x06 or 0x07, depending on the least significant bit
	 * of Y) because it is rather useless, and explicitly forbidden
	 * by PKIX (RFC 5480, section 2.2).
	 *
	 * We don't support compressed format either, because it is not
	 * much used in practice (there are or were patent-related
	 * concerns about point compression, which explains the lack of
	 * generalised support). Also, point compression support would
	 * need a bit more code.
	 */
	const unsigned char *buf;
	size_t plen, zlen;
	uint32_t r;
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian Q;

	buf = src;
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_zero(P, cc);
	plen = (cc->p[0] - (cc->p[0] >> 5) + 7) >> 3;
	if (len != 1 + (plen << 1)) {
		return 0;
	}
	r = br_i31_decode_mod(P->c[0], buf + 1, plen, cc->p);
	r &= br_i31_decode_mod(P->c[1], buf + 1 + plen, plen, cc->p);

	/*
	 * Check first byte.
	 */
	r &= EQ(buf[0], 0x04);
	/* obsolete
	r &= EQ(buf[0], 0x04) | (EQ(buf[0] & 0xFE, 0x06)
		& ~(uint32_t)(buf[0] ^ buf[plen << 1]));
	*/

	/*
	 * Convert coordinates and check that the point is valid.
	 */
	zlen = ((cc->p[0] + 63) >> 5) * sizeof(uint32_t);
	memcpy(Q.c[0], cc->R2, zlen);
	memcpy(Q.c[1], cc->b, zlen);
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_set_one(Q.c[2], cc->p);
	r &= ~_opt_libs_BearSSL_src_ec_ec_prime_i31_c_run_code(P, &Q, cc, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_code_check);
	return r;
}

/*
 * Encode a point. This method assumes that the point is correct and is
 * not the point at infinity. Encoded size is always 1+2*plen, where
 * plen is the field modulus length, in bytes.
 */
 inline  void
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_encode(void *dst, const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian *P, const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_curve_params *cc)
{
	unsigned char *buf;
	uint32_t xbl;
	size_t plen;
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian Q, T;

	buf = dst;
	xbl = cc->p[0];
	xbl -= (xbl >> 5);
	plen = (xbl + 7) >> 3;
	buf[0] = 0x04;
	memcpy(&Q, P, sizeof *P);
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_set_one(T.c[2], cc->p);
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_run_code(&Q, &T, cc, _opt_libs_BearSSL_src_ec_ec_prime_i31_c_code_affine);
	br_i31_encode(buf + 1, plen, Q.c[0]);
	br_i31_encode(buf + 1 + plen, plen, Q.c[1]);
}

 inline  const br_ec_curve_def *
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_id_to_curve_def(int curve)
{
	switch (curve) {
	case BR_EC_secp256r1:
		return &br_secp256r1;
	case BR_EC_secp384r1:
		return &br_secp384r1;
	case BR_EC_secp521r1:
		return &br_secp521r1;
	}
	return NULL;
}

 inline  const unsigned char *
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_generator(int curve, size_t *len)
{
	const br_ec_curve_def *cd;

	cd = _opt_libs_BearSSL_src_ec_ec_prime_i31_c_id_to_curve_def(curve);
	*len = cd->generator_len;
	return cd->generator;
}

 inline  const unsigned char *
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_order(int curve, size_t *len)
{
	const br_ec_curve_def *cd;

	cd = _opt_libs_BearSSL_src_ec_ec_prime_i31_c_id_to_curve_def(curve);
	*len = cd->order_len;
	return cd->order;
}

 inline  size_t
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_xoff(int curve, size_t *len)
{
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_generator(curve, len);
	*len >>= 1;
	return 1;
}

 inline  uint32_t
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_mul(unsigned char *G, size_t Glen,
	const unsigned char *x, size_t xlen, int curve)
{
	uint32_t r;
	const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_curve_params *cc;
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian P;

	cc = _opt_libs_BearSSL_src_ec_ec_prime_i31_c_id_to_curve(curve);
	r = _opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_decode(&P, G, Glen, cc);
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_mul(&P, x, xlen, cc);
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_encode(G, &P, cc);
	return r;
}

 inline  size_t
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_mulgen(unsigned char *R,
	const unsigned char *x, size_t xlen, int curve)
{
	const unsigned char *G;
	size_t Glen;

	G = _opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_generator(curve, &Glen);
	memcpy(R, G, Glen);
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_mul(R, Glen, x, xlen, curve);
	return Glen;
}

 inline  uint32_t
_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_muladd(unsigned char *A, const unsigned char *B, size_t len,
	const unsigned char *x, size_t xlen,
	const unsigned char *y, size_t ylen, int curve)
{
	uint32_t r, t, z;
	const _opt_libs_BearSSL_src_ec_ec_prime_i31_c_curve_params *cc;
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_jacobian P, Q;

	/*
	 * TODO: see about merging the two ladders. Right now, we do
	 * two independant point multiplications, which is a bit
	 * wasteful of CPU resources (but yields short code).
	 */

	cc = _opt_libs_BearSSL_src_ec_ec_prime_i31_c_id_to_curve(curve);
	r = _opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_decode(&P, A, len, cc);
	if (B == NULL) {
		size_t Glen;

		B = _opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_generator(curve, &Glen);
	}
	r &= _opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_decode(&Q, B, len, cc);
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_mul(&P, x, xlen, cc);
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_mul(&Q, y, ylen, cc);

	/*
	 * We want to compute P+Q. Since the base points A and B are distinct
	 * from infinity, and the multipliers are non-zero and lower than the
	 * curve order, then we know that P and Q are non-infinity. This
	 * leaves two special situations to test for:
	 * -- If P = Q then we must use _opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_double().
	 * -- If P+Q = 0 then we must report an error.
	 */
	t = _opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_add(&P, &Q, cc);
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_double(&Q, cc);
	z = br_i31_iszero(P.c[2]);

	/*
	 * If z is 1 then either P+Q = 0 (t = 1) or P = Q (t = 0). So we
	 * have the following:
	 *
	 *   z = 0, t = 0   return P (normal addition)
	 *   z = 0, t = 1   return P (normal addition)
	 *   z = 1, t = 0   return Q (a 'double' case)
	 *   z = 1, t = 1   report an error (P+Q = 0)
	 */
	CCOPY(z & ~t, &P, &Q, sizeof Q);
	_opt_libs_BearSSL_src_ec_ec_prime_i31_c_point_encode(A, &P, cc);
	r &= ~(z & t);

	return r;
}

/* see bearssl_ec.h */
 inline const br_ec_impl br_ec_prime_i31 = {
	(uint32_t)0x03800000,
	&_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_generator,
	&_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_order,
	&_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_xoff,
	&_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_mul,
	&_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_mulgen,
	&_opt_libs_BearSSL_src_ec_ec_prime_i31_c_api_muladd
};
#endif
