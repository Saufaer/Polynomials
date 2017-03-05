#ifndef __POLINOM_H__
#define __POLINOM_H__

#include "List.h"
#include "Monom.h"
#include <string>

using namespace std;

class Polinom: public List<Monom>//��������� �� ������-������
{
public:
	Polinom();// �����������
	void Create(int coef,int x,int y,int z);//�������� ������ � ������ � �������
	string ToString();//������������� ������ � ������
	Polinom& operator*(double num);// ���������� ��������� �� ���������
	Polinom& operator+=(Polinom &d);// ���������� ��������
	Polinom& operator-=(Polinom &d);// ���������� ���������
	Polinom& operator=(Polinom &d);// ���������� ������������

};

Polinom::Polinom()//�����������
{
	Monom temp(0, -1);//"�������" �����
	first = new Link<Monom>;
	first->SetVal(temp);//��������� ��������
	first->SetNext(first);//��������� ���������
}

void Polinom::Create(int coef,int x,int y,int z)
{
	if (coef!=0)
	{
		Monom temp(coef, 100*x+ 10*y + z);//������ �����
		Push(temp);//������ � �������	

		if (current->GetVal().degree == early->GetVal().degree)//���������� �������� �������
		{
			Monom temp(current->GetVal().coef + early->GetVal().coef, current->GetVal().degree);//���� ��������� ,�� ���������� ������������
			Push(temp);	//������ � ������� ���������
			DeleteLink(); //������� ������-�������
			DeleteLink(); //������� ������-������,������� ���� �������
		}	
	}			
}

string Polinom:: ToString()
{
	string res;
	long double k,a,b,c;//��� ������������� ����������� ������� to_string ���� ������������ ������ ����� ���
	int size=GetLength();//������� ������� ����� ��������
	for (int i=0; i<size;i++)
	{
		if (i!=0 && GetData(i).coef>0)//������� , ����� ������� +
		{
			res +=" +";
		}
		k=GetData(i).coef;//��������� �����������
		res +=(to_string(k));//�������� ����������� �� ������
		res += " x^";
		a=GetData(i).degree/100;//��������� �������
		res+=(to_string(a));//�������� ������� �� ������
		res += " y^";
		b=GetData(i).degree/10 % 10;
		res+=(to_string(b));
		res += " z^";	
		c=GetData(i).degree%10;
		res+=(to_string(c));
		res += " ";
	}
	return res;//����� ������
}

Polinom& Polinom::operator*(double num)//���������� ��������� �� ���������
{
	current = first->GetNext();//������ ��������� � �������� ������
	while (current != first)//���� �� ������ �� ����� ������������ ������
	{
		Monom temp(num*current->GetVal().coef, current->GetVal().degree);//������� ����������� ������� �� ��������
		current->SetVal(temp);//��������� �������� ������
		current = current->GetNext();//��������� ��������
	};
	return *this;
}

Polinom& Polinom::operator+=(Polinom &d)//���������� ��������� �������� ���������
{
	Return();//������� ��������� � ��������� ���������
	d.Return();//� �� ������������

	while (current != first || d.current != d.first)//���� �� ����� �� ����� ������������ ������
	{
		if (current->GetVal() < d.current->GetVal()) //���� ��� ���������� �� ������� 
		{
			Push(d.current->GetVal()); //, �� �������� ����� (�� ��������)         
			d.Forward();//�������� ������ �� �������������

		} 
		else 
			if (current->GetVal() == d.current->GetVal())//���� ������� ��������� 
			{
				Monom temp(current->GetVal().coef + d.current->GetVal().coef, current->GetVal().degree);//���������� ������

				current->SetVal(temp);//�������������� �������� ������

				if (current->GetVal().coef == 0)//���� � ���������� ��������� ������� �����������
				{
					DeleteLink();  //������� ���
					d.Forward();
				}
				else
				{
					d.Forward();//���� �� ���������, �� �������� ������
					Forward();
				};
			} 
			else 
			{
				Forward();
			}
	};

	return *this;//����� p , ��� p = p+d 
}

Polinom& Polinom::operator-=(Polinom &d)//���������� ���������
{
	return (*this) += d*(-1);//���� ����� , ������ ��������������� ��������
}

Polinom& Polinom::operator=(Polinom &d)//���������� ������������
{
	this->DeleteList();//������� ������

	Monom temp(0, -1);//������� ��� ������
	first = new Link<Monom>;
	first->SetVal (temp);
	first->SetNext(first);

	for (int i = 0; i < d.GetLength(); i++)
	{
		Push(d.GetData(i));//�������������� ������ �� ��������� ��������
	};

	return *this;
}
#endif