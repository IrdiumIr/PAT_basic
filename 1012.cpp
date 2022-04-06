// 1012 数字分类 (20 分)
// 给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：
// A1= 能被 5 整除的数字中所有偶数的和；
// A2= 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n 
// A3= 被 5 除后余 2 的数字的个数；
// A4= 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
// A5= 被 5 除后余 4 的数字中最大数字。

#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    int N = 0;
    int count_A3 = 0, count_A4 = 0;
    double A4 = 0.0;
    int A1 = 0, A2 = 0, A5 = 0;
    int flag = 1;

    int count_A2 = 0;// 如果和是0不影响，如果没执行过则输出N! 难点

    int num = 0;// 输入
    std::cin >> N;
    while (std::cin>>num)
    {
        if (num % 5 == 0 && num % 2 == 0)
            A1 += num;
        else if (num % 5 == 1)
        {
            if (flag == 1)
                A2 += num;
            else if (flag == -1)
                A2 -= num;
            flag = -flag;
            ++count_A2;
        }
        else if (num % 5 == 2)
            ++count_A3;
        else if (num % 5 == 3)
        {
            A4 += num;
            ++count_A4;
        }
        else if (num % 5 == 4)
        {
            if (num > A5)
                A5 = num;
        }
    }

    double avg = A4 / count_A4;
    if (A1 == 0)
        std::cout << 'N' << " ";
    else
        std::cout << A1 << " ";
    if (A2 == 0 && count_A2 == 0)
        std::cout << 'N' << " ";
    else
        std::cout << A2 << " ";
    if (count_A3 == 0)
        std::cout << 'N' << " ";
    else
        std::cout << count_A3 << " ";
    if (A4 == 0)
        std::cout << 'N' << " ";
    else
        std::cout << std::fixed << std::setprecision(1) << avg << " ";
    if (A5 == 0)
        std::cout << 'N';
    else
        std::cout << A5;
    // std::cout << ((A1 == 0) ? 'N' : A1) << " " 
    //             << ((A2 == 0) ? 'N' : A2) << " " 
    //             << ((count_A3 == 0) ? 'N' : count_A3) << " " 
    //             << std::fixed << std::setprecision(1) << ((A4 == 0) ? 'N' : avg) << " " 
    //             << ((A5 == 0) ? 'N' : A5) << std::endl;
    return 0;
}


// or使用vector<vector<int>>将每个输入的num存入二维数组，再使用两层嵌套循环进行处理
