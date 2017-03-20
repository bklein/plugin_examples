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

using PickupFactory = std::function<std::unique_ptr<Pickup>()>;

const std::map<std::string,PickupFactory>& getFactories();

}  // namespace compile_time
