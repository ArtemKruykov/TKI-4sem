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
    
    std::cout << "Введите четное количество элементов: ";
    
    std::list<int> L;
    std::copy(
        std::istream_iterator<int>(std::cin),
        std::istream_iterator<int>(),
        std::back_inserter(L)
    );

    if (L.size() % 2 != 0)
    {
        std::cout << "Ошибка: количество элементов должно быть четным\n";
        return 0;
    }
    
    auto i = L.begin();
    std::advance(i, L.size() / 2);

    for (auto j = i; j != L.begin(); )
    {
        L.insert(j--, -1);
    }

    std::cout << "Результат: ";

    std::copy(L.begin(), L.end(),
        std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
