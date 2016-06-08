#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere:public Shape{

	public:
		Shere();

		Sphere(glm::vec3 const& center, float const& rad);

		virtual float area() const override; //Ueberschreiben
		virtual float volume() const override;
		glm::vec3 center() const;
		float rad() const;
		void center(glm::vec3 const& center);
		void radius(float const& rad);

	private:
		glm::vec3 center_;
		float rad_;





};
#endif