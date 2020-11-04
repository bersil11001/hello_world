// Laba6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
void zapol(int** arr, int N, int M) {
    for (int i = 0; i < N; i++)
    {
        arr[i][0] = i + 1;
        for (int j = 1; j < M; j++) {
            arr[i][j] = rand() % 10;
        }
    }
}
void zapol(int* arr, int N) {
    for (int i = 0; i < N; i++)
    {
            arr[i] = 0;
    }
}
void vivod(int** arr, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }cout << endl;
    }cout << endl;
}
//void vivod(int* arr, int n) {
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << endl;
//    }cout << endl;
//}
void max(int** arr, int N, int M, int* temp) {
    int k;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] > temp[i]) {
                temp[i] = arr[i][j];
            }
        }
    }
}
void buble(int** arr, int N, int M, int* temp) {
    for (int k = 0; k < N; k++)
    {


        for (int i = N; 0 < i; i--) {
            if (temp[i] > temp[i - 1]) {
                temp[i] = temp[i - 1] + temp[i];
                temp[i - 1] = temp[i] - temp[i - 1];
                temp[i] = temp[i] - temp[i - 1];

                for (int j = M; j >= 0; j--) {
                    arr[i][j] = arr[i - 1][j] + arr[i][j];
                    arr[i - 1][j] = arr[i][j] - arr[i - 1][j];
                    arr[i][j] = arr[i][j] - arr[i - 1][j];
                }
            }
        }
    }
}//a=a+b;
//b=a-b;
//a=a-b;
int main()
{   
    system("chcp 1251>nul");
    const time_t timer = time(NULL);
    srand(timer);
    int N, M;
    cout << "задайте количиство элементов ";
    cin >> N >> M;
    int** arr = new int*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[M];
    } 
    zapol(arr, N, M);
    vivod(arr, N, M);
    int* temp = new int[N];
    zapol(temp, N);
    max(arr, N, M, temp);
    buble(arr, N, M, temp);
    cout << "Результат сортировки : " << endl;
    vivod(arr, N, M);
    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] temp;
    system("pause>nul");
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
