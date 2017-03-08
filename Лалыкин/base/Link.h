#ifndef __LINK_H__
#define __LINK_H__


#include <iostream>
using namespace std;
template <class Type> //��������� ����� - ����� ������
class Link
{
protected:
	Type val;// ��������, ������������ � �����
	Link<Type> *next;// ��������� �� ��������� �����

public:

	Link()//�����������
	{
		val=0;
		next=NULL;
	}
	void SetVal (Type Val) { val = Val; } // �������� �������� �����
	void SetNext(Link<Type> *Next) { next = Next; }// �������� ��������� �� ��������� �����

	Type GetVal () { return val; } // ������� �������� �����
	Link<Type> *GetNext () { return next;}// ������� ��������� �� ��������� �����

};
#endif