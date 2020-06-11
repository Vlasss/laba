#include "functions.h"

void Copy(Systema* NewData, Systema* OldData, int n)
{
	for (int i = 0; i < n; i++)
	{
		NewData[i] = OldData[i];
	}
}


void PrintP(Systema* dp, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Планета № " << i + 1 << endl;
		dp[i].PrintP();
		cout << "-------------------------------" << endl;
	}
}
void PrintS(Systema* ds, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Звезда № " << i + 1 << endl;
		ds[i].PrintS();
		cout << "-------------------------------" << endl;
	}
}

void ChangeP(Systema* dp, int n)
{
	Planets planet;
	int np;
	cout << "Введите номер нужной планеты: ";
	cin >> np;
	np--;
	if (np >= 0 && np < n)
	{
		cout << "Введите новое имя планеты" << endl;
		cin >> planet.name;
		cout << "Введите новый возраст планеты" << endl;
		cin >> planet.age;
		cout << "Введите новую массу планеты" << endl;
		cin >> planet.weight;
		dp[np].InputP(planet);
	}
	else
		cout << "номер введен неверно" << endl;
}

void ChangeS(Systema* ds, int n)
{
	Stars star;
	int ns;
	cout << "Введите номер нужной звезды: ";
	cin >> ns;
	ns--;
	if (ns >= 0 && ns < n)
	{
		cout << "Введите новое имя звезды" << endl;
		cin >> star.name;
		cout << "Введите новый возраст звезды" << endl;
		cin >> star.age;
		cout << "Введите новую массу звезды" << endl;
		cin >> star.weight;
		cout << "Введите новую светисмость звезды" << endl;
		cin >> star.luminosity;
		ds[ns].InputS(star);
	}
	else
		cout << "номер введен неверно" << endl;
}

void AddStar(Systema* (&ds), int& n)
{
	Stars star;
	Systema* ds2 = new Systema[n];
	int k = n;
	int new_k = ++n;
	Copy(ds2, ds, k);
	ds = new Systema[new_k];
	Copy(ds, ds2, k);

	cout << "Введите новое имя звезды" << endl;
	cin >> star.name;
	cout << "Введите новый возраст звезды" << endl;
	cin >> star.age;
	cout << "Введите новую массу звезды" << endl;
	cin >> star.weight;
	cout << "Введите новую светисмость звезды" << endl;
	cin >> star.luminosity;
	ds[k].InputS(star);
	delete[] ds2;

}
void AddPlanet(Systema* (&dp), int& n)
{
	Planets planet;
	Systema* dp2 = new Systema[n];
	int k = n;
	int new_k = ++n;
	Copy(dp2, dp, k);
	dp = new Systema[new_k];
	Copy(dp, dp2, k);

	cout << "Введите новое имя планеты" << endl;
	cin >> planet.name;
	cout << "Введите новый возраст планеты" << endl;
	cin >> planet.age;
	cout << "Введите новую массу планеты" << endl;
	cin >> planet.weight;
	dp[k].InputP(planet);
	delete[] dp2;
}



void DeleteP(Systema* (&dp), int& n)
{
	int k;
	Systema* dp2 = new Systema[n];
	cout << "Введите номер планеты" << endl;
	cin >> k;
	k--;
	if (k >= 0 && k < n)
	{
		Copy(dp2, dp, n);
		int q = 0;
		n--;
		dp = new Systema[n];
		for (int i = 0; i <= n; i++)
		{
			if (i != k)
			{
				dp[q] = dp2[i];
				q++;
			}
		}

	}
	else
		cout << "номер введен неверно" << endl;
	delete[] dp2;
}
void DeleteS(Systema* (&ds), int& n)
{
	int k;
	Systema* ds2 = new Systema[n];
	cout << "Введите номер планеты" << endl;
	cin >> k;
	k--;
	if (k >= 0 && k < n)
	{
		Copy(ds2, ds, n);
		int q = 0;
		n--;
		ds = new Systema[n];
		for (int i = 0; i <= n; i++)
		{
			if (i != k)
			{
				ds[q] = ds2[i];
				q++;
			}
		}

	}
	else
		cout << "номер введен неверно" << endl;
	delete[] ds2;
}

void PPoiskAge(Systema* dp, int n)
{
	Planets planet;

	cout << "Введите данные планеты: " << endl;
	cout << "Введите  возраст планеты" << endl;
	cin >> planet.age;
	for (int i = 0; i < n; i++)
	{
		if (dp[i].planet.age == planet.age)
		{
			cout << "Название планеты:" << dp[i].planet.name << endl;
			cout << "Возраст:" << dp[i].planet.age << endl;
			cout << "Вес:" << dp[i].planet.weight << endl;
		}
	}
}

void SPoiskAge(Systema* ds, int n)
{
	Stars star;

	cout << "Введите данные звезды: " << endl;
	cout << "Введите  возраст звезды" << endl;
	cin >> star.age;
	for (int i = 0; i < n; i++)
	{
		if (ds[i].star.age == star.age)
		{
			cout << "Название звезды:" << ds[i].star.name << endl;
			cout << "Возраст:" << ds[i].star.age << endl;
			cout << "Вес:" << ds[i].star.weight << endl;
			cout << "Светимость:" << ds[i].star.luminosity << endl;
		}

	}
}



void PPoiskWeight(Systema* dp, int n)
{
	Planets planet;

	cout << "Введите данные планеты: " << endl;
	cout << "Введите массу планеты" << endl;
	cin >> planet.weight;
	for (int i = 0; i < n; i++)
	{
		if (dp[i].planet.weight == planet.weight)
		{
			cout << "Название планеты:" << dp[i].planet.name << endl;
			cout << "Возраст:" << dp[i].planet.age << endl;
			cout << "Вес:" << dp[i].planet.weight << endl;
		}
	}
}

void SPoiskWeight(Systema* ds, int n)
{
	Stars star;

	cout << "Введите данные звезды: " << endl;
	cout << "Введите массу звезды" << endl;
	cin >> star.weight;
	for (int i = 0; i < n; i++)
	{
		if (ds[i].star.weight == star.weight)
		{
			cout << "Название звезды:" << ds[i].star.name << endl;
			cout << "Возраст:" << ds[i].star.age << endl;
			cout << "Вес:" << ds[i].star.weight << endl;
			cout << "Светимость:" << ds[i].star.luminosity << endl;
		}

	}
}

void SPoiskLuminosity(Systema* ds, int n)
{
	Stars star;

	cout << "Введите данные звезды: " << endl;
	cout << "Введите Светимость звезды" << endl;
	cin >> star.luminosity;
	for (int i = 0; i < n; i++)
	{
		if (ds[i].star.luminosity == star.luminosity)
		{
			cout << "Название звезды:" << ds[i].star.name << endl;
			cout << "Возраст:" << ds[i].star.age << endl;
			cout << "Вес:" << ds[i].star.weight << endl;
			cout << "Светимость:" << ds[i].star.luminosity << endl;
		}

	}
}
