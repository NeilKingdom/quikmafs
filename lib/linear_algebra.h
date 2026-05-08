#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

/*
    Matrix convention:
    - Row-major storage
    - Column vectors
    - Multiplication: result = M * v
    - Right-handed coordinate system
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "qm_common.h"

/*** Definitions ***/

typedef union {
    f32 v[2];
    struct {
        f32 x;
        f32 y;
    };
} Vec2_t;

typedef union {
    f32 v[3];
    struct {
        f32 x;
        f32 y;
        f32 z;
    };
} Vec3_t;

typedef union {
    f32 v[4];
    struct {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
} Vec4_t;

typedef union {
    f32 m[2][2];
    struct {
        f32 m00, m01;
        f32 m10, m11;
    };
} Mat2_t;

typedef union {
    f32 m[3][3];
    struct {
        f32 m00, m01, m02;
        f32 m10, m11, m12;
        f32 m20, m21, m22;
    };
} Mat3_t;

typedef union {
    f32 m[4][4];
    struct {
        f32 m00, m01, m02, m03;
        f32 m10, m11, m12, m13;
        f32 m20, m21, m22, m23;
        f32 m30, m31, m32, m33;
    };
} Mat4_t;

/*** Globals ***/

// Identity matrix 2x2
static const Mat2_t qm_m2_ident = { .m = {
    { 1, 0 },
    { 0, 1 }
}};

// Identity matrix 3x3
static const Mat3_t qm_m3_ident = { .m = {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 }
}};

// Identity matrix 4x4
static const Mat4_t qm_m4_ident = { .m = {
    { 1, 0, 0, 0 },
    { 0, 1, 0, 0 },
    { 0, 0, 1, 0 },
    { 0, 0, 0, 1 },
}};

// Orthogonal projection matrix
static const Mat4_t qm_m4_ortho = { .m = {
    { 1, 0, 0, 0 },
    { 0, 1, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 1 },
}};

/*** Vector Mafs ***/

/**
 * @brief Calculates the sum between two vectors of length 2.
 * @since 19-10-2023
 * @param a[in] The Augend vector
 * @param b[in] The Addend vector
 * @returns Sum Vec2_t
 */
static inline Vec2_t qm_v2_add(const Vec2_t a, const Vec2_t b) {
    return (Vec2_t){
        .x = a.x + b.x,
        .y = a.y + b.y
    };
}

/**
 * @brief Calculates the sum between two vectors of length 3.
 * @since 19-10-2023
 * @param[in] a The Augend vector
 * @param[in] b The Addend vector
 * @returns Sum Vec3_t
 */
static inline Vec3_t qm_v3_add(const Vec3_t a, const Vec3_t b) {
    return (Vec3_t){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z
    };
}

/**
 * @brief Calculates the sum between two vectors of length 4.
 * @since 19-10-2023
 * @param[in] a The Augend vector
 * @param[in] b The Addend vector
 * @returns Sum Vec4_t
 */
static inline Vec4_t qm_v4_add(const Vec4_t a, const Vec4_t b) {
    return (Vec4_t){
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z,
        .w = a.w + b.w
    };
}

/**
 * @brief Calculates the difference between two vectors of length 2.
 * @since 17-10-2023
 * @param[in] a The minuend vector
 * @param[in] b The subtrahend vector
 * @returns Difference Vec2_t
 */
static inline Vec2_t qm_v2_sub(const Vec2_t a, const Vec2_t b) {
    return (Vec2_t){
        .x = a.x - b.x,
        .y = a.y - b.y
    };
}

/**
 * @brief Calculates the difference between two vectors of length 3.
 * @since 17-10-2023
 * @param[in] a The minuend vector
 * @param[in] b The subtrahend vector
 * @returns Difference Vec3_t
 */
static inline Vec3_t qm_v3_sub(const Vec3_t a, const Vec3_t b) {
    return (Vec3_t){
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z
    };
}

/**
 * @brief Calculates the difference between two vectors of length 4.
 * @since 17-10-2023
 * @param[in] a The minuend vector
 * @param[in] b The subtrahend vector
 * @returns Difference Vec4_t
 */
static inline Vec4_t qm_v4_sub(const Vec4_t a, const Vec4_t b) {
    return (Vec4_t){
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z,
        .w = a.w - b.w
    };
}

/**
 * @brief Scales a vector of length 2 by a factor of __c__.
 * @since 19-10-2023
 * @param[in] v The vector to be scaled
 * @param[in] c A scalar constant
 * @returns Scaled Vec2_t
 */
static inline Vec2_t qm_v2_scale(const Vec2_t v, const f32 c) {
    return (Vec2_t){
        .x = v.x * c,
        .y = v.y * c
    };
}

/**
 * @brief Scales a vector of length 3 by a factor of __c__.
 * @since 19-10-2023
 * @param[in] v The vector to be scaled
 * @param[in] c A scalar constant
 * @returns Scaled Vec3_t
 */
static inline Vec3_t qm_v3_scale(const Vec3_t v, const f32 c) {
    return (Vec3_t){
        .x = v.x * c,
        .y = v.y * c,
        .z = v.z * c
    };
}

/**
 * @brief Scales a vector of length 4 by a factor of __c__.
 * @since 19-10-2023
 * @param[in] v The vector to be scaled
 * @param[in] c A scalar constant
 * @returns Scaled Vec4_t
 */
static inline Vec4_t qm_v4_scale(const Vec4_t v, const f32 c) {
    return (Vec4_t){
        .x = v.x * c,
        .y = v.y * c,
        .z = v.z * c,
        .w = v.w * c
    };
}

/**
 * @brief Calculates the dot product given two vectors of length 2.
 * @since 17-10-2023
 * @param[in] a The left-hand operand for the operation
 * @param[in] b The right-hand operand for the operation
 * @returns The dot product of a and b
 */
static inline f32 qm_v2_dot(const Vec2_t a, const Vec2_t b) {
    return (a.x * b.x) + (a.y * b.y);
}

/**
 * @brief Calculates the dot product given two vectors of length 3.
 * @since 17-10-2023
 * @param[in] a The left-hand operand for the operation
 * @param[in] b The right-hand operand for the operation
 * @returns The dot product of a and b
 */
static inline f32 qm_v3_dot(const Vec3_t a, const Vec3_t b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

/**
 * @brief Calculates the dot product given two vectors of length 4.
 * @since 17-10-2023
 * @param[in] a The left-hand operand for the operation
 * @param[in] b The right-hand operand for the operation
 * @returns The dot product of a and b
 */
static inline f32 qm_v4_dot(const Vec4_t a, const Vec4_t b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

/**
 * @brief Calculates the "cross product" given two vectors of length 2.
 * Note that this is not a real cross-product (that only applies to Vec3_t).
 * @since 17-10-2023
 * @param[in] a The left-hand operand for the operation
 * @param[in] b The right-hand operand for the operation
 * @returns A scalar value representing the magnitude of the 3D cross product's z component
 */
static inline f32 qm_v2_cross(const Vec2_t a, const Vec2_t b) {
    return (a.x * b.y) - (a.y * b.x);
}

/**
 * @brief Calculates the cross product given two vectors of length 3.
 * @since 17-10-2023
 * @param[in] a The left-hand operand for the operation
 * @param[in] b The right-hand operand for the operation
 * @returns The cross product of a and b
 */
static inline Vec3_t qm_v3_cross(const Vec3_t a, const Vec3_t b) {
    return (Vec3_t){
        .x = (a.y * b.z) - (a.z * b.y),
        .y = (a.z * b.x) - (a.x * b.z),
        .z = (a.x * b.y) - (a.y * b.x)
    };
}

/**
 * @brief Calculates the magnitude for a given vector of length 2.
 * @since 10-12-2023
 * @param[in] v The vector for which the magnitude is calculated
 * @returns The magnitude of v
 */
static inline f32 qm_v2_len(const Vec2_t v) {
    return sqrtf((v.x * v.x) + (v.y * v.y));
}

/**
 * @brief Calculates the magnitude for a given vector of length 3.
 * @since 10-12-2023
 * @param[in] v The vector for which the magnitude is calculated
 * @returns The magnitude of v
 */
static inline f32 qm_v3_len(const Vec3_t v) {
    return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

/**
 * @brief Calculates the magnitude for a given vector of length 4.
 * @since 10-12-2023
 * @param[in] v The vector for which the magnitude is calculated
 * @returns The magnitude of v
 */
static inline f32 qm_v4_len(const Vec4_t v) {
    return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

/**
 * @brief Normalize a vector of length 2.
 * @since 17-10-2023
 * @param[in] v The vector to be normalized
 * @returns The normalized vector
 */
static inline Vec2_t qm_v2_norm(const Vec2_t v) {
    f32 len = qm_v2_len(v);
    if (len > 1e-8f) {
        f32 inv_len = 1.0f / len;
        return (Vec2_t){
            .x = v.x * inv_len,
            .y = v.y * inv_len
        };
    }

    // Magnitude was already 0...
    return (Vec2_t){ 0 };
}

/**
 * @brief Normalize a vector of length 3.
 * @since 17-10-2023
 * @param[in] v The vector to be normalized
 * @returns The normalized vector
 */
static inline Vec3_t qm_v3_norm(const Vec3_t v) {
    f32 len = qm_v3_len(v);
    if (len > 1e-8f) {
        f32 inv_len = 1.0f / len;
        return (Vec3_t){
            .x = v.x * inv_len,
            .y = v.y * inv_len,
            .z = v.z * inv_len
        };
    }

    // Magnitude was already 0...
    return (Vec3_t){ 0 };
}

/**
 * @brief Normalize a vector of length 4.
 * @since 17-10-2023
 * @param[in] v The vector to be normalized
 * @returns The normalized vector
 */
static inline Vec4_t qm_v4_norm(const Vec4_t v) {
    f32 len = qm_v4_len(v);
    if (len > 1e-8f) {
        f32 inv_len = 1.0f / len;
        return (Vec4_t){
            .x = v.x * inv_len,
            .y = v.y * inv_len,
            .z = v.z * inv_len,
            .w = v.w * inv_len
        };
    }

    // Magnitude was already 0...
    return (Vec4_t){ 0 };
}

/*** Vector-Matrix Mafs ***/

/**
 * @brief Multiplies a 2x2 matrix by a vector of length 2.
 * @since 22-10-2023
 * @param[in] m The input matrix
 * @param[in] v The input vector
 * @returns Product of Vec2_t * Mat2_t
 */
static inline Vec2_t qm_m2_v2_mul(const Mat2_t m, const Vec2_t v) {
    return (Vec2_t){
        .x = (m.m00 * v.x) + (m.m01 * v.y),
        .y = (m.m10 * v.x) + (m.m11 * v.y)
    };
}

/**
 * @brief Multiplies a 3x3 matrix by a vector of length 3.
 * @since 22-10-2023
 * @param[in] m The input matrix
 * @param[in] v The input vector
 * @returns Product of Vec3_t * Mat3_t
 */
static inline Vec3_t qm_m3_v3_mul(const Mat3_t m, const Vec3_t v) {
    return (Vec3_t){
        .x = (m.m00 * v.x) + (m.m01 * v.y) + (m.m02 * v.z),
        .y = (m.m10 * v.x) + (m.m11 * v.y) + (m.m12 * v.z),
        .z = (m.m20 * v.x) + (m.m21 * v.y) + (m.m22 * v.z)
    };
}

/**
 * @brief Multiplies a 4x4 matrix by a vector of length 4.
 * @since 22-10-2023
 * @param[in] m The input matrix
 * @param[in] v The input vector
 * @returns Product of Vec4_t * Mat4_t
 */
static inline Vec4_t qm_m4_v4_mul(const Mat4_t m, const Vec4_t v) {
    return (Vec4_t){
        .x = (m.m00 * v.x) + (m.m01 * v.y) + (m.m02 * v.z) + (m.m03 * v.w),
        .y = (m.m10 * v.x) + (m.m11 * v.y) + (m.m12 * v.z) + (m.m13 * v.w),
        .z = (m.m20 * v.x) + (m.m21 * v.y) + (m.m22 * v.z) + (m.m23 * v.w),
        .w = (m.m30 * v.x) + (m.m31 * v.y) + (m.m32 * v.z) + (m.m33 * v.w)
    };
}

/*** Matrix Mafs ***/

/**
 * @brief Adds two 2x2 matrices.
 * @since 17-10-2023
 * @param[in] a The augend matrix
 * @param[in] b The addend matrix
 * @returns Sum of a and b
 */
static inline Mat2_t qm_m2_add(const Mat2_t a, const Mat2_t b) {
    return (Mat2_t){
        .m00 = (a.m00 + b.m00), .m01 = (a.m01 + b.m01),
        .m10 = (a.m10 + b.m10), .m11 = (a.m11 + b.m11)
    };
}

/**
 * @brief Adds two 3x3 matrices.
 * @since 17-10-2023
 * @param[in] a The augend matrix
 * @param[in] b The addend matrix
 * @returns Sum of a and b
 */
static inline Mat3_t qm_m3_add(const Mat3_t a, const Mat3_t b) {
    return (Mat3_t){
        .m00 = (a.m00 + b.m00), .m01 = (a.m01 + b.m01), .m02 = (a.m02 + b.m02),
        .m10 = (a.m10 + b.m10), .m11 = (a.m11 + b.m11), .m12 = (a.m12 + b.m12),
        .m20 = (a.m20 + b.m20), .m21 = (a.m21 + b.m21), .m22 = (a.m22 + b.m22)
    };
}

/**
 * @brief Adds two 4x4 matrices.
 * @since 17-10-2023
 * @param[in] a The augend matrix
 * @param[in] b The addend matrix
 * @returns Sum of a and b
 */
static inline Mat4_t qm_m4_add(const Mat4_t a, const Mat4_t b) {
    return (Mat4_t){
        .m00 = (a.m00 + b.m00), .m01 = (a.m01 + b.m01), .m02 = (a.m02 + b.m02), .m03 = (a.m03 + b.m03),
        .m10 = (a.m10 + b.m10), .m11 = (a.m11 + b.m11), .m12 = (a.m12 + b.m12), .m13 = (a.m13 + b.m13),
        .m20 = (a.m20 + b.m20), .m21 = (a.m21 + b.m21), .m22 = (a.m22 + b.m22), .m23 = (a.m23 + b.m23),
        .m30 = (a.m30 + b.m30), .m31 = (a.m31 + b.m31), .m32 = (a.m32 + b.m32), .m33 = (a.m33 + b.m33),
    };
}

/**
 * @brief Subtracts two 2x2 matrices.
 * @since 17-10-2023
 * @param[in] a The minuend matrix
 * @param[in] b The subtrahend matrix
 * @returns Difference between a and b
 */
static inline Mat2_t qm_m2_sub(const Mat2_t a, const Mat2_t b) {
    return (Mat2_t){
        .m00 = (a.m00 - b.m00), .m01 = (a.m01 - b.m01),
        .m10 = (a.m10 - b.m10), .m11 = (a.m11 - b.m11)
    };
}

/**
 * @brief Subtracts two 3x3 matrices.
 * @since 17-10-2023
 * @param[in] a The minuend matrix
 * @param[in] b The subtrahend matrix
 * @returns Difference between a and b
 */
static inline Mat3_t qm_m3_sub(const Mat3_t a, const Mat3_t b) {
    return (Mat3_t){
        .m00 = (a.m00 - b.m00), .m01 = (a.m01 - b.m01), .m02 = (a.m02 - b.m02),
        .m10 = (a.m10 - b.m10), .m11 = (a.m11 - b.m11), .m12 = (a.m12 - b.m12),
        .m20 = (a.m20 - b.m20), .m21 = (a.m21 - b.m21), .m22 = (a.m22 - b.m22)
    };
}

/**
 * @brief Subtracts two 4x4 matrices.
 * @since 17-10-2023
 * @param[in] a The minuend matrix
 * @param[in] b The subtrahend matrix
 * @returns Difference between a and b
 */
static inline Mat4_t qm_m4_sub(const Mat4_t a, const Mat4_t b) {
    return (Mat4_t){
        .m00 = (a.m00 - b.m00), .m01 = (a.m01 - b.m01), .m02 = (a.m02 - b.m02), .m03 = (a.m03 - b.m03),
        .m10 = (a.m10 - b.m10), .m11 = (a.m11 - b.m11), .m12 = (a.m12 - b.m12), .m13 = (a.m13 - b.m13),
        .m20 = (a.m20 - b.m20), .m21 = (a.m21 - b.m21), .m22 = (a.m22 - b.m22), .m23 = (a.m23 - b.m23),
        .m30 = (a.m30 - b.m30), .m31 = (a.m31 - b.m31), .m32 = (a.m32 - b.m32), .m33 = (a.m33 - b.m33),
    };
}

/**
 * @brief Performs matrix multiplication on two 2x2 matrices.
 * @anchor lac_multiply_mat2_anchor
 * @since 17-10-2023
 * @param[in] a The multiplicand matrix
 * @param[in] b The multiplier matrix
 * @returns The product matrix
 */
static inline Mat2_t qm_m2_mul(const Mat2_t a, const Mat2_t b) {
    return (Mat2_t){
        .m00 = (a.m00 * b.m00) + (a.m01 * b.m10),
        .m01 = (a.m00 * b.m01) + (a.m01 * b.m11),

        .m10 = (a.m10 * b.m00) + (a.m11 * b.m10),
        .m11 = (a.m10 * b.m01) + (a.m11 * b.m11)
    };
}

/**
 * @brief Performs matrix multiplication on two 3x3 matrices.
 * @anchor lac_multiply_mat3_anchor
 * @since 17-10-2023
 * @param[in] a The multiplicand matrix
 * @param[in] b The multiplier matrix
 * @returns The product matrix
 */
static inline Mat3_t qm_m3_mul(const Mat3_t a, const Mat3_t b) {
    return (Mat3_t){
        .m00 = (a.m00 * b.m00) + (a.m01 * b.m10) + (a.m02 * b.m20),
        .m01 = (a.m00 * b.m01) + (a.m01 * b.m11) + (a.m02 * b.m21),
        .m02 = (a.m00 * b.m02) + (a.m01 * b.m12) + (a.m02 * b.m22),

        .m10 = (a.m10 * b.m00) + (a.m11 * b.m10) + (a.m12 * b.m20),
        .m11 = (a.m10 * b.m01) + (a.m11 * b.m11) + (a.m12 * b.m21),
        .m12 = (a.m10 * b.m02) + (a.m11 * b.m12) + (a.m12 * b.m22),

        .m20 = (a.m20 * b.m00) + (a.m21 * b.m10) + (a.m22 * b.m20),
        .m21 = (a.m20 * b.m01) + (a.m21 * b.m11) + (a.m22 * b.m21),
        .m22 = (a.m20 * b.m02) + (a.m21 * b.m12) + (a.m22 * b.m22)
    };
}

/**
 * @brief Performs matrix multiplication on two 4x4 matrices.
 * @since 17-10-2023
 * @param[out] m_out The product matrix
 * @param[in] a The multiplicand matrix
 * @param[in] b The multiplier matrix
 * @returns The product matrix
 */
static inline Mat4_t qm_m4_mul(const Mat4_t a, const Mat4_t b) {
    return (Mat4_t){
        .m00 = (a.m00 * b.m00) + (a.m01 * b.m10) + (a.m02 * b.m20) + (a.m03 * b.m30),
        .m01 = (a.m00 * b.m01) + (a.m01 * b.m11) + (a.m02 * b.m21) + (a.m03 * b.m31),
        .m02 = (a.m00 * b.m02) + (a.m01 * b.m12) + (a.m02 * b.m22) + (a.m03 * b.m32),
        .m03 = (a.m00 * b.m03) + (a.m01 * b.m13) + (a.m02 * b.m23) + (a.m03 * b.m33),

        .m10 = (a.m10 * b.m00) + (a.m11 * b.m10) + (a.m12 * b.m20) + (a.m13 * b.m30),
        .m11 = (a.m10 * b.m01) + (a.m11 * b.m11) + (a.m12 * b.m21) + (a.m13 * b.m31),
        .m12 = (a.m10 * b.m02) + (a.m11 * b.m12) + (a.m12 * b.m22) + (a.m13 * b.m32),
        .m13 = (a.m10 * b.m03) + (a.m11 * b.m13) + (a.m12 * b.m23) + (a.m13 * b.m33),

        .m20 = (a.m20 * b.m00) + (a.m21 * b.m10) + (a.m22 * b.m20) + (a.m23 * b.m30),
        .m21 = (a.m20 * b.m01) + (a.m21 * b.m11) + (a.m22 * b.m21) + (a.m23 * b.m31),
        .m22 = (a.m20 * b.m02) + (a.m21 * b.m12) + (a.m22 * b.m22) + (a.m23 * b.m32),
        .m23 = (a.m20 * b.m03) + (a.m21 * b.m13) + (a.m22 * b.m23) + (a.m23 * b.m33),

        .m30 = (a.m30 * b.m00) + (a.m31 * b.m10) + (a.m32 * b.m20) + (a.m33 * b.m30),
        .m31 = (a.m30 * b.m01) + (a.m31 * b.m11) + (a.m32 * b.m21) + (a.m33 * b.m31),
        .m32 = (a.m30 * b.m02) + (a.m31 * b.m12) + (a.m32 * b.m22) + (a.m33 * b.m32),
        .m33 = (a.m30 * b.m03) + (a.m31 * b.m13) + (a.m32 * b.m23) + (a.m33 * b.m33)
    };
}

/**
 * @brief Transpose a 2x2 matrix.
 * @since 17-10-2023
 * @param[in] m The matrix to be transposed
 * @returns The transposed matrix
 */
static inline Mat2_t qm_m2_transpose(const Mat2_t m) {
    return (Mat2_t){
        .m00 = m.m00, .m01 = m.m10,
        .m10 = m.m01, .m11 = m.m11
    };
}

/**
 * @brief Transpose a 3x3 matrix.
 * @since 17-10-2023
 * @param[in] m The matrix to be transposed
 * @returns The transposed matrix
 */
static inline Mat3_t qm_m3_transpose(const Mat3_t m) {
    return (Mat3_t){
        .m00 = m.m00, .m01 = m.m10, .m02 = m.m20,
        .m10 = m.m01, .m11 = m.m11, .m12 = m.m21,
        .m20 = m.m02, .m21 = m.m12, .m22 = m.m22
    };
}

/**
 * @brief Transpose a 4x4 matrix.
 * @since 17-10-2023
 * @param[in] m The matrix to be transposed
 * @returns The transposed matrix
 */
static inline Mat4_t qm_m4_transpose(const Mat4_t m) {
    return (Mat4_t){
        .m00 = m.m00, .m01 = m.m10, .m02 = m.m20, .m03 = m.m30,
        .m10 = m.m01, .m11 = m.m11, .m12 = m.m21, .m13 = m.m31,
        .m20 = m.m02, .m21 = m.m12, .m22 = m.m22, .m23 = m.m32,
        .m30 = m.m03, .m31 = m.m13, .m32 = m.m23, .m33 = m.m33,
    };
}

/*** Matrix Transforms ***/

/**
 * @brief This function reflects a 2x2 matrix along one or more planes.
 * @since 24-09-2024
 * @param[in] yz_plane If set to true, reflection is applied about the y-z plane
 * @param[in] xz_plane If set to true, reflection is applied about the x-z plane
 * @returns A 2x2 reflection matrix that can be applied through matrix multiplication
 */
static inline Mat2_t qm_m2_reflect(
    const bool yz_plane,
    const bool xz_plane
) {
    Mat2_t m = qm_m2_ident;

    // Flip sign for axes that should be reflected
    if (yz_plane) {
        m.m00 = -1;
    }
    if (xz_plane) {
        m.m11 = -1;
    }

    return m;
}

/**
 * @brief This function reflects a 3x3 matrix along one or more planes.
 * @since 24-09-2024
 * @param[in] yz_plane If set to true, reflection is applied about the y-z plane
 * @param[in] xz_plane If set to true, reflection is applied about the x-z plane
 * @param[in] xy_plane If set to true, reflection is applied about the x-y plane
 * @returns A 3x3 reflection matrix that can be applied through matrix multiplication
 */
static inline Mat3_t qm_m3_reflect(
    const bool yz_plane,
    const bool xz_plane,
    const bool xy_plane
) {
    Mat3_t m = qm_m3_ident;

    // Flip sign for axes that should be reflected
    if (yz_plane) {
        m.m00 = -1;
    }
    if (xz_plane) {
        m.m11 = -1;
    }
    if (xy_plane) {
        m.m22 = -1;
    }

    return m;
}

/**
 * @brief This function reflects a 4x4 matrix along one or more planes.
 * @since 17-10-2023
 * @param[in] yz_plane If set to true, reflection is applied about the y-z plane
 * @param[in] xz_plane If set to true, reflection is applied about the x-z plane
 * @param[in] xy_plane If set to true, reflection is applied about the x-y plane
 * @returns A 4x4 reflection matrix that can be applied through matrix multiplication
 */
static inline Mat4_t qm_m4_reflect(
    const bool yz_plane,
    const bool xz_plane,
    const bool xy_plane
) {
    Mat4_t m = qm_m4_ident;

    // Flip sign for axes that should be reflected
    if (yz_plane) {
        m.m00 = -1;
    }
    if (xz_plane) {
        m.m11 = -1;
    }
    if (xy_plane) {
        m.m22 = -1;
    }

    return m;
}

/**
 * @brief Gets a 3x3 translation matrix according to the input parameters.
 * @since 24-09-2024
 * @param[in] tx Arbitrary unit for translation in the x-direction
 * @param[in] ty Arbitrary unit for translation in the y-direction
 * @returns The 3x3 translation matrix which can be applied through matrix multiplication
 */
static inline Mat3_t qm_m3_translate(const f32 tx, const f32 ty) {
    return (Mat3_t){ .m = {
        { 1, 0, tx },
        { 0, 1, ty },
        { 0, 0, 1 },
    }};
}

/**
 * @brief Gets a 4x4 translation matrix according to the input parameters.
 * @since 17-10-2023
 * @param[out] m_out The 4x4 translation matrix which can be applied through matrix multiplication
 * @param[in] tx Arbitrary unit for translation in the x-direction
 * @param[in] ty Arbitrary unit for translation in the y-direction
 * @param[in] tz Arbitrary unit for translation in the z-direction
 */
static inline Mat4_t qm_m4_translate(const f32 tx, const f32 ty, const f32 tz) {
    return (Mat4_t){ .m = {
        { 1, 0, 0, tx },
        { 0, 1, 0, ty },
        { 0, 0, 1, tz },
        { 0, 0, 0, 1 },
    }};
}

/**
 * @brief Gets a 2x2 scalar matrix according to the input parameters.
 * @since 24-09-2024
 * @param[in] sx Arbitrary unit for scaling in the x-direction
 * @param[in] sy Arbitrary unit for scaling in the y-direction
 * @returns The 2x2 scalar matrix which can be applied through matrix multiplication
 */
static inline Mat2_t qm_m2_scale(const f32 sx, const f32 sy) {
    return (Mat2_t){ .m = {
        { sx, 0 },
        { 0,  sy }
    }};
}

/**
 * @brief Gets a 3x3 scalar matrix according to the input parameters.
 * @since 24-09-2024
 * @param[in] sx Arbitrary unit for scaling in the x-direction
 * @param[in] sy Arbitrary unit for scaling in the y-direction
 * @param[in] sz Arbitrary unit for scaling in the z-direction
 * @returns The 3x3 scalar matrix which can be applied through matrix multiplication
 */
static inline Mat3_t qm_m3_scale(const f32 sx, const f32 sy, const f32 sz) {
    return (Mat3_t){ .m = {
        { sx, 0,  0 },
        { 0,  sy, 0 },
        { 0,  0,  sz }
    }};
}

/**
 * @brief Gets a 4x4 scalar matrix according to the input parameters.
 * @since 17-10-2023
 * @param[in] sx Arbitrary unit for scaling in the x-direction
 * @param[in] sy Arbitrary unit for scaling in the y-direction
 * @param[in] sz Arbitrary unit for scaling in the z-direction
 * @returns m_out The 4x4 scalar matrix which can be applied through matrix multiplication
 */
static inline Mat4_t qm_m4_scale(const f32 sx, const f32 sy, const f32 sz) {
    return (Mat4_t){ .m = {
        { sx, 0,  0,  0 },
        { 0,  sy, 0,  0 },
        { 0,  0,  sz, 0 },
        { 0,  0,  0,  1 }
    }};
}

/**
 * @brief Gets a rotation matrix according to the input angle of yaw.
 * @since 17-10-2023
 * @param[in] yaw Rotation angle about the yaw axis (given in radians)
 * @returns The rotation matrix which can be applied through matrix multiplication
 */
static inline Mat4_t qm_m4_yaw(const f32 yaw) {
    f32 cos_yaw = cosf(yaw);
    f32 sin_yaw = sinf(yaw);

    return (Mat4_t){ .m = {
        { cos_yaw, -sin_yaw, 0, 0 },
        { sin_yaw,  cos_yaw, 0, 0 },
        { 0,        0,       1, 0 },
        { 0,        0,       0, 1 }
    }};
}

/**
 * @brief Gets a rotation matrix according to the input angle of pitch.
 * @since 17-10-2023
 * @param[in] pitch Rotation angle about the pitch axis (given in radians)
 * @returns The rotation matrix which can be applied through matrix multiplication
 */
static inline Mat4_t qm_m4_pitch(const f32 pitch) {
    f32 cos_pitch = cosf(pitch);
    f32 sin_pitch = sinf(pitch);

    return (Mat4_t){ .m = {
        {  cos_pitch,  0, sin_pitch, 0 },
        {  0,          1, 0,         0 },
        { -sin_pitch,  0, cos_pitch, 0 },
        {  0,          0, 0,         1 }
    }};
}

/**
 * @brief Gets a rotation matrix according to the input angle of roll.
 * @since 17-10-2023
 * @param[in] roll Rotation angle about the roll axis (given in radians)
 * @returns The rotation matrix which can be applied through matrix multiplication
 */
static inline Mat4_t qm_m4_roll(const f32 roll) {
    f32 cos_roll = cosf(roll);
    f32 sin_roll = sinf(roll);

    return (Mat4_t){ .m = {
        { 1, 0,         0,        0 },
        { 0, cos_roll, -sin_roll, 0 },
        { 0, sin_roll,  cos_roll, 0 },
        { 0, 0,         0,        1 }
    }};
}

/**
 * @brief Gets a rotation matrix according to the input angles for each axis.
 * @since 17-10-2023
 * @param[in] rx Rotation angle in the x-axis (given in radians)
 * @param[in] ry Rotation angle in the y-axis (given in radians)
 * @param[in] rz Rotation angle in the z-axis (given in radians)
 * @returns The rotation matrix which can be applied through matrix multiplication
 */
static inline Mat4_t qm_m4_rotation(const f32 rx, const f32 ry, const f32 rz) {
    f32 cos_rx = cosf(rx);
    f32 sin_rx = sinf(rx);
    f32 cos_ry = cosf(ry);
    f32 sin_ry = sinf(ry);
    f32 cos_rz = cosf(rz);
    f32 sin_rz = sinf(rz);

    Mat4_t yaw_mat = { .m = {
        { cos_rz, -sin_rz, 0, 0 },
        { sin_rz,  cos_rz, 0, 0 },
        { 0,       0,      1, 0 },
        { 0,       0,      0, 1 }
    }};

    Mat4_t pitch_mat = { .m = {
        {  cos_ry,  0, sin_ry, 0 },
        {  0,       1, 0,      0 },
        { -sin_ry,  0, cos_ry, 0 },
        {  0,       0, 0,      1 }
    }};

    Mat4_t roll_mat = { .m = {
        { 1, 0,       0,      0 },
        { 0, cos_rx, -sin_rx, 0 },
        { 0, sin_rx,  cos_rx, 0 },
        { 0, 0,       0,      1 }
    }};

    // Get the final rotation matrix by obtaining dot product of (yaw * pitch * roll)
    Mat4_t rot_mat = qm_m4_mul(yaw_mat, pitch_mat);
    return qm_m4_mul(rot_mat, roll_mat);
}

/**
 * @brief Gets a normalized point-at matrix.
 * @since 20-10-2023
 * @param[in] eye A vector representing the camera's position
 * @param[in] tgt A vector representing the target point in 3D space for the camera to point towards
 * @param[in] up A vector representing the "up" direction (used for camera orientation)
 * @returns The point-at matrix
 */
static inline Mat4_t qm_m4_lookat(
    const Vec3_t eye,
    const Vec3_t tgt,
    const Vec3_t up
) {
    // Forward vector (camera direction)
    Vec3_t f = qm_v3_norm(qm_v3_sub(eye, tgt));

    // Right vector
    Vec3_t r = qm_v3_norm(qm_v3_cross(up, f));

    // Recomputed up vector
    Vec3_t u = qm_v3_cross(f, r);

    return (Mat4_t){ .m = {
        { r.x, r.y, r.z, -qm_v3_dot(r, eye) },
        { u.x, u.y, u.z, -qm_v3_dot(u, eye) },
        { f.x, f.y, f.z, -qm_v3_dot(f, eye) },
        { 0,   0,   0,    1                 }
    }};
}

/**
 * @brief This function is designed specifically for inverting the point-at matrix.
 * @warning This is not a true matrix inversion function; it only works with rotation and translation matrices.
 * @since 17-10-2023
 * @param[in] m The matrix to be inverted
 * @returns The resulting look-at matrix
 */
static inline Mat4_t qm_m4_affine_inv(const Mat4_t m) {
    Mat4_t inv;

    // Transpose rotation part
    inv.m00 = m.m00;
    inv.m01 = m.m10;
    inv.m02 = m.m20;

    inv.m10 = m.m01;
    inv.m11 = m.m11;
    inv.m12 = m.m21;

    inv.m20 = m.m02;
    inv.m21 = m.m12;
    inv.m22 = m.m22;

    // Original translation
    Vec3_t t = { .x = m.m03, .y = m.m13, .z = m.m23 };

    // New translation = -R^T * t
    inv.m03 = - (inv.m00 * t.x + inv.m01 * t.y + inv.m02 * t.z);
    inv.m13 = - (inv.m10 * t.x + inv.m11 * t.y + inv.m12 * t.z);
    inv.m23 = - (inv.m20 * t.x + inv.m21 * t.y + inv.m22 * t.z);

    inv.m30 = 0;
    inv.m31 = 0;
    inv.m32 = 0;
    inv.m33 = 1;

    return inv;
}

/**
 * @brief Returns a frustum projection matrix according to the input parameters.
 * @since 17-10-2023
 * @param[in] aspect The aspect ratio of the screen (taken by height/width)
 * @param[in] fov The field of view (given as an angle in degrees)
 * @param[in] znear The "near" clipping z-plane
 * @param[in] zfar The "far" clipping z-plane
 * @returns The resulting projection matrix that can be applied through matrix multiplication
 */
static inline Mat4_t qm_m4_projection(
    const f32 aspect,
    const f32 fov,
    const f32 znear,
    const f32 zfar
) {
    f32 fov_rad = fov * (qm_pi / 180.0f);
    f32 f = 1.0f / tanf(fov_rad / 2.0f);
    f32 range_inv = 1.0f / (znear - zfar);

    // Row-Major Layout
    return (Mat4_t){ .m = {
        { f / aspect, 0.0f, 0.0f,                          0.0f },
        { 0.0f,       f,    0.0f,                          0.0f },
        { 0.0f,       0.0f, (zfar + znear) * range_inv,    (2.0f * zfar * znear) * range_inv },
        { 0.0f,       0.0f, -1.0f,                         0.0f }
    }};
}

#ifdef __cplusplus
}
#endif

#endif
