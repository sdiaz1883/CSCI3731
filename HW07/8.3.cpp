#include <iostream>
#include <string>

using namespace std;

class Vector {
	public:
		double x;
		double y;
		double z;
	
	Vector (double a,double b,double c)
	{
		this->x=a;
		this->y=b;
		this->z=c;
	}
	
	Vector* add(Vector V2)
	{
		double temp_x = this->x+V2.x;
		double temp_y = this->y+V2.y;
		double temp_z = this->z+V2.z;
		return new Vector(temp_x,temp_y,temp_z);
	}
	
	Vector* subtract(Vector V2)
	{
		double temp_x = this->x-V2.x;
		double temp_y = this->y-V2.y;
		double temp_z = this->z-V2.z;
		return new Vector(temp_x,temp_y,temp_z);
	}
	
	Vector& operator+= (const Vector& V2)
	{
		x +=V2.x;
		y +=V2.y;
		z +=V2.z; 
		return *this;
	}
	
	Vector* multiply_by_double(double a)
	{
		double temp_x = this->x*a;
		double temp_y = this->y*a;
		double temp_z = this->z*a;
		
		return new Vector(temp_x,temp_y,temp_z);
	}
	
	double multiply(Vector V2)
	{
		double temp_x = this->x*V2.x;
		double temp_y = this->y*V2.y;
		double temp_z = this->z*V2.z;
		
		return (temp_x+temp_y+temp_z);
	}
	
	void display()
	{
		cout<<"Vector Values are:"<<endl;
		cout<<"X: "<<x<<endl;
		cout<<"Y: "<<y<<endl;
		cout<<"Z: "<<z<<endl;
	}

};

