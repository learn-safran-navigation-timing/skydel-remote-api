#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// Possible values for antenna patterns
  ///
  
  enum class AntennaPatternType : int { Default, AntennaNone, Custom };
}

template<>
struct parse_json<Sdx::AntennaPatternType>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::AntennaPatternType parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return (Sdx::AntennaPatternType)value.GetInt();
  }
  static rapidjson::Value format(Sdx::AntennaPatternType value, rapidjson::Value::AllocatorType&) { return rapidjson::Value((int)value); }
};

