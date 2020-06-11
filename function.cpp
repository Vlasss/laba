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
		cout << "������� � " << i + 1 << endl;
		dp[i].PrintP();
		cout << "-------------------------------" << endl;
	}
}
void PrintS(Systema* ds, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "������ � " << i + 1 << endl;
		ds[i].PrintS();
		cout << "-------------------------------" << endl;
	}
}

void ChangeP(Systema* dp, int n)
{
	Planets planet;
	int np;
	cout << "������� ����� ������ �������: ";
	cin >> np;
	np--;
	if (np >= 0 && np < n)
	{
		cout << "������� ����� ��� �������" << endl;
		cin >> planet.name;
		cout << "������� ����� ������� �������" << endl;
		cin >> planet.age;
		cout << "������� ����� ����� �������" << endl;
		cin >> planet.weight;
		dp[np].InputP(planet);
	}
	else
		cout << "����� ������ �������" << endl;
}

void ChangeS(Systema* ds, int n)
{
	Stars star;
	int ns;
	cout << "������� ����� ������ ������: ";
	cin >> ns;
	ns--;
	if (ns >= 0 && ns < n)
	{
		cout << "������� ����� ��� ������" << endl;
		cin >> star.name;
		cout << "������� ����� ������� ������" << endl;
		cin >> star.age;
		cout << "������� ����� ����� ������" << endl;
		cin >> star.weight;
		cout << "������� ����� ����������� ������" << endl;
		cin >> star.luminosity;
		ds[ns].InputS(star);
	}
	else
		cout << "����� ������ �������" << endl;
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

	cout << "������� ����� ��� ������" << endl;
	cin >> star.name;
	cout << "������� ����� ������� ������" << endl;
	cin >> star.age;
	cout << "������� ����� ����� ������" << endl;
	cin >> star.weight;
	cout << "������� ����� ����������� ������" << endl;
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

	cout << "������� ����� ��� �������" << endl;
	cin >> planet.name;
	cout << "������� ����� ������� �������" << endl;
	cin >> planet.age;
	cout << "������� ����� ����� �������" << endl;
	cin >> planet.weight;
	dp[k].InputP(planet);
	delete[] dp2;
}



void DeleteP(Systema* (&dp), int& n)
{
	int k;
	Systema* dp2 = new Systema[n];
	cout << "������� ����� �������" << endl;
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
		cout << "����� ������ �������" << endl;
	delete[] dp2;
}
void DeleteS(Systema* (&ds), int& n)
{
	int k;
	Systema* ds2 = new Systema[n];
	cout << "������� ����� �������" << endl;
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
		cout << "����� ������ �������" << endl;
	delete[] ds2;
}

void PPoiskAge(Systema* dp, int n)
{
	Planets planet;

	cout << "������� ������ �������: " << endl;
	cout << "�������  ������� �������" << endl;
	cin >> planet.age;
	for (int i = 0; i < n; i++)
	{
		if (dp[i].planet.age == planet.age)
		{
			cout << "�������� �������:" << dp[i].planet.name << endl;
			cout << "�������:" << dp[i].planet.age << endl;
			cout << "���:" << dp[i].planet.weight << endl;
		}
	}
}

void SPoiskAge(Systema* ds, int n)
{
	Stars star;

	cout << "������� ������ ������: " << endl;
	cout << "�������  ������� ������" << endl;
	cin >> star.age;
	for (int i = 0; i < n; i++)
	{
		if (ds[i].star.age == star.age)
		{
			cout << "�������� ������:" << ds[i].star.name << endl;
			cout << "�������:" << ds[i].star.age << endl;
			cout << "���:" << ds[i].star.weight << endl;
			cout << "����������:" << ds[i].star.luminosity << endl;
		}

	}
}



void PPoiskWeight(Systema* dp, int n)
{
	Planets planet;

	cout << "������� ������ �������: " << endl;
	cout << "������� ����� �������" << endl;
	cin >> planet.weight;
	for (int i = 0; i < n; i++)
	{
		if (dp[i].planet.weight == planet.weight)
		{
			cout << "�������� �������:" << dp[i].planet.name << endl;
			cout << "�������:" << dp[i].planet.age << endl;
			cout << "���:" << dp[i].planet.weight << endl;
		}
	}
}

void SPoiskWeight(Systema* ds, int n)
{
	Stars star;

	cout << "������� ������ ������: " << endl;
	cout << "������� ����� ������" << endl;
	cin >> star.weight;
	for (int i = 0; i < n; i++)
	{
		if (ds[i].star.weight == star.weight)
		{
			cout << "�������� ������:" << ds[i].star.name << endl;
			cout << "�������:" << ds[i].star.age << endl;
			cout << "���:" << ds[i].star.weight << endl;
			cout << "����������:" << ds[i].star.luminosity << endl;
		}

	}
}

void SPoiskLuminosity(Systema* ds, int n)
{
	Stars star;

	cout << "������� ������ ������: " << endl;
	cout << "������� ���������� ������" << endl;
	cin >> star.luminosity;
	for (int i = 0; i < n; i++)
	{
		if (ds[i].star.luminosity == star.luminosity)
		{
			cout << "�������� ������:" << ds[i].star.name << endl;
			cout << "�������:" << ds[i].star.age << endl;
			cout << "���:" << ds[i].star.weight << endl;
			cout << "����������:" << ds[i].star.luminosity << endl;
		}

	}
}
