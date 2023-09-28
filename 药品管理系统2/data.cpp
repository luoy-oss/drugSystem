#include <vector>
#include <string>
#include <iostream>
#include "auxiliaryFunction.h"
#include "medicine.h"
#include "data.h"


void loadDrugData(const char* file, std::vector<Drug>& drugList) {
	FILE* fin = NULL;
	errno_t err = freopen_s(&fin, file, "r", stdin);

	if (fin == NULL) {
		std::cout << "文件打开失败。" << std::endl;
	}
	else {
		std::string name;				//名称
		std::string manufacturer;		//制造商
		std::string indications;		//适应证或功能主治

		std::wstring wsname;			//名称
		std::wstring wsmanufacturer;	//制造商
		std::wstring wsindications;		//适应证或功能主治

		int year;
		int month;
		int day;
		int guaranteeDate;				//保质期(天)
		int quantity;					//数量
		while (!feof(fin)) {
			std::cin >> name >> manufacturer >> indications >> year >> month >> day >> guaranteeDate >> quantity;

			wsname = stringTowstring(name);
			wsmanufacturer = stringTowstring(manufacturer);
			wsindications = stringTowstring(indications);

			Drug drug;
			drug.name = wsname;
			drug.manufacturer = wsmanufacturer;
			drug.indications = wsindications;
			drug.quantity = quantity;
			drug.dateOfManufacture = Date{ year, month, day };
			drug.guaranteeDate = guaranteeDate;
			drug.quantity = quantity;

			drugList.push_back(drug);
		}
		std::cout << "当前数据库中药品数量：" << drugList.size() << std::endl;
		fclose(fin);
		freopen_s(&fin, "CON", "w", stdin);//取消重定向
	}
}

void saveDrugData(const char* file, std::vector<Drug>& drugList) {
	FILE* fout = NULL;
	errno_t err = freopen_s(&fout, file, "w", stdout);

	if (fout == NULL) {
		std::cout << "文件打开失败。" << std::endl;
	}
	else {
		std::string name;				//名称
		std::string manufacturer;		//制造商
		std::string indications;		//适应证或功能主治

		Date date;
		int guaranteeDate;				//保质期(天)
		int quantity;					//数量
		for (int i = 0; i < drugList.size(); i++) {
			if (i)std::cout << std::endl;
			name = wstringTostring(drugList[i].name);
			manufacturer = wstringTostring(drugList[i].manufacturer);
			indications = wstringTostring(drugList[i].indications);
			quantity = drugList[i].quantity;
			date = drugList[i].dateOfManufacture;
			guaranteeDate = drugList[i].guaranteeDate;
			quantity = drugList[i].quantity;
			std::cout << name << " " << manufacturer << " " << indications << " "
				<< date.year << " " << date.month << " " << date.day << " " << guaranteeDate << " " << quantity;
		}
		fclose(fout);
		freopen_s(&fout,"CON", "w", stdout);//取消重定向
	}
}
