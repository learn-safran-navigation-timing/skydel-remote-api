#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// The SV data update mode.
  ///
  
  enum class SVDataUpdateMode : int { Extrapolation, Dynamic };
}

template<>
struct parse_json<Sdx::SVDataUpdateMode>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::SVDataUpdateMode parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return (Sdx::SVDataUpdateMode)value.GetInt();
  }
  static rapidjson::Value format(Sdx::SVDataUpdateMode value, rapidjson::Value::AllocatorType&) { return rapidjson::Value((int)value); }
};

