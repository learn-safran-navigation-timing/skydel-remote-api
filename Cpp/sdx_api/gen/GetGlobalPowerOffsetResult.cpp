
#include "gen/GetGlobalPowerOffsetResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlobalPowerOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlobalPowerOffsetResult::CmdName = "GetGlobalPowerOffsetResult";
    const char* const GetGlobalPowerOffsetResult::Documentation = "Result of GetGlobalPowerOffset.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGlobalPowerOffsetResult);


    GetGlobalPowerOffsetResult::GetGlobalPowerOffsetResult()
      : CommandResult(CmdName)
    {}

    GetGlobalPowerOffsetResult::GetGlobalPowerOffsetResult(double offset)
      : CommandResult(CmdName)
    {

      setOffset(offset);
    }

    GetGlobalPowerOffsetResult::GetGlobalPowerOffsetResult(CommandBasePtr relatedCommand, double offset)
      : CommandResult(CmdName, relatedCommand)
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
