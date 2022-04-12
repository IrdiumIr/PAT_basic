// 1038 统计同成绩学生 (20 分)
// 本题要求读入 N 名学生的成绩，将获得某一给定分数的学生人数输出。

#include <iostream>
#include <unordered_map>
int main()
{
    int N = 0;
    scanf("%d", &N);
    int num;
    std::unordered_map<int, int> ans;
    while (N)
    {
        scanf("%d", &num);
        auto ret = ans.insert({num, 1});
        if (!ret.second)
            ++ret.first->second;
        --N;
    }
    int n = 0;
    scanf("%d", &n);
    while (n)
    {
        if (n != 1)
        {
            scanf("%d", &num);
            printf("%d ", ans[num]);
            --n;
        }
        else
        {
            scanf("%d", &num);
            printf("%d", ans[num]);
            --n;
        }
    }
    return 0;
}


// given solution from github by `liuchuo-`
// vector[num]++很好用
    // vector<int> b(101);
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &temp);
    //     b[temp]++;
    // }
    // scanf("%d", &m);
    // for (int i = 0; i < m; i++) {
    //     scanf("%d", &temp);
    //     if (i != 0) printf(" ");
    //     printf("%d", b[temp]);
    // }