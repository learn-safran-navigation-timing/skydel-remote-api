#pragma once

#include "parse_json.hpp"


namespace Sdx
{
    ///
    /// Information on the signal power.
    ///
    /// Name                Type   Description
    /// ------------------- ------ -----------------------------------------------------------------------------------------------------------
    /// AntennaOffset       double The receiver antenna power offset (dB). It depends on antenna pattern and relative orientation with signal.
    /// StrengthModelOffset double The power offset coming from the Signal Strength Model (dB).
    /// SignalOffset        double The signal power offset (dB). See SetSignalPowerOffset.
    /// ManualOffset        double The manual power offset (dB). See SetManualPowerOffsetForSV.
    /// Total               double The sum of all the other fields, including nominal power and the global power offset (dBm).
    ///

    struct SignalPower
    {
      double AntennaOffset;
      double StrengthModelOffset;
      double SignalOffset;
      double ManualOffset;
      double Total;
    };
}

template<>
struct parse_json<Sdx::SignalPower>
{
    static bool is_valid(const rapidjson::Value& value)
    {
      
        return value.IsObject()
          && parse_json<double>::is_valid(value["AntennaOffset"])
          && parse_json<double>::is_valid(value["StrengthModelOffset"])
          && parse_json<double>::is_valid(value["SignalOffset"])
          && parse_json<double>::is_valid(value["ManualOffset"])
          && parse_json<double>::is_valid(value["Total"])
        ;

    }

    static Sdx::SignalPower parse(const rapidjson::Value& value)
    {
      if (!is_valid(value))
        throw std::runtime_error("Unexpected value");
      Sdx::SignalPower sent;

      sent.AntennaOffset = parse_json<double>::parse(value["AntennaOffset"]);
      sent.StrengthModelOffset = parse_json<double>::parse(value["StrengthModelOffset"]);
      sent.SignalOffset = parse_json<double>::parse(value["SignalOffset"]);
      sent.ManualOffset = parse_json<double>::parse(value["ManualOffset"]);
      sent.Total = parse_json<double>::parse(value["Total"]);
      return sent;
    }

    static rapidjson::Value format(const Sdx::SignalPower& value, rapidjson::Value::AllocatorType& alloc)
    {
      rapidjson::Value sent(rapidjson::kObjectType);

      sent.AddMember("AntennaOffset", parse_json<double>::format(value.AntennaOffset, alloc), alloc);
      sent.AddMember("StrengthModelOffset", parse_json<double>::format(value.StrengthModelOffset, alloc), alloc);
      sent.AddMember("SignalOffset", parse_json<double>::format(value.SignalOffset, alloc), alloc);
      sent.AddMember("ManualOffset", parse_json<double>::format(value.ManualOffset, alloc), alloc);
      sent.AddMember("Total", parse_json<double>::format(value.Total, alloc), alloc);
      return sent;
    }
};

