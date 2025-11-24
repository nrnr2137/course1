#include <iostream>
#include <cstdlib>
#include <clocale>

// функции


//вывод матрицы
void printMatrix(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
        std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

//нахождения строк с нулевыми элементами
int* zerocount(int** matrix, int rows, int cols, int& zero)
{
    zero = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0) 
            {
                zero++;
                break; 
            }
        }
    }

    //память для индексов строк
    int* zeror = (int*)malloc(zero * sizeof(int));

    int p = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) 
        {
            if (matrix[i][j] == 0)
            {
                zeror[p++] = i;
                break;
            }
        }
    }

    return zeror;
}

//удаление строк из матрицы
void remove(int** matrix, int& rows, int cols)
{
    int l = 0;
    for (int i = 0; i < rows; i++) 
    {
        bool O = false;
        for (int j = 0; j < cols; j++) 
        {
            if (matrix[i][j] == 0) 
            {
                O = true;
                break;
            }
        }

        if (!O)
        {
            if (l != i) 
            {
                for (int j = 0; j < cols; j++)
                {
                    matrix[l][j] = matrix[i][j];
                }
            }
            l++;
        }
    }
    rows = l;
}


//основа 1,2
int main()
{

    setlocale(LC_ALL, "Russian");

    std::cout << "Пункт 1" << std::endl;

    //начальная матрица
    int** fm = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++)
    {
        fm[i] = (int*)malloc(2 * sizeof(int));
    }

    int A, B, C, D;

    do
    {
        std::cout << "Введите A (неотрицательное): ";
        std::cin >> A;
        if (A < 0) std::cout << "Ошибка! A должно быть неотрицательным." << std::endl;
    } while (A < 0);

    do
    {
        std::cout << "Введите B (неотрицательное): ";
        std::cin >> B;
        if (B < 0) std::cout << "Ошибка! B должно быть неотрицательным." << std::endl;
    } while (B < 0);

    std::cout << "Введите C: ";
    std::cin >> C;
    std::cout << "Введите D: ";
    std::cin >> D;

    fm[0][0] = A;
    fm[0][1] = B;
    fm[1][0] = C;
    fm[1][1] = D;

    std::cout << "начальная матрица:" << std::endl;
    printMatrix(fm, 2, 2);

    int nrows = 2 + A;
    int ncols = 2 + B; 

    int** bm = (int**)malloc(nrows * sizeof(int*));
    for (int i = 0; i < nrows; i++) 
    {
        bm[i] = (int*)malloc(ncols * sizeof(int));
        for (int j = 0; j < ncols; j++) 
        {
            bm[i][j] = i * C + j * D;
        }
    }

    std::cout << "расширенная матрица:" << std::endl;
    printMatrix(bm, nrows, ncols);


    int zeroCount;
    int* zeroRows = zerocount(bm, nrows, ncols, zeroCount);

    std::cout << "индекс строк с нулевыми элементами: ";
    for (int i = 0; i < zeroCount; i++)
    {
        std::cout << zeroRows[i] << " ";
    }
    std::cout << std::endl;


    remove(bm, nrows, ncols);

    std::cout << "финальная матрица:" << std::endl;
    printMatrix(bm, nrows, ncols);


    // Освобождаем память
    for (int i = 0; i < 2; i++)
    {
        free(fm[i]);
    }
    free(fm);

    for (int i = 0; i < nrows; i++) 
    {
        free(bm[i]);
    }
    free(bm);

    if (zeroRows != nullptr) 
    {
        free(zeroRows);
    }





    std::cout << "Пункт 2" << std::endl;

    int a, b;

    std::cout << "Введите значение a: ";
    std::cin >> a;
    std::cout << "Введите значение b: ";
    std::cin >> b;

    int* ptrA = new int;
    int* ptrB = new int;

    ptrA = &a;
    ptrB = &b;
    *ptrA *= 2;
    std::cout << "После увеличения a в 2 раза: " << a << ", b = " << b << std::endl;

    int cm = *ptrA;
    *ptrA = *ptrB;
    *ptrB = cm;

    std::cout << "После обмена значений: a = " << a << ", b = " << b << std::endl;

    delete ptrA;
    delete ptrB;

    return 0;
}