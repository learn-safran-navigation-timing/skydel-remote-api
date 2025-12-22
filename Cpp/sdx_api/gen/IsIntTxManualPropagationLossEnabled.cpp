
#include "IsIntTxManualPropagationLossEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxManualPropagationLossEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxManualPropagationLossEnabled::CmdName = "IsIntTxManualPropagationLossEnabled";
    const char* const IsIntTxManualPropagationLossEnabled::Documentation = "Tells whether a dynamic interference transmitter uses propagation loss values provided by the user.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -------------------------------------------\n"
      "Id   string Interference transmitter unique identifier.";
    const char* const IsIntTxManualPropagationLossEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsIntTxManualPropagationLossEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsIntTxManualPropagationLossEnabled);


    IsIntTxManualPropagationLossEnabled::IsIntTxManualPropagationLossEnabled()
      : CommandBase(CmdName, TargetId)
    {}

    IsIntTxManualPropagationLossEnabled::IsIntTxManualPropagationLossEnabled(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    IsIntTxManualPropagationLossEnabledPtr IsIntTxManualPropagationLossEnabled::create(const std::string& id)
    {
      return std::make_shared<IsIntTxManualPropagationLossEnabled>(id);
    }

    IsIntTxManualPropagationLossEnabledPtr IsIntTxManualPropagationLossEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIntTxManualPropagationLossEnabled>(ptr);
    }

    bool IsIntTxManualPropagationLossEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsIntTxManualPropagationLossEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsIntTxManualPropagationLossEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int IsIntTxManualPropagationLossEnabled::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string IsIntTxManualPropagationLossEnabled::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsIntTxManualPropagationLossEnabled::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
