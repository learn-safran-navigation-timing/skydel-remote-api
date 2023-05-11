
#include "gen/SetIntTxIgnoreRxAntennaGainPattern.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxIgnoreRxAntennaGainPattern
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxIgnoreRxAntennaGainPattern::CmdName = "SetIntTxIgnoreRxAntennaGainPattern";
    const char* const SetIntTxIgnoreRxAntennaGainPattern::Documentation = "Set whether a dynamic transmitter should ignore the receiver's antenna gain pattern.";

    REGISTER_COMMAND_FACTORY(SetIntTxIgnoreRxAntennaGainPattern);


    SetIntTxIgnoreRxAntennaGainPattern::SetIntTxIgnoreRxAntennaGainPattern()
      : CommandBase(CmdName)
    {}

    SetIntTxIgnoreRxAntennaGainPattern::SetIntTxIgnoreRxAntennaGainPattern(bool ignore, const std::string& id)
      : CommandBase(CmdName)
    {

      setIgnore(ignore);
      setId(id);
    }

    SetIntTxIgnoreRxAntennaGainPatternPtr SetIntTxIgnoreRxAntennaGainPattern::create(bool ignore, const std::string& id)
    {
      return std::make_shared<SetIntTxIgnoreRxAntennaGainPattern>(ignore, id);
    }

    SetIntTxIgnoreRxAntennaGainPatternPtr SetIntTxIgnoreRxAntennaGainPattern::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxIgnoreRxAntennaGainPattern>(ptr);
    }

    bool SetIntTxIgnoreRxAntennaGainPattern::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxIgnoreRxAntennaGainPattern::documentation() const { return Documentation; }


    int SetIntTxIgnoreRxAntennaGainPattern::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxIgnoreRxAntennaGainPattern::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void SetIntTxIgnoreRxAntennaGainPattern::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxIgnoreRxAntennaGainPattern::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxIgnoreRxAntennaGainPattern::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
