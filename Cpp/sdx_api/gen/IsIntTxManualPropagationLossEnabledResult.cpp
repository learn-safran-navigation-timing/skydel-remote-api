
#include "IsIntTxManualPropagationLossEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxManualPropagationLossEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxManualPropagationLossEnabledResult::CmdName = "IsIntTxManualPropagationLossEnabledResult";
    const char* const IsIntTxManualPropagationLossEnabledResult::Documentation = "Result of IsIntTxManualPropagationLossEnabled.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------\n"
      "Manual bool   If true, propagation loss will be 1000 dB until set manually.\n"
      "Id     string Interference transmitter unique identifier.";
    const char* const IsIntTxManualPropagationLossEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsIntTxManualPropagationLossEnabledResult);


    IsIntTxManualPropagationLossEnabledResult::IsIntTxManualPropagationLossEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsIntTxManualPropagationLossEnabledResult::IsIntTxManualPropagationLossEnabledResult(bool manual, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setManual(manual);
      setId(id);
    }

    IsIntTxManualPropagationLossEnabledResult::IsIntTxManualPropagationLossEnabledResult(CommandBasePtr relatedCommand, bool manual, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setManual(manual);
      setId(id);
    }


    IsIntTxManualPropagationLossEnabledResultPtr IsIntTxManualPropagationLossEnabledResult::create(bool manual, const std::string& id)
    {
      return std::make_shared<IsIntTxManualPropagationLossEnabledResult>(manual, id);
    }

    IsIntTxManualPropagationLossEnabledResultPtr IsIntTxManualPropagationLossEnabledResult::create(CommandBasePtr relatedCommand, bool manual, const std::string& id)
    {
      return std::make_shared<IsIntTxManualPropagationLossEnabledResult>(relatedCommand, manual, id);
    }

    IsIntTxManualPropagationLossEnabledResultPtr IsIntTxManualPropagationLossEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIntTxManualPropagationLossEnabledResult>(ptr);
    }

    bool IsIntTxManualPropagationLossEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Manual"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsIntTxManualPropagationLossEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsIntTxManualPropagationLossEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Manual", "Id"}; 
      return names; 
    }


    bool IsIntTxManualPropagationLossEnabledResult::manual() const
    {
      return parse_json<bool>::parse(m_values["Manual"]);
    }

    void IsIntTxManualPropagationLossEnabledResult::setManual(bool manual)
    {
      m_values.AddMember("Manual", parse_json<bool>::format(manual, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsIntTxManualPropagationLossEnabledResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsIntTxManualPropagationLossEnabledResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
