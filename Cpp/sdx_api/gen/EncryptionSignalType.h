#pragma once

#include "parse_json.hpp"

namespace Sdx
{
  ///
  /// Encryption signal type.
  ///
  
  enum class EncryptionSignalType : int { PY_CODE, M_CODE, PRS };
}

template<>
struct parse_json<Sdx::EncryptionSignalType>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt(); }
  static Sdx::EncryptionSignalType parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return static_cast<Sdx::EncryptionSignalType>(value.GetInt());
  }
  static rapidjson::Value format(Sdx::EncryptionSignalType value, rapidjson::Value::AllocatorType&) { return rapidjson::Value(static_cast<int>(value)); }
};

