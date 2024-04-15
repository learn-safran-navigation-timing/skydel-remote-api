
#include "IsSpoofTxTrajectorySmoothingEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpoofTxTrajectorySmoothingEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpoofTxTrajectorySmoothingEnabledResult::CmdName = "IsSpoofTxTrajectorySmoothingEnabledResult";
    const char* const IsSpoofTxTrajectorySmoothingEnabledResult::Documentation = "Result of IsSpoofTxTrajectorySmoothingEnabled.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ ---------------------------------------------------------------------------\n"
      "Enabled bool   If true, spoofer transmitter trajectory will be smoothed during simulation.\n"
      "Id      string Transmitter unique identifier.";
    const char* const IsSpoofTxTrajectorySmoothingEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSpoofTxTrajectorySmoothingEnabledResult);


    IsSpoofTxTrajectorySmoothingEnabledResult::IsSpoofTxTrajectorySmoothingEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsSpoofTxTrajectorySmoothingEnabledResult::IsSpoofTxTrajectorySmoothingEnabledResult(bool enabled, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
      setId(id);
    }

    IsSpoofTxTrajectorySmoothingEnabledResult::IsSpoofTxTrajectorySmoothingEnabledResult(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
      setId(id);
    }


    IsSpoofTxTrajectorySmoothingEnabledResultPtr IsSpoofTxTrajectorySmoothingEnabledResult::create(bool enabled, const std::string& id)
    {
      return std::make_shared<IsSpoofTxTrajectorySmoothingEnabledResult>(enabled, id);
    }

    IsSpoofTxTrajectorySmoothingEnabledResultPtr IsSpoofTxTrajectorySmoothingEnabledResult::create(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
    {
      return std::make_shared<IsSpoofTxTrajectorySmoothingEnabledResult>(relatedCommand, enabled, id);
    }

    IsSpoofTxTrajectorySmoothingEnabledResultPtr IsSpoofTxTrajectorySmoothingEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSpoofTxTrajectorySmoothingEnabledResult>(ptr);
    }

    bool IsSpoofTxTrajectorySmoothingEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsSpoofTxTrajectorySmoothingEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSpoofTxTrajectorySmoothingEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "Id"}; 
      return names; 
    }


    bool IsSpoofTxTrajectorySmoothingEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsSpoofTxTrajectorySmoothingEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsSpoofTxTrajectorySmoothingEnabledResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsSpoofTxTrajectorySmoothingEnabledResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
