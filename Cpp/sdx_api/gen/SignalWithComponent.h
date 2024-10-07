#pragma once

#include "parse_json.hpp"
#include <optional>
#include <string>

namespace Sdx
{
    ///
    /// A signal with an optional component.
    ///
    /// Name      Type            Description
    /// --------- --------------- -----------------------------------------------------------------------------------
    /// Signal    string          The signal key.
    /// Component optional string Some signals are divided into multiple components, such as E1b ("b") and E1c ("c").
    ///

    struct SignalWithComponent
    {
      std::string Signal;
      std::optional<std::string> Component;
    };
}

template<>
struct parse_json<Sdx::SignalWithComponent>
{
    static bool is_valid(const rapidjson::Value& value)
    {
      
        return value.IsObject()
          && parse_json<std::string>::is_valid(value["Signal"])
          && parse_json<std::optional<std::string>>::is_valid(value["Component"])
        ;

    }

    static Sdx::SignalWithComponent parse(const rapidjson::Value& value)
    {
      if (!is_valid(value))
        throw std::runtime_error("Unexpected value");
      Sdx::SignalWithComponent sent;

      sent.Signal = parse_json<std::string>::parse(value["Signal"]);
      sent.Component = parse_json<std::optional<std::string>>::parse(value["Component"]);
      return sent;
    }

    static rapidjson::Value format(const Sdx::SignalWithComponent& value, rapidjson::Value::AllocatorType& alloc)
    {
      rapidjson::Value sent(rapidjson::kObjectType);

      sent.AddMember("Signal", parse_json<std::string>::format(value.Signal, alloc), alloc);
      sent.AddMember("Component", parse_json<std::optional<std::string>>::format(value.Component, alloc), alloc);
      return sent;
    }
};

