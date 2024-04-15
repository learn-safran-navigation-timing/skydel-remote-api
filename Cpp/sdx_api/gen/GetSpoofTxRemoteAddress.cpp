
#include "GetSpoofTxRemoteAddress.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxRemoteAddress
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxRemoteAddress::CmdName = "GetSpoofTxRemoteAddress";
    const char* const GetSpoofTxRemoteAddress::Documentation = "Get the address of the spoofer instance that will\n"
      "generate the signal for this spoofer transmitter.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetSpoofTxRemoteAddress::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofTxRemoteAddress);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxRemoteAddress);


    GetSpoofTxRemoteAddress::GetSpoofTxRemoteAddress()
      : CommandBase(CmdName, TargetId)
    {}

    GetSpoofTxRemoteAddress::GetSpoofTxRemoteAddress(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetSpoofTxRemoteAddressPtr GetSpoofTxRemoteAddress::create(const std::string& id)
    {
      return std::make_shared<GetSpoofTxRemoteAddress>(id);
    }

    GetSpoofTxRemoteAddressPtr GetSpoofTxRemoteAddress::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxRemoteAddress>(ptr);
    }

    bool GetSpoofTxRemoteAddress::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxRemoteAddress::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxRemoteAddress::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetSpoofTxRemoteAddress::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSpoofTxRemoteAddress::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxRemoteAddress::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
