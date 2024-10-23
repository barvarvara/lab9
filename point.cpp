//
// Created by Barbara on 11.05.2022.
//

#include "point.hpp"

bool operator==(const Point &p1, const Point &p2) {
    return (abs(p1.x - p2.x) <= 0.000001 &&
            abs(p1.y - p2.y) <= 0.000001 &&
            abs(p1.z - p2.z) <= 0.000001);
}

bool operator!=(const Point &p1, const Point &p2) {
    return (!(p1 == p2));
}

bool operator<(const Point &p1, const Point &p2) {
    return (p1.x < p2.x) ||
           (p1.x == p2.x) && (p1.y < p2.y) ||
           (p1.x == p2.x) && (p1.y == p2.y) && (p1.z < p2.z);
}

bool operator>(const Point &p1, const Point &p2) {
    return (p1.x > p2.x) ||
           (p1.x == p2.x) && (p1.y > p2.y) ||
           (p1.x == p2.x) && (p1.y == p2.y) && (p1.z > p2.z);
}
