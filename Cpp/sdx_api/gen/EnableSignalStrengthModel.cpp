
#include "gen/EnableSignalStrengthModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSignalStrengthModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSignalStrengthModel::CmdName = "EnableSignalStrengthModel";
    const char* const EnableSignalStrengthModel::Documentation = "Set signal strength model Enable/Disable which affect satellite transmission strength based on their elevation angle";

    REGISTER_COMMAND_FACTORY(EnableSignalStrengthModel);


    EnableSignalStrengthModel::EnableSignalStrengthModel()
      : CommandBase(CmdName)
    {}

    EnableSignalStrengthModel::EnableSignalStrengthModel(bool enabled)
      : CommandBase(CmdName)
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
