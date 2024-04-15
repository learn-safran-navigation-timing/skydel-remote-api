
#include "IsSpoofTxIgnoreRxAntennaPhasePattern.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpoofTxIgnoreRxAntennaPhasePattern
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpoofTxIgnoreRxAntennaPhasePattern::CmdName = "IsSpoofTxIgnoreRxAntennaPhasePattern";
    const char* const IsSpoofTxIgnoreRxAntennaPhasePattern::Documentation = "Get whether a spoofer ignore the receiver's antenna phase pattern.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const IsSpoofTxIgnoreRxAntennaPhasePattern::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSpoofTxIgnoreRxAntennaPhasePattern);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSpoofTxIgnoreRxAntennaPhasePattern);


    IsSpoofTxIgnoreRxAntennaPhasePattern::IsSpoofTxIgnoreRxAntennaPhasePattern()
      : CommandBase(CmdName, TargetId)
    {}

    IsSpoofTxIgnoreRxAntennaPhasePattern::IsSpoofTxIgnoreRxAntennaPhasePattern(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    IsSpoofTxIgnoreRxAntennaPhasePatternPtr IsSpoofTxIgnoreRxAntennaPhasePattern::create(const std::string& id)
    {
      return std::make_shared<IsSpoofTxIgnoreRxAntennaPhasePattern>(id);
    }

    IsSpoofTxIgnoreRxAntennaPhasePatternPtr IsSpoofTxIgnoreRxAntennaPhasePattern::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSpoofTxIgnoreRxAntennaPhasePattern>(ptr);
    }

    bool IsSpoofTxIgnoreRxAntennaPhasePattern::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsSpoofTxIgnoreRxAntennaPhasePattern::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSpoofTxIgnoreRxAntennaPhasePattern::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int IsSpoofTxIgnoreRxAntennaPhasePattern::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSpoofTxIgnoreRxAntennaPhasePattern::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsSpoofTxIgnoreRxAntennaPhasePattern::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
