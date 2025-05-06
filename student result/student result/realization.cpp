#include "student.h"

// 按成绩排序（私有方法）
void StudentManager::sortStudentsByScore() {
  std::sort(students.begin(), students.end(), [](Student a, Student b) {
    return a.score > b.score;  // 按成绩从高到低排序
  });
}

  // 保存数据到文件
void StudentManager::saveToFile() {
  std::ofstream file(
      "C:\\Users\\ykp\\source\\repos\\student result\\student "
      "result\\students.txt");
  if (!file) {
    std::cout << "无法保存数据到文件！\n";
    return;
  }
  for (const auto& s : students) {
    file << s.name << " " << s.score << "\n";
  }
  file.close();
}

// 从文件加载数据
void StudentManager::loadFromFile() {
  std::ifstream file(
      "C:\\Users\\ykp\\source\\repos\\student result\\student "
      "result\\students.txt");
  if (!file) {
    std::cout << "未找到数据文件，未加载任何数据。\n";
    return;
  }
  students.clear();  // 清空当前数据
  Student s;
  while (file >> s.name >> s.score) {
    students.push_back(s);
  }
  file.close();
}

// 添加学生成绩
void StudentManager::addStudent() {
  Student s;
  std::cout << "请输入学生姓名：";
  std::cin >> s.name;
  while (true) {
    std::cout << "请输入学生成绩（0-100）：";
    std::cin >> s.score;
    if (std::cin.fail() || s.score < 0 || s.score > 100) {  // 检查非法输入
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "成绩输入有误，请重新输入！\n";
    } else {
      break;
    }
  }
  students.push_back(s);
  std::cout << "学生成绩已添加！\n";
}

// 查看所有学生成绩
void StudentManager::viewStudents() {
  if (students.empty()) {
    std::cout << "当前无学生数据！\n";
    return;
  }
  std::cout << "\n=== 所有学生成绩 ===\n";
  for (size_t i = 0; i < students.size(); ++i) {
    std::cout << i + 1 << ". " << students[i].name << " - " << students[i].score
              << "分\n";
  }
}

// 修改学生成绩
void StudentManager::modifyStudent() {
  std::string name;
  std::cout << "请输入要修改的学生姓名：";
  std::cin >> name;
  for (auto& s : students) {
    if (s.name == name) {
      std::cout << "当前成绩为：" << s.score << "，请输入新成绩：";
      while (true) {
        std::cin >> s.score;
        if (std::cin.fail() || s.score < 0 || s.score > 100) {  // 检查非法输入
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "成绩输入有误，请重新输入！\n";
        } else {
          std::cout << "成绩已修改！\n";
          return;
        }
      }
    }
  }
  std::cout << "未找到该学生！\n";
}

// 删除学生成绩
void StudentManager::deleteStudent() {
  std::string name;
  std::cout << "请输入要删除的学生姓名：";
  std::cin >> name;
  for (auto it = students.begin(); it != students.end(); ++it) {
    if (it->name == name) {
      students.erase(it);
      std::cout << "学生成绩已删除！\n";
      return;
    }
  }
  std::cout << "未找到该学生！\n";
}

// 按成绩排名
void StudentManager::rankStudents() {
  if (students.empty()) {
    std::cout << "当前无学生数据！\n";
    return;
  }
  sortStudentsByScore();  // 调用私有方法排序
  std::cout << "\n=== 成绩排名 ===\n";
  for (size_t i = 0; i < students.size(); ++i) {
    std::cout << i + 1 << ". " << students[i].name << " - " << students[i].score
              << "分\n";
  }
}

// 分数段统计
void StudentManager::scoreStatistics() {
  if (students.empty()) {
    std::cout << "当前无学生数据！\n";
    return;
  }
  int below60 = 0, between60and80 = 0, above80 = 0;
  for (const auto& s : students) {
    if (s.score < 60)
      below60++;
    else if (s.score <= 80)
      between60and80++;
    else
      above80++;
  }
  std::cout << "\n=== 分数段统计 ===\n";
  std::cout << "低于60分：" << below60 << "人\n";
  std::cout << "60-80分：" << between60and80 << "人\n";
  std::cout << "高于80分：" << above80 << "人\n";
};

// 主函数
int main() {
  StudentManager manager;  // 创建学生管理对象
  int choice;

  do {
    // 显示菜单
    std::cout << "\n=== 学生成绩管理系统 ===\n";
    std::cout << "1. 添加学生成绩\n";
    std::cout << "2. 查看所有学生成绩\n";
    std::cout << "3. 修改学生成绩\n";
    std::cout << "4. 删除学生成绩\n";
    std::cout << "5. 按成绩排名\n";
    std::cout << "6. 分数段统计\n";
    std::cout << "0. 退出系统\n";
    std::cout << "请选择操作：";
    std::cin >> choice;

     // 防止输入非数字
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "无效输入，请输入数字！\n";
      continue;
    }

    // 根据用户选择调用对应功能
    switch (choice) {
      case 1:
        manager.addStudent();
        break;
      case 2:
        manager.viewStudents();
        break;
      case 3:
        manager.modifyStudent();
        break;
      case 4:
        manager.deleteStudent();
        break;
      case 5:
        manager.rankStudents();
        break;
      case 6:
        manager.scoreStatistics();
        break;
      case 0:
        std::cout << "系统已退出！\n";
        break;
      default:
        std::cout << "无效选项，请重新选择！\n";
    }
  } while (choice != 0);

  std::cin.get();
}