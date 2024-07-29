
	#include"rectangle.hpp"
	
	void rectangle::setwidth(double w)
	{
		width=w;
	}

	void rectangle::setlength(double l)
	{
		length=l;
	}

	void rectangle::setboth(double l,double w)
	{
		length=l;
		width=w;
	}
	double rectangle::getwidth()
	{
		
		return width; 
	}
	double rectangle::getlength()
	{
		
		return length;
	}

	double rectangle::getparameter()
	{
		return 2 * (length + width);
	}

/*rectangle::rectangle():length(1),width(2)
{

}
*/