
#include "IsSpoofTxManualPropagationLossEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpoofTxManualPropagationLossEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpoofTxManualPropagationLossEnabledResult::CmdName = "IsSpoofTxManualPropagationLossEnabledResult";
    const char* const IsSpoofTxManualPropagationLossEnabledResult::Documentation = "Result of IsSpoofTxManualPropagationLossEnabled.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------\n"
      "Manual bool   If true, propagation loss will be 1000 dB until set manually.\n"
      "Id     string Spoofing transmitter unique identifier.";
    const char* const IsSpoofTxManualPropagationLossEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSpoofTxManualPropagationLossEnabledResult);


    IsSpoofTxManualPropagationLossEnabledResult::IsSpoofTxManualPropagationLossEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsSpoofTxManualPropagationLossEnabledResult::IsSpoofTxManualPropagationLossEnabledResult(bool manual, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setManual(manual);
      setId(id);
    }

    IsSpoofTxManualPropagationLossEnabledResult::IsSpoofTxManualPropagationLossEnabledResult(CommandBasePtr relatedCommand, bool manual, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setManual(manual);
      setId(id);
    }


    IsSpoofTxManualPropagationLossEnabledResultPtr IsSpoofTxManualPropagationLossEnabledResult::create(bool manual, const std::string& id)
    {
      return std::make_shared<IsSpoofTxManualPropagationLossEnabledResult>(manual, id);
    }

    IsSpoofTxManualPropagationLossEnabledResultPtr IsSpoofTxManualPropagationLossEnabledResult::create(CommandBasePtr relatedCommand, bool manual, const std::string& id)
    {
      return std::make_shared<IsSpoofTxManualPropagationLossEnabledResult>(relatedCommand, manual, id);
    }

    IsSpoofTxManualPropagationLossEnabledResultPtr IsSpoofTxManualPropagationLossEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSpoofTxManualPropagationLossEnabledResult>(ptr);
    }

    bool IsSpoofTxManualPropagationLossEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Manual"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsSpoofTxManualPropagationLossEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSpoofTxManualPropagationLossEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Manual", "Id"}; 
      return names; 
    }


    bool IsSpoofTxManualPropagationLossEnabledResult::manual() const
    {
      return parse_json<bool>::parse(m_values["Manual"]);
    }

    void IsSpoofTxManualPropagationLossEnabledResult::setManual(bool manual)
    {
      m_values.AddMember("Manual", parse_json<bool>::format(manual, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsSpoofTxManualPropagationLossEnabledResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsSpoofTxManualPropagationLossEnabledResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
