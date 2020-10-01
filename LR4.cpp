#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

void Filler1(std::vector<int>& vec, int n){
    std::srand(std::time(nullptr));
    for (int i = 0; i <= n; i++){
        vec.push_back(rand() % 201 - 100);
        std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;
}

void Filler2(std::vector<int>& vec){
    std::srand(std::time(nullptr));
    int m, b;
    m = rand() % 6 + 30;
    b = rand() % 31;

}

void CocktailSort(std::vector<int>& vec){
    int L = 0;
    int R = vec.size() - 1;
    int A;
    do{
        for (int i = L; i < R; i++){
            if (vec[i] > vec[i+1]){
                A = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = A;
            }
        }
        R--;
        for (int i = R; i > L; i--){
            if(vec[i] < vec[i-1]){
                A = vec[i];
                vec[i] = vec[i-1];
                vec[i-1] = vec[i];
            }

        }
        L++;
    } while (L < R);

}

void MergeSort{

}

void BitonicSort{

}

int main(){
    int x, n;
    std::vector<int> vec1;
    std::cout<<"Choose sort(1, 2 or 3): "<<std::endl;
    std::cin>>x;
    switch (x){
        case 1:
            std::cout<<"Enter n (n >= 30): "<<std::endl;
            std::cin>>n;
            Filler1(vec1, n);
            CocktailSort(vec1);
        case 2:
            MergeSort(vec1);
        case 3:
            BitonicSort(vec1);
    }
    for (int i = 0; i < vec1.size(); i++) {
        std::cout<<vec1[i]<<" ";
    }
}

