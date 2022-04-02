// 1041 考试座位号 (15 分)
// 每个 PAT 考生在参加考试时都会被分配两个座位号，一个是试机座位，一个是考试座位。
// 正常情况下，考生在入场时先得到试机座位号码，入座进入试机状态后，系统会显示该考生的考试座位号码，
// 考试时考生需要换到考试座位就座。
// 但有些考生迟到了，试机已经结束，他们只能拿着领到的试机座位号码求助于你，从后台查出他们的考试座位号码。

#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<std::string>> sv;
    int N = 0;
    std::cin >> N;
    for (auto i = 0; i != N; ++i)// 二维vector存储数据
    {
        std::string s;
        std::vector<std::string> tmp;
        tmp.clear();
        for (auto i = 0; i != 3; ++i)
        {
            std::cin >> s;
            tmp.push_back(s);
        }
        sv.push_back(tmp);
    }
    int M = 0;
    std::cin >> M;
    for (auto i = 0; i != M; ++i)
    {
        std::string s_check;
        std::cin >> s_check;
        for (auto j = 0; j != N; ++j)
        {
            if (sv[j][1] == s_check)
            {
                std::cout << sv[j][0] << " " << sv[j][2] << std::endl;
                break;
            }
        }
    }
    return 0;
}

// given by github liuchuo-
//
// string stu[1005][2], s1, s2;;
// int n, m, t;
// cin >> n;
// for(int i = 0; i < n; i++) {
//     cin >> s1 >> t >> s2;
//     stu[t][0] = s1;
//     stu[t][1] = s2; 
// } 
// cin >> m;
// for(int i = 0; i < m; i++) {
//     cin >> t;
//     cout << stu[t][0] << " " << stu[t][1] << endl;
// } 

// think twice using unordered_map 
// 各个测试用例均提高了1ms！！！
// #include <iostream>
// #include <unordered_map>
// #include <vector>

// int main()
// {
//     std::unordered_map<int, std::vector<std::string>> test_map;
//     int N = 0;
//     std::cin >> N;
//     for (auto i = 0; i != N; ++i)// unordered_map
//     {
//         std::string sfz;
//         std::cin >> sfz;
//         int sj = 0;
//         std::cin >> sj;
//         std::string ks;
//         std::cin >> ks;
//         std::vector<std::string> tmp;
//         tmp.push_back(sfz);
//         tmp.push_back(ks);
//         test_map.insert(std::make_pair(sj, tmp));
//     }
//     int M = 0;
//     std::cin >> M;
//     for (auto i = 0; i != M; ++i)
//     {
//         int i_check;
//         std::cin >> i_check;
//         auto iter = (test_map.find(i_check))->second;
//         std::cout << iter[0] << " " << iter[1] << std::endl;
//     }
//     return 0;
// }