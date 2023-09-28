#pragma once
#ifndef __DRUGSORT_H__
#define __DRUGSORT_H__
void readPinYinData();

void sortByName(std::vector<Drug>& drugList);
void sortByManufacturer(std::vector<Drug>& drugList);
void sortByManufactureDate(std::vector<Drug>& drugList);
void sortByGuaranteeDate(std::vector<Drug>& drugList);
void sortByQuantity(std::vector<Drug>& drugList);

#endif // !__DRUG_SORT_H__
