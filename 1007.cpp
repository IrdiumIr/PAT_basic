// 1007 素数对猜想 (20 分)
// “素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
// 现给定任意正整数N(<10e5)，请计算不超过N的满足猜想的素数对的个数。

#include <iostream>
#include <cmath>

auto isPrime(int n)
{
    // i * i <= n
    int sq = static_cast<int>(sqrt(n) + 1);
    for (auto i = 2; i != sq; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int N = 0;
    std::cin >> N;
    int count = 0;

    if (N >= 1 && N <= 4)// n=1234时无素数对
        std::cout << 0 << std::endl;
    else if (N >= 5)
    {
         for (auto i = 5; i != N + 1; ++i)// 2,3,5,7 d1=1已排除，从d2开始
        {
            if (isPrime(i) && isPrime(i - 2))
                ++count;
        }
        std::cout << count << std::endl;
    }
    return 0;
}