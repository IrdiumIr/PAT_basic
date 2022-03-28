// 1021 个位数统计 (15 分)

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string str;
    std::cin >> str;
    std::vector<int> ivec(10, 0);
    for (std::string::size_type i = 0; i != str.size(); ++i)
        ++ivec[str[i] - '0'];
    for (int i = 0; i != 10; ++i)
    {
        if (ivec[i] != 0)
            std::cout << i << ":" << ivec[i] << std::endl;
    }
    return 0;
}