#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// The flow control used by a serial port.
  ///
  
  enum class SerialPortFlowControl : int { NoFlowControl, Hardware, Software };
}

template<>
struct parse_json<Sdx::SerialPortFlowControl>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::SerialPortFlowControl parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return static_cast<Sdx::SerialPortFlowControl>(value.GetInt());
  }
  static rapidjson::Value format(Sdx::SerialPortFlowControl value, rapidjson::Value::AllocatorType&) { return rapidjson::Value(static_cast<int>(value)); }
};

