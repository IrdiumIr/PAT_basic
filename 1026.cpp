// 1026 程序运行时间 (15 分)
// 要获得一个 C 语言程序的运行时间，常用的方法是调用头文件 time.h，其中提供了 clock() 函数，可以捕捉从程序开始运行到 clock() 被调用时所耗费的时间。
// 这个时间单位是 clock tick，即“时钟打点”。同时还有一个常数 CLK_TCK，给出了机器时钟每秒所走的时钟打点数。
// 于是为了获得一个函数 f 的运行时间，我们只要在调用 f 之前先调用 clock()，获得一个时钟打点数 C1；在 f 执行完成后再调用 clock()，获得另一个时钟打点数 C2；
// 两次获得的时钟打点数之差 (C2-C1) 就是 f 运行所消耗的时钟打点数，再除以常数 CLK_TCK，就得到了以秒为单位的运行时间。

// 这里不妨简单假设常数 CLK_TCK 为 100。现给定被测函数前后两次获得的时钟打点数，请你给出被测函数运行的时间。

#include <iostream>
#include <iomanip>

int main()
{
    int c1 = 0, c2 = 0;
    std::cin >> c1 >> c2;
    // int time = (c2 - c1) / 100;
    // 不足1s四舍五入补足
    int time = ((c2 - c1) + 50) / 100;// 或直接c2-c1/100 + 0.5同样实现四舍五入取整
    int hour = time / 3600;
    time %= 3600;
    int min = time / 60;
    int sec = time % 60;
    // 使用iomanip的setfill/setw控制输出格式 使用printf更简单
    // printf("%02d:%02d:%02d", hour, minute, second);
    std::cout << std::setfill('0') << std::setw(2) << hour << ":" 
              << std::setfill('0') << std::setw(2) << min << ":" 
              << std::setfill('0') << std::setw(2) << sec << std::endl;
    return 0;
}