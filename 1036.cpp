// 1036 跟奥巴马一起编程 (15 分)
// 美国总统奥巴马不仅呼吁所有人都学习编程，甚至以身作则编写代码，成为美国历史上首位编写计算机代码的总统。
// 2014 年底，为庆祝“计算机科学教育周”正式启动，奥巴马编写了很简单的计算机代码：在屏幕上画一个正方形。现在你也跟他一起画吧！

#include <iostream>

int main()
{
    int n = 0;// 边长
    char c;// char字符
    std::cin >> n >> c;
    // int row = n / 2 + 0.5;
    // n是偶数时并不需要+0.5
    int row = n / 2 + n % 2;
    for (int i = 0; i != n; ++i)
        std::cout << c;
    std::cout << std::endl;
    for (int i = 0; i != row - 2; ++i)
    {
        std::cout << c;
        for (int k = 0; k != n - 2; ++k)
            std::cout << " ";
        std::cout << c << std::endl;
    }
    for (int i = 0; i != n; ++i)
        std::cout << c;
    std::cout << std::endl;
    return 0;
}