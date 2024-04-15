
#include "GetOsnmaTeslaHashFunctionResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetOsnmaTeslaHashFunctionResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetOsnmaTeslaHashFunctionResult::CmdName = "GetOsnmaTeslaHashFunctionResult";
    const char* const GetOsnmaTeslaHashFunctionResult::Documentation = "Result of GetOsnmaTeslaHashFunction.\n"
      "\n"
      "Name         Type   Description\n"
      "------------ ------ -------------------------------------------------------------------------------------\n"
      "HashFunction string Hash function used for the TESLA chain. Hash functions are: \"SHA-256\" and \"SHA3-256\".";
    const char* const GetOsnmaTeslaHashFunctionResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetOsnmaTeslaHashFunctionResult);


    GetOsnmaTeslaHashFunctionResult::GetOsnmaTeslaHashFunctionResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetOsnmaTeslaHashFunctionResult::GetOsnmaTeslaHashFunctionResult(const std::string& hashFunction)
      : CommandResult(CmdName, TargetId)
    {

      setHashFunction(hashFunction);
    }

    GetOsnmaTeslaHashFunctionResult::GetOsnmaTeslaHashFunctionResult(CommandBasePtr relatedCommand, const std::string& hashFunction)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setHashFunction(hashFunction);
    }


    GetOsnmaTeslaHashFunctionResultPtr GetOsnmaTeslaHashFunctionResult::create(const std::string& hashFunction)
    {
      return std::make_shared<GetOsnmaTeslaHashFunctionResult>(hashFunction);
    }

    GetOsnmaTeslaHashFunctionResultPtr GetOsnmaTeslaHashFunctionResult::create(CommandBasePtr relatedCommand, const std::string& hashFunction)
    {
      return std::make_shared<GetOsnmaTeslaHashFunctionResult>(relatedCommand, hashFunction);
    }

    GetOsnmaTeslaHashFunctionResultPtr GetOsnmaTeslaHashFunctionResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetOsnmaTeslaHashFunctionResult>(ptr);
    }

    bool GetOsnmaTeslaHashFunctionResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["HashFunction"])
        ;

    }

    std::string GetOsnmaTeslaHashFunctionResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetOsnmaTeslaHashFunctionResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"HashFunction"}; 
      return names; 
    }


    std::string GetOsnmaTeslaHashFunctionResult::hashFunction() const
    {
      return parse_json<std::string>::parse(m_values["HashFunction"]);
    }

    void GetOsnmaTeslaHashFunctionResult::setHashFunction(const std::string& hashFunction)
    {
      m_values.AddMember("HashFunction", parse_json<std::string>::format(hashFunction, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
