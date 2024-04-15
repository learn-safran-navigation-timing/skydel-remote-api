
#include "IsIntTxTrajectorySmoothingEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxTrajectorySmoothingEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxTrajectorySmoothingEnabledResult::CmdName = "IsIntTxTrajectorySmoothingEnabledResult";
    const char* const IsIntTxTrajectorySmoothingEnabledResult::Documentation = "Result of IsIntTxTrajectorySmoothingEnabled.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ -------------------------------------------------------------------\n"
      "Enabled bool   If true, interference trajectory will be smoothed during simulation\n"
      "Id      string Transmitter unique identifier.";
    const char* const IsIntTxTrajectorySmoothingEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsIntTxTrajectorySmoothingEnabledResult);


    IsIntTxTrajectorySmoothingEnabledResult::IsIntTxTrajectorySmoothingEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsIntTxTrajectorySmoothingEnabledResult::IsIntTxTrajectorySmoothingEnabledResult(bool enabled, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
      setId(id);
    }

    IsIntTxTrajectorySmoothingEnabledResult::IsIntTxTrajectorySmoothingEnabledResult(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
      setId(id);
    }


    IsIntTxTrajectorySmoothingEnabledResultPtr IsIntTxTrajectorySmoothingEnabledResult::create(bool enabled, const std::string& id)
    {
      return std::make_shared<IsIntTxTrajectorySmoothingEnabledResult>(enabled, id);
    }

    IsIntTxTrajectorySmoothingEnabledResultPtr IsIntTxTrajectorySmoothingEnabledResult::create(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
    {
      return std::make_shared<IsIntTxTrajectorySmoothingEnabledResult>(relatedCommand, enabled, id);
    }

    IsIntTxTrajectorySmoothingEnabledResultPtr IsIntTxTrajectorySmoothingEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIntTxTrajectorySmoothingEnabledResult>(ptr);
    }

    bool IsIntTxTrajectorySmoothingEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsIntTxTrajectorySmoothingEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsIntTxTrajectorySmoothingEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "Id"}; 
      return names; 
    }


    bool IsIntTxTrajectorySmoothingEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsIntTxTrajectorySmoothingEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsIntTxTrajectorySmoothingEnabledResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsIntTxTrajectorySmoothingEnabledResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
