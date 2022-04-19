// 1054 求平均值 (20 分)
// 本题的基本要求非常简单：给定 N 个实数，计算它们的平均值。
// 但复杂的是有些输入数据可能是非法的。
// 一个“合法”的输入是 [−1000,1000] 区间内的实数，并且最多精确到小数点后 2 位。
// 当你计算平均值的时候，不能把那些非法的数据算在内。

#include <iostream>

int main()
{
    using sz = std::string::size_type;
    int N = 0;
    std::cin >> N;
    double sum = 0.0;
    int cnt = 0;
    std::string str;

    for (int i = 0; i != N; ++i)
    // 对每个Ni单独判断：1.存在非数字 . - 之外的符号/2.符号超过1个/3.-不在首位/4.小数点之后超过2位/5.数字超范围
    {
        std::cin >> str;
        int num_negative = 0, num_decimal = 0;
        bool flag = true;

        for (sz j = 0; j != str.size(); ++j)
        {
            if (isdigit(str[j]) || (str[j] == '-') || (str[j] == '.'))
            {
                if (str[j] == '-')
                    num_negative++;
                if (str[j] == '.')
                    num_decimal++;
            }
            else
            {
                flag = false;
                break;
            }
        }

        if (num_decimal > 1 || num_negative > 1)// 超出1个的符号
            flag = false;
        if ((str[0] != '-') && num_negative == 1)// - 不在首位
            flag = false;
        if (num_decimal == 1 && (str.size() - 1 - str.find('.')) > 2)// . 后超过2位
            flag = false;
        
        if (!flag)
            std::cout << "ERROR: " << str << " is not a legal number" << std::endl;
        else
        {
            double tmp = 0.0;
            sscanf(str.c_str(), "%lf", &tmp);
            
            if (tmp >= -1000 && tmp <= 1000)
            {
                cnt++;
                sum += tmp;
            }
            else
                std::cout << "ERROR: " << str << " is not a legal number" << std::endl;
        }
    }

    if (cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else if (cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}


// given solution from github by `liuchuo-`
// use char str[50] instead of string
// for(int i = 0; i < n; i++) {
//         scanf("%s", a);
//         sscanf(a, "%lf", &temp);
//         sprintf(b, "%.2f",temp);

// sscanf && sprintf