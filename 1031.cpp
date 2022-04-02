// 1031 查验身份证 (15 分)
// 一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：

// 首先对前17位数字加权求和，权重分配为：
// {7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；
// 然后将计算的和对11取模得到值Z；最后按照以下关系对应Z值与校验码M的值：

#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    std::vector<int> iv{7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    std::unordered_map<int, char> um{{0, '1'}, {1, '0'}, {2, 'X'}, {3, '9'}, {4, '8'}, {5, '7'}, {6, '6'}, {7, '5'}, {8, '4'}, {9, '3'}, {10, '2'}};
    int N = 0;
    std::cin >> N;
    getchar();
    bool flag = false;
    int count_true = 0;

    for (auto i = 0; i != N; ++i)
    {    
        int sum = 0;
        std::string s;
        std::cin >> s;
        int count = 0;
        
        for (auto j = 0; j != 17; ++j)
        {
            if (s[j] >= '0' && s[j] <= '9')
                sum += (s[j] - '0') * iv[j];
            else
                break;
            ++count;// 中途退出的情况count！=17；前17位都遍历过=17
        }
        
        if (count != 17)
        {
            std::cout << s << std::endl;
            flag = false;
            continue;
        }

        int z = sum % 11;
        
        if (um.find(z)->second == s[17])
        {
            flag = true;
            ++count_true;// flag=true给计数+1，最后如果要输出all passed必须count=N
        }
        else
            std::cout << s << std::endl;
    }
    if (flag && (count_true == N))
        std::cout << "All passed" << std::endl;
    return 0;
}