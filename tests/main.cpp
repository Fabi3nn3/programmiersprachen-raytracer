#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <shape.hpp>
#include <sphere.hpp>
#include <box.hpp>
#include <color.hpp>
#include <glm/vec3.hpp>


TEST_CASE("Box","[function1]"){
	Box b{};
	REQUIRE(Approx(0.0f) == b.minimum().x);
	REQUIRE(Approx(0.0f) == b.minimum().y);
	REQUIRE(Approx(0.0f) == b.minimum().z);

	//Color farbe{0.0f,0.0f,0.0f};
	//std::string name;
	glm::vec3 max{1.5f,5.6f,2.3f};
	glm::vec3 min{2.0f,3.3f,4.0f};
	
	Box b1{min, max};
	REQUIRE(Approx(2.0f) == b1.minimum().x);
	REQUIRE(Approx(3.3f) == b1.minimum().y);
	REQUIRE(Approx(4.0f) == b1.minimum().z);
}

TEST_CASE("Boxmax","[function2]"){

	Box b{};
	REQUIRE(Approx(0.0f) == b.maximum().x);
	REQUIRE(Approx(0.0f) == b.maximum().y);
	REQUIRE(Approx(0.0f) == b.maximum().z);

	glm::vec3 min{2.0f,3.3f,4.0f};
	glm::vec3 max{1.5f,5.6f,2.3f};

	Box b1{min, max};
	REQUIRE(Approx(1.5f) == b1.maximum().x);
	REQUIRE(Approx(5.6f) == b1.maximum().y);
	REQUIRE(Approx(2.3f) == b1.maximum().z);
}

TEST_CASE("intersect RaySphere","[intersect]"){
	//Ray
	glm::vec3 ray_origin {0.0f,0.0f,0.0f};
	//ray direction has to be normalized!
	//you can use:
	v = glm::normalize(some_vector);
	glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};
	//Sphere
	glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
	float sphere_radius {1.0f};
	float distance {0.0f};
	auto result = glm::intersectRaySphere(
		ray_origin, ray_direction,
		sphere_center, sphere_radius,
		distance);
	REQUIRE(distance == Approx(4.0f));
}





float sphere_radius {1.0};
float distance {0.0};
auto result = glm :: in te rs ect Ra yS ph er e (
ray_origin , ray_direction ,
sphere_center ,
sphere_radius * sphere_radius , // squared radius !!!
distance );
REQUIRE ( distance == Approx (4.0 f ));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
