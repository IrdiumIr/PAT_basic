// 1011 A+B 和 C (15 分)
// 给定区间 [−2 31,2 31] 内的 3 个整数 A、B 和 C，请判断 A+B 是否大于 C。

#include <iostream>
#include <vector>

// ABC[i].push_back(abc);
// 使用此类的写法会直接导致程序中断
// vector二维数组必须逐个插入一维数组

int main()
{
    int count = 0;// 测试用例数
    std::cin >> count;
    std::vector<std::vector<long long int>> ABC;
    std::vector<long long int> tmp;
    for (int i = 0; i != count; ++i)
    {
        tmp.clear();
        for (int ii = 0; ii != 3; ++ii)
        {
            long long int abc = 0;
            std::cin >> abc;
            tmp.push_back(abc);
            // ABC[i].push_back(abc);
        }
        ABC.push_back(tmp);
    }
    for (int i = 0; i != count; ++i)
    {
        std::cout << "Case #" << i + 1 << ": " << (ABC[i][0] + ABC[i][1] > ABC[i][2] ? "true" : "false") << std::endl;
    }   
    return 0;
}

// given solution from github by `liuchuo-`
// for (int i = 0; i < n; i++) {
//         long long int a, b, c;
//         scanf("%lld%lld%lld", &a, &b, &c);
//         printf("Case #%d: %s\n", i + 1, a + b > c ? "true" : "false");
//     }