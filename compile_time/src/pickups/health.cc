#include "compile_time/pickup_base.hpp"
#include "compile_time/registration_macro.hpp"

class HealthPickup : public compile_time::Pickup {
 public:
  std::string apply() override;
};

std::string HealthPickup::apply() {
  return "Player has full health";
}

REGISTER_PICKUP("health", HealthPickup)

