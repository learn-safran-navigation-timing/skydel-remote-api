
#include "gen/IsIntTxAttitudeToZeroForced.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxAttitudeToZeroForced
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxAttitudeToZeroForced::CmdName = "IsIntTxAttitudeToZeroForced";
    const char* const IsIntTxAttitudeToZeroForced::Documentation = "Get force interference vehicle yaw, pitch and roll to zero enabled or disabled";

    REGISTER_COMMAND_FACTORY(IsIntTxAttitudeToZeroForced);


    IsIntTxAttitudeToZeroForced::IsIntTxAttitudeToZeroForced()
      : CommandBase(CmdName)
    {}

    IsIntTxAttitudeToZeroForced::IsIntTxAttitudeToZeroForced(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    IsIntTxAttitudeToZeroForcedPtr IsIntTxAttitudeToZeroForced::create(const std::string& id)
    {
      return std::make_shared<IsIntTxAttitudeToZeroForced>(id);
    }

    IsIntTxAttitudeToZeroForcedPtr IsIntTxAttitudeToZeroForced::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIntTxAttitudeToZeroForced>(ptr);
    }

    bool IsIntTxAttitudeToZeroForced::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsIntTxAttitudeToZeroForced::documentation() const { return Documentation; }


    int IsIntTxAttitudeToZeroForced::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsIntTxAttitudeToZeroForced::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsIntTxAttitudeToZeroForced::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
