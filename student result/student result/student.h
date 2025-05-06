#pragma once

#include <algorithm>  // 用于排序
#include <fstream>    // 文件操作
#include <iostream>
#include <string>
#include <vector>

// 学生成绩管理类
class StudentManager {
 private:
  // 定义学生结构体
  struct Student {
    std::string name;  // 学生姓名
    int score;         // 学生成绩
  };

  // 存储学生的容器
  std::vector<Student> students;

  // 按成绩排序（私有方法）
  void sortStudentsByScore();

  // 保存数据到文件
  void saveToFile();

  // 从文件加载数据
  void loadFromFile();

 public:
  // 构造函数：启动时加载数据
  StudentManager() { loadFromFile(); }

  // 析构函数：退出时保存数据
  ~StudentManager() { saveToFile(); }
  // 添加学生成绩
  void addStudent();

  // 查看所有学生成绩
  void viewStudents();

  // 修改学生成绩
  void modifyStudent();

  // 删除学生成绩
  void deleteStudent();

  // 按成绩排名
  void rankStudents();

  // 分数段统计
  void scoreStatistics();
};
