#pragma once
#include <compile_time/pickup_base.hpp>

namespace compile_time {

template <class T>
struct PickupTraits {
  static std::string name;
};

template <class T>
struct PickupRegistration {
  template <class... Args>
  PickupRegistration(Args&&... args) {
    PickupManager::registerFactory(
        PickupTraits<T>::name,
        [args...] (void) {
          return std::unique_ptr<Pickup>(new T(args...));
        });
  }
};

}  // namespace compile_time

#define REGISTER_PICKUP(key, klass) \
  template <> \
  std::string compile_time::PickupTraits<klass>::name = key; \
  static const compile_time::PickupRegistration<klass> global_##klass##_registration;

