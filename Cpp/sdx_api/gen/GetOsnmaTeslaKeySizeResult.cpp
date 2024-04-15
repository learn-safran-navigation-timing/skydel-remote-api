
#include "GetOsnmaTeslaKeySizeResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetOsnmaTeslaKeySizeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetOsnmaTeslaKeySizeResult::CmdName = "GetOsnmaTeslaKeySizeResult";
    const char* const GetOsnmaTeslaKeySizeResult::Documentation = "Result of GetOsnmaTeslaKeySize.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------------------------------------\n"
      "KeySize int  TESLA key size in bits. Accepted key sizes are: 96, 104, 112, 120, 128, 160, 192, 224 and 256.\n"
      "             Note: Only 128, 192 and 256 bits keys can be be used with CMAC-AES.";
    const char* const GetOsnmaTeslaKeySizeResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetOsnmaTeslaKeySizeResult);


    GetOsnmaTeslaKeySizeResult::GetOsnmaTeslaKeySizeResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetOsnmaTeslaKeySizeResult::GetOsnmaTeslaKeySizeResult(int keySize)
      : CommandResult(CmdName, TargetId)
    {

      setKeySize(keySize);
    }

    GetOsnmaTeslaKeySizeResult::GetOsnmaTeslaKeySizeResult(CommandBasePtr relatedCommand, int keySize)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setKeySize(keySize);
    }


    GetOsnmaTeslaKeySizeResultPtr GetOsnmaTeslaKeySizeResult::create(int keySize)
    {
      return std::make_shared<GetOsnmaTeslaKeySizeResult>(keySize);
    }

    GetOsnmaTeslaKeySizeResultPtr GetOsnmaTeslaKeySizeResult::create(CommandBasePtr relatedCommand, int keySize)
    {
      return std::make_shared<GetOsnmaTeslaKeySizeResult>(relatedCommand, keySize);
    }

    GetOsnmaTeslaKeySizeResultPtr GetOsnmaTeslaKeySizeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetOsnmaTeslaKeySizeResult>(ptr);
    }

    bool GetOsnmaTeslaKeySizeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["KeySize"])
        ;

    }

    std::string GetOsnmaTeslaKeySizeResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetOsnmaTeslaKeySizeResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"KeySize"}; 
      return names; 
    }


    int GetOsnmaTeslaKeySizeResult::keySize() const
    {
      return parse_json<int>::parse(m_values["KeySize"]);
    }

    void GetOsnmaTeslaKeySizeResult::setKeySize(int keySize)
    {
      m_values.AddMember("KeySize", parse_json<int>::format(keySize, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
