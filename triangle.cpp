//
// Created by Barbara on 11.05.2022.
//

#include "triangle.hpp"

bool operator<(const Triangle &p1, const Triangle &p2) {
    return (p1.v1 < p2.v1) ||
           (p1.v1 == p2.v1) && (p1.v2 < p2.v2) ||
           (p1.v1 == p2.v1) && (p1.v2 == p2.v2) && (p1.v3 < p2.v3);
}