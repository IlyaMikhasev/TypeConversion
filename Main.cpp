#include <iostream>
#include "Car.h"
#include "Van.h"
int main() {
	setlocale(LC_ALL, "Russian");

	//1. Преобразуйте double i = 32200030001.1 в int по правилам языка C++, выведите экран на результат.Предположите, что произошло ?
	double i = 32200030001.1;
	int i_doub = static_cast<double>(i);
	std::cout << "int i = " << i_doub << '\n';//результат больше чем вмещает в себя тип int поэтому данные вмещались по кругу по не соталось такое
	//значение такое большое число можно вместить например в тип данных long long 
	long long i_doubl = static_cast<double>(i);
	std::cout << "long long i = " << i_doubl << '\n';

	//2. Приведите пример снятия константности с указателя на double.
	const double* p_i = &i;
	double* pp_i = const_cast<double*>(p_i);

	//3. Создайте класс Car и Van, второй наследуется от первого.В main проведите	успешный upcast, успешный downcast и два неуспешных downcast’a
	//  : с указателем и ссылкой.Закомментированным кодом предложите версию	downcast’a которая будет считаться неопределенным поведением.
	Car car;
	Van van;
	Car* pCar = &van;//up-cast
	pCar->NameClass();
	Van* pVan = static_cast<Van*>(pCar);//down-cast
	pVan->NameClass();
	Van* pVan2 =(Van*)& car;//неправильный down-cast(возможно UB)
	pVan2->NameClass();//сдесь работает 
	Van* pVan3 = (Van*)pCar;//неправильный down-cast
	pVan3->NameClass();//сдесь работает т.к. класс не виртуальный
	return 0;
}