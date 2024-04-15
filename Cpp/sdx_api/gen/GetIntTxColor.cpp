
#include "GetIntTxColor.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxColor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxColor::CmdName = "GetIntTxColor";
    const char* const GetIntTxColor::Documentation = "Get a transmitter color in spectrums\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetIntTxColor::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxColor);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxColor);


    GetIntTxColor::GetIntTxColor()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxColor::GetIntTxColor(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetIntTxColorPtr GetIntTxColor::create(const std::string& id)
    {
      return std::make_shared<GetIntTxColor>(id);
    }

    GetIntTxColorPtr GetIntTxColor::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxColor>(ptr);
    }

    bool GetIntTxColor::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxColor::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxColor::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetIntTxColor::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxColor::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxColor::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
