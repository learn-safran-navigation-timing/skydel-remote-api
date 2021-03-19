#pragma once

#include "parse_json.hpp"
#include <string>

namespace Sdx
{
    ///
    /// A pair of string
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------
    /// First  string First string in pair
    /// Second string Second string in pair
    ///

    struct StringPair
    {
      std::string First;
      std::string Second;
    };
}

template<>
struct parse_json<Sdx::StringPair>
{
    static bool is_valid(const rapidjson::Value& value)
    {
      
        return value.IsObject()
          && parse_json<std::string>::is_valid(value["First"])
          && parse_json<std::string>::is_valid(value["Second"])
        ;

    }

    static Sdx::StringPair parse(const rapidjson::Value& value)
    {
      if (!is_valid(value))
        throw std::runtime_error("Unexpected value");
      Sdx::StringPair sent;

      sent.First = parse_json<std::string>::parse(value["First"]);
      sent.Second = parse_json<std::string>::parse(value["Second"]);
      return sent;
    }

    static rapidjson::Value format(const Sdx::StringPair& value, rapidjson::Value::AllocatorType& alloc)
    {
      rapidjson::Value sent(rapidjson::kObjectType);

      sent.AddMember("First", parse_json<std::string>::format(value.First, alloc), alloc);
      sent.AddMember("Second", parse_json<std::string>::format(value.Second, alloc), alloc);
      return sent;
    }
};

