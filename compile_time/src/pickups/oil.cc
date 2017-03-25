#include "compile_time/pickup_base.hpp"
#include "compile_time/registration_macro.hpp"

class OilPickup : public compile_time::Pickup {
  public:
   std::string apply() override;
};

std::string OilPickup::apply() {
  return "Player speed reduced by half";
}

REGISTER_PICKUP("oil", OilPickup)
