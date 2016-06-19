#include "box.hpp"
#include <cmath>

Box::Box():
	Shape(),
	min_{0.0,0.0,0.0},
	max_{0.0,0.0,0.0}
	{std::cout << "Create Box" << std::endl; }

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
	min_{min},
	max_{max}
	{std::cout << "Create Box" << std::endl; }

Box::Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max):
	Shape(name,color),
	min_{min},
	max_{max}
	{std::cout << "Create Box" << std::endl; }

Box::~Box()
	{
		std::cout << "Delete Box" << std::endl;
	}

float Box::area() const{

	glm::vec3 differenz = max_ - min_;
	return 2*(differenz.y*differenz.z+differenz.x*differenz.z+differenz.x*differenz.y);

}

float Box::volume() const{
	
	glm::vec3 differenz = max_ - min_;
	return differenz.x*differenz.y*differenz.z;

}

std::ostream& Box::print(std::ostream & os) const{
	Shape::print(os);

	os<< "min "
	<<min_.x<< ", "
	<<min_.y<< ", "
	<<min_.z<< ", " <<std::endl<< "max "
	<<max_.x<< ", "
	<<max_.y<< ", "
	<<max_.z<< ". ";
}

glm::vec3 Box::maximum() const{
	return max_;
}

glm::vec3 Box::minimum() const{
	return min_;
}

void Box::maximum(glm::vec3 const& max){
	max_ = max;
}

void Box::minimum(glm::vec3 const& min){
	min_=min;
}