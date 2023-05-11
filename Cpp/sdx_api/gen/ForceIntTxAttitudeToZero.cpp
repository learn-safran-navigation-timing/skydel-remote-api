
#include "gen/ForceIntTxAttitudeToZero.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ForceIntTxAttitudeToZero
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ForceIntTxAttitudeToZero::CmdName = "ForceIntTxAttitudeToZero";
    const char* const ForceIntTxAttitudeToZero::Documentation = "Set force interference vehicle yaw, pitch and roll to zero enabled or disabled";

    REGISTER_COMMAND_FACTORY(ForceIntTxAttitudeToZero);


    ForceIntTxAttitudeToZero::ForceIntTxAttitudeToZero()
      : CommandBase(CmdName)
    {}

    ForceIntTxAttitudeToZero::ForceIntTxAttitudeToZero(bool enabled, const std::string& id)
      : CommandBase(CmdName)
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
