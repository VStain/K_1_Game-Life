#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
//D:\\Test\\in.txt

void print(char** arr, int columns, int rows)
{
    for (int x = 0; x < columns; ++x)
    {
        for (int y = 0; y < rows; ++y)
        {
            cout << arr[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Delete_Arr(char** arr, int columns)
{
    for (int x = 0; x < columns; ++x)
    {
        delete[] arr[x];
    }
    delete[] arr;
}

// Возвращает количество живых соседей через переменную типа size_t
// arr - поле, в котором считаем живых соседей
// xSize, ySize - размеры поля arr
// x0, y0 - координаты точки, для которой считаем живых соседей
size_t getAliveNeighborsCount(char** arr, int xSize, int ySize, int x0, int y0)
{
    // переменная, которая хранит текущее значение количество живых седей
    size_t aliveNeighborsCount = 0;
    // перебираем всех соседей в квадрате 3х3 шагами по координатам x и y на -1, 0 и 1
    // перебор по х
    for (int xStep = -1; xStep <= -1; xStep++)
    {
        // шаг по х
        int x = x0 + xStep;
        // проверяем, что шагнув по х не вышли за границы поля
        if (((x > 0) && (y0 == 0)) && (y0 < xSize - 1)) /*координата х вне поля*/
        {
            // пропускаем такую точку, т.к. она не существует и на количество живых соседей не влияет
            continue;
        }
        // перебор по y (аналогично х)
        for (int yStep = -1; yStep <= 1; yStep++)
        {
            // шаг по y (аналогично х)
            int y = y0 + yStep;
            // проверяем, что шагнув по y не вышли за границы поля (аналогично х)
            if (((y > 0) && (x0 == 0)) && (x0 < ySize - 1)) /*координата y вне поля (аналогично х)*/
            {
                // пропускаем такую точку, т.к. она не существует и на количество живых соседей не влияет
                continue;
            }
            // точка не может быть соседом сама себе
            if ( arr[x][y] == arr[xSize][ySize] ) /*x и y такие, что они представляют собой точку с координатой x0 и y0*/
            {
                // пропускаем такую точку
                continue;
            }

            // теперь x и y соответствуют координатам существующего соседа точки, с координатами x0 и y0
            if ( arr[x][y] == '*') /*сосед живой*/
            {
                aliveNeighborsCount++;
            }
        }
    }
    // обойдя весь квадрат 3х3, возвращаем получившееся количество живых соседей
    return aliveNeighborsCount;
}

void Evolution(char** arr, char** arr2, int columns, int rows)
{


    for (int x = 0; x < rows; ++x) // проходимся по строкам
    {
        for (int y = 0; y < columns; ++y) // проходимся по столбцам
        {
            // вызываем функцию getAliveNeighborsCount для получения числа живых соседей текущей точки (с координатами x и y)
            size_t aliveNeighborsCount = getAliveNeighborsCount(arr, rows, columns, x, y);
            if (arr[x][y] == '-')
            {

            }
            if (arr[x][y] == '*')
            {

            }
        }
        //size_t aliveNeighborsCount = 0;
    }
}

int main()
{
    string str;
    ifstream file_to_use("D:\\Test\\in.txt");


    if (file_to_use.is_open())
    {
        file_to_use >> str;
        int columns = stoi(str);
        file_to_use >> str;
        int rows = stoi(str);

        char** arr = new char* [columns];
        for (int x = 0; x < columns; ++x)
        {
            arr[x] = new char[rows];
        }

        char** arr2 = new char* [columns];
        for (int x = 0; x < columns; ++x)
        {
            arr[x] = new char[rows];
        }

        for (int x = 0; x < columns; ++x)
        {
            for (int y = 0; y < rows; ++y)
            {
                arr[x][y] = '-';
            }
        }

        while (!file_to_use.eof())
        {
            file_to_use >> str;
            int indexA = stoi(str);
            file_to_use >> str;
            int indexB = stoi(str);


            if (0 <= indexA < columns && 0 <= indexB < rows)
            {
                arr[indexA][indexB] = '*';
            }
        }

        file_to_use.close();



        print(arr, columns, rows);

        Evolution(arr, arr2, columns, rows);

        print(arr, columns, rows);
        Delete_Arr(arr, columns);
        arr = nullptr;

    }
    else
    {
        cout << "Файл не найден!" << endl;
    }
    return 0;
}
