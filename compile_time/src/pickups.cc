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

class OilPickup : public compile_time::Pickup {
  public:
   std::string apply() override;
};

std::string OilPickup::apply() {
  return "Player speed reduced by half";
}

REGISTER_PICKUP("oil", OilPickup)

class LightningPickup : public compile_time::Pickup {
 public:
  std::string apply() override;
};

std::string LightningPickup::apply() {
  return "Player has lightning ability for 60 seconds";
}

REGISTER_PICKUP("lightning", LightningPickup)
