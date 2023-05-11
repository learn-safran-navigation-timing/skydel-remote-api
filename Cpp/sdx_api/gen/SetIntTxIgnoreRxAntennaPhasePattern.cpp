
#include "gen/SetIntTxIgnoreRxAntennaPhasePattern.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxIgnoreRxAntennaPhasePattern
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxIgnoreRxAntennaPhasePattern::CmdName = "SetIntTxIgnoreRxAntennaPhasePattern";
    const char* const SetIntTxIgnoreRxAntennaPhasePattern::Documentation = "Set whether a dynamic transmitter should ignore the receiver's antenna phase pattern.";

    REGISTER_COMMAND_FACTORY(SetIntTxIgnoreRxAntennaPhasePattern);


    SetIntTxIgnoreRxAntennaPhasePattern::SetIntTxIgnoreRxAntennaPhasePattern()
      : CommandBase(CmdName)
    {}

    SetIntTxIgnoreRxAntennaPhasePattern::SetIntTxIgnoreRxAntennaPhasePattern(bool ignore, const std::string& id)
      : CommandBase(CmdName)
    {

      setIgnore(ignore);
      setId(id);
    }

    SetIntTxIgnoreRxAntennaPhasePatternPtr SetIntTxIgnoreRxAntennaPhasePattern::create(bool ignore, const std::string& id)
    {
      return std::make_shared<SetIntTxIgnoreRxAntennaPhasePattern>(ignore, id);
    }

    SetIntTxIgnoreRxAntennaPhasePatternPtr SetIntTxIgnoreRxAntennaPhasePattern::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxIgnoreRxAntennaPhasePattern>(ptr);
    }

    bool SetIntTxIgnoreRxAntennaPhasePattern::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxIgnoreRxAntennaPhasePattern::documentation() const { return Documentation; }


    int SetIntTxIgnoreRxAntennaPhasePattern::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxIgnoreRxAntennaPhasePattern::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void SetIntTxIgnoreRxAntennaPhasePattern::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxIgnoreRxAntennaPhasePattern::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxIgnoreRxAntennaPhasePattern::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
