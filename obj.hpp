//
// Created by Barbara on 09.05.2022.
//

#ifndef OOP_OBJ_HPP
#define OOP_OBJ_HPP

#include "triangle.hpp"
#include "point.hpp"

#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include <set>


class listTriangles {
private:
    list<Triangle> triangles;
public:
    listTriangles(list<Triangle> lt = {}) {
        triangles.insert(triangles.begin(), lt.begin(), lt.end());
    }

    void push_back(Triangle &triangle) {
        triangles.push_back(triangle);
    }

    void print() {
        for (auto triangle: triangles) {
            triangle.print();
            cout << "\n";
        }
    }


    auto begin() const {
        return triangles.begin();
    }

    auto end() const {
        return triangles.end();
    }

    void sort() {
        triangles.sort();
    }
};

template<typename T>
class listElements {
private:
    list<T> elements;
public:
    listPoints(list<T> lp = {}) {
        elements.insert(elements.begin(), lp.begin(), lp.end());
    }

    T &operator[](int i) {
        for (auto &x: elements) {
            if (i == 0)
                return x;
            --i;
        }

        throw out_of_range("listElements::operator[]: Index is out of range!");
    }

    void push_back(T &el) {
        elements.push_back(el);
    }

    void print() {
        int i = 0;
        for (auto el: elements) {
            cout << ++i << ". ";
            el.print();
            cout << "\n";
        }
    }

    auto begin() const {
        return elements.begin();
    }

    auto end() const {
        return elements.end();
    }

    void sort() {
        elements.sort();
    }
};


class listPoints {
private:
    list<Point> points;
public:
    listPoints(list<Point> lp = {}) {
        points.insert(points.begin(), lp.begin(), lp.end());
    }

    Point &operator[](int i) {
        for (auto &x: points) {
            if (i == 0)
                return x;
            --i;
        }

        throw out_of_range("listPoints::operator[]: Index is out of range!");
    }

    void push_back(Point &point) {
        points.push_back(point);
    }

    void print() {
        int i = 0;
        for (auto point: points) {
            cout << ++i << ". ";
            point.print();
            cout << "\n";
        }
    }

    auto begin() const {
        return points.begin();
    }

    auto end() const {
        return points.end();
    }

    void sort() {
        points.sort();
    }
};


class Object {
    listPoints points;
    listTriangles triangles;

public:
    //конструктор по умолчанию
    Object(listPoints _points = {}, listTriangles _triangles = {}) : points(_points), triangles(_triangles) {}

    //конструктор копирования
    Object(const Object &object) : points(object.points), triangles(object.triangles) {}

    // инициализирует объект информацией из формата *.obj,
    // расположенным в файле по адресу fName
    Object(const char *fName);

    void push_back(Point &_point) {
        points.push_back(_point);
    }

    void push_back(Triangle &_triangle) {
        triangles.push_back(_triangle);
    }

    // возвращает вектор цифр из строки s
    static vector<int> getDigitsVector(string &s) {
        // удаляет из строки все пробельные символы -> изменить на: удаляет все символы не-цифры
        s.erase(remove(s.begin(), s.end(), ' '), s.end());

        transform(
                s.begin(), s.end(),
                s.begin(),
                [](char a) {return a - '0' - 1;});

        vector<int> numbers(s.begin(), s.end());

        return numbers;
    }

    // возвращает координаты точки, записанные в строке string
    Point getPoint(const string &string) {
        Point p = {0, 0, 0};

        char *ptr1;
        char *ptr2;

        auto s = string.c_str();
        p.x = strtod(s, &ptr1);
        p.y = strtod(ptr1, &ptr2);
        p.z = strtod(ptr2, nullptr);

        return p;
    }

    // выводит полученные списки объекта на экран
    void print() {
        cout << "\nСписок точек из файла: \n";
        points.print();

        cout << "\nСписок треугольников из файла: \n";
        triangles.print();
    }

    //определяет, является ли точка вершиной какой-либо поверхности объекта
    bool isPointVertex(Point p) {
        for (auto f : triangles) {
            if (f.hasVertex(p))
                return true;
        }
        return false;
    }

    void sort() {
        points.sort();
        triangles.sort();
    }

    // сложение *.obj объектов, путем удаления лишних точек,
    // лежащих внутри новой поверхности.
    Object operator+(const Object &other) {
        Object result;

        //копирование без дублирования всех точек в результат
        set<Point> vertexesToAdd(points.begin(), points.end());
        vertexesToAdd.insert(other.points.begin(), other.points.end());

        for (auto f : triangles) {
            for (auto v : vertexesToAdd) {
                if (!isPointVertex(v) and f.doesContain(v)) {
                    vertexesToAdd.erase(v);
                }
            }
        }

        for (auto v : vertexesToAdd)
            result.push_back(v);

        //копирование поверхностей с исключением лежащих внутри точек
        for (auto f : other.triangles)
            result.push_back(f);
        for (auto f : triangles)
            result.push_back(f);

        return result;
    }

};


#endif //OOP_OBJ_HPP
