#ifndef BIKE_H
#define BIKE_H
#include "vehicle.h"

class bike: public vehicle {
	private:
		char* bike_name;
		int bike_number;
	public:
		bike();
		bike(int wheel_number, int max_speed);
		bike(int wheel_number, int max_speed, char* bike_name);
		bike(int wheel_number, int max_speed, char* bike_name, int bike_number);
		bike(int wheel_number, int max_speed, char* bike_name, int bike_number, bool has_name);
		int get_bike_number();
		char* get_bike_name();
		const char* get_class_name();
		void set_bike_name(char* bike_name);
		void set_bike_number(int);
};
#endif
