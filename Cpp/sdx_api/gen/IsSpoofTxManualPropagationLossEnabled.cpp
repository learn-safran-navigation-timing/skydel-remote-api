
#include "IsSpoofTxManualPropagationLossEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpoofTxManualPropagationLossEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpoofTxManualPropagationLossEnabled::CmdName = "IsSpoofTxManualPropagationLossEnabled";
    const char* const IsSpoofTxManualPropagationLossEnabled::Documentation = "Tells whether a spoofer uses propagation loss values provided by the user.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ---------------------------------------\n"
      "Id   string Spoofing transmitter unique identifier.";
    const char* const IsSpoofTxManualPropagationLossEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSpoofTxManualPropagationLossEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSpoofTxManualPropagationLossEnabled);


    IsSpoofTxManualPropagationLossEnabled::IsSpoofTxManualPropagationLossEnabled()
      : CommandBase(CmdName, TargetId)
    {}

    IsSpoofTxManualPropagationLossEnabled::IsSpoofTxManualPropagationLossEnabled(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    IsSpoofTxManualPropagationLossEnabledPtr IsSpoofTxManualPropagationLossEnabled::create(const std::string& id)
    {
      return std::make_shared<IsSpoofTxManualPropagationLossEnabled>(id);
    }

    IsSpoofTxManualPropagationLossEnabledPtr IsSpoofTxManualPropagationLossEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSpoofTxManualPropagationLossEnabled>(ptr);
    }

    bool IsSpoofTxManualPropagationLossEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsSpoofTxManualPropagationLossEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSpoofTxManualPropagationLossEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int IsSpoofTxManualPropagationLossEnabled::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string IsSpoofTxManualPropagationLossEnabled::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsSpoofTxManualPropagationLossEnabled::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
