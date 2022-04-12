// 1037 在霍格沃茨找零钱 (20 分)
// 如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：
// “十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”
// 现在，给定哈利应付的价钱 P 和他实付的钱 A，你的任务是写一个程序来计算他应该被找的零钱。

#include <iostream>

int main()
{
    int a, b, c, x, y, z;
    int g = 0, s = 0; // abc应付xyz实付
    scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &x, &y, &z);
    
    int tmp = ((17 * x + y) * 29 + z) - ((17 * a + b) * 29 + c);
    
    if (tmp < 0)
        printf("-");
    tmp = abs(tmp);
    
    s = tmp / 29;
    if (s == 0)
        printf("%d.%d.%d", g, s, tmp);
    else
    {
        if (s >= 17)
        {
            g = s / 17;
            s = s % 17;
            printf("%d.%d.%d", g, s, tmp - 29 * (17 * g + s));
        }
        else
            printf("%d.%d.%d", g, s, tmp - 29 * s);
    }
    return 0;
}       
