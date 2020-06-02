#include "systema.h"
Systema::Systema()
{
	star.age = 0;
	star.luminosity = 0;
	star.name = "";
	star.weight = 0;

	planet.age = 0;
	planet.weight = 0;
	planet.name = "";


}

Systema::Systema(Planets planet_, Stars star_)
{
	star.age = star_.age;
	star.luminosity = star_.luminosity;
	star.weight = star_.weight;
	star.name = star_.name;

	planet.age = planet_.age;
	planet.weight = planet_.weight;
	planet.name = planet_.name;
}
Systema::~Systema()
{
}

void Systema::PrintP()
{
	cout << "Название планеты: " << planet.name << " " << " Вес: " << planet.weight << " " << " Возраст " << planet.age << endl;
}
void Systema::PrintS()
{
	cout << "Название звезды: " << star.name << " " << " Вес: " << star.weight << " " << " Возраст: " << star.age << " " << " Светимость: " << star.luminosity << endl;
}

void Systema::InputS(Stars star_)
{
	star.age = star_.age;
	star.luminosity = star_.luminosity;
	star.weight = star_.weight;
	star.name = star_.name;

}
void Systema::InputP(Planets planet_)
{
	planet.age = planet_.age;
	planet.weight = planet_.weight;
	planet.name = planet_.name;
}

Systema& Systema::operator=(Systema OldData)
{
	this->star.age = OldData.star.age;
	this->star.luminosity = OldData.star.luminosity;
	this->star.name = OldData.star.name;
	this->star.weight = OldData.star.weight;
	this->planet.age = OldData.planet.age;
	this->planet.name = OldData.planet.name;
	this->planet.weight = OldData.planet.weight;
	return *this;
}





istream& operator >>(istream& in, Stars& star)
{
	in >> star.name;
	in >> star.age;
	in >> star.luminosity;
	in >> star.weight;
	return in;
}
ostream& operator <<(ostream& out, const Stars& star)
{
	out << "название звезды: " << star.name << " ";
	out << "возраст: " << star.age << " ";
	out << "светимость: " << star.luminosity << " ";
	out << "вес: " << star.weight << " ";
	out << endl;
	return out;
}
istream& operator >>(istream& in, Planets& planet)
{
	in >> planet.name;
	in >> planet.age;
	in >> planet.weight;
	return in;
}
ostream& operator <<(ostream& out, const Planets& planet)
{
	out <<"название планеты: " << planet.name << " ";
	out <<"возраст: "<< planet.age << " ";
	out <<"вес: " << planet.weight << " ";
  out<<endl;
	return out;
}
