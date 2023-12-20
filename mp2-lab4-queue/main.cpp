#include "queue.h"

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    TQueue<int> a(5);
    int b;
    int c;
    cout << "Введите размер" << endl;
    cin >> c;
    cout << "Введите очередь"<<endl;
    for (int i = 0; i < c; i++)
    {
        cin >> b;
        a.Push(b);
    }
    cout << "Очередь" << endl;
    cout << a;
    cout << "Удаленный элемент: " << endl;
    cout<<a.Pop()<<endl;
    a.Push(6);
    cout << a;
}

