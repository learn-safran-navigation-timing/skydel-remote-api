
#include "GetDynamicRangeOffsetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDynamicRangeOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDynamicRangeOffsetResult::CmdName = "GetDynamicRangeOffsetResult";
    const char* const GetDynamicRangeOffsetResult::Documentation = "Result of GetDynamicRangeOffset.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------------------------------------\n"
      "Offset double Dynamic Range Offset (dB). Value must be between -10 and +45 dB.";
    const char* const GetDynamicRangeOffsetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDynamicRangeOffsetResult);


    GetDynamicRangeOffsetResult::GetDynamicRangeOffsetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetDynamicRangeOffsetResult::GetDynamicRangeOffsetResult(double offset)
      : CommandResult(CmdName, TargetId)
    {

      setOffset(offset);
    }

    GetDynamicRangeOffsetResult::GetDynamicRangeOffsetResult(CommandBasePtr relatedCommand, double offset)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setOffset(offset);
    }


    GetDynamicRangeOffsetResultPtr GetDynamicRangeOffsetResult::create(double offset)
    {
      return std::make_shared<GetDynamicRangeOffsetResult>(offset);
    }

    GetDynamicRangeOffsetResultPtr GetDynamicRangeOffsetResult::create(CommandBasePtr relatedCommand, double offset)
    {
      return std::make_shared<GetDynamicRangeOffsetResult>(relatedCommand, offset);
    }

    GetDynamicRangeOffsetResultPtr GetDynamicRangeOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDynamicRangeOffsetResult>(ptr);
    }

    bool GetDynamicRangeOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetDynamicRangeOffsetResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetDynamicRangeOffsetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Offset"}; 
      return names; 
    }


    double GetDynamicRangeOffsetResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetDynamicRangeOffsetResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
