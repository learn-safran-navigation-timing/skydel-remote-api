#pragma once

#include "parse_json.hpp"
#include <string>

namespace Sdx
{
    ///
    /// SBAS service message region.
    ///
    /// Name            Type   Description
    /// --------------- ------ -------------------------------------------------
    /// FirstLatitude   int    First latitude (deg).
    /// FirstLongitude  int    First longitude (deg).
    /// SecondLatitude  int    Second latitude (deg).
    /// SecondLongitude int    Second longitude (deg).
    /// Shape           string Region shape, accepts "Triangle" and "Rectangle".
    ///

    struct SbasServiceMessageRegion
    {
      int FirstLatitude;
      int FirstLongitude;
      int SecondLatitude;
      int SecondLongitude;
      std::string Shape;
    };
}

template<>
struct parse_json<Sdx::SbasServiceMessageRegion>
{
    static bool is_valid(const rapidjson::Value& value)
    {
      
        return value.IsObject()
          && parse_json<int>::is_valid(value["FirstLatitude"])
          && parse_json<int>::is_valid(value["FirstLongitude"])
          && parse_json<int>::is_valid(value["SecondLatitude"])
          && parse_json<int>::is_valid(value["SecondLongitude"])
          && parse_json<std::string>::is_valid(value["Shape"])
        ;

    }

    static Sdx::SbasServiceMessageRegion parse(const rapidjson::Value& value)
    {
      if (!is_valid(value))
        throw std::runtime_error("Unexpected value");
      Sdx::SbasServiceMessageRegion sent;

      sent.FirstLatitude = parse_json<int>::parse(value["FirstLatitude"]);
      sent.FirstLongitude = parse_json<int>::parse(value["FirstLongitude"]);
      sent.SecondLatitude = parse_json<int>::parse(value["SecondLatitude"]);
      sent.SecondLongitude = parse_json<int>::parse(value["SecondLongitude"]);
      sent.Shape = parse_json<std::string>::parse(value["Shape"]);
      return sent;
    }

    static rapidjson::Value format(const Sdx::SbasServiceMessageRegion& value, rapidjson::Value::AllocatorType& alloc)
    {
      rapidjson::Value sent(rapidjson::kObjectType);

      sent.AddMember("FirstLatitude", parse_json<int>::format(value.FirstLatitude, alloc), alloc);
      sent.AddMember("FirstLongitude", parse_json<int>::format(value.FirstLongitude, alloc), alloc);
      sent.AddMember("SecondLatitude", parse_json<int>::format(value.SecondLatitude, alloc), alloc);
      sent.AddMember("SecondLongitude", parse_json<int>::format(value.SecondLongitude, alloc), alloc);
      sent.AddMember("Shape", parse_json<std::string>::format(value.Shape, alloc), alloc);
      return sent;
    }
};

