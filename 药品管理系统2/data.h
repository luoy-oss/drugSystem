#pragma once
#ifndef __LOADDATA_H__

void loadDrugData(const char* file, std::vector<Drug>& drugList);
void saveDrugData(const char* file, std::vector<Drug>& drugList);

#endif // !__LOADDATA_H__
