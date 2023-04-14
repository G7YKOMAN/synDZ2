#include <iostream>
using namespace std;

class student {
public:
	friend class teacher;// дружественный класс
student(int age_, string name_, string gender_) {
		age = age_;
		name = name_;
		gender = gender_;
		population++;
		cout << "student age and name and gender Construcrot\n";
	}

	~student() {
		cout << "student " << name << " Destructor\n";
		population--;
	}
							// поля к 1-ому заданию 
	void set_age(int age_) {
		if (age_ > 0) {
			age = age_;
		}
	}
	void set_name(string name_) {
		name = name_;
	}
	void set_gender(string gender_) {
		gender = gender_;
	}
	int get_age() {
		return age;
	}
	string get_name() {
		return name;
	}
	string get_gender() {
		return gender;
	}
						//поля к 1-ому заданию 
	static int get_population() {
		return population;
	}
private:					//методы
	void speak() {
		cout << "Woof!\n";
	}
		static int population;
		int age;
		string name;
		string gender;
private:
	void speak2() {
		cout << "I am sorry\n";
	}
private:
	void speak3() {
		cout << "I won't do it again\n";
	}						//методы

	};
	int student::population = 0;

	class teacher {
	public:
		teacher(int age_, string name_) {
			age = age_;
			name = name_;
			population++;
			cout << "teacher age and name Constructor\n";
		}

		~teacher() {
			cout << "teacher " << name << " Destructor\n";
		}

		void set_age(int age_) {
			if (age_ > 0) {
				age = age_;
			}
		}
		void set_name(string name_) {
			name = name_;
		}
		int get_age() {
			return age;
		}
		string get_name() {
			return name;
		}

		static int get_population() {
			return population;
		}

		void Student_speak(student &ss) { //Метод, взаимодействующий с одним из приватных полей класса «Студент».
			ss.speak();
			cout << "Apologize!\n";
			ss.speak2();
			cout << "Well done!\n";
			ss.speak3();

		}
	private:
		static int population;
		int age;
		string name;
	};
	int teacher::population = 0;
	int main()
	{
		teacher t1(26, "Irina");
		student s1(19, "Igor", "Male");
		t1.Student_speak(s1);

		cout << "Total population is " << student::get_population() << endl;
		cout << s1.get_name() << " is " << s1.get_age() << " years old!\n";
		cout << t1.get_name() << " is " << t1.get_age() << " years old!\n";



	}
