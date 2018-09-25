#pragma once
class StatBag
{
public:
	StatBag();
	~StatBag();
	int PuissancePhysique();
	int PuissanceMagique();
	int PuissanceRunique();
	int DefensePhysique();
	int DefenseMagique();
	int DefenseRunique();
	int Vitesse();
	int Intelligence();
	int HitRatio();
	void PuissancePhysique(int val);
	void PuissanceMagique(int val);
	void PuissanceRunique(int val);
	void DefensePhysique(int val);
	void DefenseMagique(int val);
	void DefenseRunique(int val);
	void Vitesse(int val);
	void Intelligence(int val);
	void HitRatio(int val);
private:
	int _PuissancePhysique;
	int _PuissanceMagique;
	int _PuissanceRunique;
	int _DefensePhysique;
	int _DefenseMagique;
	int _DefenseRunique;
	int _Vitesse;
	int _Intelligence;
	int _HitRatio;
};

