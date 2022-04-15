// 1044 火星数字 (20 分)
// 火星人是以 13 进制计数的：
// 地球人的 0 被火星人称为 tret。
// 地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
// 火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
// 例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。
// 为了方便交流，请你编写程序实现地球和火星数字之间的互译。

#include <iostream>
std::string low_arr[13]{"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
std::string high_arr[13]{"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void func1(int i)// i<169 i/13=0-12 i%13=0-12
{
    if (i / 13)
        std::cout << high_arr[i / 13];
    if ((i / 13) && (i % 13))
        std::cout << " ";
    if (i % 13 || i == 0)
        std::cout << low_arr[i % 13];
}
void func2(std::string &s)
{
    std::string s1, s2;// s1-10 s2-1
    s1 = s.substr(0, 3);
    if (s.size() > 4)
        s2 = s.substr(4, 3);
    int ans1 = 0, ans10 = 0;// 1位 10位
    for (int j = 0; j != 13; ++j)
    {
        if (s1 == low_arr[j] || s2 == low_arr[j])
            ans1 = j;
        if (s1 == high_arr[j])
            ans10 = j;
    }
    std::cout << 13 * ans10 + ans1;
}
int main()
{
    int N = 0;// N<100
    std::string s;// 0<=s<169 ---- 13^2=169
    std::cin >> N;
    getchar();
    for (int i = 0; i != N; ++i)
    {
        getline(std::cin, s);
        if (isdigit(s[0]))// 10进制转13
            func1(stoi(s));
        else// 13进制转10
            func2(s);
        std::cout << std::endl;
    }
    return 0;
}