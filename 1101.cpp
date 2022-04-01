// 1101 B是A的多少倍 (15 分)
// 截下来移到 A 的最高位前面，就形成了一个新的数 B。
// B 是 A 的多少倍？例如将 12345 的最低 2 位 45 截下来放到 123 的前面，就得到 45123，它约是 12345 的 3.66 倍。

#include <iostream>
#include <iomanip>
#include <string>
// 数字循环算法&string拼接
int main()
{
    int A = 0, D = 0;//12345, 2
    std::cin >> A >> D;
    int tmpvar = 1;
    int count = 0;// A位数
    for (auto i = 0; i != D; ++i)
        tmpvar *= 10;//用于%和/输入的A
    int ad = A % tmpvar;// 45
    int al = A / tmpvar;// 123

    int A_save = A;
    while (A != 0)
    {
        ++count;
        A /= 10;
    }// count=5  且此时A=0已不可用
    for (auto i = 0; i != (count - D); ++i)
        ad *= 10;
    float B = ad + al;// 45123
    std::cout << std::fixed << std::setprecision(2) << (B / A_save) << std::endl;
    return 0;
}

// int main()
// {
//     std::string A;
//     int D;
//     std::cin >> A >> D;
//     std::string Ad = A.substr(A.length() - D, D) + A;
//     Ad.erase(Ad.end() - D, Ad.end());
//     double b = stoi(Ad) * 1.0 / stoi(A);
//     std::cout << std::fixed << std::setprecision(2) << b << std::endl;
//     return 0;
// }