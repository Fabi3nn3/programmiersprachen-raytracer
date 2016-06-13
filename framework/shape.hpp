#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP


class Shape{

	public:
		

		virtual float area() const = 0; //Funktion auf dieser Ebene nicht implementiert
		virtual float volume() const = 0;





};
#endif 

/*kommentar Aufagbe 5.7
std::shared_ptr<Shape>, s ist statisch S=std::make_shared<Sphere>(); dynamisch,
für alle methoden die nicht virtuell sind geht c++ nach statisch Typ */