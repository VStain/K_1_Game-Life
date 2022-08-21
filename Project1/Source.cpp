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
int alive_count(char** arr, int i, int j, int rows, int cols)
{
    int count = 0;
    for (int k = i - 1; k <= i + 1; ++k) // ���� ����� � ���� �� �������
        if (k >= 0 && k < rows) // �������� ������ ����
            for (int l = j - 1; l <= j + 1; ++l) // ���� ����� � ������ �� ��������
                if (l >= 0 && l < cols && (k != i || l != j)) // �������� ������ � ��������� ���� ������
                    if (arr[k][l] == '*') // ������� ����?
                        ++count;
    return count;
}

void Evolution(char** arr, char** arr2, int columns, int rows)
{
    for (int x = 0; x < rows; ++x) // ���������� �� �������
    {
        for (int y = 0; y < columns; ++y) // ���������� �� ��������
        {
            // �������� ������� alive_count (getAliveNeighborsCount) ��� ��������� ����� ����� ������� ������� ����� (� ������������ x � y)
            //arr2[x][y] = '-';
            int alive_cell = alive_count(arr, x, y, rows, columns);
            if (arr[x][y] == '-') // ���� ������ ������
            {
                for (int x0 = -1; x0 <= 1; ++x0) // �������� ������, ����� ����� ����� �������
                {
                    for (int y0 = -1; y0 <= 1; ++y0)
                    {
                        alive_cell += arr[x + x0][y + y0]; // ������� ������� ����� ������ �����
                        alive_cell -= arr[x][y]; // �� ������� ����;
                        if (arr[x][y] == 0 && alive_cell == 3) // ���� �����_������� == 3
                        {
                            arr2[x][y] = '*'; // �� �������_������_�_�����_����;
                        }
                    }
                }
            if (arr[x][y] == '*') // ���� ������ ���� 
            {
                for (int x0 = -1; x0 <= 1; ++x0) // �������� ������, ����� ����� ����� �������
                {
                    for (int y0 = -1; y0 <= 1; ++y0)
                    {
                        alive_cell += arr[x + x0][y + y0]; // ������� ������� ����� ������ �����
                        alive_cell -= arr[x][y]; // �� ������� ����;
                        if (alive_cell < 2 || alive_cell > 3)   //���� �����_������� < 2 ��� �����_������� > 3
                        {
                            arr2[x][y] = '-';   //    �� ���������_������_�_�����_����;
                        }
                    }
                }

            }
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


            if (0 <= indexA && 0 <= indexB)
            {
                if (indexA < columns && indexB < rows)
                {
                    arr[indexA][indexB] = '*';
                }
            }
        }

        file_to_use.close();



        print(arr, columns, rows);

        Evolution(arr, arr2, columns, rows);

        print(arr2, columns, rows);
        Delete_Arr(arr, columns);
        arr = nullptr;

    }
    else
    {
        cout << "���� �� ������!" << endl;
    }
    return 0;
}
/*
* if (arr[x][y + 1] + arr[x][y - 1] + arr[x + 1][y] + arr[x - 1][y] + arr[x + 1][y + 1] + arr[x - 1][y - 1]  == 126 ) ������� � �������������
*/