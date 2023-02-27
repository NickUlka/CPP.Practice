
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



class Human {
public:
	Human(std::string name, std::string surname)
	{
		this->name = name;
		this->surname = surname;
	}
	virtual~Human(){};

	virtual std::string status() = 0;


	virtual std::string get_full_info() 
	{
		std::ostringstream full_info;
		full_info <<this->surname<<" " << this->name;
		return full_info.str();
	}

private:
	std::string name; 
	std::string surname;

};


class Collegue : public Human {
public:
	Collegue(std::string surname, std::string name, std::string second_name, std::string email, std::string dep) : Human(name, surname)
	{
		this->second_name = second_name;
		this->department = dep;
		this->email = email;
	}

	std::string get_full_info() 
	{
		std::ostringstream full_info;
		full_info << status() << " " << this->department << " " << Human::get_full_info() << " " << this->second_name << " " << this->email;
		return full_info.str();
	}

	std::string status() {
		return "collegue";
	}

private:
	std::string email;;
	std::string second_name;
	std::string department;
};

class Friend :  public Human {
public:
	Friend(std::string surname, std::string name, std::string phone) : Human(name, surname)
	{
		this->phone = phone;
	}
	Friend(Collegue* col, std::string surname, std::string name, std::string phone) : Human(name, surname), phone(phone), collegue(col)
	{
	}

	std::string get_full_info() 
	{
		std::ostringstream full_info;
		if (collegue == nullptr)
			full_info << status() << " " << Human::get_full_info() << " " << this->phone;
		else
			full_info << status() << " " << collegue->get_full_info() << " " << this->phone;
		return full_info.str();
	}

	std::string status() {
		return "friend";
	}

private:
	std::string phone;
	Collegue* collegue;

};

class Relative : public Human {
public:
	Relative(std::string surname,std::string name,  std::string phone, std::string bday, std::string relstat) : Human(name, surname), \
		birthday(bday), relative_status(relstat)
	{
		this->phone = phone;
	}

	std::string get_full_info() 
	{
		std::ostringstream full_info;
		full_info << status() << " " << this->relative_status << " " << Human::get_full_info() << " " << this->birthday << " " << this->phone;
		return full_info.str();
	}

	std::string status() {
		return "relative";
	}

private:
	std::string birthday;
	std::string relative_status;
	std::string phone;
};


int main()
{
	std::vector<Human*> people;
	char choice;
	std::string name, surname, secondname, phone, email, bday, dep, rel;
	std::cout << "Let's start to fillful address book" << std::endl;

	do {
		std::cout << "Enter: surname and name: " << std::endl;
		std::cin >> surname >> name;
		std::cout << "Who is this person? Enter 'f' - friend, 'r' - relative, 'c' - collegue: ";
		std::cin >> choice;

		if(choice=='r'){
			std::cout << "phone - ";
			std::cin >> phone;
			std::cout << "birthday - ";
			std::cin >> bday;
			std::cout << "relativity - ";
			std::cin >> rel;
			people.push_back(new Relative(surname, name, phone, bday, rel));
		}
		else if (choice == 'f') {
			std::cout << "phone - ";
			std::cin >> phone;
			std::cout << "Your friend is your collegue? (y/n): ";
			std::cin >> choice;
			if (choice == 'n')
				people.push_back(new Friend(surname, name, phone));
			else {
				std::cout << "second name - ";
				std::cin >> secondname;
				std::cout << "e-mail - ";
				std::cin >> email;
				std::cout << "department - ";
				std::cin >> dep;
				people.push_back(new Friend((new Collegue(surname, name, secondname, email, dep)), surname, name, phone));
			}
		}
		else if (choice == 'c'){
			std::cout << "second name - ";
				std::cin >> secondname;
				std::cout << "e-mail - ";
				std::cin >> email;
				std::cout << "department - ";
				std::cin >> dep;
				std::cout << "Your collegue is your friend? (y/n): " << std::endl;
				std::cin >> choice;
				if (choice == 'n')
					people.push_back(new Collegue(surname, name, secondname, email, dep));
				else
				{
					std::cout << "phone - " << std::endl;
					std::cin >> phone;
					people.push_back(new Friend((new Collegue(surname, name, secondname, email, dep)), surname, name, phone));
				}
		}
		std::cout << "Continue? (y/n): ";
		std::cin >> choice;
	}
	while (choice=='y');


	std::string fileName = "text.txt";
	std::ofstream fout (fileName, std::ios::app);
	for (auto a : people)
		fout << a->get_full_info() << std::endl;
	fout.close();

	for (auto a : people)
		delete a;
}



