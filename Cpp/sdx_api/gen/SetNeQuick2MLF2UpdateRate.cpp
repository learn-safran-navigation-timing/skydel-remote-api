
#include "SetNeQuick2MLF2UpdateRate.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNeQuick2MLF2UpdateRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNeQuick2MLF2UpdateRate::CmdName = "SetNeQuick2MLF2UpdateRate";
    const char* const SetNeQuick2MLF2UpdateRate::Documentation = "Set the update rate of the NeQuick2-MLF2 model.\n"
      "\n"
      "Name       Type Description\n"
      "---------- ---- ----------------------------\n"
      "UpdateRate int  The update rate, in seconds.";
    const char* const SetNeQuick2MLF2UpdateRate::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNeQuick2MLF2UpdateRate);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNeQuick2MLF2UpdateRate);


    SetNeQuick2MLF2UpdateRate::SetNeQuick2MLF2UpdateRate()
      : CommandBase(CmdName, TargetId)
    {}

    SetNeQuick2MLF2UpdateRate::SetNeQuick2MLF2UpdateRate(int updateRate)
      : CommandBase(CmdName, TargetId)
    {

      setUpdateRate(updateRate);
    }

    SetNeQuick2MLF2UpdateRatePtr SetNeQuick2MLF2UpdateRate::create(int updateRate)
    {
      return std::make_shared<SetNeQuick2MLF2UpdateRate>(updateRate);
    }

    SetNeQuick2MLF2UpdateRatePtr SetNeQuick2MLF2UpdateRate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNeQuick2MLF2UpdateRate>(ptr);
    }

    bool SetNeQuick2MLF2UpdateRate::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["UpdateRate"])
        ;

    }

    std::string SetNeQuick2MLF2UpdateRate::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNeQuick2MLF2UpdateRate::fieldNames() const 
    { 
      static const std::vector<std::string> names {"UpdateRate"}; 
      return names; 
    }


    int SetNeQuick2MLF2UpdateRate::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetNeQuick2MLF2UpdateRate::updateRate() const
    {
      return parse_json<int>::parse(m_values["UpdateRate"]);
    }

    void SetNeQuick2MLF2UpdateRate::setUpdateRate(int updateRate)
    {
      setValue("UpdateRate", parse_json<int>::format(updateRate, m_values.GetAllocator()));
    }


  }
}
