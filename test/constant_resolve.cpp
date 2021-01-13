#include <catch2/catch.hpp>

#include <mosure/inversify.hpp>

#include "mock/types.hpp"


namespace inversify = mosure::inversify;

SCENARIO("container resolves constant values", "[resolve]") {

    GIVEN("A container with constant binding") {
        inversify::Container container {};

        container.bind<int>(types::foo)->toConstantValue(10);

        WHEN("the dependency is resolved") {
            auto result = container.get<int>(types::foo);

            THEN("the correct value is returned") {
                REQUIRE(result == 10);
            }
        }

        WHEN("the binding is redefined") {
            container.bind<int>(types::foo)->toConstantValue(20);

            WHEN("the dependency is resolved") {
                auto result = container.get<int>(types::foo);

                THEN("the updated value is returned") {
                    REQUIRE(result == 20);
                }
            }
        }
    }
}