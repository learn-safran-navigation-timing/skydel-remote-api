#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// HIL extrapolation state.
  ///
  
  enum class HilExtrapolationState : int { Deterministic, NonDeterministic, Snap };
}

template<>
struct parse_json<Sdx::HilExtrapolationState>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::HilExtrapolationState parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return static_cast<Sdx::HilExtrapolationState>(value.GetInt());
  }
  static rapidjson::Value format(Sdx::HilExtrapolationState value, rapidjson::Value::AllocatorType&) { return rapidjson::Value(static_cast<int>(value)); }
};

