#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// The different kinds of filters for configuration.
  ///
  
  enum class ConfigFilter : int { Radios, OutputAndRadios, VehicleMotion, VehicleAntenna, Interference, PlugIn };
}

template<>
struct parse_json<Sdx::ConfigFilter>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::ConfigFilter parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return (Sdx::ConfigFilter)value.GetInt();
  }
  static rapidjson::Value format(Sdx::ConfigFilter value, rapidjson::Value::AllocatorType&) { return rapidjson::Value((int)value); }
};

