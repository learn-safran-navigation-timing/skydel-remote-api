
#include "gen/IsSpoofTxIgnoreRxAntennaGainPattern.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpoofTxIgnoreRxAntennaGainPattern
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpoofTxIgnoreRxAntennaGainPattern::CmdName = "IsSpoofTxIgnoreRxAntennaGainPattern";
    const char* const IsSpoofTxIgnoreRxAntennaGainPattern::Documentation = "Get whether a spoofer ignore the receiver's antenna gain pattern.";

    REGISTER_COMMAND_FACTORY(IsSpoofTxIgnoreRxAntennaGainPattern);


    IsSpoofTxIgnoreRxAntennaGainPattern::IsSpoofTxIgnoreRxAntennaGainPattern()
      : CommandBase(CmdName)
    {}

    IsSpoofTxIgnoreRxAntennaGainPattern::IsSpoofTxIgnoreRxAntennaGainPattern(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    IsSpoofTxIgnoreRxAntennaGainPatternPtr IsSpoofTxIgnoreRxAntennaGainPattern::create(const std::string& id)
    {
      return std::make_shared<IsSpoofTxIgnoreRxAntennaGainPattern>(id);
    }

    IsSpoofTxIgnoreRxAntennaGainPatternPtr IsSpoofTxIgnoreRxAntennaGainPattern::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSpoofTxIgnoreRxAntennaGainPattern>(ptr);
    }

    bool IsSpoofTxIgnoreRxAntennaGainPattern::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsSpoofTxIgnoreRxAntennaGainPattern::documentation() const { return Documentation; }


    int IsSpoofTxIgnoreRxAntennaGainPattern::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSpoofTxIgnoreRxAntennaGainPattern::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsSpoofTxIgnoreRxAntennaGainPattern::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
