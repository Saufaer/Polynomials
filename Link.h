#ifndef __LINK_H__
#define __LINK_H__


#include <iostream>
using namespace std;
template <class Type> //шаблонный класс - звено списка
class Link
{
protected:
	Type val;// «начение, содержаща€с€ в звене
	Link<Type> *next;// ”казатель на следующее звено

public:

	Link()//конструктор
	{
		val=0;
		next=NULL;
	}
	void SetVal (Type Val) { val = Val; } // «аписать значение звена
	void SetNext(Link<Type> *Next) { next = Next; }// «аписать указатель на следующее звено

	Type GetVal () { return val; } // ¬ернуть значение звена
	Link<Type> *GetNext () { return next;}// ¬ернуть указатель на следующее звено

};
#endif