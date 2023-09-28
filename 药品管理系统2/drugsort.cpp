#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <graphics.h>
#include "medicine.h"
#include "drugsort.h"

std::map<int, std::string> pinyinMap;

void readPinYinData() {
    FILE* fin;
    fopen_s(&fin, "unicode_to_hanyu_pinyin.txt", "r");

    if (fin == NULL) {
        printf("ƴ���ļ���ʧ�ܣ�\n����������ܳ���");
        MessageBox(NULL, _T("ƴ���ļ���ʧ�ܣ�\n����������ܳ���"), _T(""), MB_OK | MB_SYSTEMMODAL);
    }
    else {
        int hexNum;
        char* pinyinStr = new char[100];
        while (!feof(fin)) {
            fscanf_s(fin, "%x,%s", &hexNum, pinyinStr, 10);
            getc(fin);
            //printf("%x %s\n", hexNum, pinyinStr);
            pinyinMap.insert(std::pair<int, std::string>{hexNum, pinyinStr});         
        }

        printf("�ɹ�����ƴ�����ݣ�%zd��", pinyinMap.size());
        fclose(fin);
    }
}

bool compare(const std::wstring& a, const std::wstring& b) {
    for (size_t i = 0; i < a.size() && i < b.size(); ++i) {
        if (a[i] != b[i]) {
            return strcmp(pinyinMap[(int)a[i]].c_str(), pinyinMap[(int)b[i]].c_str()) < 0 ? 1 : 0;
        }
    }
    return a.size() < b.size();
}


bool cmpWithName(Drug a, Drug b) {
    return compare(a.name, b.name);
}
bool cmpWithManufacturer(Drug a, Drug b) {
	return compare(a.manufacturer, b.manufacturer);
}

bool cmpWithManufactureDate(Drug a, Drug b) {
	return a.dateOfManufacture > b.dateOfManufacture;
}

bool cmpWithGuaranteeDate(Drug a, Drug b) {
	return a.guaranteeDate > b.guaranteeDate;
}

bool cmpWithQuantity(Drug a, Drug b) {
	return a.quantity > b.quantity;
}

void sortByName(std::vector<Drug>& drugList) {
	std::sort(drugList.begin(), drugList.end(), cmpWithName);
}

void sortByManufacturer(std::vector<Drug>& drugList) {
	std::sort(drugList.begin(), drugList.end(), cmpWithManufacturer);
}

void sortByManufactureDate(std::vector<Drug>& drugList) {
	std::sort(drugList.begin(), drugList.end(), cmpWithManufactureDate);
}

void sortByGuaranteeDate(std::vector<Drug>& drugList) {
	std::sort(drugList.begin(), drugList.end(), cmpWithGuaranteeDate);
}

void sortByQuantity(std::vector<Drug>& drugList) {
	std::sort(drugList.begin(), drugList.end(), cmpWithQuantity);
}
