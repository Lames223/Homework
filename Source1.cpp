#include <iostream>
#include <string>
using namespace std;
class Student // ��������� ����� �������
{
public:
	friend class Teacher; // ������������� �����
	double attendance;
	double behaivourgrade; // ���� ������
	string name;
	Student(double attendance_, double behaivourgrade_, string name_) // �����������
	{
		attendance = attendance_;
		behaviourgrade = behaivourgrade_;
		name = name_;
		amount++;
	}
	void Learn() // ������ ������
	{
		cout << "Learning..." << "\n";
		avgrade += 0.25;
	}
	void Visit()
	{
		cout << "Visiting lessons..." << "\n";
		avgrade += 0.05;
		attendance += 0.1
	}
	void BehaveGood()
	{
		cout << "Trying to behave good..." << "\n";
		behaivourgrade += 0.15
	}
	double getavgrade() // ������ ��� ���������� ����
	{
		return avgrade;
	}
	static void NewStudent() // �����������	�����
	{
		amount++;
	}
private:
	static int amount; // ��������� ����
	double avgrade;
	void Setavgrade(double avgrade_) // ��������� ������
	{
		avgrade = avgrade_;
	}
};

class Teacher
{
public:
	string lesson; // ���� �������
	Teacher(string lesson_) // ����������� �������
	{
		lesson = lesson_;
	}
	void SetStudentAvGrade(Student& S, double avgrd) // ���������� � ������� ������ ������� � ���������� ��� ��������� ������
	{
		S.Setavgrade(avgrd);
	}
};

int Student::amount = 0; // ������ �������� ����������� ���������� ������ �������
int main()
{
	Student Boris(0.5, 0.8, "Boris"); // �������� � ��������� ������
	Teacher Anna("Math");
	Anna.SetStudentAvGrade(Boris, 4.9);
	Boris.Learn();
	Boris.BehaveGood();
	Boris.Visit();
	cout << "Average " << Boris.name << "'s grade: " << Boris.getavgrade(); // ������� ������� ���� ������
	cout << Boris.name << "'s attendance: " << Boris.attendance;
	cout << Boris.name << "'s behaviour grade: " << Boris.behaivourgrade;
}