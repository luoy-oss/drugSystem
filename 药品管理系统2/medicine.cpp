#include <iostream>
#include <string>
#include <vector>
#include "medicine.h"
#include "auxiliaryFunction.h"

Date::Date() {
	year = 1900;
	month = 1;
	day = 1;
}

Date::Date(int _year, int _month, int _day) {
	year = _year;
	month = _month;
	day = _day;
}

std::ostream& operator<< (std::ostream& os, Date date) {
	os << date.year << "��" << date.month << "��" << date.day << "��";
	return os;
}

std::wostream& operator<< (std::wostream& wos, Date date) {
	wos << date.year << "��" << date.month << "��" << date.day << "��";
	return wos;
}

Date& Date::operator=(const Date& date) {
	if (this == &date) {
		return *this;
	}

	this->year = date.year;
	this->month = date.month;
	this->day = date.day;
	return *this;
}

bool Date::operator<(const Date& a) const {
	return this->year * 365 + this->month * 31 + this->day < a.year * 365 + a.month * 31 + a.day;
}

bool Date::operator>(const Date& a) const {
	return this->year * 365 + this->month * 31 + this->day > a.year * 365 + a.month * 31 + a.day;
}


Drug::Drug() {
	name = L"";
	manufacturer = L"";
	indications = L"";
	dateOfManufacture = Date();
	guaranteeDate = 0;
	quantity = 0;
}

Drug::Drug(std::wstring _name, std::wstring _manufacturer, std::wstring _indications, Date _dateOfManufacture, int _guaranteeDate) {
	name = _name;
	manufacturer = _manufacturer;
	indications = _indications;
	dateOfManufacture = _dateOfManufacture;
	guaranteeDate = _guaranteeDate;
}

std::ostream& operator<< (std::ostream& os, Drug drug) {
	os
		<< "********************************" << std::endl
		<< "ҩ����" << wstringTostring(drug.name) << std::endl
		<< "�����̣�" << wstringTostring(drug.manufacturer) << std::endl
		<< "��Ӧ֤�������Σ�" << wstringTostring(drug.indications) << std::endl
		<< "��������(yy mm dd)��" << drug.dateOfManufacture << std::endl
		<< "������(��)��" << drug.guaranteeDate << "��" << std::endl
		<< "���������" << drug.quantity << "��" << std::endl
		<< "********************************";
	return os;
}

Drug& Drug::operator=(const Drug& drug) {
	if (this == &drug) {
		return *this;
	}

	this->dateOfManufacture = drug.dateOfManufacture;
	this->name = drug.name;
	this->manufacturer = drug.manufacturer;
	this->indications = drug.indications;
	this->guaranteeDate = drug.guaranteeDate;
	this->quantity = drug.quantity;
	return *this;
}
