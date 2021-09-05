#include <stdio.h>
#include <iostream>
#include <Windows.h>

int main(void)
{
    std::cout << "Print test data\n" << std::endl;
    int a[5] = { 23,443,16,49,66 };

    for (auto &ii : a)
    {
        std::cout << "auto ii: " << ii << std::endl;
    }

    printf("\n");

    for (auto jj : a)
    {
        std::cout << "auto jj: " << jj << std::endl;
    }
    system("pause");

}

 
