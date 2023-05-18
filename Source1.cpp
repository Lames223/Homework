#include <iostream>
#include <string>
using namespace std;
class Student // объявляем класс студент
{
public:
	friend class Teacher; // дружественный класс
	double attendance;
	double behaivourgrade; // поля класса
	string name;
	Student(double attendance_, double behaivourgrade_, string name_) // конструктор
	{
		attendance = attendance_;
		behaviourgrade = behaivourgrade_;
		name = name_;
		amount++;
	}
	void Learn() // методы класса
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
	double getavgrade() // геттер для приватного поля
	{
		return avgrade;
	}
	static void NewStudent() // статический	метод
	{
		amount++;
	}
private:
	static int amount; // приватные поля
	double avgrade;
	void Setavgrade(double avgrade_) // приватный сеттер
	{
		avgrade = avgrade_;
	}
};

class Teacher
{
public:
	string lesson; // поле учителя
	Teacher(string lesson_) // конструктор учителя
	{
		lesson = lesson_;
	}
	void SetStudentAvGrade(Student& S, double avgrd) // Обращаемся к объекту класса Студент и используем его приватный сеттер
	{
		S.Setavgrade(avgrd);
	}
};

int Student::amount = 0; // задаем значение статической переменной класса студент
int main()
{
	Student Boris(0.5, 0.8, "Boris"); // Действия с объектами класса
	Teacher Anna("Math");
	Anna.SetStudentAvGrade(Boris, 4.9);
	Boris.Learn();
	Boris.BehaveGood();
	Boris.Visit();
	cout << "Average " << Boris.name << "'s grade: " << Boris.getavgrade(); // выводим средний балл Бориса
	cout << Boris.name << "'s attendance: " << Boris.attendance;
	cout << Boris.name << "'s behaviour grade: " << Boris.behaivourgrade;
}