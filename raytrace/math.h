#pragma once

#include <cmath>
#include <iostream>
#include <stdio.h>

constexpr float PI = 3.14159265358979323846f;
constexpr float TAU = 6.28318530717958647692f;
constexpr float INV_PI = 0.31830988618379067154f;
constexpr float TOL = 10e-4;
constexpr float EPS = 10e-3;

inline float min(float a, float b) { return a < b ? a : b; }
inline float max(float a, float b) { return a > b ? a : b; }
inline float clamp01(float a) { return min(max(a, 0.0f), 1.0f); }
inline float clamp(float a, float mn, float mx) { return min(max(a, mn), mx); }
inline float radians(float a) { return a * PI / 180.0f; }
inline float degrees(float a) { return a * 180.0f / PI; }

template<typename T>
inline T lerp(float t, T a, T b) { return a + t * (b - a); }

union Vec3 {
    struct {
        float x, y, z;
    };
    struct {
        float r, g, b;
    };
    struct {
        float u, v, _unused1;
    };
    float P[3];

    Vec3()
        : x(0)
        , y(0)
        , z(0)
    {
    }
    Vec3(float x, float y, float z)
        : x(x)
        , y(y)
        , z(z)
    {
    }
    Vec3(float xyz)
        : x(xyz)
        , y(xyz)
        , z(xyz)
    {
    }

    float operator[](int i) const { return P[i]; }
    Vec3 operator-() { return Vec3(-x, -y, -z); }

    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(const Vec3& v) const { return Vec3(x * v.x, y * v.y, z * v.z); }
    Vec3 operator/(const Vec3& v) const { return Vec3(x / v.x, y / v.y, z / v.z); }

    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    Vec3 cross(const Vec3& v) const { return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
    float length() const { return std::sqrt(x * x + y * y + z * z); }
    float length2() const { return x * x + y * y + z * z; }
    Vec3 normalized() const { return *this / length(); }
    Vec3 abs() const { return Vec3(std::abs(x), std::abs(y), std::abs(z)); }

    Vec3 cwise_min(const Vec3& v) const { return Vec3(min(x, v.x), min(y, v.y), min(z, v.z)); }
    Vec3 cwise_max(const Vec3& v) const { return Vec3(max(x, v.x), max(y, v.y), max(z, v.z)); }

    float max_coeff() const { return max(max(x, y), z); }
    float min_coeff() const { return min(min(x, y), z); }

    int max_coeff_index() const { return x > y ? (x > z ? 0 : 2) : (y > z ? 1 : 2); }
    int min_coeff_index() const { return x < y ? (x < z ? 0 : 2) : (y < z ? 1 : 2); }
};

inline Vec3 operator*(float s, const Vec3& v) { return Vec3(s * v.x, s * v.y, s * v.z); }
inline Vec3 operator/(float s, const Vec3& v) { return Vec3(s / v.x, s / v.y, s / v.z); }
inline Vec3 operator*(const Vec3& v, float s) { return Vec3(s * v.x, s * v.y, s * v.z); }
inline Vec3 operator/(const Vec3& v, float s) { return Vec3(v.x / s, v.y / s, v.z / s); }

inline Vec3 operator+(float s, const Vec3& v) { return Vec3(s + v.x, s + v.y, s + v.z); }
inline Vec3 operator-(float s, const Vec3& v) { return Vec3(s - v.x, s - v.y, s - v.z); }
inline Vec3 operator+(const Vec3& v, float s) { return Vec3(s + v.x, s + v.y, s + v.z); }
inline Vec3 operator-(const Vec3& v, float s) { return Vec3(v.x - s, v.y - s, v.z - s); }

inline float dot(const Vec3& v1, const Vec3& v2) { return v1.dot(v2); }
inline Vec3 cross(const Vec3& v1, const Vec3& v2) { return v1.cross(v2); }
inline Vec3 normalized(const Vec3& v) { return v / v.length(); }

inline std::ostream& operator<<(std::ostream& os, const Vec3& v)
{
    return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}
