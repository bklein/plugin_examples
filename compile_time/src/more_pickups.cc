#include "pickup_base.hpp"

class HealthPickup : public Pickup {
 public:
  std::string apply() override;
};

std::string HealthPickup::apply() {
  return "Player has full health";
}

REGISTER_PICKUP("health", HealthPickup)

class OilPickup : public Pickup {
  public:
   std::string apply() override;
};

std::string OilPickup::apply() {
  return "Player speed reduced by half";
}

REGISTER_PICKUP("oil", OilPickup)

class LightningPickup : public Pickup {
 public:
  std::string apply() override;
};

std::string LightningPickup::apply() {
  return "Player has lightning ability for 60 seconds";
}

REGISTER_PICKUP("lightning", LightningPickup)
