#include "sphere.hpp"
#include <cmath>
#define M_PI   3.14159265358979323846 

Sphere::Sphere():

	center_{0.0,0.0,0.0},
	rad_{0.0}{}

Spehre::Sphere(glm::vec3 const& center, float const& rad):
		
	center_{center},
	rad_{rad}{}

float area() const override{
	return 4.0f * M_PI * r * r;

}

float volume() const override{

	return(4.0f/3.0f) * M_PI * r * r * r;
}

glm::vec3 Sphere::center() const{

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