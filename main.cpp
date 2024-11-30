/*
Вариант 9
Дана последовательность целых чисел {Aj}. Найти произведение чисел, оканчивающихся цифрой 2, наибольшее из таких чисел и номер этого числа в последовательности.

Дано натуральное число N (N<10^9). Найти наиболее часто встречающуюся цифру числа N. Если таких чисел несколько, выведите любое.
*/


#include <iostream>
#include <vector>
#include <map>
using namespace std;





int main() 
{
//последовательнасть
    int subsequence;
    cout << "Enter subsequence: "; //получили послед.
    cin >> subsequence;

    vector<int> numbers(subsequence);
    long long product = 1;
    int maxNumber = -1;
    int maxIndex = -1;

    for (int i = 0; i < subsequence; ++i) 
    {
        cout << "Введите число A" << i + 1 << ": ";
        cin >> numbers[i];
        
//оканчивается ли число на 2?
        if (numbers[i] % 10 == 2) 
        {
            product *= numbers[i];
// проверка на максимальное число
            if (numbers[i] > maxNumber) 
            {
                maxNumber = numbers[i]; //число
                maxIndex = i + 1; // номер (индекс + 1)
            }
        }
    }

    if (maxNumber == -1) 
    {
        cout << "нет чисела, оканчивающивося на 2." << endl;
    } 
    else 
    {
        cout << "произведение чисел, оканчивающихся на 2: " << product << endl;
        cout << "наибольшее число, оканчивающееся на 2: " << maxNumber << endl;
        cout << "номер числа в последовательности: " << maxIndex << endl;
    }

//Найти наиболее часто встречающуюся цифру числа N
    long long N;
    cout << "Enter N (N < 10^9): ";
    cin >> N;

    map<int, int> Count;
    while (N > 0) 
    {
        int digit = N % 10;
       Count[digit]++;
        N /= 10;
    }

    int maxCount = 0;
    int most_frequent_digit = -1;

    for (const auto& pair : Count) 
    {
        if (pair.second > maxCount) 
        {
            maxCount = pair.second;
            most_frequent_digit = pair.first;
        }
    }

    cout << "наиболее часто встречающуюся цифру числа N: " << most_frequent_digit << endl;

    return 0;
}
