
#include "EnableSignalStrengthModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSignalStrengthModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSignalStrengthModel::CmdName = "EnableSignalStrengthModel";
    const char* const EnableSignalStrengthModel::Documentation = "Set signal strength model Enable/Disable which affect satellite transmission strength based on their elevation angle\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -----------------------------------------------------------\n"
      "Enabled bool If true, signal strengh model is enabled for all satellites";
    const char* const EnableSignalStrengthModel::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSignalStrengthModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSignalStrengthModel);


    EnableSignalStrengthModel::EnableSignalStrengthModel()
      : CommandBase(CmdName, TargetId)
    {}

    EnableSignalStrengthModel::EnableSignalStrengthModel(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableSignalStrengthModelPtr EnableSignalStrengthModel::create(bool enabled)
    {
      return std::make_shared<EnableSignalStrengthModel>(enabled);
    }

    EnableSignalStrengthModelPtr EnableSignalStrengthModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSignalStrengthModel>(ptr);
    }

    bool EnableSignalStrengthModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableSignalStrengthModel::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableSignalStrengthModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableSignalStrengthModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableSignalStrengthModel::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSignalStrengthModel::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
