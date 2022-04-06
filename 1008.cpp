// 1008 数组元素循环右移问题 (20 分)
// 一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（≥0）个位置。
// （最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

#include <iostream>
#include <vector>
#include <algorithm>
// 不能每次记下尾数，再移动一位，次数较多
// 此算法类似于[矩阵的逆运算]
int main()
{
    int N, M = 0;
    std::cin >> N >> M;
    std::vector<int> arr(N);
    
    for (auto i = 0; i != N; ++i)
        std::cin >> arr[i];
    M %= N;// m>n时，归一到m<n的情况

    std::reverse(arr.begin(), arr.end());

    std::reverse(arr.begin(), arr.begin() + M);

    std::reverse(arr.begin() + M, arr.end());
    // A-B要变成B-A-->先全部反转变为B^-1-A^-1-->再分别反转
    for (auto i = 0; i != N - 1; ++i)
        std::cout << arr[i] << " ";
    std::cout << arr[N - 1] << std::endl;
    return 0;
}