// Danilevskiy.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "matrix.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	matrix m1;
	matrix m2=m2.danilevsky(m1);
	getchar();
    return 0;
}



/*m1.mas[0][0] = 1;
m1.mas[0][1] = 0;
m1.mas[0][2] = 0;
m1.mas[2][0] = 0;
m1.mas[2][1] = 0;
m1.mas[2][2] = 1;
m1.mas[1][0] = 4;
m1.mas[1][1] = 2;
m1.mas[1][2] = 1;*/