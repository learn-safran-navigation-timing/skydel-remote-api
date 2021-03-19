#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// A log record level.
  ///
  
  enum class LogLevel : int { Message, Warning, Error };
}

template<>
struct parse_json<Sdx::LogLevel>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::LogLevel parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return (Sdx::LogLevel)value.GetInt();
  }
  static rapidjson::Value format(Sdx::LogLevel value, rapidjson::Value::AllocatorType&) { return rapidjson::Value((int)value); }
};

