#include "shape.hpp"
#include <cmath>
#include <iostream>


Shape::Shape():
	name_{""},
	color_{0.0,0.0,0.0}{

		std::cout <<"Create Shape" <<std::endl;
	}

Shape::Shape(std::string const&  name, Color const& color):
	name_{name},
	color_{color}{

		std::cout << "Create Shape" <<std::endl;
	}

Shape::~Shape()
	{
		std::cout<< "Delete Shape" <<std::endl;
	}

std::string Shape::getname() const{

	return name_;
}

Color const& Shape::getcolor() const{

	return color_;
}


std::ostream & Shape::print(std::ostream & os) const{

	os << name_ << std::endl << color_ ; 
	return os; //gibt Name & Farbe zurueck

}


std::ostream & operator <<(std::ostream & os, Shape const& s){
	return s.print(os);
}