#pragma once

#include <mosure/interfaces/icontainer.hpp>


namespace mosure::inversify {

template <typename... SymbolTypes>
class Container;

template <typename... SymbolTypes>
struct Context {
    inversify::IContainer<Container, SymbolTypes...>& container;
};

}
