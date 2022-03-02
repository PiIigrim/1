#include <iostream>
#include <math.h>
#include <windows.h>
#include <iomanip>
using namespace std;

struct Sponsor
{
	char name[32];
	char surname[32];
	char lastname[32];
	char homeadress[128];
	char group[32];
	char rate[32];
};

Sponsor* AddStruct(Sponsor* Obj, const int amount);
void setData(Sponsor* Obj, const int amount);
void showData(const Sponsor* Obj, const int amount);

int main()
{
	setlocale(LC_ALL, "rus");

	Sponsor* OurSponsors = 0;
	int sponsorAmount = 0;
	int YesOrNot = 0; //  продолжить или остановить ввод данных

	do
	{
		OurSponsors = AddStruct(OurSponsors, sponsorAmount);
		setData(OurSponsors, sponsorAmount);

		sponsorAmount++;

		cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
		cin >> YesOrNot;
		cin.get();
	} while (YesOrNot != 0);

	showData(OurSponsors, sponsorAmount);

	delete[] OurSponsors;
	return 0;
}

Sponsor* AddStruct(Sponsor* Obj, const int amount)
{
	if (amount == 0)
	{
		Obj = new Sponsor[amount + 1]; // выделение памяти для первой структуры
	}
	else
	{
		Sponsor* tempObj = new Sponsor[amount + 1];

		for (int i = 0; i < amount; i++)
		{
			tempObj[i] = Obj[i]; // копируем во временный объект
		}
		delete[] Obj;

		Obj = tempObj;
	}
	return Obj;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setData(Sponsor* Obj, const int amount)
{
	cout << "Имя: ";
	cin.getline(Obj[amount].name, 32);
	cout << "Фамилия: ";
	cin.getline(Obj[amount].surname, 32);
	cout << "Отчество: ";
	cin.getline(Obj[amount].lastname, 32);
	cout << "Домашний адресс: ";
	cin.getline(Obj[amount].homeadress, 128);
	cout << "Группа: ";
	cin.getline(Obj[amount].group, 32);
	cout << "Рейтинг: ";
	cin.getline(Obj[amount].rate, 32);
	cout << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void showData(const Sponsor* Obj, const int amount)
{
	char option;
	int a = 1;
	cout << "Инструкция: b-база, n-имена, f-фамилии, o-отчество, d-домашний адрес, g-группы, r-рейтинг, i-инструкция, e-выход" << endl;
	while (a > 0) {
		cin >> option;
		switch (option) {
		case 'b':
			cout << "№  " << "Имя\t" << "Фамилия\t" << "Отчество\t" << "Домашний адрес\t" << "Группа\t" << "Рейтинг\t" << endl;
			cout << "========================================" << endl;
			for (int i = 0; i < amount; i++)
			{
				cout << i + 1 << "  " << Obj[i].name << '\t' << Obj[i].surname << '\t' << Obj[i].lastname << '\t' << Obj[i].homeadress << '\t' << Obj[i].group << '\t' << Obj[i].rate << endl;
			}
			cout << endl;
			break;
		case 'n':
			cout << "№  " << "Имя\t" << endl;
			cout << "========================================" << endl;
			for (int i = 0; i < amount; i++)
			{
				cout << i + 1 << "  " << Obj[i].name << endl;
			}
			cout << endl;
			break;
		case 'f':
			cout << "№  " << "Фамилия\t" << endl;
			cout << "========================================" << endl;
			for (int i = 0; i < amount; i++)
			{
				cout << i + 1 << "  " << Obj[i].surname << endl;
			}
			cout << endl;
			break;
		case 'o':
			cout << "№  " << "Отчество\t" << endl;
			cout << "========================================" << endl;
			for (int i = 0; i < amount; i++)
			{
				cout << i + 1 << "  " << Obj[i].lastname << endl;
			}
			cout << endl;
			break;
		case 'd':
			cout << "№  " << "Домаший адрес\t" << endl;
			cout << "========================================" << endl;
			for (int i = 0; i < amount; i++)
			{
				cout << i + 1 << "  " << Obj[i].homeadress << endl;
			}
			cout << endl;
			break;
		case 'g':
			cout << "№  " << "Группа\t" << endl;
			cout << "========================================" << endl;
			for (int i = 0; i < amount; i++)
			{
				cout << i + 1 << "  " << Obj[i].group << endl;
			}
			cout << endl;
			break;
		case 'r':
			cout << "№  " << "Рейтинг\t" << endl;
			cout << "========================================" << endl;
			for (int i = 0; i < amount; i++)
			{
				cout << i + 1 << "  " << Obj[i].rate << endl;
			}
			cout << endl;
			break;
		case 'i':
			cout << "Инструкция: b-база, n-имена, f-фамилии, o-отчество, d-домашний адрес, g-группы, r-рейтинг, i-инструкция" << endl;
			cout << endl;
			break;
		case 'e':
			system("cls");
			exit(0);
		default:
			break;
		}
	}
}
