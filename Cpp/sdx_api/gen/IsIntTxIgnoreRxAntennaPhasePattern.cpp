
#include "gen/IsIntTxIgnoreRxAntennaPhasePattern.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxIgnoreRxAntennaPhasePattern
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxIgnoreRxAntennaPhasePattern::CmdName = "IsIntTxIgnoreRxAntennaPhasePattern";
    const char* const IsIntTxIgnoreRxAntennaPhasePattern::Documentation = "Get whether a dynamic transmitter ignore the receiver's antenna phase pattern.";

    REGISTER_COMMAND_FACTORY(IsIntTxIgnoreRxAntennaPhasePattern);


    IsIntTxIgnoreRxAntennaPhasePattern::IsIntTxIgnoreRxAntennaPhasePattern()
      : CommandBase(CmdName)
    {}

    IsIntTxIgnoreRxAntennaPhasePattern::IsIntTxIgnoreRxAntennaPhasePattern(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    IsIntTxIgnoreRxAntennaPhasePatternPtr IsIntTxIgnoreRxAntennaPhasePattern::create(const std::string& id)
    {
      return std::make_shared<IsIntTxIgnoreRxAntennaPhasePattern>(id);
    }

    IsIntTxIgnoreRxAntennaPhasePatternPtr IsIntTxIgnoreRxAntennaPhasePattern::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIntTxIgnoreRxAntennaPhasePattern>(ptr);
    }

    bool IsIntTxIgnoreRxAntennaPhasePattern::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsIntTxIgnoreRxAntennaPhasePattern::documentation() const { return Documentation; }


    int IsIntTxIgnoreRxAntennaPhasePattern::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsIntTxIgnoreRxAntennaPhasePattern::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsIntTxIgnoreRxAntennaPhasePattern::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
