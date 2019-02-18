//Author:Hurtle_Rzr$
// Triangle objects

#include <iostream>
#include <cstring>

using namespace std;

class Triangle
{
	private:	
		char *m_LABEL;
		unsigned int m_ID;
		double *m_point_1;
		double *m_point_2;
		double *m_point_3;

		
	public:	
		Triangle(const char *LABEL, const unsigned int ID, const double *m_POINT_1, const double *m_POINT_2,  const double *m_POINT_3):m_ID(ID)
		{
			m_LABEL = NULL;
			m_LABEL = new char(strlen(LABEL));
			strcpy(m_LABEL, LABEL);
			
			m_point_1 = NULL;
			m_point_2 = NULL;
			m_point_3 = NULL;
			
			m_point_1 = new double[3];	
			m_point_2 = new double[3];
			m_point_3 = new double[3];
			
			for ( int i =0 ; i < 3 ; i++)
			{	
				m_point_1[i] = m_POINT_1[i];	
			}
			for ( int i =0 ; i < 3 ; i++)
			{	
				m_point_2[i] = m_POINT_2[i];	
			}
			for ( int i =0 ; i < 3 ; i++)
			{	
				m_point_3[i] = m_POINT_3[i];	
			}
			
		}	

		Triangle(const Triangle &obj)
		{
			strcpy(m_LABEL,obj.m_LABEL);
			
			m_ID = obj.m_ID;
					
			for ( int i =0 ; i < 3 ; i++)
			{	
				m_point_1[i] = obj.m_point_1[i];	
			}
			for ( int i =0 ; i < 3 ; i++)
			{	
				m_point_2[i] = obj.m_point_2[i];	
			}
			for ( int i =0 ; i < 3 ; i++)
			{	
				m_point_3[i] = obj.m_point_3[i];	
			}				
		}

		void display_points()
		{
		  	for ( int i =0; i< strlen(m_LABEL); i++)
			{		
			std::cout << *(m_LABEL+i);
			}
			std::cout << "ID number of the point is   " << m_ID << std::endl;
			std::cout << '\n' ;
			
			std::cout << "The specific co ordinates are " << std::endl;
			
			for (int i = 0 ; i < 3 ; i++)
			{
				std::cout << *(m_point_1 + i)<< '\t';
			}
			
			std::cout << '\n' ;
			
			for (int i = 0 ; i < 3 ; i++)
			{
				std::cout << *(m_point_2 + i) << '\t';
			}
			
			std::cout << '\n' ;
			
			for (int i = 0 ; i < 3 ; i++)
			{
				std::cout << *(m_point_3 + i) << '\t';
			}
			
			std::cout << '\n' ;	
		}	
		
		~Triangle()
		{
			delete m_LABEL;
			delete m_point_1;
			delete m_point_2;
			delete m_point_3;
		}		
};


int main()
{	
		double p_1[] = {1.2, 1.3, 1.5};		
		double p_2[] = {1.2, 1.3, 1.5};		
		double p_3[] = {1.2, 1.3, 1.5};	
		Triangle *ptr = new Triangle("Triangle_1", 1, p_1, p_2, p_3);		
		Triangle *ptr1 = ptr;
		
		ptr1->display_points();		
			
		delete ptr1;

}