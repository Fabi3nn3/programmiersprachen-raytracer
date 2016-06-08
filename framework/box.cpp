#include "box.hpp"
#include <cmath>

Box::Box():
	max_{0.0,0.0,0.0},
	min_{0.0,0.0,0.0}{}

Box::Box(glm::vec3 const& min, glm::vec3 const&max):
	max_{max},
	min_{min}{}

float area() const override{

	return 
}

float volume() const override{
	return

}

glm::vec3 maximum() const{
	return max_;
}

glm::vec3 minimum() const{
	return min_;
}

void maximum(glm::vec3 const& max){
	max_ = max;
}

void minimum(glm::vec3 const& min){
	min_=min;
}