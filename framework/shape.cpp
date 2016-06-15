#include "shape.hpp"
#include <cmath>


Shape::Shape():
	name_{""},
	color_{0.0,0.0,0.0}{}

Shape::Shape(std::string const&  name, Color const& color):
	name_{name},
	color_{color}{}

std::ostream & Shape::print(std::ostream & os) const{

	os << name_ << std::endl << color_ ; 
	return os; //gibt Name & Farbe zurueck

}


std::ostream & operator <<(std::ostream & os, Shape const& s){
	return s.print(os);
}