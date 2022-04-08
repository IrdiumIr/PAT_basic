// 1022 D进制的A+B (20 分)
// 输入两个非负 10 进制整数 A 和 B (≤2 30−1)，
// 输出 A+B 的 D (1<D≤10)进制数。

#include <iostream>
#include <vector>

int main()
{
    int A = 0, B = 0, D = 0;
    std::cin >> A >> B >> D;
    int res = A + B;
    if (res == 0)
        std::cout << res;
    else if (res != 0)
    {
        std::vector<int> ans;
        while (res != 0)
        {
            ans.push_back(res % D);
            res /= D;
        }
        for (auto iter = ans.rbegin(); iter != ans.rend(); ++iter)
            std::cout << *iter;
    }
    return 0;
}