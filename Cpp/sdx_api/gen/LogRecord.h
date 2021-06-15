#pragma once

#include "parse_json.hpp"
#include "date_time.h"
#include "gen/LogLevel.h"
#include "gen/SimulatorState.h"
#include "gen/SimulatorSubState.h"
#include <string>

namespace Sdx
{
    ///
    /// Represents a record inside the status log.
    ///
    /// Name      Type              Description
    /// --------- ----------------- --------------------------------------------------
    /// TimeStamp datetime          The record time, in the host os time.
    /// State     SimulatorState    The simulator state at the time of the record.
    /// SubState  SimulatorSubState The simulator sub-state at the time of the record.
    /// Level     LogLevel          The record level.
    /// Message   string            The record message.
    ///

    struct LogRecord
    {
      Sdx::DateTime TimeStamp;
      Sdx::SimulatorState State;
      Sdx::SimulatorSubState SubState;
      Sdx::LogLevel Level;
      std::string Message;
    };
}

template<>
struct parse_json<Sdx::LogRecord>
{
    static bool is_valid(const rapidjson::Value& value)
    {
      
        return value.IsObject()
          && parse_json<Sdx::DateTime>::is_valid(value["TimeStamp"])
          && parse_json<Sdx::SimulatorState>::is_valid(value["State"])
          && parse_json<Sdx::SimulatorSubState>::is_valid(value["SubState"])
          && parse_json<Sdx::LogLevel>::is_valid(value["Level"])
          && parse_json<std::string>::is_valid(value["Message"])
        ;

    }

    static Sdx::LogRecord parse(const rapidjson::Value& value)
    {
      if (!is_valid(value))
        throw std::runtime_error("Unexpected value");
      Sdx::LogRecord sent;

      sent.TimeStamp = parse_json<Sdx::DateTime>::parse(value["TimeStamp"]);
      sent.State = parse_json<Sdx::SimulatorState>::parse(value["State"]);
      sent.SubState = parse_json<Sdx::SimulatorSubState>::parse(value["SubState"]);
      sent.Level = parse_json<Sdx::LogLevel>::parse(value["Level"]);
      sent.Message = parse_json<std::string>::parse(value["Message"]);
      return sent;
    }

    static rapidjson::Value format(const Sdx::LogRecord& value, rapidjson::Value::AllocatorType& alloc)
    {
      rapidjson::Value sent(rapidjson::kObjectType);

      sent.AddMember("TimeStamp", parse_json<Sdx::DateTime>::format(value.TimeStamp, alloc), alloc);
      sent.AddMember("State", parse_json<Sdx::SimulatorState>::format(value.State, alloc), alloc);
      sent.AddMember("SubState", parse_json<Sdx::SimulatorSubState>::format(value.SubState, alloc), alloc);
      sent.AddMember("Level", parse_json<Sdx::LogLevel>::format(value.Level, alloc), alloc);
      sent.AddMember("Message", parse_json<std::string>::format(value.Message, alloc), alloc);
      return sent;
    }
};

