
#include "gen/IsIntTxIgnoreRxAntennaPhasePatternResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxIgnoreRxAntennaPhasePatternResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxIgnoreRxAntennaPhasePatternResult::CmdName = "IsIntTxIgnoreRxAntennaPhasePatternResult";
    const char* const IsIntTxIgnoreRxAntennaPhasePatternResult::Documentation = "Result of IsIntTxIgnoreRxAntennaPhasePattern.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsIntTxIgnoreRxAntennaPhasePatternResult);


    IsIntTxIgnoreRxAntennaPhasePatternResult::IsIntTxIgnoreRxAntennaPhasePatternResult()
      : CommandResult(CmdName)
    {}

    IsIntTxIgnoreRxAntennaPhasePatternResult::IsIntTxIgnoreRxAntennaPhasePatternResult(bool ignore, const std::string& id)
      : CommandResult(CmdName)
    {

      setIgnore(ignore);
      setId(id);
    }

    IsIntTxIgnoreRxAntennaPhasePatternResult::IsIntTxIgnoreRxAntennaPhasePatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
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
