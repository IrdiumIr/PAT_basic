// 1051 复数乘法 (15 分)
// 复数可以写成 (A+Bi) 的常规形式，其中 A 是实部，B 是虚部，i 是虚数单位，满足 i 
// 2
//  =−1；也可以写成极坐标下的指数形式 (R×e 
// (Pi)
//  )，其中 R 是复数模，P 是辐角，i 是虚数单位，其等价于三角形式 R(cos(P)+isin(P))。

// 现给定两个复数的 R 和 P，要求输出两数乘积的常规形式。

#include <iostream>
#include <cmath>
#include <iomanip>
// cout控制输出格式太难了……
// printf简单些

int main()
{
    double r1, p1, r2, p2, A, B;
    std::cin >> r1 >> p1 >> r2 >> p2;
    A = r1 * r2 * (cos(p1) * cos(p2) - sin(p1) * sin(p2));
    B = r1 * r2 * (cos(p1) * sin(p2) + sin(p1) * cos(p2));// 展开
    if (A >= -0.005 && A <= 0)
        std::cout << "0.00";
    else
        std::cout << std::fixed << std::setprecision(2) << A;
    //----------------------------
    if (B > 0)
        std::cout << "+" << std::fixed << std::setprecision(2) << B << "i" << std::endl;
    else if (B >= -0.005 && B <= 0)
        std::cout << "+"
                  << "0.00"
                  << "i" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(2) << B << "i" << std::endl;
    return 0;
}

// given solution from github by `liuchuo-`
// if (A + 0.005 >= 0 && A < 0)
//         printf("0.00");
//     else
//         printf("%.2f", A);
//     if(B >= 0)
//         printf("+%.2fi", B);
//     else if (B + 0.005 >= 0 && B < 0)
//         printf("+0.00i");
//     else
//         printf("%.2fi", B);