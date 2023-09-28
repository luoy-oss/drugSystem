#pragma once
#ifndef __ACCOUNT_H__

int loginCheck(std::wstring& _account, std::wstring& _passwd);
void regist(std::wstring& _account, std::wstring& _passwd);
void loginWindow();

#endif // !__ACCOUNT_H__
