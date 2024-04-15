
#include "IsIntTxIgnoreRxAntennaPhasePatternResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxIgnoreRxAntennaPhasePatternResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxIgnoreRxAntennaPhasePatternResult::CmdName = "IsIntTxIgnoreRxAntennaPhasePatternResult";
    const char* const IsIntTxIgnoreRxAntennaPhasePatternResult::Documentation = "Result of IsIntTxIgnoreRxAntennaPhasePattern.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------\n"
      "Ignore bool   If true, the receiver's antenna phase pattern will be ignored.\n"
      "Id     string Transmitter unique identifier.";
    const char* const IsIntTxIgnoreRxAntennaPhasePatternResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsIntTxIgnoreRxAntennaPhasePatternResult);


    IsIntTxIgnoreRxAntennaPhasePatternResult::IsIntTxIgnoreRxAntennaPhasePatternResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsIntTxIgnoreRxAntennaPhasePatternResult::IsIntTxIgnoreRxAntennaPhasePatternResult(bool ignore, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setIgnore(ignore);
      setId(id);
    }

    IsIntTxIgnoreRxAntennaPhasePatternResult::IsIntTxIgnoreRxAntennaPhasePatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIgnore(ignore);
      setId(id);
    }


    IsIntTxIgnoreRxAntennaPhasePatternResultPtr IsIntTxIgnoreRxAntennaPhasePatternResult::create(bool ignore, const std::string& id)
    {
      return std::make_shared<IsIntTxIgnoreRxAntennaPhasePatternResult>(ignore, id);
    }

    IsIntTxIgnoreRxAntennaPhasePatternResultPtr IsIntTxIgnoreRxAntennaPhasePatternResult::create(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
    {
      return std::make_shared<IsIntTxIgnoreRxAntennaPhasePatternResult>(relatedCommand, ignore, id);
    }

    IsIntTxIgnoreRxAntennaPhasePatternResultPtr IsIntTxIgnoreRxAntennaPhasePatternResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIntTxIgnoreRxAntennaPhasePatternResult>(ptr);
    }

    bool IsIntTxIgnoreRxAntennaPhasePatternResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsIntTxIgnoreRxAntennaPhasePatternResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsIntTxIgnoreRxAntennaPhasePatternResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ignore", "Id"}; 
      return names; 
    }


    bool IsIntTxIgnoreRxAntennaPhasePatternResult::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void IsIntTxIgnoreRxAntennaPhasePatternResult::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsIntTxIgnoreRxAntennaPhasePatternResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsIntTxIgnoreRxAntennaPhasePatternResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
