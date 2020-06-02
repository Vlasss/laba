#pragma once
#include "systema.h"


void PrintP(Systema* dp, int n);
void PrintS(Systema* ds, int n);
void ChangeP(Systema* dp, int n);
void ChangeS(Systema* ds, int n);
void Copy(Systema* NewData, Systema* OldData, int n);
void AddStar(Systema* (&ds), int& n);
void AddPlanet(Systema* (&dp), int& n);
void DeleteP(Systema* (&dp), int& n);
void DeleteS(Systema* (&ds), int& n);
void PoiskP(Systema* dp, int n);
void PoiskS(Systema* ds, int n);
