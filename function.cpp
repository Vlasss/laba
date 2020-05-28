#include "functions.h"

void PrintP (Systema* dp, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "ѕланета є " << i + 1 << endl;
		dp[i].PrintP();
		cout << "-------------------------------" << endl;
	}
}
void PrintS(Systema* ds, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "«везда є " << i + 1 << endl;
		ds[i].PrintS();
		cout << "-------------------------------" << endl;
	}
}

void ChangeP(Systema* dp, int n)
{
	Planets planet;
	int np;
	cout << "¬ведите номер нужной планеты: ";
	cin >> np;
	np--;
	if (np>=0 && np<n)
	{
		cout << "¬ведите новое им¤ планеты" << endl;
		cin >> planet.name;
		cout << "¬ведите новый возраст планеты" << endl;
		cin >> planet.age;
		cout << "¬ведите новую массу планеты" << endl;
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
	cout << "¬ведите номер нужной планеты: ";
	cin >> ns;
	ns--;
	if (ns >= 0 && ns < n)
	{
		cout << "¬ведите новое им¤ звезды" << endl;
		cin >> star.name;
		cout << "¬ведите новый возраст звезды" << endl;
		cin >> star.age;
		cout << "¬ведите новую массу звезды" << endl;
		cin >> star.weight;
		cout << "¬ведите новую светисмость звезды" << endl;
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

	cout << "¬ведите новое им¤ звезды" << endl;
	cin >> star.name;
	cout << "¬ведите новый возраст звезды" << endl;
	cin >> star.age;
	cout << "¬ведите новую массу звезды" << endl;
	cin >> star.weight;
	cout << "¬ведите новую светисмость звезды" << endl;
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

	cout << "¬ведите новое им¤ планеты" << endl;
	cin >> planet.name;
	cout << "¬ведите новый возраст планеты" << endl;
	cin >> planet.age;
	cout << "¬ведите новую массу планеты" << endl;
	cin >> planet.weight;
	dp[k].InputP(planet);
	delete[] dp2;
}

void Copy(Systema* NewData, Systema* OldData, int n)
{
	for (int i = 0; i < n; i++)
	{
		NewData[i] = OldData[i];
	}
}

void DeleteP(Systema* (&dp), int& n)
{
	int k;
	Systema* dp2 = new Systema[n];
	cout << "¬ведите номер планеты" << endl;
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
	cout << "¬ведите номер планеты" << endl;
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