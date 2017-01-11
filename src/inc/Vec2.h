//
// Created by Russell Blickhan on 1/10/17.
//

#pragma once

//std
#include <tuple>
#define _USE_MATH_DEFINES
#include <cmath>

//gah
#include <Types.h>

static Vec2 add(Vec2 x, Vec2 y) {
    return std::make_tuple(std::get<0>(x) + std::get<0>(y), std::get<1>(x) + std::get<1>(y));
};

static Vec2 subtract(Vec2 x, Vec2 y) {
    return std::make_tuple(std::get<0>(x) - std::get<0>(y), std::get<1>(x) - std::get<1>(y));
};

static Vec2 multiply(double a, Vec2 x) {
    return std::make_tuple(a * std::get<0>(x), a * std::get<1>(x));
};

static double dot(Vec2 x, Vec2 y) {
    return std::get<0>(x) * std::get<0>(y) + std::get<1>(x) * std::get<1>(y);
};

static Vec2 rotate(double degrees, Vec2 x) {
    double radians = (M_PI / 180) * degrees;
    return std::make_tuple(std::get<0>(x) * cos(radians) - std::get<1>(x) * sin(radians),
                           std::get<0>(x) * sin(radians) + std::get<1>(x) * cos(radians));
};

static Vec2 operator+(Vec2 x, Vec2 y) {
    return add(x, y);
};

static Vec2 operator-(Vec2 x, Vec2 y) {
    return subtract(x, y);
};

static Vec2 operator*(double a, Vec2 x) {
    return multiply(a, x);
};

static int operator*(Vec2 x, Vec2 y) {
    return dot(x, y);
};