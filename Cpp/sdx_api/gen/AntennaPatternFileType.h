#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// CSV file format of antenna pattern
  ///
  
  enum class AntennaPatternFileType : int { NotAngle, Degrees, Radians, NoneFile };
}

template<>
struct parse_json<Sdx::AntennaPatternFileType>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::AntennaPatternFileType parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return static_cast<Sdx::AntennaPatternFileType>(value.GetInt());
  }
  static rapidjson::Value format(Sdx::AntennaPatternFileType value, rapidjson::Value::AllocatorType&) { return rapidjson::Value(static_cast<int>(value)); }
};

