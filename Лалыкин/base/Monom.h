#ifndef __MONOM_H__
#define __MONOM_H__
#include <iostream>

using namespace std;

class Monom 
{
public:
	double coef;//коэффициент
	int degree;//степень

	Monom(double coef = 0, int degree = -1)//конструктор
	{
		this->coef = coef;//для коэффициента
		this->degree = degree;//для свернутой степени
	}

	bool operator<(const Monom &m)//оператор сравнения(меньше)
	{
		if (degree < m.degree) return true;		
		else
			return false;
	}

	bool operator>(const Monom &m)//оператор сравнения(больше)
	{
		if (degree > m.degree) return true;		
		else
			return false;
	}	

	bool operator==(const Monom &m)//оператор сравнения(равно)
	{
		if (degree == m.degree) return true;	
		else
			return false;
	}
};
#endif
