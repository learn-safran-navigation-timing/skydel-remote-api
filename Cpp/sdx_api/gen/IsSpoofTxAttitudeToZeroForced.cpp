
#include "IsSpoofTxAttitudeToZeroForced.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpoofTxAttitudeToZeroForced
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpoofTxAttitudeToZeroForced::CmdName = "IsSpoofTxAttitudeToZeroForced";
    const char* const IsSpoofTxAttitudeToZeroForced::Documentation = "Get whether the spoofer transmitter vehicle yaw, pitch and roll should be forced to zero.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const IsSpoofTxAttitudeToZeroForced::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSpoofTxAttitudeToZeroForced);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSpoofTxAttitudeToZeroForced);


    IsSpoofTxAttitudeToZeroForced::IsSpoofTxAttitudeToZeroForced()
      : CommandBase(CmdName, TargetId)
    {}

    IsSpoofTxAttitudeToZeroForced::IsSpoofTxAttitudeToZeroForced(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    IsSpoofTxAttitudeToZeroForcedPtr IsSpoofTxAttitudeToZeroForced::create(const std::string& id)
    {
      return std::make_shared<IsSpoofTxAttitudeToZeroForced>(id);
    }

    IsSpoofTxAttitudeToZeroForcedPtr IsSpoofTxAttitudeToZeroForced::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSpoofTxAttitudeToZeroForced>(ptr);
    }

    bool IsSpoofTxAttitudeToZeroForced::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsSpoofTxAttitudeToZeroForced::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSpoofTxAttitudeToZeroForced::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int IsSpoofTxAttitudeToZeroForced::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSpoofTxAttitudeToZeroForced::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsSpoofTxAttitudeToZeroForced::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
