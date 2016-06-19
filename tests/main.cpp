#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <shape.hpp>
#include <sphere.hpp>
#include <box.hpp>
#include <color.hpp>
#include <ray.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

TEST_CASE("Spherecenter","[aufgabe5.2]"){

	Sphere s1{};
	REQUIRE(Approx(0.0f) == s1.center().x);
	REQUIRE(Approx(0.0f) == s1.center().y);
	REQUIRE(Approx(0.0f) == s1.center().z);

	Sphere s2 {{0.6f, 1.9f, 1.1f}, 4.2f};
	REQUIRE(Approx(0.6f) == s2.center().x);
	REQUIRE(Approx(1.9f) == s2.center().y);
	REQUIRE(Approx(1.1f) == s2.center().z);

	Sphere s3 {{3.3f, 4.5f, -2.3f}, 4.2f};
	REQUIRE(Approx(3.3f) == s3.center().x);
	REQUIRE(Approx(4.5f) == s3.center().y);
	REQUIRE(Approx(-2.3f) == s3.center().z);

}

TEST_CASE("Sphereradius","[aufgabe5.2]"){

	Sphere s1{};
	REQUIRE(Approx(0.0f) == s1.radius());

	Sphere s2 {{0.6f, 1.9f, 1.1f}, -4.2f};
	REQUIRE(Approx(-4.2f) == s2.radius());
	

	Sphere s3 {{3.3f, 4.5f, -2.3f}, 5.3f};
	REQUIRE(Approx(5.3f) == s3.radius());
	
}

TEST_CASE("SphereSetCenter","[aufgabe5.2]"){

	Sphere s1{};
	s1.center({1.0f, 1.0f, 1.0f});
	REQUIRE(Approx(1.0f) == s1.center().x);
	REQUIRE(Approx(1.0f) == s1.center().y);
	REQUIRE(Approx(1.0f) == s1.center().z);

	Sphere s2{{0.6f, 1.9f, 1.1f}, 4.2f};
	s2.center({1.3f, 2.6f, 1.2f});
	REQUIRE(Approx(1.3f) == s2.center().x);
	REQUIRE(Approx(2.6f) == s2.center().y);
	REQUIRE(Approx(1.2f) == s2.center().z);

	Sphere s3 {{3.3f, 4.5f, -2.3f}, 4.2f};
	s3.center({2.3f, 3.6f, -4.4f});
	REQUIRE(Approx(2.3f) == s3.center().x);
	REQUIRE(Approx(3.6f) == s3.center().y);
	REQUIRE(Approx(-4.4f) == s3.center().z);

}

TEST_CASE("SphereSetsRadius","[aufgabe5.2]"){

	Sphere s1{};
	s1.radius(4.2f);
	REQUIRE(Approx(4.2f) == s1.radius());

	Sphere s2{{0.6f, 1.9f, 1.1f}, 4.2f};
	s2.radius(-1.3f);
	REQUIRE(Approx(-1.3f) == s2.radius());

	Sphere s3 {{3.3f, 4.5f, -2.3f}, 4.2f};
	s3.radius(3.5f);
	REQUIRE(Approx(3.5f) == s3.radius());
}

TEST_CASE("SphereGetsArea","[aufgabe5.2]"){

	Sphere s1{};
	REQUIRE(Approx(0.0f) == s1.area());

	Sphere s2{{0.4f, 2.3f, 1.2f}, 4.3f};
	REQUIRE(Approx(232.3522f) == s2.area());

	Sphere s3{{6.9f, 4.2f, -1.2f}, -6.9f};
	REQUIRE(Approx(598.2849f) == s3.area());
}

TEST_CASE("SphereGetsVolume","[aufgabe5.2]"){

	Sphere s1{};
	REQUIRE(Approx(0.0f) == s1.volume());

	Sphere s2{{0.4f, 2.3f, 1.2f}, 4.3f};
	REQUIRE(Approx(333.0381f) == s2.volume());

	Sphere s3{{6.9f, 4.2f, -1.2f}, -6.9f};
	REQUIRE(Approx(-1376.0553f) == s3.volume());
}

TEST_CASE("Boxmin","[function1]"){
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

TEST_CASE("BoxSetsMin","[aufgabe5.2]"){

	Box b1{};
	b1.minimum({1.0f, 1.0f, 1.0f});
	REQUIRE(Approx(1.0f) == b1.minimum().x);
	REQUIRE(Approx(1.0f) == b1.minimum().y);
	REQUIRE(Approx(1.0f) == b1.minimum().z);

	glm::vec3 min2{2.0f, 3.3f, 4.0f};
	glm::vec3 max2{1.5f, 5.6f, 2.3f};

	Box b2{min2, max2};
	b2.minimum({2.3f, 1.3f, 4.3f});
	REQUIRE(Approx(2.3f) == b2.minimum().x);
	REQUIRE(Approx(1.3f) == b2.minimum().y);
	REQUIRE(Approx(4.3f) == b2.minimum().z);

	glm::vec3 min3{1.0f, 2.3f, 4.1f};
	glm::vec3 max3{0.0f, 2.5f, 1.2f};

	Box b3{min3, max3};
	b3.minimum({6.9f, 4.2f, 1.6f});
	REQUIRE(Approx(6.9f) == b3.minimum().x);
	REQUIRE(Approx(4.2f) == b3.minimum().y);
	REQUIRE(Approx(1.6f) == b3.minimum().z);

}

TEST_CASE("BoxSetsMax","[aufgabe5.2]"){

	Box b1{};
	b1.maximum({1.0f, 1.0f, 1.0f});
	REQUIRE(Approx(1.0f) == b1.maximum().x);
	REQUIRE(Approx(1.0f) == b1.maximum().y);
	REQUIRE(Approx(1.0f) == b1.maximum().z);

	glm::vec3 min2{2.0f, 3.3f, 4.0f};
	glm::vec3 max2{1.5f, 5.6f, 2.3f};

	Box b2{min2, max2};
	b2.maximum({2.3f, 1.3f, 4.3f});
	REQUIRE(Approx(2.3f) == b2.maximum().x);
	REQUIRE(Approx(1.3f) == b2.maximum().y);
	REQUIRE(Approx(4.3f) == b2.maximum().z);

	glm::vec3 min3{1.0f, 2.3f, 4.1f};
	glm::vec3 max3{0.0f, 2.5f, 1.2f};

	Box b3{min3, max3};
	b3.maximum({6.9f, 4.2f, 1.6f});
	REQUIRE(Approx(6.9f) == b3.maximum().x);
	REQUIRE(Approx(4.2f) == b3.maximum().y);
	REQUIRE(Approx(1.6f) == b3.maximum().z);
}

TEST_CASE("BoxArea","[aufgabe5.2]"){

	Box b1{};
	REQUIRE(Approx(0.0f) == b1.area());

	glm::vec3 min2{1.0f, 2.3f, 4.1f};
	glm::vec3 max2{0.0f, 2.5f, 1.2f};

	Box b2{min2, max2};
	REQUIRE(Approx(4.24f) == b2.area());

	glm::vec3 min3{-1.0f, -4.3f, 5.6f};
	glm::vec3 max3{-9.0f, 1.5f, -2.2f};

	Box b3{min3, max3};
	REQUIRE(Approx(-58.48f) == b3.area());
}

TEST_CASE("BoxVolume","[aufgabe5.2]"){

	Box b1{};
	REQUIRE(Approx(0.0f) == b1.volume());

	glm::vec3 min2{1.0f, 2.3f, 4.1f};
	glm::vec3 max2{0.0f, 2.5f, 1.2f};

	Box b2{min2, max2};
	REQUIRE(Approx(0.58f) == b2.volume());

	glm::vec3 min3{-1.0f, -4.3f, 5.6f};
	glm::vec3 max3{-9.0f, 1.5f, -2.2f};

	Box b3{min3, max3};
	REQUIRE(Approx(361.92f) == b3.volume());
}

TEST_CASE("BoxConst","[aufgabe5.3]"){

	Box b1{};

	REQUIRE("" == b1.getname());

	REQUIRE(Approx(0.0f) == b1.getcolor().r);
	REQUIRE(Approx(0.0f) == b1.getcolor().g);
	REQUIRE(Approx(0.0f) == b1.getcolor().b);

	REQUIRE(Approx(0.0f) == b1.minimum().x);
	REQUIRE(Approx(0.0f) == b1.minimum().y);
	REQUIRE(Approx(0.0f) == b1.minimum().z);

	REQUIRE(Approx(0.0f) == b1.maximum().x);
	REQUIRE(Approx(0.0f) == b1.maximum().y);
	REQUIRE(Approx(0.0f) == b1.maximum().z);

	glm::vec3 min2{1.0f, 4.3f, 5.6f};
	glm::vec3 max2{9.0f, 1.5f, 2.2f};

	Box b2{"Box", {1.0,0.0,0.0}, min2, max2};

	Color col1 = b2.getcolor();

	REQUIRE(b2.getname() == "Box");
	REQUIRE(col1.r == 1.0);
	REQUIRE(col1.g == 0.0);
	REQUIRE(col1.b == 0.0);

	glm::vec3 min3{2.3f, 3.4f, 1.6f};
	glm::vec3 max3{4.5f, 3.5f, 2.3f};

	Box b3{"Box3",{0.6f,0.5f,0.0f}, min3, max3};

	Color col2 = b3.getcolor();

	REQUIRE(b3.getname() == "Box3");
	REQUIRE(col2.r == Approx(0.6f));
	REQUIRE(col2.g == Approx(0.5f));
	REQUIRE(col2.b == Approx(0.0f));

}

TEST_CASE("SphereConst","aufgabe5.3"){

	Sphere s1{};
	REQUIRE("" == s1.getname());

	REQUIRE(Approx(0.0f) == s1.getcolor().r);
	REQUIRE(Approx(0.0f) == s1.getcolor().g);
	REQUIRE(Approx(0.0f) == s1.getcolor().b);

	REQUIRE(Approx(0.0f) == s1.center().x);
	REQUIRE(Approx(0.0f) == s1.center().y);
	REQUIRE(Approx(0.0f) == s1.center().z);

	REQUIRE(Approx(0.0f) == s1.radius());

	Sphere s2{"Sphere2", {0.67f, 0.3f, 0.9f}, {4.2f, 3.3f, 1.3f}, 6.9f};

	REQUIRE("Sphere2" == s2.getname());
	REQUIRE(Approx(0.67f) == s2.getcolor().r);
	REQUIRE(Approx(0.3f) == s2.getcolor().g);
	REQUIRE(Approx(0.9f) == s2.getcolor().b);

}

TEST_CASE("print","[aufgabe5.5]"){

	Sphere s1{{1.3f, 0.5f, 2.6f}, 3.3f};
	std::cout << s1 << std::endl;

	Box b1{};
	std::cout << b1 << std::endl;
}

TEST_CASE("intersect RaySphere","[intersect]"){
	//Ray
	glm::vec3 ray_origin {0.0f,0.0f,0.0f};
	//ray direction has to be normalized!
	//you can use:
	//v = glm::normalize(some_vector);
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


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
