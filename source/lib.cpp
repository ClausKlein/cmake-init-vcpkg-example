#include "lib.hpp"

#include <array>
#include <string>

#include <fmt/core.h>
#include <uuid/uuid.h>


std::array<uint8_t, 16> make_uuid() {
  std::array<uint8_t, 16> uuid;
  uuid_generate(uuid.data());
  return uuid;
}

library::library()
    : name {fmt::format("{}", "vcpkg-example")}
{
    auto result = make_uuid();
    fmt::print("{}\n", std::string((const char*)result.data(), result.size()));
}
