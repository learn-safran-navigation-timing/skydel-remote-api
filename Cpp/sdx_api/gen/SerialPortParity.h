#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// The Parity scheme used by a serial port.
  ///
  
  enum class SerialPortParity : int { NoParity, Even, Odd, Space, Mark };
}

template<>
struct parse_json<Sdx::SerialPortParity>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::SerialPortParity parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return (Sdx::SerialPortParity)value.GetInt();
  }
  static rapidjson::Value format(Sdx::SerialPortParity value, rapidjson::Value::AllocatorType&) { return rapidjson::Value((int)value); }
};

