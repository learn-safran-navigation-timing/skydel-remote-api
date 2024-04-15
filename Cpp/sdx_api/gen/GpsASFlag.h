#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// The GPS AS flag value.
  ///
  
  enum class GpsASFlag : int { On, Off, Auto };
}

template<>
struct parse_json<Sdx::GpsASFlag>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::GpsASFlag parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return static_cast<Sdx::GpsASFlag>(value.GetInt());
  }
  static rapidjson::Value format(Sdx::GpsASFlag value, rapidjson::Value::AllocatorType&) { return rapidjson::Value(static_cast<int>(value)); }
};

