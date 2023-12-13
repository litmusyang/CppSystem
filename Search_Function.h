#include "list.h"
#ifndef CPPSYSTEM_SEARCH_FUNCTION_H
#define CPPSYSTEM_SEARCH_FUNCTION_H

int SearchInCourse(std::string coursename)
{
    for (int i = 0 ; i < allcourse.size() ;++i)
    {
        if (allcourse[i].myname == coursename)
        {
            return  i;
        }
    }
    return -1;
}//输入课程名，返回课程对象在目录中的下标

Curriculum* SearchInVectorCourse(std::string coursename)
{
    return &allcourse[SearchInCourse(coursename)];
}//输入课程名，返回课程对象的地址

int SearchInTeacher(const std::string& username)
{
    for (int i = 0 ; i < allteacher.size() ;++i)
    {
        if (allteacher[i].myname == username)
        {
            return  i;
        }
    }
    return -1;
}//输入教师用户名，返回教师对象在目录中的下标

Teacher* SearchInVectorTeacher(const std::string& username)
{
    return &allteacher[SearchInTeacher(username)];
}//输入教师用户名，返回教师对象的地址

int SearchInAssistant(const std::string& username)
{
    for (int i = 0 ; i < allassistant.size() ;++i)
    {
        if (allassistant[i].myname == username)
        {
            return  i;
        }
    }
    return -1;
}//输入助教用户名，返回助教对象在目录中的下标

Assistant* SearchInVectorAssistant(std::string username)
{
    return &allassistant[SearchInAssistant(username)];
}//输入助教用户名，返回助教对象的地址

int SearchInStudent(std::string username)
{
    for (int i = 0 ; i < allstudent.size() ;++i)
    {
        if (allstudent[i].myname == username)
        {
            return  i;
        }
    }
    return -1;
}//输入学生用户名，返回学生对象在目录中的下标

Student* SearchInVectorStudent(std::string username)
{
    return &allstudent[SearchInAssistant(username)];
}//输入学生用户名，返回学生对象的地址
#endif //CPPSYSTEM_SEARCH_FUNCTION_H