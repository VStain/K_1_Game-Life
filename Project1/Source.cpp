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

// ���������� ���������� ����� ������� ����� ���������� ���� size_t
// arr - ����, � ������� ������� ����� �������
// xSize, ySize - ������� ���� arr
// x0, y0 - ���������� �����, ��� ������� ������� ����� �������
size_t getAliveNeighborsCount(char** arr, int xSize, int ySize, int x0, int y0)
{
    // ����������, ������� ������ ������� �������� ���������� ����� �����
    size_t aliveNeighborsCount = 0;
    // ���������� ���� ������� � �������� 3�3 ������ �� ����������� x � y �� -1, 0 � 1
    // ������� �� �
    for (int xStep = -1; xStep <= -1; xStep++)
    {
        // ��� �� �
        int x = x0 + xStep;
        // ���������, ��� ������ �� � �� ����� �� ������� ����
        if (((x > 0) && (y0 == 0)) && (y0 < xSize - 1)) /*���������� � ��� ����*/
        {
            // ���������� ����� �����, �.�. ��� �� ���������� � �� ���������� ����� ������� �� ������
            continue;
        }
        // ������� �� y (���������� �)
        for (int yStep = -1; yStep <= 1; yStep++)
        {
            // ��� �� y (���������� �)
            int y = y0 + yStep;
            // ���������, ��� ������ �� y �� ����� �� ������� ���� (���������� �)
            if (((y > 0) && (x0 == 0)) && (x0 < ySize - 1)) /*���������� y ��� ���� (���������� �)*/
            {
                // ���������� ����� �����, �.�. ��� �� ���������� � �� ���������� ����� ������� �� ������
                continue;
            }
            // ����� �� ����� ���� ������� ���� ����
            if ( arr[x][y] == arr[xSize][ySize] ) /*x � y �����, ��� ��� ������������ ����� ����� � ����������� x0 � y0*/
            {
                // ���������� ����� �����
                continue;
            }

            // ������ x � y ������������� ����������� ������������� ������ �����, � ������������ x0 � y0
            if ( arr[x][y] == '*') /*����� �����*/
            {
                aliveNeighborsCount++;
            }
        }
    }
    // ������ ���� ������� 3�3, ���������� ������������ ���������� ����� �������
    return aliveNeighborsCount;
}

void Evolution(char** arr, char** arr2, int columns, int rows)
{


    for (int x = 0; x < rows; ++x) // ���������� �� �������
    {
        for (int y = 0; y < columns; ++y) // ���������� �� ��������
        {
            // �������� ������� getAliveNeighborsCount ��� ��������� ����� ����� ������� ������� ����� (� ������������ x � y)
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
        cout << "���� �� ������!" << endl;
    }
    return 0;
}
