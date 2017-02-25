#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include "Link.h"

using namespace std;

template <class Type>
class List//��������� �����-������
{
	int length;// ����� ������

	Link<Type>* first;// ��������� �� ������ ����� � ������

public:

		Link<Type>* temp;// ��������� �� ��������� ����� 
	Link<Type>* current;// ��������� �� ������� �����
	Link<Type>* early;// ��������� �� ���������� ����� ������������ ��������

    List();// �����������

	void Push (Type data);// ���������� ������� � ������ ��-�������� (���� ������������� ���������)

	Link<Type>* Search (Type elem);//����� �������� � ������ �� �������� � �����

	bool IsEmpty();//�������� �� �������

	int GetLength();//������� ����� ������

	Type GetData(int pos);//������� �������� � �������� �������

	void DeleteList();//������� ������ 


	//void DeleteCurr ();// �������� �������� �����
	//void GoNext();// ����������� ���������
	//void Reset();// ������� ��������� �� ������
};


template <class Type>
List<Type>::List()// �����������
{   
	first=NULL;
	temp=NULL;
	current=NULL;
	early=NULL;
	length = 0;

	first = new Link<Type>();
	first->SetNext(first);//��������� ��������� �� ������ �����

}

template <class Type>
void List<Type>::Push (Type data)// ���������� ���������
{

	temp = new Link<Type>();   //������ ����� �����
	temp->SetVal(data);//�������� �������� ����� �� ��������� 

	current = first->GetNext();     // ��������� �� ������� ����� ������ �� ������ ����� � ������ (��� ��� ��� �� ������)
	early = first;    // � ��������� �� ���������� ������ �� ������

	while (data < current->GetVal())  //���� ��������� �������� �������� ������ ,��� � ������� �����
	{
		early = current;//��������� �� ����������(������� ����� �� ������) ������ �� �������                   
		current = current->GetNext(); //����������� ������� �����  
	};

	temp->SetNext(current);  //��������� ��������� �� ��������� ������ ����� � ���������� �� ������� �������,
	early->SetNext(temp); //��������� �� ��������� �� ����������� � ���������� �� �����,

	early = early->GetNext();//����������� ��������� �� ���������� �� �����, ����� ��������� �� ���������� � ������� ��������� �� �������� ������ ������

	length++;
}

template <class Type>
Link<Type>* List<Type>::Search (Type elem)//����� �������� � ������ �� �������� � �����
{
	if (!IsEmpty())//���� �� ����
	{
		current = first->GetNext(); // ��������� �� ������� ����� ������ �� ������ ����� � ������ (��� ��� ��� �� ������)
		while (current->GetVal() != elem)//���� �� �������� ������� �������
		{
			early = current;               //��������� �� ����������(������� ����� �� ������) ������ �� �������      
			current = current->GetNext();//����������� ������� ����� 
		};

		return current;//����� �� �� ��� ������������
	};
}

template <class Type>
bool List<Type>::IsEmpty()//�������� �� �������
{
	if (length == 0) return true;
	return false;
}

template <class Type>
int List<Type>::GetLength()//������� ����� ������
{
	return length;
}

template <class Type>
Type List<Type>::GetData(int pos)//������� �������� � �������� �������
{
	current = first->GetNext();// ��������� �� ������� ����� ������ �� ������ ����� � ������ (��� ��� ��� �� ������)
	early = current; //��������� �� ���������� ������ �� �������   

	for (int i = 0; i < pos; i++) 
	{
		early = current;              //��������� �� ����������(������� ����� �� ������) ������ �� �������            
		current = current->GetNext(); //����������� ������� �����    
	};

	return current->GetVal();//����� �� �� ��� ������������
}

template <class Type>
void List<Type>::DeleteList()//������� ������ 
{
	current = first->GetNext();//��������� �� ������� ����� ������ �� ������ ����� � ������ (��� ��� ��� �� ������)

	while (current != first)//���� �� ����� �� ������ 
	{
		early = current;             //��������� �� ����������(������� ����� �� ������) ������ �� ������� 
		current = current->GetNext();//����������� ������� �����       
		delete early;//������ ����������
	};

	delete current;//������ ��������� ����������
	length = 0;
}
#endif

//template <class Type>
//void List<Type>::DeleteCurr ()// �������� �������� ����� 
//{
//	if (!IsEmpty())//���� ������ �� ����
//	{
//		early->SetNext(current->GetNext());//�� ��������� �� ���������� ���������� �� �������
//		delete current;//������� ����� �������,
//
//		current = early->GetNext();//��������� �� ������� ����������� ��������� �� ����������
//            
//		length--;
//	};
//}

//template <class Type>
//void List<Type>::GoNext()// ����������� ���������
//{
//	early = current;
//	current = current->GetNext();
//}

//template <class Type>
//void List<Type>::Reset()
//{
//	early = first;
//	current = first->GetNext();
//}


