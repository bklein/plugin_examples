#include "pickup_base.hpp"
#include <iostream>

Pickup::Pickup() {
}

Pickup::~Pickup() {
}

static
std::map<std::string, PickupManager::Factory>& get_factories() {
  static std::map<std::string, PickupManager::Factory> factories;
  return factories;
}

bool PickupManager::registerFactory(const std::string& name, const Factory& factory) {
  if (!get_factories().insert(std::make_pair(name, factory)).second) {
    std::cerr << "factory already registered: " << name << std::endl;
    return false;
  }
  return true;
}

const std::map<std::string,PickupManager::Factory>& PickupManager::getFactories() {
  return get_factories();
}
