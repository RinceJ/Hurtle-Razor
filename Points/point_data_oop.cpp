
//Author:Hurtle_Rzr$
// Academic code regarding the distance between two cartesian co-oridnates.

#include <iostream>
#include <cstring>
#include <math.h>


// to do // bug on same ID number on multiple points.
// to do // data structure on storing key co -ordinates



class point
{
	private:	
		char *m_LABEL;
		unsigned int m_ID;
		double *ptr;

		
	public:	
		point(const char *LABEL, const unsigned int ID, const double *PT):m_ID(ID)
		{
			m_LABEL = NULL;
			m_LABEL = new char(strlen(LABEL));
			strcpy(m_LABEL, LABEL);
			ptr = NULL;
			ptr = new double[3];
			for (int i = 0; i < 3; i++)
			{
				ptr[i] = PT[i];
			}		
		}		

		void operator=(const point &obj)
			{
				strcpy(m_LABEL, obj.m_LABEL);
				m_ID = obj.m_ID;
				for (int i = 0; i < 3; i++)
				{
					ptr[i] = obj.ptr[i];
				}
			}	

	// to do creating multiple instances. //demo overloading
		// A &operator+(const A &obj)
		// {	
		// 	double *temp = new double[3];
		// 	A *ptr_add = new A(temp);
		// 	for (int i = 0; i < 3; i++)
		// 	{
		// 		ptr_add->ptr[i] = ptr[i] + obj.ptr[i];  /// 
		// 	}
		// 	return *ptr_add;
		// 	delete[] temp;
		// }


		point &operator-(const point &obj)
		{
			double *temp = new double[3];
			point *ptr_add = new point("", 0, temp);
			for (int i = 0; i < 3; i++)
			{
				ptr_add->ptr[i] = pow(ptr[i] - obj.ptr[i], 2);  /// 
			}
			return *ptr_add;
			delete[] temp;
		}


		void display_forward()
		{
		  	for ( int i =0; i< strlen(m_LABEL); i++)
			{		
			std::cout << *(m_LABEL+i);
			}
			std::cout << "ID number of the point is " << m_ID << std::endl;
			std::cout << '\n' ;
		}	

		void display_reverse()
		{
		  	for ( int i = strlen(m_LABEL)-1 ; i>-1; i--)
			{		
			std::cout << *(m_LABEL+i);
			}
			//std::cout << "" << m_ID << std::endl;
			std::cout << '\n' ;
		}	

		void display_distance()
		{
			double temp = 0.0;
			for (int i = 0; i < 3; i++)
			{
				//std::cout << *(ptr + i) << std::endl;

				temp += *(ptr + i);
				
			}
			std::cout << sqrt(temp) << std::endl;
		}	
		~point()
		{
			delete[] ptr;
		}		

};


int main()
{

		double a[] = { 10, 10, 10 };
		double b[] = { 5, 5, 5 };
		double c[3];

		point *ptr_1 = new point("point_1", 1, a);	
		ptr_1->display_forward();		
		point *ptr_2 = new point("point_2", 2, b);	
		std::cout << '\n';
		ptr_2->display_forward();
	

		point *ptr_3 = new point("", 0, c); 
		*ptr_3 = *ptr_1 - *ptr_2;   //to do alternate approach to attack the distance problem.
		point *ptr_4;
		ptr_4 = ptr_3;
		ptr_4->display_distance();


		ptr_3->display_distance();

		delete ptr_3;
}