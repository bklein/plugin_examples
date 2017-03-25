#include "compile_time/pickup_base.hpp"
#include "compile_time/registration_macro.hpp"

class LightningPickup : public compile_time::Pickup {
 public:
  std::string apply() override;
};

std::string LightningPickup::apply() {
  return "Player has lightning ability for 60 seconds";
}

REGISTER_PICKUP("lightning", LightningPickup)
