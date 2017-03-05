#ifndef __MONOM_H__
#define __MONOM_H__
#include <iostream>

using namespace std;

class Monom 
{
public:
	double coef;//�����������
	int degree;//�������

	Monom(double coef = 0, int degree = -1)//�����������
	{
		this->coef = coef;//��� ������������
		this->degree = degree;//��� ��������� �������
	}

	bool operator<(const Monom &m)//�������� ���������(������)
	{
		if (degree < m.degree) return true;		
		else
			return false;
	}

	bool operator>(const Monom &m)//�������� ���������(������)
	{
		if (degree > m.degree) return true;		
		else
			return false;
	}	

	bool operator==(const Monom &m)//�������� ���������(�����)
	{
		if (degree == m.degree) return true;	
		else
			return false;
	}
};
#endif
