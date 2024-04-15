
#include "SetOsnmaTeslaKeySize.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetOsnmaTeslaKeySize
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetOsnmaTeslaKeySize::CmdName = "SetOsnmaTeslaKeySize";
    const char* const SetOsnmaTeslaKeySize::Documentation = "Set OSNMA TESLA key size.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------------------------------------\n"
      "KeySize int  TESLA key size in bits. Accepted key sizes are: 96, 104, 112, 120, 128, 160, 192, 224 and 256.\n"
      "             Note: Only 128, 192 and 256 bits keys can be be used with CMAC-AES.";
    const char* const SetOsnmaTeslaKeySize::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetOsnmaTeslaKeySize);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetOsnmaTeslaKeySize);


    SetOsnmaTeslaKeySize::SetOsnmaTeslaKeySize()
      : CommandBase(CmdName, TargetId)
    {}

    SetOsnmaTeslaKeySize::SetOsnmaTeslaKeySize(int keySize)
      : CommandBase(CmdName, TargetId)
    {

      setKeySize(keySize);
    }

    SetOsnmaTeslaKeySizePtr SetOsnmaTeslaKeySize::create(int keySize)
    {
      return std::make_shared<SetOsnmaTeslaKeySize>(keySize);
    }

    SetOsnmaTeslaKeySizePtr SetOsnmaTeslaKeySize::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetOsnmaTeslaKeySize>(ptr);
    }

    bool SetOsnmaTeslaKeySize::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["KeySize"])
        ;

    }

    std::string SetOsnmaTeslaKeySize::documentation() const { return Documentation; }

    const std::vector<std::string>& SetOsnmaTeslaKeySize::fieldNames() const 
    { 
      static const std::vector<std::string> names {"KeySize"}; 
      return names; 
    }


    int SetOsnmaTeslaKeySize::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetOsnmaTeslaKeySize::keySize() const
    {
      return parse_json<int>::parse(m_values["KeySize"]);
    }

    void SetOsnmaTeslaKeySize::setKeySize(int keySize)
    {
      m_values.AddMember("KeySize", parse_json<int>::format(keySize, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
