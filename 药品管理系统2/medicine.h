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
	std::wstring name;				//名称
	std::wstring manufacturer;		//制造商
	std::wstring indications;		//适应证或功能主治

	Date dateOfManufacture;			//生产日期(yy mm dd)
	int guaranteeDate;				//保质期(天)
	int quantity;					//数量

	Drug();

	Drug(std::wstring _name, std::wstring _manufacturer, std::wstring _indications, Date _dateOfManufacture, int _guaranteeDate);
	
	friend std::ostream& operator<< (std::ostream& os, Drug drug);
	Drug& operator=(const Drug& drug);

};


#endif // !__MEDICINE_H__
