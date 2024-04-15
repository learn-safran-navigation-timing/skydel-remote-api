
#include "GetSpoofTxAntenna.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxAntenna
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxAntenna::CmdName = "GetSpoofTxAntenna";
    const char* const GetSpoofTxAntenna::Documentation = "Get transmitter antenna pattern.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetSpoofTxAntenna::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofTxAntenna);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxAntenna);


    GetSpoofTxAntenna::GetSpoofTxAntenna()
      : CommandBase(CmdName, TargetId)
    {}

    GetSpoofTxAntenna::GetSpoofTxAntenna(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetSpoofTxAntennaPtr GetSpoofTxAntenna::create(const std::string& id)
    {
      return std::make_shared<GetSpoofTxAntenna>(id);
    }

    GetSpoofTxAntennaPtr GetSpoofTxAntenna::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxAntenna>(ptr);
    }

    bool GetSpoofTxAntenna::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxAntenna::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxAntenna::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetSpoofTxAntenna::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSpoofTxAntenna::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxAntenna::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
