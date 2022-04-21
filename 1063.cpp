// 1063 计算谱半径 (20 分)
// 在数学中，矩阵的“谱半径”是指其特征值的模集合的上确界。
// 换言之，对于给定的 n 个复数空间的特征值，它们的模为实部与虚部的平方和的开方，而“谱半径”就是最大模。
// 现在给定一些复数空间的特征值，请你计算并输出这些特征值的谱半径。

#include <iostream>
#include <cmath>

int main()
{
    int N = 0;
    std::cin >> N;
    double max = 0.0;
    for (int i = 0; i != N; ++i)
    {
        int a = 0, b = 0;
        double tmp = 0.0;
        std::cin >> a >> b;
        tmp = sqrt(a * a + b * b);
        if (tmp > max)
            max = tmp;
    }
    printf("%.2f", max);
    return 0;
}

