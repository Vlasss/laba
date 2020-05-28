#include "functions.h"

int num;
void menu()
{
	cout << "1) Вывод данных" << endl;
	cout << "2) Изменение планеты" << endl;
	cout << "3) Изменение звезды" << endl;
	cout << "4) Добавление планеты" << endl;
	cout << "5) Добавление звезды" << endl;
	cout << "6) Удаление планеты" << endl;
	cout << "7) Удаление звезды" << endl;
	cout << "0) Выход из программы" << endl;
	cin >> num;
}
int main(int argc, char* argv[])
{
	if (argc <= 2) {
		cout << "Не задано имя файла" << endl;
		return 0;
	}

	ifstream BaseP(argv[1]);
	ifstream BaseS(argv[2]);
	if (!BaseP.is_open())
	{
		cout << "ошибка";
		return 0;
	}
	if (!BaseS.is_open())
	{
		cout << "ошибка";
		return 0;
	}
	

	setlocale(LC_ALL, "ru");
	menu();
	int sizeS = 0;
	int sizeP = 0;
	Systema* ds = new Systema[sizeS];
	Systema* dp = new Systema[sizeP];

	while (num != 0)
	{
		switch (num)
		{
		case 1:
			system("cls");
			if (sizeS != 0)
			{
				cout << "Звезды:" << endl;
				PrintS(ds, sizeS);
			}
			if (sizeP != 0)
			{
				cout << "Планеты:" << endl;
				PrintP(dp, sizeP);
			}
			if (sizeS == 0 && sizeP == 0)
			{
				cout << "система пуста" << endl;
			}
			system("pause");
			system("cls");
			menu();
			break;

		case 2:
			system("cls");
			if (sizeP != 0)
			{
				ChangeP(dp, sizeP);
			}
			else
			{
				cout << "Cистема пуста " << endl;
			}
			system("pause");
			system("cls");
			menu();
			break;
		case 3:
			system("cls");
			if (sizeS != 0)
			{
				ChangeS(ds, sizeS);
			}
			else
			{
				cout << "Cистема пуста " << endl;
			}
			system("pause");
			system("cls");
			menu();
			break;
		case 4:
			system("cls");
			AddPlanet(dp, sizeP);
			system("pause");
			system("cls");
			menu();
			break;
		case 5:
			system("cls");
			AddStar(ds, sizeS);
			system("pause");
			system("cls");
			menu();
			break;
		case 6:
			system("cls");
			if (sizeP != 0)
			{
				DeleteP(dp, sizeP);
			}
			else
			{
				cout << "Cистема пуста " << endl;
			}
			system("pause");
			system("cls");
			menu();
			break;
		case 7:
			system("cls");
			if (sizeS != 0)
			{
				DeleteS(ds, sizeS);
			}
			else
			{
				cout << "Cистема пуста " << endl;
			}
			system("pause");
			system("cls");
			menu();
			break;
		}
	}
	if (num == 0)
	{
		system("clear");
		ofstream f1(argv[1], ios_base::trunc);
		ofstream f2(argv[2], ios_base::trunc);
		for (int i = 0; i < sizeS; i++)
		{
			f1 << ds[i].star;
		}
		for (int i = 0; i < sizeP; i++)
		{
			f2 << dp[i].planet;
		}
		f1.close();
		f2.close();

		return 0;
	}



}