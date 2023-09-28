#pragma once
#ifndef __DUGUMANAGEMENTSYSTEM_H__
#define __DUGUMANAGEMENTSYSTEM_H__

#ifdef __cplusplus
int _main_();	//c++函数入口

extern "C" {
	//该文件同时被 C 和 C++ 编译器使用，
	//使用 extern "C" 将其中的下方函数声明指定为使用 C 的方式进行编译链接
#endif
int _main_c();	//c语言函数入口

#ifdef __cplusplus

}
#endif

#endif
