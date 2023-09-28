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
		std::cout << "�ļ���ʧ�ܡ�" << std::endl;
	}
	else {
		std::string name;				//����
		std::string manufacturer;		//������
		std::string indications;		//��Ӧ֤��������

		std::wstring wsname;			//����
		std::wstring wsmanufacturer;	//������
		std::wstring wsindications;		//��Ӧ֤��������

		int year;
		int month;
		int day;
		int guaranteeDate;				//������(��)
		int quantity;					//����
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
		std::cout << "��ǰ���ݿ���ҩƷ������" << drugList.size() << std::endl;
		fclose(fin);
		freopen_s(&fin, "CON", "w", stdin);//ȡ���ض���
	}
}

void saveDrugData(const char* file, std::vector<Drug>& drugList) {
	FILE* fout = NULL;
	errno_t err = freopen_s(&fout, file, "w", stdout);

	if (fout == NULL) {
		std::cout << "�ļ���ʧ�ܡ�" << std::endl;
	}
	else {
		std::string name;				//����
		std::string manufacturer;		//������
		std::string indications;		//��Ӧ֤��������

		Date date;
		int guaranteeDate;				//������(��)
		int quantity;					//����
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
		freopen_s(&fout,"CON", "w", stdout);//ȡ���ض���
	}
}
