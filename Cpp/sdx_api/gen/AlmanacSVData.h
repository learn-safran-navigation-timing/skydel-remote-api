#pragma once

#include "parse_json.hpp"
#include <map>
#include <string>

namespace Sdx
{
    ///
    /// Almanac data for a single SV.
    ///
    /// Name           Type               Description
    /// -------------- ------------------ -------------------------------------------------------------------------------
    /// SvId           int                Satellite's SV ID.
    /// ParametersDict dict string:double A dictionary of parameters pairs.
    ///                                   Accepted keys are: "Time of ephemeris", "Week Number", "Transmission Time",
    ///                                                      "ClockBias", "ClockDrift", "ClockDriftRate", "DeltaN", "M0",
    ///                                                      "Eccentricity", "SqrtA", "BigOmega", "I0", "LittleOmega",
    ///                                                      "BigOmegaDot" and "Idot"
    ///

    struct AlmanacSVData
    {
      int SvId;
      std::map<std::string, double> ParametersDict;
    };
}

template<>
struct parse_json<Sdx::AlmanacSVData>
{
    static bool is_valid(const rapidjson::Value& value)
    {
      
        return value.IsObject()
          && parse_json<int>::is_valid(value["SvId"])
          && parse_json<std::map<std::string, double>>::is_valid(value["ParametersDict"])
        ;

    }

    static Sdx::AlmanacSVData parse(const rapidjson::Value& value)
    {
      if (!is_valid(value))
        throw std::runtime_error("Unexpected value");
      Sdx::AlmanacSVData sent;

      sent.SvId = parse_json<int>::parse(value["SvId"]);
      sent.ParametersDict = parse_json<std::map<std::string, double>>::parse(value["ParametersDict"]);
      return sent;
    }

    static rapidjson::Value format(const Sdx::AlmanacSVData& value, rapidjson::Value::AllocatorType& alloc)
    {
      rapidjson::Value sent(rapidjson::kObjectType);

      sent.AddMember("SvId", parse_json<int>::format(value.SvId, alloc), alloc);
      sent.AddMember("ParametersDict", parse_json<std::map<std::string, double>>::format(value.ParametersDict, alloc), alloc);
      return sent;
    }
};

