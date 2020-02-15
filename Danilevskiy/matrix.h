#pragma once
class matrix
{	
public:
	float mas[3][3];
	matrix();
	~matrix();
	matrix obrat(matrix m1);
	matrix danilevsky(matrix m1);
	matrix & operator*(matrix & m3);
	matrix & operator=(matrix & m1);
	void Display();
	void edin();
	void reset();
};


