// 1013 数素数 (20 分)
// 令 P i表示第 i 个素数。现任给两个正整数 M≤N≤10 4
// 请输出 P M到 P N的所有素数。

#include <iostream>
#include <cmath>
#include <vector>

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
    int M = 0, N = 0, count = 0, num = 2;
    std::vector<int> ivec;
    std::cin >> M >> N;
    while (count < N)
    {
        if (isPrime(num))
        {    
            ++count;
            if (count >= M)// Pm-Pn之间计入计算范围
                ivec.emplace_back(num);
        }
        ++num; 
    }
    
    int count_line = 0;
    for (int i = 0; i != (N - M + 1); ++i)
    {   // 当某一行不足10个时，尾数会多输出一个" "
        // ++count_line;
        // if ((count_line % 10) != 0)
        //     std::cout << ivec[i] << " ";
        // else if ((count_line % 10) == 0)
        //     std::cout << ivec[i] << std::endl;
        ++count_line;
        if ((count_line % 10 != 1))
        {
            std::cout << " " << ivec[i];
            if ((count_line % 10 == 0))
                std::cout << std::endl;
        }
        else if ((count_line % 10 == 1))
            std::cout << ivec[i];
    }
    return 0;
}