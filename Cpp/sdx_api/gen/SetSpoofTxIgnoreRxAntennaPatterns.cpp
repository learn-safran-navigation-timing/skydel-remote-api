
#include "gen/SetSpoofTxIgnoreRxAntennaPatterns.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxIgnoreRxAntennaPatterns
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxIgnoreRxAntennaPatterns::CmdName = "SetSpoofTxIgnoreRxAntennaPatterns";
    const char* const SetSpoofTxIgnoreRxAntennaPatterns::Documentation = "Set whether a spoofer should ignore the receiver's antenna patterns (gain and phase).";

    REGISTER_COMMAND_FACTORY(SetSpoofTxIgnoreRxAntennaPatterns);


    SetSpoofTxIgnoreRxAntennaPatterns::SetSpoofTxIgnoreRxAntennaPatterns()
      : CommandBase(CmdName)
    {}

    SetSpoofTxIgnoreRxAntennaPatterns::SetSpoofTxIgnoreRxAntennaPatterns(bool ignore, const std::string& id)
      : CommandBase(CmdName)
    {

      setIgnore(ignore);
      setId(id);
    }

    SetSpoofTxIgnoreRxAntennaPatternsPtr SetSpoofTxIgnoreRxAntennaPatterns::create(bool ignore, const std::string& id)
    {
      return std::make_shared<SetSpoofTxIgnoreRxAntennaPatterns>(ignore, id);
    }

    SetSpoofTxIgnoreRxAntennaPatternsPtr SetSpoofTxIgnoreRxAntennaPatterns::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxIgnoreRxAntennaPatterns>(ptr);
    }

    bool SetSpoofTxIgnoreRxAntennaPatterns::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSpoofTxIgnoreRxAntennaPatterns::documentation() const { return Documentation; }


    int SetSpoofTxIgnoreRxAntennaPatterns::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool SetSpoofTxIgnoreRxAntennaPatterns::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void SetSpoofTxIgnoreRxAntennaPatterns::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxIgnoreRxAntennaPatterns::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxIgnoreRxAntennaPatterns::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
