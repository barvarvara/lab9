#include "obj.hpp"


Object::Object(const char *fName) {
    fstream f(fName);

    if (f.is_open()) {
        string readString;

        while (!f.eof()) {
            getline(f, readString);
            char v1 = readString[0];
            char v2 = readString[1];

            switch (v1) {
                case 'v' :
                    switch (v2) {
                        case ' ': {
                            //запись типа v x y z -- координаты точки
                            readString.erase(readString.begin(), readString.begin() + 2); //удаляет символы "v "

                            Point p = getPoint(readString);
                            points.push_back(p);

                            break;
                        }
                        case 'n': {
                            //запись типа vn x y z -- координаты нормали

                            readString.erase(readString.begin(), readString.begin() + 3); //удаляет символы "vn "
                            Point p = getPoint(readString);

                            break;
                        }
                        case 't': {
                            //запись типа vt x y z
                            cout << "texture: " << readString << "\n";

                            readString.erase(readString.begin(), readString.begin() + 3); //удаляет символы "vt "
                            Point p = getPoint(readString);

                            break;
                        }
                        default:
                            break;
                    }
                    break;
                case 'f': {
                    readString.erase(readString.begin(), readString.begin() + 2);
                    vector<int> numbers = getDigitsVector(readString);

                    if (numbers.size() == 3) {
                        Triangle t;

                        vector<Point> p;
                        for (auto n: numbers) {
                            Point point = points[n];
                            p.push_back(point);
                        }

                        t.v1 = p[0];
                        t.v2 = p[1];
                        t.v3 = p[2];

                        triangles.push_back(t);

                    } else {
                        cout << "Поверхность не представляет собой треугольник";
                    };

                    break;
                }
                default: // если комментарий (с символом '#' в начале) или пустая строка
                    break;
            }
        }
    } else {
        f.close();
        throw runtime_error("Object(string &): Ошибка! Не удалось открыть файл.");
    }

    f.close();
}
