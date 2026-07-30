
#include "GetNeQuick2MLF2UpdateRateResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNeQuick2MLF2UpdateRateResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNeQuick2MLF2UpdateRateResult::CmdName = "GetNeQuick2MLF2UpdateRateResult";
    const char* const GetNeQuick2MLF2UpdateRateResult::Documentation = "Result of GetNeQuick2MLF2UpdateRate.\n"
      "\n"
      "Name       Type Description\n"
      "---------- ---- ----------------------------\n"
      "UpdateRate int  The update rate, in seconds.";
    const char* const GetNeQuick2MLF2UpdateRateResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNeQuick2MLF2UpdateRateResult);


    GetNeQuick2MLF2UpdateRateResult::GetNeQuick2MLF2UpdateRateResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetNeQuick2MLF2UpdateRateResult::GetNeQuick2MLF2UpdateRateResult(int updateRate)
      : CommandResult(CmdName, TargetId)
    {

      setUpdateRate(updateRate);
    }

    GetNeQuick2MLF2UpdateRateResult::GetNeQuick2MLF2UpdateRateResult(CommandBasePtr relatedCommand, int updateRate)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setUpdateRate(updateRate);
    }


    GetNeQuick2MLF2UpdateRateResultPtr GetNeQuick2MLF2UpdateRateResult::create(int updateRate)
    {
      return std::make_shared<GetNeQuick2MLF2UpdateRateResult>(updateRate);
    }

    GetNeQuick2MLF2UpdateRateResultPtr GetNeQuick2MLF2UpdateRateResult::create(CommandBasePtr relatedCommand, int updateRate)
    {
      return std::make_shared<GetNeQuick2MLF2UpdateRateResult>(relatedCommand, updateRate);
    }

    GetNeQuick2MLF2UpdateRateResultPtr GetNeQuick2MLF2UpdateRateResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNeQuick2MLF2UpdateRateResult>(ptr);
    }

    bool GetNeQuick2MLF2UpdateRateResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["UpdateRate"])
        ;

    }

    std::string GetNeQuick2MLF2UpdateRateResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNeQuick2MLF2UpdateRateResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"UpdateRate"}; 
      return names; 
    }


    int GetNeQuick2MLF2UpdateRateResult::updateRate() const
    {
      return parse_json<int>::parse(m_values["UpdateRate"]);
    }

    void GetNeQuick2MLF2UpdateRateResult::setUpdateRate(int updateRate)
    {
      setValue("UpdateRate", parse_json<int>::format(updateRate, m_values.GetAllocator()));
    }


  }
}
