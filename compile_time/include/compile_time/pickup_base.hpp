#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>

namespace compile_time {

class Pickup {
 public:
  Pickup();
  virtual ~Pickup();

  virtual std::string apply() = 0; // Dummy action
};

class PickupManager {
 public:
  using Factory = std::function<std::unique_ptr<Pickup>()>;

  PickupManager() = delete;
  static const std::map<std::string,Factory>& getFactories();
  static bool registerFactory(const std::string& name, const Factory& factory);
};

}  // namespace compile_time
