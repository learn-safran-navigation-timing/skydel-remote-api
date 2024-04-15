
#include "GetGlobalPowerOffsetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlobalPowerOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlobalPowerOffsetResult::CmdName = "GetGlobalPowerOffsetResult";
    const char* const GetGlobalPowerOffsetResult::Documentation = "Result of GetGlobalPowerOffset.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ---------------------------------------------------\n"
      "Offset double Offset in dB (negative value will attenuate signal)";
    const char* const GetGlobalPowerOffsetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGlobalPowerOffsetResult);


    GetGlobalPowerOffsetResult::GetGlobalPowerOffsetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGlobalPowerOffsetResult::GetGlobalPowerOffsetResult(double offset)
      : CommandResult(CmdName, TargetId)
    {

      setOffset(offset);
    }

    GetGlobalPowerOffsetResult::GetGlobalPowerOffsetResult(CommandBasePtr relatedCommand, double offset)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setOffset(offset);
    }


    GetGlobalPowerOffsetResultPtr GetGlobalPowerOffsetResult::create(double offset)
    {
      return std::make_shared<GetGlobalPowerOffsetResult>(offset);
    }

    GetGlobalPowerOffsetResultPtr GetGlobalPowerOffsetResult::create(CommandBasePtr relatedCommand, double offset)
    {
      return std::make_shared<GetGlobalPowerOffsetResult>(relatedCommand, offset);
    }

    GetGlobalPowerOffsetResultPtr GetGlobalPowerOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlobalPowerOffsetResult>(ptr);
    }

    bool GetGlobalPowerOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetGlobalPowerOffsetResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGlobalPowerOffsetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Offset"}; 
      return names; 
    }


    double GetGlobalPowerOffsetResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetGlobalPowerOffsetResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
