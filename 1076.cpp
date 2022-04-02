// 1076 Wifi密码 (15 分)
// 下面是微博上流传的一张照片：
// “各位亲爱的同学们，鉴于大家有时需要使用 wifi，又怕耽误亲们的学习，
// 现将 wifi 密码设置为下列数学题答案：A-1；B-2；C-3；D-4；
// 请同学们自己作答，每两日一换。谢谢合作！！~”
// —— 老师们为了促进学生学习也是拼了…… 
// 本题就要求你写程序把一系列题目的答案按照卷子上给出的对应关系翻译成 wifi 的密码。
// 这里简单假设每道选择题都有 4 个选项，有且只有 1 个正确答案。

#include <iostream>
#include <string>

int main()
{
    int N = 0;
    std::cin >> N;
    getchar();
    std::string ans;
    for (auto i = 0; i != N; ++i)
    {
        char s[5];// a-b(space)' ' size=4+1
        for (auto i = 0; i != 4; ++i)
        {
            if (i >= 0 && i <= 2)
                std::cin.getline(s, 4, ' ');
            else if (i == 3)
                std::cin.getline(s, 4, '\n');
            if (s[2] == 'T')
            {
                ans += std::to_string((s[0] - 'A' + 1));
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}


// another solution: scanf能够直接按照标准的a-b格式输入检测输入内容是否有T
// for(int i=0;i<n;i++)
// {
//     for(int j=1;j<=4;j++)
//     {
//         char m,t;
//         scanf("%c-%c",&m,&t);
//         getchar();
//         if(t=='T')
//             printf("%d",m-'A'+1);
//     }
// }