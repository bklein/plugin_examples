#include <iostream>

#include <compile_time/pickup_base.hpp>

int main() {
  const auto& factories = compile_time::PickupManager::getFactories();
  std::cout << "Pickups registered: " << factories.size() << std::endl;
  for (const auto& f : factories) {
    const auto& name = f.first;
    const auto& factory = f.second;
    const auto pickup = factory();
    if (pickup) {
      std::cout << " " << name << ": " << pickup->apply() << std::endl;
    } else {
      std::cerr << "failed to create pickup: " << name << std::endl;
    }
  }
  return 0;
}

