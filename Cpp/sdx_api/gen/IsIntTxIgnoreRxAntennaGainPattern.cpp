
#include "gen/IsIntTxIgnoreRxAntennaGainPattern.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxIgnoreRxAntennaGainPattern
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxIgnoreRxAntennaGainPattern::CmdName = "IsIntTxIgnoreRxAntennaGainPattern";
    const char* const IsIntTxIgnoreRxAntennaGainPattern::Documentation = "Get whether a dynamic transmitter ignore the receiver's antenna gain pattern.";

    REGISTER_COMMAND_FACTORY(IsIntTxIgnoreRxAntennaGainPattern);


    IsIntTxIgnoreRxAntennaGainPattern::IsIntTxIgnoreRxAntennaGainPattern()
      : CommandBase(CmdName)
    {}

    IsIntTxIgnoreRxAntennaGainPattern::IsIntTxIgnoreRxAntennaGainPattern(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    IsIntTxIgnoreRxAntennaGainPatternPtr IsIntTxIgnoreRxAntennaGainPattern::create(const std::string& id)
    {
      return std::make_shared<IsIntTxIgnoreRxAntennaGainPattern>(id);
    }

    IsIntTxIgnoreRxAntennaGainPatternPtr IsIntTxIgnoreRxAntennaGainPattern::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIntTxIgnoreRxAntennaGainPattern>(ptr);
    }

    bool IsIntTxIgnoreRxAntennaGainPattern::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsIntTxIgnoreRxAntennaGainPattern::documentation() const { return Documentation; }


    int IsIntTxIgnoreRxAntennaGainPattern::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsIntTxIgnoreRxAntennaGainPattern::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsIntTxIgnoreRxAntennaGainPattern::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
