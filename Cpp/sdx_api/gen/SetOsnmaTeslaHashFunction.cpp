
#include "SetOsnmaTeslaHashFunction.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetOsnmaTeslaHashFunction
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetOsnmaTeslaHashFunction::CmdName = "SetOsnmaTeslaHashFunction";
    const char* const SetOsnmaTeslaHashFunction::Documentation = "Set OSNMA TESLA hash function.\n"
      "\n"
      "Name         Type   Description\n"
      "------------ ------ -------------------------------------------------------------------------------------\n"
      "HashFunction string Hash function used for the TESLA chain. Hash functions are: \"SHA-256\" and \"SHA3-256\".";
    const char* const SetOsnmaTeslaHashFunction::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetOsnmaTeslaHashFunction);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetOsnmaTeslaHashFunction);


    SetOsnmaTeslaHashFunction::SetOsnmaTeslaHashFunction()
      : CommandBase(CmdName, TargetId)
    {}

    SetOsnmaTeslaHashFunction::SetOsnmaTeslaHashFunction(const std::string& hashFunction)
      : CommandBase(CmdName, TargetId)
    {

      setHashFunction(hashFunction);
    }

    SetOsnmaTeslaHashFunctionPtr SetOsnmaTeslaHashFunction::create(const std::string& hashFunction)
    {
      return std::make_shared<SetOsnmaTeslaHashFunction>(hashFunction);
    }

    SetOsnmaTeslaHashFunctionPtr SetOsnmaTeslaHashFunction::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetOsnmaTeslaHashFunction>(ptr);
    }

    bool SetOsnmaTeslaHashFunction::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["HashFunction"])
        ;

    }

    std::string SetOsnmaTeslaHashFunction::documentation() const { return Documentation; }

    const std::vector<std::string>& SetOsnmaTeslaHashFunction::fieldNames() const 
    { 
      static const std::vector<std::string> names {"HashFunction"}; 
      return names; 
    }


    int SetOsnmaTeslaHashFunction::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetOsnmaTeslaHashFunction::hashFunction() const
    {
      return parse_json<std::string>::parse(m_values["HashFunction"]);
    }

    void SetOsnmaTeslaHashFunction::setHashFunction(const std::string& hashFunction)
    {
      m_values.AddMember("HashFunction", parse_json<std::string>::format(hashFunction, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
