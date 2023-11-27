#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

/* Define the number of fractional bits. 
   In a 17.14 fixed-point representation, there are 14 fractional bits. */
#define FRACTIONAL_BITS 14

/* The factor to be used for conversions, which is 2 raised to the power of FRACTIONAL_BITS */
#define F (1 << FRACTIONAL_BITS)

/* Convert an integer to fixed-point representation */
static inline int int_to_fixed_point(int n) {
    return n * F;
}

/* Convert fixed-point to integer (rounding toward zero) */
static inline int fixed_point_to_int_round_zero(int x) {
    return x / F;
}

/* Convert fixed-point to integer (rounding to nearest) */
static inline int fixed_point_to_int_round_nearest(int x) {
    if (x >= 0) {
        return (x + F / 2) / F;
    } else {
        return (x - F / 2) / F;
    }
}

/* Add two fixed-point numbers */
static inline int add_to_fixed_points(int x, int y) {
    return x + y;
}
/* add a fixed-point number and an integer*/
static inline int add_to_fixed_point(int x, int n) {
    return x + n * F;
}

/* Subtract two fixed-point numbers */
static inline int subtract_fixed_points(int x, int y) {
    return x - y;
}

/* Add a fixed-point number and an integer */
static inline int add_fixed_point_and_int(int x, int n) {
    return x + int_to_fixed_point(n);
}
/* Subtract an integer from a fixed-point number */
static inline int subtract_int_from_fixed_point(int x, int n) {
    return x - int_to_fixed_point(n);
}

/* Multiply two fixed-point numbers */
static inline int multiply_fixed_points(int x, int y) {
    return ((int64_t) x) * y / F;
}

/* Multiply a fixed-point number by an integer */
static inline int multiply_fixed_point_by_int(int x, int n) {
    return x * n;
}

/* Divide two fixed-point numbers */
static inline int divide_fixed_points(int x, int y) {
    return ((int64_t) x) * F / y;
}

/* Divide a fixed-point number by an integer */
static inline int divide_fixed_point_by_int(int x, int n) {
    return x / n;
}

/* Convert fixed-point to integer (rounding to nearest) */
static inline int convert_to_integer_round_nearest(int x) {
    return x >= 0 ? (x + F / 2) / F : (x - F / 2) / F;
}



#endif /* FIXED_POINT_H */