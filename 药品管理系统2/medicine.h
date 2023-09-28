#pragma once
#ifndef __MEDICINE_H__
#define __MEDICINE_H__
#include <vector>
struct Date {
	int year;
	int month;
	int day;
	
	Date();

	Date(int _year, int _month, int _day);

	friend std::ostream& operator<< (std::ostream& os, Date date);

	friend std::wostream& operator<< (std::wostream& wos, Date date);
	Date& operator=(const Date& date);
	bool operator<(const Date& a) const;
	bool operator>(const Date& a) const;

};

struct Drug {
	std::wstring name;				//����
	std::wstring manufacturer;		//������
	std::wstring indications;		//��Ӧ֤��������

	Date dateOfManufacture;			//��������(yy mm dd)
	int guaranteeDate;				//������(��)
	int quantity;					//����

	Drug();

	Drug(std::wstring _name, std::wstring _manufacturer, std::wstring _indications, Date _dateOfManufacture, int _guaranteeDate);
	
	friend std::ostream& operator<< (std::ostream& os, Drug drug);
	Drug& operator=(const Drug& drug);

};


#endif // !__MEDICINE_H__
