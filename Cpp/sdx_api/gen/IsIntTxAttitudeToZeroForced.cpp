
#include "IsIntTxAttitudeToZeroForced.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxAttitudeToZeroForced
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxAttitudeToZeroForced::CmdName = "IsIntTxAttitudeToZeroForced";
    const char* const IsIntTxAttitudeToZeroForced::Documentation = "Get force interference vehicle yaw, pitch and roll to zero enabled or disabled\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const IsIntTxAttitudeToZeroForced::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsIntTxAttitudeToZeroForced);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsIntTxAttitudeToZeroForced);


    IsIntTxAttitudeToZeroForced::IsIntTxAttitudeToZeroForced()
      : CommandBase(CmdName, TargetId)
    {}

    IsIntTxAttitudeToZeroForced::IsIntTxAttitudeToZeroForced(const std::string& id)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& IsIntTxAttitudeToZeroForced::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


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
