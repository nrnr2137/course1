#include <iostream>
#include <vector>
#include <array>
#include <random>

void menu()
{
    std::cout << "0. Выход" << std::endl;
    std::cout << "1. Просмотр массива" << std::endl;
    std::cout << "2. Добавить элемент в начало" << std::endl;
    std::cout << "3. Добавить элемент в конец" << std::endl;
    std::cout << "4. Очистка всего массива" << std::endl;
    std::cout << "5. Поиск элемента в массиве" << std::endl;
    std::cout << "6. Добавить нули по минимальному модулю" << std::endl;
    std::cout << "Выберите опцию: ";
}

void matrx(std::vector<int>& vec)
{
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != (vec.size() - 1))
        {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;
}

void twom(std::vector<int>& vec)
{
    int l;
    std::cout << "Введите элемент: ";
    std::cin >> l;

    std::cout << "Массив до: ";
    matrx(vec);

    vec.reserve(vec.size() + 1);
    vec.insert(vec.begin(), l);

    std::cout << "Массив после: ";
    matrx(vec);
}

void threem(std::vector<int>& vec)
{
    int l;
    std::cout << "Введите элемент: ";
    std::cin >> l;

    std::cout << "Массив до: ";
    matrx(vec);

    vec.reserve(vec.size() + 1);
    vec.push_back(l);

    std::cout << "Массив после: ";
    matrx(vec);
}

void fourm(std::vector<int>& vec)
{
    std::cout << "Массив до: ";
    matrx(vec);

    vec.clear();

    std::cout << "Массив после: ";
    matrx(vec);
}

void fivem(const std::vector<int>& vec)
{
    int l;
    std::cout << "Введите элемент: ";
    std::cin >> l;

    std::cout << "Индекс/ы элемента " << l << ": [";
    bool f = false;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (vec[i] == l)
        {
            if (f) std::cout << ",";
            std::cout << i;
            f = true;
        }
    }
    std::cout << "]" << std::endl;

    if (!f)
    {
        std::cout << "Элемент не найден" << std::endl;
    }
}

void sixm(std::vector<int>& vec)
{
    if (vec.empty())
    {
        std::cout << "Массив пуст" << std::endl;
        return;
    }

    std::cout << "Массив до: ";
    matrx(vec);

    int min = std::numeric_limits<int>::max();
    for (int num : vec)
    {
        if (num != 0)
        {
            int absnum = std::abs(num);
            if (absnum < min)
            {
                min = absnum;
            }
        }
    }

    if (min == std::numeric_limits<int>::max())
    {
        std::cout << "В массиве нет ненулевых элементов" << std::endl;
        return;
    }

    for (int i = 0; i < min; ++i)
    {
        vec.push_back(0);
    }

    std::cout << "Добавлено " << min << " нулей" << std::endl;
    std::cout << "Массив после: ";
    matrx(vec);
}





// пункт2
const int numb = 10;

void arrmatrx(const std::array<int, numb >& arr)
{
    std::cout << "[";
    for (int i = 0; i < numb; i++) {
        std::cout << arr[i];
        if (i < numb - 1) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

//по значению (создается копия объекта)
void ones(std::array<int, numb > arr, const int size)
{
    std::cout << "массив до: ";
    arrmatrx(arr);
    std::sort(arr.begin(), arr.end());
    std::cout << "по возрастанию ";
    arrmatrx(arr);

    std::sort(arr.begin(), arr.end(), std::greater<int>());
    std::cout << "по убыванию";
    arrmatrx(arr);

}

//передача по ссылке (ссылка на оригинальный объект)
void twos(std::array<int, numb >& arr, const int size)
{
    std::cout << "массив до: ";
    arrmatrx(arr);
    std::sort(arr.begin(), arr.end());
    std::cout << "по возрастанию ";
    arrmatrx(arr);

    std::sort(arr.begin(), arr.end(), std::greater<int>());
    std::cout << "по убыванию";
    arrmatrx(arr);
}

// передача по указателю (передается адрес объекта,без копирования)
void threes(std::array<int, numb >* arr, const int size)
{
    std::cout << "массив до: ";
    arrmatrx(*arr);
    std::sort(arr->begin(), arr->end());
    std::cout << "по возрастанию ";
    arrmatrx(*arr);

    std::sort(arr->begin(), arr->end(), std::greater<int>());
    std::cout << "по убыванию";
    arrmatrx(*arr);
}


int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<int> vector;
    int choice;
    std::cout << "Пункт 1" << std::endl;
    do
    {
        menu();
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            std::cout << "Выход"<<std::endl;
            break;
        case 1:
            std::cout << "Текущий массив: ";
            matrx(vector);
            break;
        case 2:
            twom(vector);
            break;
        case 3:
            threem(vector);
            break;
        case 4:
            fourm(vector);
            break;
        case 5:
            fivem(vector);
            break;
        case 6:
            sixm(vector);
            break;
        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    } while (choice != 0);

    std::cout << "Пункт 2" << std::endl;

    std::array<int, numb> arr;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(-10, 10);

    for (int i = 0; i < numb; i++)
    {
        arr[i] = dist(rd);
    }

    ones(arr, numb);

    std::cout << "после функции";
    arrmatrx(arr);
    std::cout << "массив не изменился (работа с копией)" << std::endl;

    for (int i = 0; i < numb; i++)
    {
        arr[i] = dist(rd);
    }

    twos(arr, numb);

    std::cout << "после функции";
    arrmatrx(arr);
    std::cout << "массив изменился (работа с оригиналом)" << std::endl;

    for (int i = 0; i < numb; i++)
    {
        arr[i] = dist(rd);
    }

    threes(&arr, numb);

    std::cout << "массив после";
    arrmatrx(arr);
    std::cout << "массив изменился (работа с оригиналом через указатель)" << std::endl;



    std::cout << "Пункт 3" << std::endl;
    //Объяснить выбор реализации в п1 и п2, почему на самом деле здесь нет выбора 
    //когда std::vector и std::array выполняют одинаковою роль.
    std::cout << "для п1 нужен динамичный массив, std::array только статичный. => подходит только std::vector и выбора нет " << std::endl;
    std::cout << "размер std::vector можно фиксировать, тогда std::vector и std::array оба будут статичными" << std::endl;


    return 0;
}