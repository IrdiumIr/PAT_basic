// 1002 写出这个数 (20 分)
// 读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

// 输入格式：
// 每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10 ^ 100 。


// 输出格式：
// 在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

#include <iostream>
#include <string>
#include <vector>
#include <deque>
int main()
{
    std::string n;//输入正整数n，若是int则太小了
    int sum = 0;// 求和
    std::cin >> n;
    std::deque<std::string> deq;// 输出序列
    std::vector<std::string> py{"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for (auto it = n.begin(); it != n.end(); ++it)// 迭代器遍历string n，得到求和
        sum += (*it - '0');
    
    while (sum >= 10)
    {
        deq.push_front(std::to_string(sum % 10));
        sum = sum / 10;
    }
    deq.push_front(std::to_string(sum));
    for (auto iter = deq.begin(); iter != deq.end(); ++iter)
    {
        if (iter != deq.begin())
            std::cout << " ";
        std::cout << py[stoi(*iter)];
    }
    return 0;
}

// given solution from github by `liuchuo-`
// int main() {
//     string s;
//     cin >> s;
//     int sum = 0;
//     string str[10] =  {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
//     for (int i = 0; i < s.length(); i++)
//         sum += (s[i] - '0');
//     string num = to_string(sum);
//     for (int i = 0; i < num.length(); i++) {
//         if (i != 0) cout << " ";
//         cout << str[num[i] - '0'];
//     }
//     return 0;
// }