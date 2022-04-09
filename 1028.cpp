// 1028 人口普查 (20 分)
// 某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

// 这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过 200 岁的老人，
// 而今天是 2014 年 9 月 6 日，所以超过 200 岁的生日和未出生的生日都是不合理的，应该被过滤掉。

#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;
    int cnt = 0;
    std::string name, birth, name_max, name_min;
    std::string birth_max{"1814/09/06"}, birth_min{"2014/09/06"};

    for (int i = 0; i != N; ++i)
    {
        std::cin >> name >> birth;
        if (birth >= "1814/09/06" && birth <= "2014/09/06")
        {
            ++cnt;
            
            if (birth >= birth_max)
            {
                birth_max = birth;
                name_max = name;
            }
            if (birth <= birth_min)
            {
                birth_min = birth;
                name_min = name;
            }
        }
    }

    std::cout << cnt;
    if (cnt !=0) 
        std::cout << ' ' << name_min << ' ' << name_max;
}