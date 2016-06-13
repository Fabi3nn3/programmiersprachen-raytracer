#include "box.hpp"
#include <cmath>

Box::Box():
	max_{0.0,0.0,0.0},
	min_{0.0,0.0,0.0}{}

Box::Box(glm::vec3 const& min, glm::vec3 const&max):
	max_{max},
	min_{min}{}

float Box::area() const{

	glm::vec3 differenz = max_ - min_;
	return 2*(differenz.y*differenz.z+differenz.x*differenz.z+differenz.x*differenz.y);

}

float Box::volume() const{
	
	glm::vec3 differenz = max_ - min_;
	return differenz.x*differenz.y*differenz.z;

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