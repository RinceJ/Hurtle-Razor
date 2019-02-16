//Author:RJE2
#pragma once

#ifdef RJE2LIBRARY_EXPORTS
#define RJE2LIBRARY_API __declspec(dllexport)
#else
#define RJE2LIBRARY_API __declspec(dllimport)
#endif 


extern "C" RJE2LIBRARY_API void display();
