#include "compile_time/pickup_base.hpp"
#include "compile_time/registration_macro.hpp"

#include <iostream>

namespace compile_time {

Pickup::Pickup() {
}

Pickup::~Pickup() {
}

static
std::map<std::string, PickupFactory>& get_factories() {
  static std::map<std::string, PickupFactory> factories;
  return factories;
}

bool registerFactory(const std::string& name, const PickupFactory& factory) {
  if (!get_factories().insert(std::make_pair(name, factory)).second) {
    std::cerr << "factory already registered: " << name << std::endl;
    return false;
  }
  return true;
}

const std::map<std::string,PickupFactory>& getFactories() {
  return get_factories();
}

}  // namespace compile_time
