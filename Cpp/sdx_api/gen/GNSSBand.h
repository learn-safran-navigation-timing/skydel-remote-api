#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// The different GNSS bands
  ///
  
  enum class GNSSBand : int { L1, L2, L5, E6 };
}

template<>
struct parse_json<Sdx::GNSSBand>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::GNSSBand parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return (Sdx::GNSSBand)value.GetInt();
  }
  static rapidjson::Value format(Sdx::GNSSBand value, rapidjson::Value::AllocatorType&) { return rapidjson::Value((int)value); }
};

