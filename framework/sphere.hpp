#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include "shape.hpp"
#include "ray.hpp"
#include <glm/vec3.hpp>

class Sphere:public Shape{

	public:
		Sphere();
		Sphere(glm::vec3 const& center, float const& rad); //floats sind primiziv -> keine const& 
		Sphere(std::string const& name, Color const& color, glm::vec3 const& center, float const& rad);
		~Sphere();

		float area() const override; //Ueberschreiben
		float volume() const override;
		glm::vec3 const& center() const;
		float radius() const;
		void center(glm::vec3 const& center);
		void radius(float const& rad);
		std::ostream & print (std::ostream & os) const override;
		//bool intersect const&(glm::vec3 const& origin, glm::vec3 const&direction);
		bool intersect (Ray const& ray, float& distance);

	private:
		glm::vec3 center_;
		float rad_;
		






};
#endif