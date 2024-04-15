
#include "SetSpoofTxIgnoreRxAntennaPhasePattern.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxIgnoreRxAntennaPhasePattern
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxIgnoreRxAntennaPhasePattern::CmdName = "SetSpoofTxIgnoreRxAntennaPhasePattern";
    const char* const SetSpoofTxIgnoreRxAntennaPhasePattern::Documentation = "Set whether a spoofer should ignore the receiver's antenna phase pattern.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------\n"
      "Ignore bool   If true, the receiver's antenna phase pattern will be ignored.\n"
      "Id     string Transmitter unique identifier.";
    const char* const SetSpoofTxIgnoreRxAntennaPhasePattern::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSpoofTxIgnoreRxAntennaPhasePattern);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSpoofTxIgnoreRxAntennaPhasePattern);


    SetSpoofTxIgnoreRxAntennaPhasePattern::SetSpoofTxIgnoreRxAntennaPhasePattern()
      : CommandBase(CmdName, TargetId)
    {}

    SetSpoofTxIgnoreRxAntennaPhasePattern::SetSpoofTxIgnoreRxAntennaPhasePattern(bool ignore, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setIgnore(ignore);
      setId(id);
    }

    SetSpoofTxIgnoreRxAntennaPhasePatternPtr SetSpoofTxIgnoreRxAntennaPhasePattern::create(bool ignore, const std::string& id)
    {
      return std::make_shared<SetSpoofTxIgnoreRxAntennaPhasePattern>(ignore, id);
    }

    SetSpoofTxIgnoreRxAntennaPhasePatternPtr SetSpoofTxIgnoreRxAntennaPhasePattern::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxIgnoreRxAntennaPhasePattern>(ptr);
    }

    bool SetSpoofTxIgnoreRxAntennaPhasePattern::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSpoofTxIgnoreRxAntennaPhasePattern::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSpoofTxIgnoreRxAntennaPhasePattern::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ignore", "Id"}; 
      return names; 
    }


    int SetSpoofTxIgnoreRxAntennaPhasePattern::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool SetSpoofTxIgnoreRxAntennaPhasePattern::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void SetSpoofTxIgnoreRxAntennaPhasePattern::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxIgnoreRxAntennaPhasePattern::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxIgnoreRxAntennaPhasePattern::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
