#include "lib.hpp"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>  // for to_string
#include <fmt/format.h>

namespace
{

boost::uuids::uuid make_uuid()
{
  static boost::uuids::random_generator gen {};
  return gen();
}

}  // namespace

library::library()
    : name {fmt::format("{}", "vcpkg-example")}
{
  const auto uuid = make_uuid();
  fmt::print("{}\n", boost::uuids::to_string(uuid));
}
