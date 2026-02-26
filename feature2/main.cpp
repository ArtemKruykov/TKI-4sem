#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

/**
 * @brief Вставляет -1 после каждого элемента первой половины списка
 * @return 0 при успешном выполнении
 */
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int n;

    std::cout << "Введите количество элементов (n): ";
    std::cin >> n;

    if (n % 2 != 0)
    {
        std::cout << "Ошибка: n должно быть четным!" << std::endl;
        return 0;
    }

    std::list<int> L;

    std::cout << "Введите " << n << " целых чисел: ";

    for (int k = 0; k < n; ++k)
    {
        int x;
        std::cin >> x;
        L.push_back(x);
    }

    std::list<int>::iterator i = L.begin();
    std::advance(i, n / 2);

    for (int k = 0; k < n / 2; ++k)
    {
        L.insert(i--, -1);
    }

    std::cout << "Результат: ";

    std::copy(
        L.begin(),
        L.end(),
        std::ostream_iterator<int>(std::cout, " ")
    );

    std::cout << std::endl;

    return 0;
}