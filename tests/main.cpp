#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <shape.hpp>
#include <sphere.hpp>
#include <box.hpp>

TEST_CASE("Box","[function]"){
	Box b{};
	REQUIRE(0.0f == b.minimum().x);
	REQUIRE(0.0f == b.minimum().y);
	REQUIRE(0.0f == b.minimum().z);

	Box b1{{2.0f,3.3f,4.0f},{1.5f,5.6f,2.3f}};
	REQUIRE(2.0f == b1.minimum().x);
	REQUIRE(3.3f == b1.minimum().y);
	REQUIRE(4.0f == b1.minimum().z);

}

TEST_CASE("Boxmax","[function]"){

	Box b{};
	REQUIRE(0.0f == b.maximum().x);
	REQUIRE(0.0f == b.maximum().y);
	REQUIRE(0.0f == b.maximum().z);

	Box b1{{2.0f,3.3f,4.0f},{1.5f,5.6f,2.3f}};
	REQUIRE(1.5f == b1.maximum().x);
	REQUIRE(5.6f == b1.maximum().y);
	REQUIRE(2.3f == b1.maximum().z);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
