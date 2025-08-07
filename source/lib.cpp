#include <array>
#include <cstddef>
#include <cstdint>

#include "lib.hpp"

#include <fmt/base.h>
#include <fmt/format.h>
#include <uuid/uuid.h>

namespace
{

constexpr size_t UUID_LEN {sizeof(uuid_t)};
std::array<uint8_t, UUID_LEN> make_uuid()
{
  std::array<uint8_t, UUID_LEN> uuid {};
  uuid_generate(uuid.data());
  return uuid;
}

}  // namespace

library::library()
    : name {fmt::format("{}", "vcpkg-example")}
{
  auto result = make_uuid();

#define USE_UUID_PARSE
#ifndef USE_UUID_PARSE
  for (uint8_t byte : result) {
    fmt::print("{:02x}", byte);
  }
  fmt::print("\n");
  // 21950b2713b04824af5938b0037c2731
#else
  std::array<char, (2 * UUID_LEN) + sizeof("----")> uuid_str {};  // 37
  uuid_unparse(result.data(), uuid_str.data());
  fmt::print("{}\n", uuid_str.data());
  // cbb96c92-f9b0-4ab1-ae95-0799dae04bee
#endif
}
