
#include "EnableSpoofTxTrajectorySmoothing.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSpoofTxTrajectorySmoothing
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSpoofTxTrajectorySmoothing::CmdName = "EnableSpoofTxTrajectorySmoothing";
    const char* const EnableSpoofTxTrajectorySmoothing::Documentation = "Set trajectory smoothing for spoofer transmitter Track enabled or disabled\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ ---------------------------------------------------------------------------\n"
      "Enabled bool   If true, spoofer transmitter trajectory will be smoothed during simulation.\n"
      "Id      string Transmitter unique identifier.";
    const char* const EnableSpoofTxTrajectorySmoothing::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSpoofTxTrajectorySmoothing);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSpoofTxTrajectorySmoothing);


    EnableSpoofTxTrajectorySmoothing::EnableSpoofTxTrajectorySmoothing()
      : CommandBase(CmdName, TargetId)
    {}

    EnableSpoofTxTrajectorySmoothing::EnableSpoofTxTrajectorySmoothing(bool enabled, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
      setId(id);
    }

    EnableSpoofTxTrajectorySmoothingPtr EnableSpoofTxTrajectorySmoothing::create(bool enabled, const std::string& id)
    {
      return std::make_shared<EnableSpoofTxTrajectorySmoothing>(enabled, id);
    }

    EnableSpoofTxTrajectorySmoothingPtr EnableSpoofTxTrajectorySmoothing::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSpoofTxTrajectorySmoothing>(ptr);
    }

    bool EnableSpoofTxTrajectorySmoothing::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string EnableSpoofTxTrajectorySmoothing::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableSpoofTxTrajectorySmoothing::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "Id"}; 
      return names; 
    }


    int EnableSpoofTxTrajectorySmoothing::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableSpoofTxTrajectorySmoothing::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSpoofTxTrajectorySmoothing::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string EnableSpoofTxTrajectorySmoothing::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void EnableSpoofTxTrajectorySmoothing::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
