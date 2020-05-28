#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Stars
{
public:
	int age;
	int luminosity;
	int weight;
	string name;
	friend ostream& operator <<(ostream& out, const Stars& star);
	friend istream& operator >>(istream& in, Stars& star);
};

class Planets
{
public:
	string name;
	int age;
	int weight;
	friend ostream& operator <<(ostream& out, const Planets& planet);
	friend istream& operator >>(istream& in, Planets& planet);

};

class Systema
{
public:
	Planets planet;
	Stars star;
	Systema();
	Systema(Planets planet_, Stars star_);
	~Systema();
	void PrintP();
	void PrintS();
	void InputP(Planets planet_);
	void InputS(Stars star_);
	Planets GetPlanets() { return planet; };
	Stars GetStars() { return star; };
	Systema& operator = (Systema OldData);
};