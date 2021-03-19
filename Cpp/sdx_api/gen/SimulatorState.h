#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// The simulator state.
  ///
  
  enum class SimulatorState : int { StateNone, StateIdle, StateStarted, StateError };
}

template<>
struct parse_json<Sdx::SimulatorState>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::SimulatorState parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return (Sdx::SimulatorState)value.GetInt();
  }
  static rapidjson::Value format(Sdx::SimulatorState value, rapidjson::Value::AllocatorType&) { return rapidjson::Value((int)value); }
};

