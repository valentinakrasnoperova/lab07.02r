#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;

void CreateRow(int** P, const int colCount, int High, int Low, int rowNo, int colNo) {
    P[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1) {
        CreateRow(P, colCount, High, Low, rowNo, colNo + 1);
    }
}

void Create(int** P, const int rowCount, const int colCount, int High, int Low, int rowNo) {
    CreateRow(P, colCount, High, Low, rowNo, 0);
    if (rowNo < rowCount - 1) {
        Create(P, rowCount, colCount, High, Low, rowNo + 1);
    }
}

void PrintRow(int** P, const int colCount, int rowNo, int colNo) {
    cout << setw(4) << P[rowNo][colNo];
    if (colNo < colCount - 1) {
        PrintRow(P, colCount, rowNo, colNo + 1);
    }
    else {
        cout << endl;
    }
}

void Print(int** P, const int rowCount, const int colCount, int rowNo) {
    PrintRow(P, colCount, rowNo, 0);
    if (rowNo < rowCount - 1) {
        Print(P, rowCount, colCount, rowNo + 1);
    }
    else {
        cout << endl;
    }
}



int colMax(int** P, const int rowCount, const int j, int colMaxEl, int i) {
    if (P[j][i] > colMaxEl) {
        colMaxEl = P[j][i];
    }
    if (i < rowCount - 1) {
        colMax(P, rowCount, j, colMaxEl, i + 1);
    } else
        return colMaxEl;
}

int arrSearchCol(int** P, const int colCount, const int rowCount, int maxEl, int j) {
    if ((j + 1) % 2 == 0) {
        int colMaxEl = colMax(P, rowCount, j, P[0][j], 0);
        if (colMaxEl < maxEl) {
            maxEl = colMaxEl;
        }
    }
    if (j < colCount - 1) {
        arrSearchCol(P, colCount, rowCount, maxEl, j + 1);
    }
    else {
        return maxEl;
    }
}

int main()
{
    int Low = -21;
    int High = 24;

    int rowCount;
    int colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** P = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        P[i] = new int[colCount];

    Create(P, rowCount, colCount, High, Low, 0);
    Print(P, rowCount, colCount, 0);

    int maxEl = colMax(P, colCount, 1, P[0][0], 0);

    cout << arrSearchCol(P, colCount, rowCount, maxEl, 0) << endl;

    return 0;
}