#pragma once

#include "parse_json.hpp"


namespace Sdx
{
    ///
    /// Elevation and Azimuth angular position.
    ///
    /// Name      Type   Description
    /// --------- ------ ----------------
    /// Elevation double Elevation angle.
    /// Azimuth   double Azimuth angle.
    ///

    struct ElevationAzimuth
    {
      double Elevation;
      double Azimuth;
    };
}

template<>
struct parse_json<Sdx::ElevationAzimuth>
{
    static bool is_valid(const rapidjson::Value& value)
    {
      
        return value.IsObject()
          && parse_json<double>::is_valid(value["Elevation"])
          && parse_json<double>::is_valid(value["Azimuth"])
        ;

    }

    static Sdx::ElevationAzimuth parse(const rapidjson::Value& value)
    {
      if (!is_valid(value))
        throw std::runtime_error("Unexpected value");
      Sdx::ElevationAzimuth sent;

      sent.Elevation = parse_json<double>::parse(value["Elevation"]);
      sent.Azimuth = parse_json<double>::parse(value["Azimuth"]);
      return sent;
    }

    static rapidjson::Value format(const Sdx::ElevationAzimuth& value, rapidjson::Value::AllocatorType& alloc)
    {
      rapidjson::Value sent(rapidjson::kObjectType);

      sent.AddMember("Elevation", parse_json<double>::format(value.Elevation, alloc), alloc);
      sent.AddMember("Azimuth", parse_json<double>::format(value.Azimuth, alloc), alloc);
      return sent;
    }
};

