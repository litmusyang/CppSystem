#include <iostream>
#include "Search_Function.h"
#include "list.h"

bool CheckName(std::string& course);

void Teacher::LogIn()
{
    unsigned teacher_operation;
    unsigned homeworkoperation;
    std::string coursename;
    std::string announcement;
    std::string username;
    std::string homeworkassignment;

    do
    {
        std::cout << "请输入数字以选择操作：" << std::endl;
        std::cout << "0：创建课程" << std::endl;
        std::cout << "1：查看所有课程" << std::endl;
        std::cout << "2：查看某课程的所有成员" << std::endl;
        std::cout << "3：解散课程" << std::endl;
        std::cout << "4：发布通知" << std::endl;
        std::cout << "5：查看所有通知" << std::endl;
        std::cout << "6：发布作业" << std::endl;
        std::cout << "7：查看所有作业" << std::endl;
        std::cout << "8：查看学生作业，录入成绩" << std::endl;
        std::cout << "9：查看作业成绩" << std::endl;
        std::cout << "10：查看评教内容" << std::endl;
        std::cout << "11：注销" << std::endl;
        std::cout << "-1：登出" << std::endl;
        switch (teacher_operation)
        {
            case (0) : //创建课程
                std::cout << "请输入课程名：" << std::endl;
                getline(std::cin , coursename);
                if (SearchCourseName(coursename) == -1)
                {
                    Teacher::Set_Up_a_Course(coursename);
                }
                else
                {
                    std::cout << "您已创建过该课程" << std::endl; //检查是否重名
                }
                break;
            case (1) : //查看所有课程
                User::Display_the_Course(courselist);
                break;
            case (2) : //查看某课程的所有成员
                if (!CheckName(coursename))
                {
                    break;
                }
                Curriculum::DisplayMembers(SearchInVectorCourse(coursename));
                //向课程类提供了课程的地址，希望该函数cout所有成员
                break;
            case (3) : //解散课程
                std::cout << "请输入课程名：" << std::endl;
                getline(std::cin , coursename);
                if (SearchCourseName(coursename) != -1)
                {
                    Teacher::End_the_Course(coursename);
                }
                else
                {
                    std::cout << "找不到该课程" << std::endl;
                }
                break;
            case (4) : //发布通知
                if (!CheckName(coursename))
                {
                    break;
                }
                getline(std::cin , announcement);
                Curriculum::Make_an_Announcement(SearchInVectorCourse(coursename) , announcement);
                //向课程类提供了课程的地址、通知内容，希望该函数向班级所有学生发布通知
                break;
            case (5) : //查看所有通知
                if (!CheckName(coursename))
                {
                    break;
                }
                Curriculum::DisplayAnnouncement(SearchInVectorCourse(coursename));
                //向课程类提供了课程的地址，希望该函数cout所有通知
                break;
            case (6) : //发布作业
                if (!CheckName(coursename))
                {
                    break;
                }
                std::cout << "请输入作业名：" << std::endl;
                getline(std::cin , homeworkassignment);
                Curriculum::AssignHomework(SearchInVectorCourse(coursename) , homeworkassignment);
                //向课程类提供了课程的地址、作业名，希望该函数向所有学生发布作业
                break;
            case (7) ://查看所有作业
                if (!CheckName(coursename))
                {
                    break;
                }
                Curriculum::DisplayHomework(SearchInVectorCourse(coursename));
                //向课程类提供了课程的地址，希望该函数cout所有作业
                break;
            case (8) : //查看学生作业、录入成绩
                if (!CheckName(coursename))
                {
                    break;
                }
                std::cout << "请输入作业名：" << std::endl;
                getline(std::cin , homeworkassignment);
                std::cout << "请输入学生名：" << std::endl;
                getline(std::cin , username);
                Curriculum::Scoring(SearchInVectorCourse(coursename),
                homeworkassignment , username);
                //向课程类提供了课程的地址、作业名、学生名，希望查看学生的作业并允许录入成绩
                break;
            case (9) : //查看作业成绩
                if (!CheckName(coursename))
                {
                    break;
                }
                std::cout << "请输入作业名：" << std::endl;
                getline(std::cin , homeworkassignment);
                Curriculum::LookUpTheScore(SearchInVectorCourse(coursename) , homeworkassignment);
                //向课程类提供了课程的地址、作业名，希望查看班级名单、作业完成情况与成绩
                break;
            case (10) : //查看评教内容
                if (!CheckName(coursename))
                {
                    break;
                }
                Curriculum::Check_The_Comment(SearchInVectorCourse(coursename));
                //向课程类提供了课程的地址，希望cout评教平均分与具体内容（匿名）
                break;
            case (11) : //注销
                Delete(myname);
                break;
            default :
                std::cout << "输入错误，请重新输入" << std::endl;

        }
    }while(teacher_operation != -1);
    std::cout << "您已登出" << std::endl;
}

void Assistant::LogIn()
{
    unsigned assistant_operation;
    unsigned homeworkoperation;
    std::string coursename;
    std::string announcement;
    std::string username;
    std::string homeworkassignment;

    do
    {
        std::cout << "请输入数字以选择操作：" << std::endl;
        std::cout << "0：查看所有课程" << std::endl;
        std::cout << "1：查看某课程的所有成员" << std::endl;
        std::cout << "2：加入课程" << std::endl;
        std::cout << "3：退出课程" << std::endl;
        std::cout << "4：发布通知" << std::endl;
        std::cout << "5：查看所有通知" << std::endl;
        std::cout << "6：查看学生作业，录入成绩" << std::endl;
        std::cout << "7：查看作业成绩" << std::endl;
        std::cout << "8：注销" << std::endl;
        std::cout << "-1：登出" << std::endl;
        switch (assistant_operation)
        {
            case (0) : //查看所有课程
                User::Display_the_Course(courselist);
                break;
            case (1) : //查看某课程的所有成员
                if (!CheckName(coursename))
                {
                    break;
                }
                Curriculum::DisplayMembers(SearchInVectorCourse(coursename));
                //向课程类提供了课程的地址，希望该函数cout所有成员
                break;
            case (2) : //加入课程
                if (!CheckName(coursename))
                {
                    break;
                }
                Curriculum::Join_In(SearchInVectorCourse(coursename) , myname , 1)//课程类的加入函数
                //向课程类提供了课程的地址、用户名、用户类型（助教：1 学生：2），希望该函数让助教加入课程
                break;
            case (3) : //退出课程
                if (!CheckName(coursename))
                {
                    break;
                }
                for (int i = SearchCourseName(coursename) ; i < coursenumber - 1; ++i)
                {
                    courselist[i] = courselist[i+1];
                }
                courselist.pop_back();
                Curriculum::DeleteAssistant(myname);
                //向课程类提供助教名称，希望该函数删除助教参与的所有课程中该助教的名字
                break;
            case (4) : //发布通知
                if (!CheckName(coursename))
                {
                    break;
                }
                getline(std::cin , announcement);
                Curriculum::Make_an_Announcement(SearchInVectorCourse(coursename) , announcement);
                //向课程类提供了课程的地址、通知内容，希望该函数向班级所有学生发布通知
                break;
            case (5) : //查看所有通知
                if (!CheckName(coursename))
                {
                    break;
                }
                Curriculum::DisplayAnnouncement(SearchInVectorCourse(coursename));
                //向课程类提供了课程的地址，希望该函数cout所有通知
                break;
            case (6) : //查看学生作业、录入成绩
                if (!CheckName(coursename))
                {
                    break;
                }
                std::cout << "请输入作业名：" << std::endl;
                getline(std::cin , homeworkassignment);
                std::cout << "请输入学生名：" << std::endl;
                getline(std::cin , username);
                Curriculum::Scoring(SearchInVectorCourse(coursename),
                                homeworkassignment , username);
                //向课程类提供了课程的地址、作业名、学生名，希望查看学生的作业并允许录入成绩
                break;
            case (7) : //查看作业成绩
                if (!CheckName(coursename))
                {
                    break;
                }
                std::cout << "请输入作业名：" << std::endl;
                getline(std::cin , homeworkassignment);
                Curriculum::LookUpTheScore(SearchInVectorCourse(coursename) , homeworkassignment);//仅仅是函数接口
                //向课程类提供了课程的地址、作业名，希望该函数可以cout班级名单、作业完成情况与成绩
                break;
            case (8) : //注销
                Delete(myname);
                break;
            default :
                std::cout << "输入错误，请重新输入" << std::endl;
        }
    }while(assistant_operation != -1);
    std::cout << "您已登出" << std::endl;

}

void Teacher::Set_Up_a_Course(const std::string& coursename)
{
    static Curriculum tmp;
    Curriculum::tmp(coursename);
    allcourse.push_back(tmp);
    ++coursenumber;
    courselist.push_back(coursename);
}

void Teacher::End_the_Course(const std::string& coursename)
{
    for (int i = SearchInCourse(coursename) ; i < allcourse.size() - 1; ++i)
    {
        allcourse[i] = allcourse[i+1];
    }
    allcourse.pop_back();

    for (int i = SearchCourseName(coursename) ; i < coursenumber - 1; ++i)
    {
        courselist[i] = courselist[i+1];
    }
    courselist.pop_back();
}

Teacher::~Teacher()
= default;

void Teacher::Delete(std::string myname)
{
    for(const auto & i : courselist)
    {
        for (int j = SearchInCourse(i); j < allcourse.size() - 1; ++j) {
            allcourse[j] = allcourse[j + 1];
        }
        allcourse.pop_back();
    }
    for (int i = SearchInCourse(myname) ; i < allteacher.size() - 1; ++i)
    {
        allteacher[i] = allteacher[i+1];
    }
    allteacher.pop_back();
}

Assistant::~Assistant()
= default;

void Assistant::Delete(std::string name)
{
    for (int i = SearchInCourse(name) ; i < allassistant.size() - 1; ++i)
    {
        allassistant[i] = allassistant[i+1];
    }
    allassistant.pop_back();
    Curriculum::DeleteAssistant(myname);
    //向课程类提供助教名称，希望该函数删除助教参与的所有课程中该助教的名字
}

User::User(std::string username)
{
    myname = std::move(username);
    coursenumber = 0;
}

int User::SearchCourseName(const std::string& coursename)
{
    for (int i = 0 ; i < coursenumber; ++i)
    {
        courselist[i] = coursename;
            return i;
    }
    return -1;
}

void User::Display_the_Course(std::vector<std::string> icourselist) const
{
    for(int i = 0; i < coursenumber ; ++i)
    {
        std::cout << icourselist[i] << std::endl;
    }
    if (coursenumber == 0)
    {
        std::cout << "暂无课程" << std::endl;
    }
}

void User::reset(std::string username)
{
    myname = std::move(username);
    coursenumber = 0;
}

User::User(const User& x)
{
    myname = x.myname;
    coursenumber = x.coursenumber;
    courselist = x.courselist;
}

bool CheckName(std::string& course)
{
    std::cout << "请输入您想要退出的课程：" << std::endl;
    getline(std::cin , course);
    if (SearchInCourse(course) == -1)
    {
        std::cout << "找不到该课程" << std::endl;
        return false;
    }
    else return true;
}