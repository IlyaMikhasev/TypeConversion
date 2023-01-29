#include <iostream>
#include "Car.h"
#include "Van.h"
int main() {
	setlocale(LC_ALL, "Russian");

	//1. ������������ double i = 32200030001.1 � int �� �������� ����� C++, �������� ����� �� ���������.������������, ��� ��������� ?
	double i = 32200030001.1;
	int i_doub = static_cast<double>(i);
	std::cout << "int i = " << i_doub << '\n';//��������� ������ ��� ������� � ���� ��� int ������� ������ ��������� �� ����� �� �� �������� �����
	//�������� ����� ������� ����� ����� �������� �������� � ��� ������ long long 
	long long i_doubl = static_cast<double>(i);
	std::cout << "long long i = " << i_doubl << '\n';

	//2. ��������� ������ ������ ������������� � ��������� �� double.
	const double* p_i = &i;
	double* pp_i = const_cast<double*>(p_i);

	//3. �������� ����� Car � Van, ������ ����������� �� �������.� main ���������	�������� upcast, �������� downcast � ��� ���������� downcast�a
	//  : � ���������� � �������.������������������ ����� ���������� ������	downcast�a ������� ����� ��������� �������������� ����������.
	Car car;
	Van van;
	Car* pCar = &van;//up-cast
	pCar->NameClass();
	Van* pVan = static_cast<Van*>(pCar);//down-cast
	pVan->NameClass();
	Van* pVan2 =(Van*)& car;//������������ down-cast(�������� UB)
	pVan2->NameClass();//����� �������� 
	Van* pVan3 = (Van*)pCar;//������������ down-cast
	pVan3->NameClass();//����� �������� �.�. ����� �� �����������
	return 0;
}