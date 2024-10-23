//
// Created by Barbara on 11.05.2022.
//

#ifndef OOP_TRIANGLE_HPP
#define OOP_TRIANGLE_HPP

#include "point.hpp"

class Triangle {
public:
    Point v1; //координаты трех точек треугольника
    Point v2;
    Point v3;

    //выводит треугольник в формате: [(x1, y1, z1); (x2, y2, z2); (x3, y3, z3)]
    void print() {
        cout << "[";
        v1.print();
        cout << "; ";
        v2.print();
        cout << "; ";
        v3.print();
        cout << "]";
    }


    static double HeronSquare(double a, double b, double c) {
        double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        return s;
    }

    bool hasVertex(Point v) const {
        return v1 == v or v2 == v or v3 == v;
    }

    // Если же сумма площадей треугольников AKB, AKC, BKC равна площади треугольника ABC,
    // то нужно проверить, не равна ли нулю одна из трех площадей.
    // Если равна, то точка лежит на границе треугольника, иначе – внутри.
    bool doesContain(Point p) {
        //ABC
        double AB = v1.distance(v2);
        double AC = v1.distance(v3);
        double BC = v2.distance(v3);
        double sqABC = HeronSquare(AB, AC, BC);

        //APB
        double AP = v1.distance(p);
        double BP = v2.distance(p);
        double sqAPB = HeronSquare(AP, BP, AB);

        //APC
        double PC = p.distance(v3);
        double sqAPC = HeronSquare(AP, PC, AC);

        //BPC
        double sqBPC = HeronSquare(BP, PC, BC);

        if (sqAPB != 0 && sqAPC != 0 && sqBPC != 0) {
            if (abs(sqBPC + sqAPC + sqAPB - sqABC) <= 1e-7)
                return true;
            else
                return false;
        }

        return false;
    }

    friend bool operator<(const Triangle &t1, const Triangle &t2);
};

#endif //OOP_TRIANGLE_HPP
