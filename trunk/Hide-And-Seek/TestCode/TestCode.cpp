// TestCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Alloc.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int* ptr = NULL;

	ptr = NEW_IN_DOMAIN(IA) int[250];

	delete_domain ptr;

	float* ptr2  = NEW_IN_DOMAIN(Sound) float[56];

	delete_domain ptr2;

	system("pause");

	return 0;
}

