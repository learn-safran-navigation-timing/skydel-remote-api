#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// The type of propagation model
  ///
  
  enum class PropagationModelType : int { Rural, Suburban, Urban, Manual };
}

template<>
struct parse_json<Sdx::PropagationModelType>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::PropagationModelType parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return static_cast<Sdx::PropagationModelType>(value.GetInt());
  }
  static rapidjson::Value format(Sdx::PropagationModelType value, rapidjson::Value::AllocatorType&) { return rapidjson::Value(static_cast<int>(value)); }
};

