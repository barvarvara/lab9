////
//// Created by Barbara on 09.05.2022.
////
//
//#include <windows.h>
//
//#include <iostream>
//#include <sstream>
//
//#include "C:\Clion\oop\lab9\obj.hpp"
//
//using namespace std;
//
//int main() {
//    SetConsoleOutputCP(CP_UTF8);
//
////    fstream file(R"(C:\Clion\oop\lab9\objects\points.obj)");
////    if (file.is_open()) {
////        string str;
////        file >> str;
////        cout << str << "\n";
////        getline(file, str);
////        cout << str;
////        getline(file, str);
////        cout << "\n" << str;
////    } else
////        cout << "Ошибка! Не удалось открыть файл." << endl;
////
////    file.close();
//
//    try {
////        {//        Object object(R"(C:\Clion\oop\lab9\objects\points.obj)");
////            Object object1(R"(C:\Clion\oop\lab9\objects\points_uvCoords.obj)");
////            cout << "\nobject1:\n";
////            object1.print();
////
////            Object object2(object1);
////            cout << "\n\nobject2:\n";
////            object2.print();
////
////            Object object3 = object1 + object2;
////            cout << "\n\nobject3: \n";
////            object3.print();
////        }
//
////        {
////            //проверка, что выведет при конструкторе по умолчанию
////            Object object3;
////            cout << "\nobject3:\n";
////
////            object3.print();
////        }
//
//        {
//            Object object1(R"(C:\Clion\oop\lab9\objects\triangles.obj)");
//            cout << "\nobject1:\n";
//            object1.print();
//
//            Object object2(R"(C:\Clion\oop\lab9\objects\points_uvCoords.obj)");
//            cout << "\nobject2:\n";
//            object2.print();
//
//            Object object3 = object1 + object2;
//            cout << "\nobject3:\n";
//            object3.print();
//        }
//
////        {
////            Object object1(R"(C:\Clion\oop\lab9\objects\triangles.obj)");
////            cout << "\nobject1:\n";
////            object1.print();
////            cout << "\nОтсортированный object1:\n";
////            object1.sort();
////            object1.print();
////
////            Object object2(R"(C:\Clion\oop\lab9\objects\points_uvCoords.obj)");
////            cout << "\n\nobject2:\n";
////            object2.print();
////            cout << "\nОтсортированный object2:\n";
////            object2.sort();
////            object2.print();
////        }
//
//
//        {
////            Triangle abc = {{0, 0, 0}, {0, 2, 3}, {0, 2, 0}};
////            Point p1 = {0, 2, 1};
////            cout << "=========================\n1) точка -- на треугольнике\n";
////            abc.doesContain(p1);
////
////            Point p2 = {1, -2, 3};
////            cout << "=========================\n2) -- далеко снаружи треугольника\n";
////            abc.doesContain(p2);
////
////            Point p3 = {0, 1, 1};
////            cout << "=========================\n3) -- строго внутри треугольника\n";
////            abc.doesContain(p3);
////
////            Point p4 = {0, 2.1, 1};
////            cout << "=========================\n4) -- недалеко снаружи треугольника\n";
////            abc.doesContain(p4);
//
////            {
////                Triangle abc = {{0, 0, 0},
////                                {0, 3, 4},
////                                {0, 3, 0}};
////                Point p1 = {0, 3, 1};
////                cout << "=========================\n1) точка -- на треугольнике\n";
////                abc.doesContain(p1);
////
////                Point p2 = {1, -2, 3};
////                cout << "=========================\n2) -- далеко снаружи треугольника\n";
////                abc.doesContain(p2);
////
////                Point p3 = {0, 2, 1};
////                cout << "=========================\n3) -- строго внутри треугольника\n";
////                abc.doesContain(p3);
////
////                Point p4 = {0, 3.1, 1};
////                cout << "=========================\n4) -- недалеко снаружи треугольника\n";
////                abc.doesContain(p4);
////            }
//        }
//
//
//
//    } catch (string &s) {
//        cout << s;
//    }
//
//    return 0;
//}