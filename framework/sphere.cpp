#include "sphere.hpp"
#include <cmath>
#define M_PI   3.14159265358979323846 

Sphere::Sphere():
	Shape(),
	center_{0.0,0.0,0.0},
	rad_{0.0}{}

Sphere::Sphere(glm::vec3 const& center, float const& rad):
	center_{center},
	rad_{rad}{}

Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& center, float const& rad):
	Shape(name,color),	
	center_{center},
	rad_{rad}{}

float Sphere::area() const{
	return 4.0f * M_PI * rad_ * rad_;

}

float Sphere::volume() const{

	return(4.0f/3.0f) * M_PI * rad_ * rad_* rad_;
}

std::ostream & Sphere::print(std::ostream & os) const{

	Shape::print(os);
	os<<"Center"
	<<center_.x<<", "
	<<center_.y<<", "
	<<center_.z<<", "
	<<rad_<< ", ";
}


glm::vec3 const& Sphere::center() const{

	return center_;
}

float Sphere::radius() const{

	return rad_;
}

void Sphere::center(glm::vec3 const& center){

	center_ = center;

}

void Sphere::radius(float const& rad){

	rad_ = rad;
}