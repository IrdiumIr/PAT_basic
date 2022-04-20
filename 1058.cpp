// 1058 选择题 (20 分)

#include <iostream>
#include <vector>
#include <set>

int main()
{
    int N = 0, M = 0;// N人M题
    std::cin >> N >> M;

    std::vector<int> score;
    score.reserve(M);
    std::vector<std::set<char>> correct(M);
    std::vector<int> wrong(M);// wrong_cnt

    for (int i = 0; i != M; ++i)// ans
    {
        int score_i = 0, option = 0, num_opt = 0;
        std::cin >> score_i >> option >> num_opt;
        score.push_back(score_i);

        for (int j = 0; j != num_opt; ++j)
        {
            char ch;
            scanf(" %c", &ch);
            correct[i].insert(ch);
        }
    }

    int k = 0;

    for (int i = 0; i != N; ++i)
    {
        int sum = 0;
        scanf("\n");

        for (int j = 0; j != M; ++j)// 输入(num, ans1, ans2, ...)
        {
            std::set<char> tmp;
            char ch;

            if (j != 0)
                scanf(" ");

            scanf("(%d", &k);

            for (int l = 0; l != k; ++l)
            {
                scanf(" %c", &ch);
                tmp.insert(ch);
            }

            scanf(")");

            if (tmp == correct[j])
                sum += score[j];
            else
                ++wrong[j];
        }

        printf("%d\n", sum);
    }

    int max_wrong_cnt = 0;
    for (int i = 0; i != M; ++i)
    {
        if (wrong[i] > max_wrong_cnt)
            max_wrong_cnt = wrong[i];
    }

    if (max_wrong_cnt == 0)
        printf("Too simple");
    else
    {
        printf("%d", max_wrong_cnt);
        
        for (int i = 0; i != M; ++i)
        {
            if (wrong[i] == max_wrong_cnt)
                printf(" %d", i + 1);
        }
    }

    return 0;
}