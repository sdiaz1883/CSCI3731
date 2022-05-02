#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

class Vector {
		double x;
		double y;
		double z;
	public:
	
	Vector (double a,double b,double c)
	{
		this->x=a;
		this->y=b;
		this->z=c;
	}
	
	Vector* add(Vector* V2)
	{
		double temp_x = this->x+V2->x;
		double temp_y = this->y+V2->y;
		double temp_z = this->z+V2->z;
		return new Vector(temp_x,temp_y,temp_z);
	}
	
	Vector* subtract(Vector* V2)
	{
		double temp_x = this->x-V2->x;
		double temp_y = this->y-V2->y;
		double temp_z = this->z-V2->z;
		return new Vector(temp_x,temp_y,temp_z);
	}
	
	Vector& operator+= (const Vector* V2)
	{
		x +=V2->x;
		y +=V2->y;
		z +=V2->z; 
		return *this;
	}
	
	Vector* multiply_by_double(double a)
	{
		double temp_x = this->x*a;
		double temp_y = this->y*a;
		double temp_z = this->z*a;
		
		return new Vector(temp_x,temp_y,temp_z);
	}
	
	double multiply(Vector* V2)
	{
		double temp_x = this->x*V2->x;
		double temp_y = this->y*V2->y;
		double temp_z = this->z*V2->z;
		
		return (temp_x+temp_y+temp_z);
	}
	
	void display()
	{
		cout<<"Vector Values are, ";
		cout<<" X: "<<x;
		cout<<" Y: "<<y;
		cout<<" Z: "<<z<<endl;
	}

};

class Planet{
	static const double G = 0.0000000000667408;
	long long int M;
	long long int radius;
	public:
	
	Planet (long long int M,long long int radius)
	{
		this->M = M;
		this->radius = radius;
	}
	
	Vector* gravitational_acceleration (Vector* V1)
	{
		double multiplied_val = V1->multiply(V1);
		double nominator_val = -G*M;
		double de_nominator_val = multiplied_val*(sqrt(multiplied_val));
		double division_res = nominator_val/de_nominator_val;
		Vector* temp_vec = V1->multiply_by_double(division_res);
		return temp_vec;
	}
	
	bool check_is_crashed (Vector* V1)
	{
		double multiplied_val = V1->multiply(V1);
		long long int t_radius = radius*radius;
		if(multiplied_val<t_radius)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


class Satellite{
	public:
	Planet* planet;
	Vector* position;
	Vector* velocity;
	
	Satellite (Planet* planet1,Vector* position1,Vector* velocity1)
	{
		this->planet = planet1;
		this->position = position1;
		this->velocity = velocity1;
	}
	
	void update (int time)
	{
		Vector* a = planet->gravitational_acceleration(position);
		this->velocity = this->velocity->add(a->multiply_by_double(time));
		this->position = this->position->add(this->velocity->multiply_by_double(time));
	}
	
	
};

class Fragments{
	Satellite* satellite[100];
	Vector* speed;
	int number_of_fragments;
	public:
	Fragments(Planet* planet, Vector* position,Vector* velocity,double speed,int const number_of_fragments)
	{
		for(int i=0;i<number_of_fragments;i++)
		{
			Satellite* temp = new Satellite(planet,position,velocity);
			satellite[i]=temp;
		}
		this->number_of_fragments=number_of_fragments;
		double z = 2.0*((double)rand()/(double)RAND_MAX)-1.0;
		double angle = 2.0*M_PI*((double)rand()/(double)RAND_MAX);
		double x = sqrt(1.0-z*z)*cos(angle);
		double y = sqrt(1.0-z*z)*sin(angle);
		Vector* vhat = new Vector(x, y, z);
		this->speed = velocity->add(vhat->multiply_by_double(speed));
	}
	
	void update (int time)
	{
		for(int i=0;i<number_of_fragments;i++)
		{
			Satellite* temp = satellite[i];
			temp->update(time);
			if(temp->planet->check_is_crashed(temp->position))
			{
				satellite[i]=NULL;
			}
		}
	}
	
	double find_distance(Satellite* sattelite_para)
	{
		Satellite* minimum = this->satellite[0];
		minimum->position = sattelite_para->position->subtract(this->satellite[0]->position);
		for(int i = 0; i < number_of_fragments; i++){
			Satellite* temp_minimum = satellite[i];
			temp_minimum->position = sattelite_para->position->subtract(temp_minimum->position);
	        if(temp_minimum->position < minimum->position){
	            minimum->position = temp_minimum->position;
	        }
    	}
    	
    	Vector* position_v1 = minimum->position;
    	Vector* position_v2 = sattelite_para->position;
    	Vector* multiplied_Vector = position_v1->subtract(position_v2);
    	double distance = sqrt(multiplied_Vector->multiply(multiplied_Vector));
    	return distance;
	}
	
};
int main()
{
	Vector* position = new Vector(400000,0,0);
	Vector* velocity = new Vector(0,7660,0);
//		M=5972000000000000000000712;
	Planet* planet = new Planet(5972000000000000000000712,6378000);
	Satellite* satellite = new Satellite(planet,position,velocity);
	bool is_true = true;
	int time = 1;
	Vector* f_position = new Vector(-400000,0,0);
	Vector* f_velocity = new Vector(0,-7660,0);
	Planet* f_planet = new Planet(5972000000000000000000712,6378000);
	
	int speed=1;
	int time_interval = 1;
	while(speed<100)
	{
		
		Fragments* fragment = new Fragments(f_planet,f_position,f_velocity,speed,time_interval);
		speed= speed+1;	
		time_interval= time_interval+1;
		double distance = fragment->find_distance(satellite);
		if(distance<400000)
		{
			time_interval=time_interval-1;
		}
	}
	
	return 0;	
}

