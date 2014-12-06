// Все делящиеся на 3 числа из списка возвести в квадрат, остальные - в куб.

#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>


using namespace std;


class Predicate
{
public:
    Predicate () = default;
    Predicate (const Predicate &orig) = default;
    Predicate &operator=(const Predicate &rhs) = default;
    ~Predicate() = default;

    int operator()(int i)
    {
        if (i % 3)
            i = pow(i,3);
        else
            i = pow(i,2);
        return i;
    }

};

int main()
{
    list <int> l;
    int i;
    for (i = 0; i < 10; i++)
        l.push_back(rand() % 99 + 1);
    cout << "Iznacalniy spisok..." << endl;
    list <int>::iterator r = l.begin();
    while (r != l.end())
    {
        cout << *r << " ";
        r++;
    }
    cout << endl << endl;
    r = transform(l.begin(), l.end(), l.begin(), Predicate());
    cout << "Pererabotanniy spisok..." << endl;
    r = l.begin();
    while (r != l.end())
    {
        cout << *r << " ";
        r++;
    }
    cout << endl;
    return 0;
}
