// 1106 2019数列 (15 分)
// 把 2019 各个数位上的数字 2、0、1、9 作为一个数列的前 4 项，用它们去构造一个无穷数列。
// 其中第 n（>4）项是它前 4 项之和的个位数字。例如第 5 项为 2， 因为 2+0+1+9=12，个位数是 2。

// 本题就请你编写程序，列出这个序列的前 n 项。

#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<int> s{2, 0, 1, 9};
    s.reserve(1000);
    if (n >= 5)
    {   
        for (auto i = 4; i != n; ++i)
        {
            int tmp = 0;
            for (auto j = 0; j != 4; ++j)
            {
                tmp += s[i - j - 1];
            }
            s.push_back(tmp % 10);
        }
    }
    for (auto i = 0; i != n; ++i)
        std::cout << s[i];
    std::cout << std::endl;
    return 0;
}