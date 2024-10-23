//
// Created by Barbara on 11.05.2022.
//

#ifndef OOP_POINT_HPP
#define OOP_POINT_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    double x;
    double y;
    double z;

    // выводит координаты точки в формате: (x, y, z)
    void print() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    double distance(Point other) const {
        return sqrt((other.x - this->x) * (other.x - this->x) +
                    (other.y - this->y) * (other.y - this->y) +
                    (other.z - this->z) * (other.z - this->z));
    }


/*//    bool isOnStraightLine(Point A, Point B) {
//        double a = (x - A.x) * (B.y - A.y) - (B.x - A.x) * (y - A.y);
//        double b = (y - A.y) * (B.z - A.z) - (B.y - A.y) * (z - A.z);
//        double c = (x - A.x) * (B.z - A.z) - (B.x - A.x) * (z - A.z);
//
//        return (a == 0) && (b == 0) && (c == 0);
//    }*/

    friend bool operator==(const Point &p1, const Point &p2);

    friend bool operator!=(const Point &p1, const Point &p2);

    friend bool operator<(const Point &p1, const Point &p2);

    friend bool operator>(const Point &p1, const Point &p2);
};


#endif //OOP_POINT_HPP
