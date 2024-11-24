#include <iostream>
#include <cmath>
using namespace std;

// Итеративный метод
double IterativeSum(const int N)
{
    double S = 0;
    for (int i = N; i <= 20; i++)
    {
        S += (cos(i) + sin(i)) / (1 + cos(i) * sin(i));
    }
    return S;
}

// Рекурсивный метод с увеличением индекса (вверх)
double Rec1(const int N, const int i)
{
    if (i > 20)
        return 0;
    else
        return (cos(i) + sin(i)) / (1 + cos(i) * sin(i)) + Rec1(N, i + 1);
}

// Рекурсивный метод с уменьшением индекса (вниз)
double Rec2(const int N, const int i)
{
    if (i < N)
        return 0;
    else
        return (cos(i) + sin(i)) / (1 + cos(i) * sin(i)) + Rec2(N, i - 1);
}

// Рекурсивный метод с аккумулятором (вверх)
double Rec3(const int N, const int i, double t)
{
    t = t + (cos(i) + sin(i)) / (1 + cos(i) * sin(i));
    if (i >= 20)
        return t;
    else
        return Rec3(N, i + 1, t);
}

// Рекурсивный метод с аккумулятором (вниз)
double Rec4(const int N, const int i, double t)
{
    t = t + (cos(i) + sin(i)) / (1 + cos(i) * sin(i));
    if (i <= N)
        return t;
    else
        return Rec4(N, i - 1, t);
}

int main()
{
    setlocale(LC_CTYPE, "ukr");
    int N;
    cout << "Введiть значення N: ";
    cin >> N;

    cout << "(iter) S0 = " << IterativeSum(N) << endl;
    cout << "(rec up ++) S1 = " << Rec1(N, N) << endl;
    cout << "(rec up --) S2 = " << Rec2(N, 20) << endl;
    cout << "(rec down ++) S3 = " << Rec3(N, N, 0) << endl;
    cout << "(rec down --) S4 = " << Rec4(N, 20, 0) << endl;

    return 0;
}