
#include "ForceIntTxAttitudeToZero.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ForceIntTxAttitudeToZero
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ForceIntTxAttitudeToZero::CmdName = "ForceIntTxAttitudeToZero";
    const char* const ForceIntTxAttitudeToZero::Documentation = "Set force interference vehicle yaw, pitch and roll to zero enabled or disabled\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ ------------------------------------------------------------\n"
      "Enabled bool   If true, interference vehicle won't rotate during simulation\n"
      "Id      string Transmitter unique identifier.";
    const char* const ForceIntTxAttitudeToZero::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ForceIntTxAttitudeToZero);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ForceIntTxAttitudeToZero);


    ForceIntTxAttitudeToZero::ForceIntTxAttitudeToZero()
      : CommandBase(CmdName, TargetId)
    {}

    ForceIntTxAttitudeToZero::ForceIntTxAttitudeToZero(bool enabled, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
      setId(id);
    }

    ForceIntTxAttitudeToZeroPtr ForceIntTxAttitudeToZero::create(bool enabled, const std::string& id)
    {
      return std::make_shared<ForceIntTxAttitudeToZero>(enabled, id);
    }

    ForceIntTxAttitudeToZeroPtr ForceIntTxAttitudeToZero::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ForceIntTxAttitudeToZero>(ptr);
    }

    bool ForceIntTxAttitudeToZero::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string ForceIntTxAttitudeToZero::documentation() const { return Documentation; }

    const std::vector<std::string>& ForceIntTxAttitudeToZero::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "Id"}; 
      return names; 
    }


    int ForceIntTxAttitudeToZero::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool ForceIntTxAttitudeToZero::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void ForceIntTxAttitudeToZero::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ForceIntTxAttitudeToZero::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ForceIntTxAttitudeToZero::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
