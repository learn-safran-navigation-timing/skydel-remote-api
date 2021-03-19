#pragma once

#include "parse_json.hpp"


namespace Sdx
{
    ///
    /// Relative orbit frame.
    ///
    /// Name Type   Description
    /// ---- ------ -------------------------------------------------------------------
    /// R    double The radial component of the relative position vector, in meter
    /// I    double The in-track component of the relative position vector, in meter
    /// C    double The cross-track component of the relative position vector, in meter
    ///

    struct RIC
    {
      double R;
      double I;
      double C;
    };
}

template<>
struct parse_json<Sdx::RIC>
{
    static bool is_valid(const rapidjson::Value& value)
    {
      
        return value.IsObject()
          && parse_json<double>::is_valid(value["R"])
          && parse_json<double>::is_valid(value["I"])
          && parse_json<double>::is_valid(value["C"])
        ;

    }

    static Sdx::RIC parse(const rapidjson::Value& value)
    {
      if (!is_valid(value))
        throw std::runtime_error("Unexpected value");
      Sdx::RIC sent;

      sent.R = parse_json<double>::parse(value["R"]);
      sent.I = parse_json<double>::parse(value["I"]);
      sent.C = parse_json<double>::parse(value["C"]);
      return sent;
    }

    static rapidjson::Value format(const Sdx::RIC& value, rapidjson::Value::AllocatorType& alloc)
    {
      rapidjson::Value sent(rapidjson::kObjectType);

      sent.AddMember("R", parse_json<double>::format(value.R, alloc), alloc);
      sent.AddMember("I", parse_json<double>::format(value.I, alloc), alloc);
      sent.AddMember("C", parse_json<double>::format(value.C, alloc), alloc);
      return sent;
    }
};

