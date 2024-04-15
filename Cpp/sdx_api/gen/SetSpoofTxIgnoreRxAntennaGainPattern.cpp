
#include "SetSpoofTxIgnoreRxAntennaGainPattern.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxIgnoreRxAntennaGainPattern
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxIgnoreRxAntennaGainPattern::CmdName = "SetSpoofTxIgnoreRxAntennaGainPattern";
    const char* const SetSpoofTxIgnoreRxAntennaGainPattern::Documentation = "Set whether a spoofer should ignore the receiver's antenna gain pattern.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------\n"
      "Ignore bool   If true, the receiver's antenna gain pattern will be ignored.\n"
      "Id     string Transmitter unique identifier.";
    const char* const SetSpoofTxIgnoreRxAntennaGainPattern::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSpoofTxIgnoreRxAntennaGainPattern);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSpoofTxIgnoreRxAntennaGainPattern);


    SetSpoofTxIgnoreRxAntennaGainPattern::SetSpoofTxIgnoreRxAntennaGainPattern()
      : CommandBase(CmdName, TargetId)
    {}

    SetSpoofTxIgnoreRxAntennaGainPattern::SetSpoofTxIgnoreRxAntennaGainPattern(bool ignore, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setIgnore(ignore);
      setId(id);
    }

    SetSpoofTxIgnoreRxAntennaGainPatternPtr SetSpoofTxIgnoreRxAntennaGainPattern::create(bool ignore, const std::string& id)
    {
      return std::make_shared<SetSpoofTxIgnoreRxAntennaGainPattern>(ignore, id);
    }

    SetSpoofTxIgnoreRxAntennaGainPatternPtr SetSpoofTxIgnoreRxAntennaGainPattern::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxIgnoreRxAntennaGainPattern>(ptr);
    }

    bool SetSpoofTxIgnoreRxAntennaGainPattern::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSpoofTxIgnoreRxAntennaGainPattern::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSpoofTxIgnoreRxAntennaGainPattern::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ignore", "Id"}; 
      return names; 
    }


    int SetSpoofTxIgnoreRxAntennaGainPattern::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool SetSpoofTxIgnoreRxAntennaGainPattern::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void SetSpoofTxIgnoreRxAntennaGainPattern::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxIgnoreRxAntennaGainPattern::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxIgnoreRxAntennaGainPattern::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
