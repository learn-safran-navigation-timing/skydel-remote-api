
#include "GetOsnmaMacFunctionResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetOsnmaMacFunctionResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetOsnmaMacFunctionResult::CmdName = "GetOsnmaMacFunctionResult";
    const char* const GetOsnmaMacFunctionResult::Documentation = "Result of GetOsnmaMacFunction.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ --------------------------------------------------------------------------------------------------------\n"
      "MacFunction string MAC function used to authenticate the navigation data. MAC functions are: \"HMAC-SHA-256\" and \"CMAC-AES\".\n"
      "                   Note: CMAC-AES can only be used with 128, 192 and 256 bits keys.";
    const char* const GetOsnmaMacFunctionResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetOsnmaMacFunctionResult);


    GetOsnmaMacFunctionResult::GetOsnmaMacFunctionResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetOsnmaMacFunctionResult::GetOsnmaMacFunctionResult(const std::string& macFunction)
      : CommandResult(CmdName, TargetId)
    {

      setMacFunction(macFunction);
    }

    GetOsnmaMacFunctionResult::GetOsnmaMacFunctionResult(CommandBasePtr relatedCommand, const std::string& macFunction)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setMacFunction(macFunction);
    }


    GetOsnmaMacFunctionResultPtr GetOsnmaMacFunctionResult::create(const std::string& macFunction)
    {
      return std::make_shared<GetOsnmaMacFunctionResult>(macFunction);
    }

    GetOsnmaMacFunctionResultPtr GetOsnmaMacFunctionResult::create(CommandBasePtr relatedCommand, const std::string& macFunction)
    {
      return std::make_shared<GetOsnmaMacFunctionResult>(relatedCommand, macFunction);
    }

    GetOsnmaMacFunctionResultPtr GetOsnmaMacFunctionResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetOsnmaMacFunctionResult>(ptr);
    }

    bool GetOsnmaMacFunctionResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["MacFunction"])
        ;

    }

    std::string GetOsnmaMacFunctionResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetOsnmaMacFunctionResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"MacFunction"}; 
      return names; 
    }


    std::string GetOsnmaMacFunctionResult::macFunction() const
    {
      return parse_json<std::string>::parse(m_values["MacFunction"]);
    }

    void GetOsnmaMacFunctionResult::setMacFunction(const std::string& macFunction)
    {
      m_values.AddMember("MacFunction", parse_json<std::string>::format(macFunction, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
