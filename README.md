Класс для хранения *.obj представляет собой набор из двух list. <br>
Один -- точки, другой -- треугольники.

Разработать программное обеспечение для решения следующей задачи: <br>

- загрузка формата *.obj в программу, <br>

- обработка объекта путем добавления цвета отображения различных элементов объекта.


- Вывести полученные списки на экран.

- Выполнить сложение *.obj объектов, путем удаления лишних точек,
лежащих внутри новой поверхности.

- Организовать сортировку точек, треугольников.


Структура формата *.obj:
 - `#` is a comment, just like // in C++
 - `usemtl` and `mtllib` describe the look of the model.
 - `v` is a vertex
 - `vt` is the texture coordinate of one vertex
 - `vn` is the normal of one vertex (Вектор нормали к поверхности в точке совпадает с нормалью к касательной плоскости в этой точке. По этому параметру вычисляется как будет освещаться конкретная точка объекта.)
 - `f` is a face

for `f 8/11/7 7/12/7 6/10/7` :

 - `8/11/7` describes the first vertex of the triangle
 - `7/12/7` describes the second vertex of the triangle
 - `6/10/7` describes the third vertex of the triangle (duh)

 - `8/11/7`: 
   - `8` -- номер первой точки (индексация с 1, а не с 0)
   - `11` -- координаты текстура
   - `7` -- номер нормали

Существует несколько наборов параметров описания поверхности.
- Файл хранит только координаты точек и как они связанны между собой.
- Файл хранит координаты точек и координаты нормалей для поверхности.
- Файл хранит координаты точек и координаты текстур.
- Файл хранит полный список параметров


[comment]: <> (Вариант 3.)

[comment]: <> (Разработать программное обеспечение для решения следующей задачи: )

[comment]: <> (построение очереди обработки задач. )

[comment]: <> (Задачи следующего вида:)

[comment]: <> (- создание файла, )

[comment]: <> (- удаление файла, )

[comment]: <> (- переименование файла, )

[comment]: <> (- вывод файла на экран, )

[comment]: <> (- добавление записи в файл, )

[comment]: <> (- удаление записи из файла. )
 
[comment]: <> (Один поток берет задачу из очереди, и производит ее выполнение, <br>)

[comment]: <> (другие потоки, число которых задается динамически, <br>)

[comment]: <> (выполняют добавление задач в очередь. <br>)

[comment]: <> (Организовать слияние очередей задач на основе времени добавление задачи.)