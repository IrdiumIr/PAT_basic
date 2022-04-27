// 1069 微博转发抽奖 分数 20

// 小明 PAT 考了满分，高兴之余决定发起微博转发抽奖活动，从转发的网友中按顺序每隔 N 个人就发出一个红包。
// 请你编写程序帮助他确定中奖名单。

#include <iostream>
#include <vector>
#include <map>

int main()
{
    int M = 0, N = 0, S = 0;
    std::cin >> M >> N >> S;
    std::vector<std::string> names;
    std::string tmp;
    bool flag = false;

    for (int i = 1; i <= M; ++i) {
        std::cin >> tmp;
        names.push_back(tmp);
    }
    std::map<std::string, int> dic;
    for (int i = 1; i <= M; ++i) {
        if (i == S) {
            dic[names[i-1]] = 1;
            std::cout << names[i - 1] << std::endl;
            flag = true;
        }
        else if ((i - S) % N == 0 && i > S) {
            if (dic[names[i-1]] == 0) {
                dic[names[i-1]] = 1;
                std::cout << names[i - 1] << std::endl;
                flag = true;
            } else if (dic[names[i-1]] == 1) {
                S++;
            }
        }
    }

    if (flag == false)
        std::cout << "Keep going...";
    return 0;
}


// given solution from github by `liuchuo-`

// for (int i = 1; i <= m; i++) {
//     cin >> str;
//     if (mapp[str] == 1) s = s + 1;
//     if (i == s && mapp[str] == 0) {
//         mapp[str] = 1;
//         cout << str << endl;
//         flag = true;
//         s = s + n;
//     }
// }