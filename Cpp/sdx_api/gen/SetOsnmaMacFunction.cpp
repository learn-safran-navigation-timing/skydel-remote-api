
#include "SetOsnmaMacFunction.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetOsnmaMacFunction
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetOsnmaMacFunction::CmdName = "SetOsnmaMacFunction";
    const char* const SetOsnmaMacFunction::Documentation = "Set OSNMA MAC function.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ --------------------------------------------------------------------------------------------------------\n"
      "MacFunction string MAC function used to authenticate the navigation data. MAC functions are: \"HMAC-SHA-256\" and \"CMAC-AES\".\n"
      "                   Note: CMAC-AES can only be used with 128, 192 and 256 bits keys.";
    const char* const SetOsnmaMacFunction::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetOsnmaMacFunction);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetOsnmaMacFunction);


    SetOsnmaMacFunction::SetOsnmaMacFunction()
      : CommandBase(CmdName, TargetId)
    {}

    SetOsnmaMacFunction::SetOsnmaMacFunction(const std::string& macFunction)
      : CommandBase(CmdName, TargetId)
    {

      setMacFunction(macFunction);
    }

    SetOsnmaMacFunctionPtr SetOsnmaMacFunction::create(const std::string& macFunction)
    {
      return std::make_shared<SetOsnmaMacFunction>(macFunction);
    }

    SetOsnmaMacFunctionPtr SetOsnmaMacFunction::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetOsnmaMacFunction>(ptr);
    }

    bool SetOsnmaMacFunction::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["MacFunction"])
        ;

    }

    std::string SetOsnmaMacFunction::documentation() const { return Documentation; }

    const std::vector<std::string>& SetOsnmaMacFunction::fieldNames() const 
    { 
      static const std::vector<std::string> names {"MacFunction"}; 
      return names; 
    }


    int SetOsnmaMacFunction::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetOsnmaMacFunction::macFunction() const
    {
      return parse_json<std::string>::parse(m_values["MacFunction"]);
    }

    void SetOsnmaMacFunction::setMacFunction(const std::string& macFunction)
    {
      m_values.AddMember("MacFunction", parse_json<std::string>::format(macFunction, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
