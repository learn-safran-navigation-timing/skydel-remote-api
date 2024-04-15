
#include "GetSpoofTxColor.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxColor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxColor::CmdName = "GetSpoofTxColor";
    const char* const GetSpoofTxColor::Documentation = "Get a spoofer color in spectrums\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetSpoofTxColor::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofTxColor);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxColor);


    GetSpoofTxColor::GetSpoofTxColor()
      : CommandBase(CmdName, TargetId)
    {}

    GetSpoofTxColor::GetSpoofTxColor(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetSpoofTxColorPtr GetSpoofTxColor::create(const std::string& id)
    {
      return std::make_shared<GetSpoofTxColor>(id);
    }

    GetSpoofTxColorPtr GetSpoofTxColor::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxColor>(ptr);
    }

    bool GetSpoofTxColor::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxColor::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxColor::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetSpoofTxColor::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSpoofTxColor::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxColor::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
