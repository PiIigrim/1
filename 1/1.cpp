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
	char nation[32];
	char birth[32];
	double guld;
	double tabnom;
	char educ[32];
	double prinat;
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
	cout << "Фамилия: ";
	cin.getline(Obj[amount].name, 32);
	cout << "Имя: ";
	cin.getline(Obj[amount].surname, 32);
	cout << "Отчество: ";
	cin.getline(Obj[amount].lastname, 32);
	cout << "Домашний адресс: ";
	cin.getline(Obj[amount].homeadress, 128);
	cout << "Национальность: ";
	cin.getline(Obj[amount].nation, 32);
	cout << "Дата рождения: ";
	cin.getline(Obj[amount].birth, 32);
	cout << "Номер цеха: ";
	cin >> Obj[amount].guld;
	cin.get();
	cout << "Табельный номер: ";
	cin >> Obj[amount].tabnom;
	cin.get();
	cout << "Образование: ";
	cin.getline(Obj[amount].educ, 32);
	cout << "Год поступления на работу: ";
	cin >> Obj[amount].prinat;
	cin.get();
	cout << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void showData(const Sponsor* Obj, const int amount)
{
	system("cls");
	cout << "№  " << "Имя\t" << "Фамилия\t" << "Отчество\t" << "Домашний адрес\t" << "Национальность\t" << "Дата рождения\t" << "номер цеха\t" << "Табельный номер\t" << "Образование\t" << "Год поступления на работу\t" << endl;
	cout << "========================================" << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << i + 1 << "  " << Obj[i].name << '\t' << Obj[i].surname << '\t' << Obj[i].lastname << '\t' << Obj[i].homeadress << '\t' << Obj[i].nation << '\t' << Obj[i].birth << '\t' << Obj[i].guld << '\t' << Obj[i].tabnom << '\t' << Obj[i].educ << '\t' << Obj[i].prinat << '\t' << endl;
	}
}
