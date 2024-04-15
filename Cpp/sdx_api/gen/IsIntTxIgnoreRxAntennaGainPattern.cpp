
#include "IsIntTxIgnoreRxAntennaGainPattern.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxIgnoreRxAntennaGainPattern
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxIgnoreRxAntennaGainPattern::CmdName = "IsIntTxIgnoreRxAntennaGainPattern";
    const char* const IsIntTxIgnoreRxAntennaGainPattern::Documentation = "Get whether a dynamic transmitter ignore the receiver's antenna gain pattern.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const IsIntTxIgnoreRxAntennaGainPattern::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsIntTxIgnoreRxAntennaGainPattern);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsIntTxIgnoreRxAntennaGainPattern);


    IsIntTxIgnoreRxAntennaGainPattern::IsIntTxIgnoreRxAntennaGainPattern()
      : CommandBase(CmdName, TargetId)
    {}

    IsIntTxIgnoreRxAntennaGainPattern::IsIntTxIgnoreRxAntennaGainPattern(const std::string& id)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& IsIntTxIgnoreRxAntennaGainPattern::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


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
