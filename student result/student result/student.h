#pragma once

#include <algorithm>  // ��������
#include <fstream>    // �ļ�����
#include <iostream>
#include <string>
#include <vector>

// ѧ���ɼ�������
class StudentManager {
 private:
  // ����ѧ���ṹ��
  struct Student {
    std::string name;  // ѧ������
    int score;         // ѧ���ɼ�
  };

  // �洢ѧ��������
  std::vector<Student> students;

  // ���ɼ�����˽�з�����
  void sortStudentsByScore();

  // �������ݵ��ļ�
  void saveToFile();

  // ���ļ���������
  void loadFromFile();

 public:
  // ���캯��������ʱ��������
  StudentManager() { loadFromFile(); }

  // �����������˳�ʱ��������
  ~StudentManager() { saveToFile(); }
  // ���ѧ���ɼ�
  void addStudent();

  // �鿴����ѧ���ɼ�
  void viewStudents();

  // �޸�ѧ���ɼ�
  void modifyStudent();

  // ɾ��ѧ���ɼ�
  void deleteStudent();

  // ���ɼ�����
  void rankStudents();

  // ������ͳ��
  void scoreStatistics();
};
