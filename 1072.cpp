// 1072 开学寄语 分数 20
// 本题要求你写个程序帮助这所学校的老师检查所有学生的物品，以助其成大器。

#include <iostream>
#include <map>

int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    int num = 0;
    std::map<int, int> dic;
    for (int i = 0; i != m; ++i) {
        scanf("%d", &num);
        dic[num] = 1;
    }

    int cnt_persons = 0, cnt_items = 0;

    for (int i = 0; i != n; ++i) {
        std::string name;
        std::cin >> name;
        int k = 0;
        scanf("%d", &k);

        bool flag = false;

        for (int j = 0; j != k; ++j) {
            int items;
            scanf("%d", &items);

            if (dic[items] == 1) {
                cnt_items++;

                if (flag == false) {
                    std::cout << name << ":";
                    printf(" %04d", items);
                    cnt_persons++;
                    flag = true;
                }
                else if (flag == true)
                    printf(" %04d", items);
            }
        }

        if (flag == true) {
            printf("\n");
        }

    }

    printf("%d %d", cnt_persons, cnt_items);
    return 0;
}