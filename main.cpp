

#include <iostream>
#include "CrossArray.hpp"

int main() {
    sjtu::CrossArray ca(5);
    int arr1[] = {1, 2, 3};
    ca.InsertArrays(arr1, 3);
    int arr2[] = {4, 5};
    ca.InsertArrays(arr2, 2);

    std::cout << "At(0, 1): " << ca.At(0, 1) << " (expected 2)" << std::endl;
    std::cout << "At(1, 0): " << ca.At(1, 0) << " (expected 4)" << std::endl;

    int arr3[] = {6, 7};
    ca.AppendArrays(arr3, 0, 2);
    std::cout << "At(0, 3): " << ca.At(0, 3) << " (expected 6)" << std::endl;
    std::cout << "At(0, 4): " << ca.At(0, 4) << " (expected 7)" << std::endl;

    sjtu::CrossArray ca2 = ca;
    std::cout << "ca2 At(0, 4): " << ca2.At(0, 4) << " (expected 7)" << std::endl;
    ca2.At(0, 4) = 10;
    std::cout << "ca At(0, 4): " << ca.At(0, 4) << " (expected 7)" << std::endl;
    std::cout << "ca2 At(0, 4): " << ca2.At(0, 4) << " (expected 10)" << std::endl;

    std::cout << "IsSame(ca2): " << ca.IsSame(ca2) << " (expected 0)" << std::endl;
    std::cout << "IsSame(ca): " << ca.IsSame(ca) << " (expected 1)" << std::endl;

    ca.DoubleCrossLength();
    int arr4[] = {8, 9, 10, 11, 12, 13};
    ca.InsertArrays(arr4, 6);
    ca.InsertArrays(arr4, 6);
    ca.InsertArrays(arr4, 6);
    bool res = ca.InsertArrays(arr4, 6);
    std::cout << "Insert 6th array: " << res << " (expected 1)" << std::endl;
    
    sjtu::CrossArray & greater = ca.WhichGreater(ca2);
    std::cout << "WhichGreater is ca: " << (&greater == &ca) << " (expected 1)" << std::endl;

    return 0;
}

