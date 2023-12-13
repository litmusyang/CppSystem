#include <iostream>
#include "Search_Function.h"
#include "list.h"
#include "ClassUser.h"

bool IsUserExist(std::string username);

int main()
{
    int operation;
    std::string username;
    Teacher tmpteacher;
    Assistant tmpassistant;
    Student tmpstudent;

    do
    {
        unsigned usertype;
        int operation;
        std::cout << "请选择操作（0：注册  1：登录  -1：退出系统）" << std::endl;
        std::cin >> operation;
        switch (operation)
        {
            case (0): {
                std::cout << "请输入用户类型（0：教师  1：助教  2：学生）" << std::endl;
                std::cin >> usertype;
                std::cout << "请输入用户名";
                getline(std::cin, username);
                if (IsUserExist(username))
                {
                    std::cout << "该用户名已被占用" << std::endl;
                    break;
                }//判断是否重名
                switch (usertype)
                {
                    case (0) ://注册教师
                        tmpteacher.reset(username);
                        allteacher.push_back(tmpteacher);
                        break;
                    case (1)  ://注册助教
                        tmpassistant.reset(username);
                        allassistant.push_back(tmpassistant);
                        break;
                    case (2)  ://注册学生
                        tmpstudent.reset(username);
                        allassistant.push_back(tmpstudent);
                        break;
                    default :
                        std::cout << "输入错误，请重新输入" << std::endl;
                }
                break;
                case (1) :
                    std::cout << "请输入用户名";
                    getline(std::cin, username);
                    if (!IsUserExist(username))
                    {
                        std::cout << "用户不存在" << std::endl;
                        break;
                    }
                    else if ( int(SearchInTeacher(username)) != -1)
                    {
                        SearchInVectorTeacher(username) -> LogIn();
                    }
                    else if ( int(SearchInAssistant(username)) != -1)
                    {
                        SearchInVectorAssistant(username) -> LogIn();
                    }
                    else
                    {
                        SearchInVectorStudent(username) -> LogIn();
                    }
            }
        }
    } while (operation != -1);
    std::cout << "您已退出系统" << std::endl;
    return 0;
}

bool IsUserExist(std::string username)
{
    return SearchInTeacher(username) != -1 ||
           SearchInAssistant(username) != -1
           ||SearchInStudent(username) != -1;
}