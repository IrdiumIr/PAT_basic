// 1016 部分A+B (15 分)

#include <iostream>

int main()
{
    int a = 0, b = 0, da = 0, db = 0, pa = 0, pb = 0;
    // int count1 = 0, count2 = 0;// 不用count计数 循环遍历过程累加即可
    std::cin >> a >> da >> b >> db;
    while (a != 0)// while (a / 10)会少计算一次
    {
        if (a % 10 == da)
            // {++count1;
            pa = pa * 10 + da;
        a /= 10;
    }
    // for (int i = 0; i != count1; ++i)
    // {
    //     pa = pa * 10 + da;
    // }
    while (b != 0)
    {
        if (b % 10 == db)
            // {++count2;
            pb = pb * 10 + db;
        b /= 10;
    }
    // for (int i = 0; i != count2; ++i)
    // {
    //     pb = pb * 10 + db;
    // }
    std::cout << pa + pb << std::endl;
    return 0;
}