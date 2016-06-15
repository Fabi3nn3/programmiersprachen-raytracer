#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape{

	public:

		Box();
		Box(glm::vec3 const& min, glm::vec3 const& max);
		Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max);
		
		float area() const override; 
		float volume() const override;
		glm::vec3 maximum() const;
		glm::vec3 minimum() const;
		void minimum(glm::vec3 const& min);
		void maximum(glm::vec3 const& max);
		std::ostream & print (std::ostream & os) const override;


	private:
		glm::vec3 min_;
		glm::vec3 max_;


};
#endif