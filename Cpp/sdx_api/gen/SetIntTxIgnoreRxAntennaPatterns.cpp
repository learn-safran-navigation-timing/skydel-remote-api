
#include "gen/SetIntTxIgnoreRxAntennaPatterns.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxIgnoreRxAntennaPatterns
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxIgnoreRxAntennaPatterns::CmdName = "SetIntTxIgnoreRxAntennaPatterns";
    const char* const SetIntTxIgnoreRxAntennaPatterns::Documentation = "Set whether a dynamic transmitter should ignore the vehicle's antenna patterns (gain and phase).";

    REGISTER_COMMAND_FACTORY(SetIntTxIgnoreRxAntennaPatterns);


    SetIntTxIgnoreRxAntennaPatterns::SetIntTxIgnoreRxAntennaPatterns()
      : CommandBase(CmdName)
    {}

    SetIntTxIgnoreRxAntennaPatterns::SetIntTxIgnoreRxAntennaPatterns(bool ignore, const std::string& id)
      : CommandBase(CmdName)
    {

      setIgnore(ignore);
      setId(id);
    }

    SetIntTxIgnoreRxAntennaPatternsPtr SetIntTxIgnoreRxAntennaPatterns::create(bool ignore, const std::string& id)
    {
      return std::make_shared<SetIntTxIgnoreRxAntennaPatterns>(ignore, id);
    }

    SetIntTxIgnoreRxAntennaPatternsPtr SetIntTxIgnoreRxAntennaPatterns::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxIgnoreRxAntennaPatterns>(ptr);
    }

    bool SetIntTxIgnoreRxAntennaPatterns::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxIgnoreRxAntennaPatterns::documentation() const { return Documentation; }


    int SetIntTxIgnoreRxAntennaPatterns::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxIgnoreRxAntennaPatterns::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void SetIntTxIgnoreRxAntennaPatterns::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxIgnoreRxAntennaPatterns::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxIgnoreRxAntennaPatterns::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
