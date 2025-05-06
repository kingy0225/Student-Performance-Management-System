#include "student.h"

// ���ɼ�����˽�з�����
void StudentManager::sortStudentsByScore() {
  std::sort(students.begin(), students.end(), [](Student a, Student b) {
    return a.score > b.score;  // ���ɼ��Ӹߵ�������
  });
}

  // �������ݵ��ļ�
void StudentManager::saveToFile() {
  std::ofstream file(
      "C:\\Users\\ykp\\source\\repos\\student result\\student "
      "result\\students.txt");
  if (!file) {
    std::cout << "�޷��������ݵ��ļ���\n";
    return;
  }
  for (const auto& s : students) {
    file << s.name << " " << s.score << "\n";
  }
  file.close();
}

// ���ļ���������
void StudentManager::loadFromFile() {
  std::ifstream file(
      "C:\\Users\\ykp\\source\\repos\\student result\\student "
      "result\\students.txt");
  if (!file) {
    std::cout << "δ�ҵ������ļ���δ�����κ����ݡ�\n";
    return;
  }
  students.clear();  // ��յ�ǰ����
  Student s;
  while (file >> s.name >> s.score) {
    students.push_back(s);
  }
  file.close();
}

// ���ѧ���ɼ�
void StudentManager::addStudent() {
  Student s;
  std::cout << "������ѧ��������";
  std::cin >> s.name;
  while (true) {
    std::cout << "������ѧ���ɼ���0-100����";
    std::cin >> s.score;
    if (std::cin.fail() || s.score < 0 || s.score > 100) {  // ���Ƿ�����
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "�ɼ������������������룡\n";
    } else {
      break;
    }
  }
  students.push_back(s);
  std::cout << "ѧ���ɼ�����ӣ�\n";
}

// �鿴����ѧ���ɼ�
void StudentManager::viewStudents() {
  if (students.empty()) {
    std::cout << "��ǰ��ѧ�����ݣ�\n";
    return;
  }
  std::cout << "\n=== ����ѧ���ɼ� ===\n";
  for (size_t i = 0; i < students.size(); ++i) {
    std::cout << i + 1 << ". " << students[i].name << " - " << students[i].score
              << "��\n";
  }
}

// �޸�ѧ���ɼ�
void StudentManager::modifyStudent() {
  std::string name;
  std::cout << "������Ҫ�޸ĵ�ѧ��������";
  std::cin >> name;
  for (auto& s : students) {
    if (s.name == name) {
      std::cout << "��ǰ�ɼ�Ϊ��" << s.score << "���������³ɼ���";
      while (true) {
        std::cin >> s.score;
        if (std::cin.fail() || s.score < 0 || s.score > 100) {  // ���Ƿ�����
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "�ɼ������������������룡\n";
        } else {
          std::cout << "�ɼ����޸ģ�\n";
          return;
        }
      }
    }
  }
  std::cout << "δ�ҵ���ѧ����\n";
}

// ɾ��ѧ���ɼ�
void StudentManager::deleteStudent() {
  std::string name;
  std::cout << "������Ҫɾ����ѧ��������";
  std::cin >> name;
  for (auto it = students.begin(); it != students.end(); ++it) {
    if (it->name == name) {
      students.erase(it);
      std::cout << "ѧ���ɼ���ɾ����\n";
      return;
    }
  }
  std::cout << "δ�ҵ���ѧ����\n";
}

// ���ɼ�����
void StudentManager::rankStudents() {
  if (students.empty()) {
    std::cout << "��ǰ��ѧ�����ݣ�\n";
    return;
  }
  sortStudentsByScore();  // ����˽�з�������
  std::cout << "\n=== �ɼ����� ===\n";
  for (size_t i = 0; i < students.size(); ++i) {
    std::cout << i + 1 << ". " << students[i].name << " - " << students[i].score
              << "��\n";
  }
}

// ������ͳ��
void StudentManager::scoreStatistics() {
  if (students.empty()) {
    std::cout << "��ǰ��ѧ�����ݣ�\n";
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
  std::cout << "\n=== ������ͳ�� ===\n";
  std::cout << "����60�֣�" << below60 << "��\n";
  std::cout << "60-80�֣�" << between60and80 << "��\n";
  std::cout << "����80�֣�" << above80 << "��\n";
};

// ������
int main() {
  StudentManager manager;  // ����ѧ���������
  int choice;

  do {
    // ��ʾ�˵�
    std::cout << "\n=== ѧ���ɼ�����ϵͳ ===\n";
    std::cout << "1. ���ѧ���ɼ�\n";
    std::cout << "2. �鿴����ѧ���ɼ�\n";
    std::cout << "3. �޸�ѧ���ɼ�\n";
    std::cout << "4. ɾ��ѧ���ɼ�\n";
    std::cout << "5. ���ɼ�����\n";
    std::cout << "6. ������ͳ��\n";
    std::cout << "0. �˳�ϵͳ\n";
    std::cout << "��ѡ�������";
    std::cin >> choice;

     // ��ֹ���������
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "��Ч���룬���������֣�\n";
      continue;
    }

    // �����û�ѡ����ö�Ӧ����
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
        std::cout << "ϵͳ���˳���\n";
        break;
      default:
        std::cout << "��Чѡ�������ѡ��\n";
    }
  } while (choice != 0);

  std::cin.get();
}