#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>

void Fill(std::vector<int> &vec)
{
    for (int i = 0; i < 32; i++) {
        vec.push_back(rand() % 201 - 100);
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl<< "Вектор готов" << std::endl;
}

void CocktailSort(std::vector<int> &vec) 
{
    int L = 0;
    int R = vec.size() - 1;
    int sorted = 0;
    do {
        for (int i = L; i < R; i++) 
        {
            if (vec[i] > vec[i + 1]) 
            {
                std::swap(vec[i], vec[i + 1]);
                sorted = i;
            }
        }
        R = sorted;
        for (int i = R; i > L; i--) 
        {
            if (vec[i] < vec[i - 1]) 
            {
                std::swap(vec[i], vec[i - 1]);
                sorted = i;
            }

        }
        L = sorted;
    } while (L < R);

}

void Compose(std::vector<int> &L, std::vector<int> &R, std::vector<int> &vec) //for Merge sort
{
    int sL = L.size();
    int sR = R.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while (sL > i and sR > j)
    {
        if (L[i] < R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    while (sL > i)
    {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (sR > j)
    {
        vec[k] = R[j];
        i++;
        j++;
    }
}

void MergeSort(std::vector<int> &vec)
{
    std::vector<int> L;
    std::vector<int> R;
    int m = vec.size() / 2;
    if (vec.size() >= 2)
    {
        for (int i = 0; i < m; i++)
        {
            L.push_back(vec[i]);
        }
        for (int i = m; i < vec.size(); i++)
        {
            R.push_back(vec[i]);
        }
    }
    else
    {
        return;
    }
    MergeSort(L);
    MergeSort(R);
    Compose(L, R, vec);
}

void BitonicMerge(std::vector<int> &vec, int begin, int size, bool direction)
{
    // direction = 1 if ascends, direction = 0 if descends
    if (size > 1)
    {
        int m = size / 2;
        for (int i = begin; i < begin + m; i++)
        {
            if (direction == (vec[i] > vec[i + m])) std::swap(vec[i], vec[i + m]);
        }
        BitonicMerge(vec, begin, m, direction);
        BitonicMerge(vec, begin + m, m, direction);
    }
}

void BitonicS(std::vector<int> &vec, int begin, int size, bool direction)
{
    if (size > 1)
    {
        int m = size / 2;
        BitonicS(vec, begin, m, 1);
        BitonicS(vec, begin + m, m, 0);
        BitonicMerge(vec, begin, size, direction);
    }
}

void BitonicSort(std::vector<int> &vec, int begin, int size, bool direction)
{
    bool even = true;
    int end;
    if (vec.size() % 2 != 0)
    {
        even = false;
        end = vec.back();
        vec.pop_back();
    }
    BitonicS(vec, begin, vec.size(), direction);
    if (!even)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if ((vec[i] > end and vec[i + 1] < end) || (vec[i] < end and vec[i + 1] > end))
            {
                vec.insert(vec.begin() + i, end);
                break;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::srand(std::time(nullptr));
    int x, n;
    bool direction = true; //ascends
    std::vector<int> vec1;
    std::cout << "Выберите задание (1, 2 или 3): ";
    std::cin >> x;
    Fill(vec1);
    switch (x) {
    case 1:
        CocktailSort(vec1);
        break;
    case 2:
        MergeSort(vec1);
        break;
    case 3:
        BitonicSort(vec1, 0, vec1.size(), direction);
        break;
    }
    for (int i : vec1 ) std::cout << i << " ";
    std::cout << std::endl << "Вектор отсортирован";
}