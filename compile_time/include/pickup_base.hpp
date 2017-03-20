#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>

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

#define REGISTER_PICKUP(key, klass) \
  template <> \
  std::string PickupTraits<klass>::name = key; \
  static const PickupRegistration<klass> global_##klass##_registration;

