#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include <color.hpp>
#include <string>


class Shape{

	public:
		Shape();
		//name_{"name"}, color_{r,g,b},
		Shape(std::string const& name, Color const& color);
		virtual float area() const = 0; //Funktion auf dieser Ebene nicht implementiert
		virtual float volume() const = 0;
		virtual std::ostream & print (std::ostream & os) const;

	private:

		std::string name_;
		Color color_;


};
std::ostream & operator <<(std::ostream & os, Shape const& s);
#endif 


/*kommentar Aufagbe 5.7
std::shared_ptr<Shape>, s ist statisch S=std::make_shared<Sphere>(); dynamisch,
für alle methoden die nicht virtuell sind geht c++ nach statisch Typ */

