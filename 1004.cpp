// 1004 成绩排名 (20 分)
// 读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

#include <iostream>
#include <string>

int main()
{
    int n = 0;
    std::cin >> n;
    int maxgrade = 0, mingrade = 100, grade;
    std::string name, number, maxname, minname, maxnumber, minnumber;
    for (int i = 0; i != n; ++i)
    {
        std::cin >> name >> number >> grade;
        if (grade >= maxgrade)
        {
            maxgrade = grade;
            maxname = name;
            maxnumber = number;
        }
        if (grade <= mingrade)
        {
            mingrade = grade;
            minname = name;
            minnumber = number;
        }
    }
    std::cout << maxname << " " << maxnumber << "\n" << minname << " " << minnumber;
    std::cout << std::endl;
    return 0;
}