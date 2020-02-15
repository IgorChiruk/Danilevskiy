#include "stdafx.h"
#include "matrix.h"


matrix::matrix()
{
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			mas[i][j] = (float)(1 + rand() % 3);
		}
	}
}


matrix& matrix::operator* (matrix & m3) 
{
	matrix result3;
	result3.reset();

	/*for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			result3.mas[i][j] = 0;
			for (int k = 0; k < 3; k++)
				result3.mas[i][j] += mas[i][k]* m3.mas[k][j];
		}*/

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int p = 0; p < 3; p++)
			{
				float a = mas[j][ p];
				float b = m3.mas[p][ i];
				float c = a * b;
				result3.mas[j] [i] = result3.mas[j][ i] + c;
			}
		}
	}


	return result3;
}

matrix& matrix::operator = (matrix &m1)
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			mas[i][j] = m1.mas[i][j];
	return *this;
}

void matrix::Display()
{
	for (int i = 0; i < 3; ++i) 
	{
		printf("\n");
		for (int j = 0; j < 3; ++j)
			printf("%.2f  ", mas[i][j]);
	}
	printf("\n");
}

void matrix::edin() 
{
	this->reset();
	for (int i = 0; i < 3; ++i)
		this->mas[i][i] = 1.0;
}

void matrix::reset()
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			mas[i][j] = 0;
}

matrix matrix::obrat(matrix m1) 
{
	matrix matr;
	matr.reset();
	for (int i = 0; i < 3; ++i)
				matr.mas[i][i] = 1;

	for (int i = 0; i < 3; ++i) 
	{
		if ((m1.mas[i][0] != 0)&(m1.mas[i][1] != 0)&(m1.mas[i][2] != 0)) 
		{
			if (i == 0) 
			{
				float q = m1.mas[i][1];
				matr.mas[0][1] = matr.mas[0][1] - q;
				q = m1.mas[i][2];
				matr.mas[0][2] = matr.mas[0][2] - q;
				matr.mas[0][0] = matr.mas[0][0]/ matr.mas[0][0];
				matr.mas[0][1] = matr.mas[0][1] / matr.mas[0][0];
				matr.mas[0][2] = matr.mas[0][2] / matr.mas[0][0];
			}

			if (i = 1) 
			{
				float q = m1.mas[i][0];
				matr.mas[1][0] = matr.mas[1][0] - q;
				q = m1.mas[i][2];
				matr.mas[1][2] = matr.mas[1][2] - q;
				q = m1.mas[1][1];
				matr.mas[1][0] = matr.mas[1][0] / q;
				matr.mas[1][1] = matr.mas[1][1] / q;
				matr.mas[1][2] = matr.mas[1][2] / q;
			}
		}

	}
	return matr;
}

matrix matrix::danilevsky(matrix m1)
{
	matrix b1, b2, d;
	d = m1;
	printf("Матрица до преобразования:\n");
	d.Display();
	float q;
	for (int i = 2; i > 0; i--)
	{
		b1.edin();
		q = d.mas[i][i-1];
		for (int j = 0; j < 3; ++j)
			b1.mas[i-1][j] = d.mas[i][j];

		for (int j = 0; j < 3; ++j) 
		{
			if((i-1)!=j)
				b1.mas[i - 1][j] = -b1.mas[i - 1][j]/q;
			else
				b1.mas[i - 1][j] = 1 / q;
		}
		b2 = b1.obrat(b1);
		matrix d1 = b2 * d;
		matrix d2 = d1 * b1;
		d = d2;
		printf("Матрица после преобразования:\n");
		d.Display();
		printf("\n\n");
	}
	printf("Матрица после всех преобразований:\n");
	d.Display();
	printf("Наши коэфициенты: %.2f  %.2f  %.2f",d.mas[0][0], d.mas[0][1], d.mas[0][2]);
	return d;
}

matrix::~matrix()
{

}
