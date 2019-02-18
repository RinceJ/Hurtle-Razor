
//Author:Hurtle_Rzr$
// 

#include <iostream>
#include <cstring>



// to do // bug on same ID number on multiple points.
// to do // data structure on storing key co -ordinates

using namespace std;

class A
{
	private:	
		char *m_LABEL;
		const unsigned int m_ID;

		
	public:	
		A(const char *LABEL, const unsigned int ID):m_ID(ID)
		{
			m_LABEL = NULL;
			m_LABEL = new char(strlen(LABEL));
			strcpy(m_LABEL, LABEL);
			
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
		~A()
		{
			std::cout << "Destructor has been called " << std::endl;
		}		
};


int main()
{
		A *ptr = new A("point_1", 1);
		
		ptr->display_forward();		
		//ptr->display_reverse();		
		delete ptr;		
		A *ptr1 = new A("point_2", 1);
		
		ptr1->display_forward();
		
		delete ptr1;
}