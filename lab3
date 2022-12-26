#include <iostream>
#include <Windows.h>

using namespace std;

const int N = 10;
void showArr(int(*arr)[N]) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            destCoord.X = i * 4;
            destCoord.Y = j;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << arr[i][j];
        }
    }
}
void setcoord(int x,int y,int a) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    destCoord.X = x * 4;
    destCoord.Y = y;
    SetConsoleCursorPosition(hStdout, destCoord);
    cout << a;
    cout.flush();
    Sleep(50);
}
void spiral(int(*arr)[N]) {    
    int k = -1;
    int dir = 1;
    for (int z = 0; z < 2 * N - 1; z++) {
        if (z % 4 == 0) k++;
        switch (dir) {
        case 1:
            for (int i = k; i < N - k; i++) {
                arr[i][k] = rand() % (N * N) + 1;
                setcoord(i, k, arr[i][k]);
            }
            dir = 2;
            break;         
        case 2:
            for (int j = k+1; j < N - k; j++) {
                arr[N-k-1][j] = rand() % (N * N) + 1;
                setcoord(N - k - 1, j, arr[N-k-1][j]);
            }
            dir = 3;
            break;
        case 3: 
            for (int i = N - k - 2; i > k-1; i--) {
                arr[i][N-k-1] = rand() % (N * N) + 1;
                setcoord(i,N - k - 1, arr[i][N-k-1]);
            }
            dir = 4;
            break;
        case 4:
            for (int j = N - k - 2; j > k; j--) {
                arr[k][j] = rand() % (N * N) + 1;
                setcoord(k, j, arr[k][j]);
            }
            dir = 1;
        }
    }
}
void rearr1(int(*arr)[N]) {
    for (int i = 0; i < (N / 2); i++) {
        for (int j = 0; j < N; j++) {
            swap(arr[i][j], arr[i + (N / 2)][j]);
        }
    }
    for (int i = 0; i < (N / 2); i++) {
        for (int j = 0; j < (N / 2); j++) {
            swap(arr[i][j], arr[i + (N / 2)][j + (N / 2)]);
        }
    }
}
void rearr2(int(*arr)[N]) {
    for (int i = 0; i < (N / 2); i++) {
        for (int j = 0; j < (N / 2); j++) {
            swap(arr[i][j], arr[i + (N / 2)][j + (N / 2)]);
        }
    }
    for (int i = N/2; i < N; i++) {
        for (int j=0; j < N/2; j++) {
            swap(arr[i][j], arr[i - (N / 2)][j + (N / 2)]);
        }
    }
}
void rearr3(int(*arr)[N]) {
    for (int i = 0; i < (N / 2); i++) {
        for (int j = 0; j < (N / 2); j++) {
            swap(arr[i][j], arr[i][j + (N / 2)]);
        }
    }
    for (int i = N / 2; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            swap(arr[i][j], arr[i][j + (N / 2)]);
        }
    }
}
void rearr4(int(*arr)[N]) {
    for (int i = 0; i < (N / 2); i++) {
        for (int j = 0; j < (N / 2); j++) {
            swap(arr[i][j], arr[i+(N/2)][j]);
        }
    }
    for (int i = 0; i < N/2; i++) {
        for (int j = N/2; j < N; j++) {
            swap(arr[i][j], arr[i + (N / 2)][j]);
        }
    }
}
void sortArr(int(*arr)[N]) {
    int* pt = arr[0];
    bool sorted = false;

    while (sorted != true) {
        sorted = true;
        for (int i = 0; i < (N * N - 1); i++)
            if (*(pt + i) > *(pt + i + 1)) {
                swap(*(pt + i), *(pt + i + 1));
                sorted = false;
            }

    }
}
int main()
{
    setlocale(0,"");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int a[N][N];
    spiral(a);
    Sleep(500);
    system("cls");
    rearr1(a);
    showArr(a);
    Sleep(500);
    system("cls");
    rearr2(a);
    showArr(a);
    Sleep(500);
    system("cls");
    rearr3(a);
    showArr(a);
    Sleep(500);
    system("cls");
    rearr4(a);
    showArr(a);
    Sleep(5000);
    system("cls");
    sortArr(a);
    showArr(a);
    int input;
    char sign;
    cout <<'\n'<< "Напишите действие ('+', '-', '*', '/') и число через пробел \n";
    cin >> sign >> input;
    if (sign == '+') {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] += input;
    }
    else if (sign =='-') {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] -= input;
    }
    else if (sign == '*') {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] *= input;
    }
    else if (sign == '/') {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] /= input;
    }
    showArr(a);
    return 0;
}
