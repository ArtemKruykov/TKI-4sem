#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

/**
 * @brief Подсчитывает суммарную длину слов по первой букве и выводит результат
 * @return 0 - успешное выполнение
 */
int main(int argc, char* argv[]) {
    /**
     * @brief Вектор английских слов, набранных заглавными буквами
     */
    std::vector<std::string> V = {
        "APPLE",
        "BANANA",
        "APRICOT",
        "CHERRY",
        "BERRY",
        "AVOCADO",
        "CHERRY",
        "BANANA"
    };

    /**
     * @brief Вспомогательное отображение M
     * @key первая буква слова
     * @value суммарная длина слов, начинающихся с этой буквы
     */
    std::map<char, int> M;

    /**
     * @brief Заполнение отображения M с использованием алгоритма for_each
     * @param V.begin итератор на начало вектора
     * @param V.end итератор на конец вектора
     * @param лямбда-функция для обработки каждого слова
     */
    std::for_each(V.begin(), V.end(), [&M](const std::string& word) {
        char firstLetter = word[0];
        M[firstLetter] += word.size();
        });

    /**
     * @brief Вывод результатов с использованием алгоритма for_each
     * @param M.begin итератор на начало отображения
     * @param M.end итератор на конец отображения
     * @param лямбда-функция для вывода каждой пары буква-длина
     */
    std::for_each(M.begin(), M.end(), [](const std::pair<const char, int>& pair) {
        std::cout << pair.first << pair.second;
        });

    std::cout << std::endl;

    return 0;
}