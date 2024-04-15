
#include "GetMultipathForID.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMultipathForID
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMultipathForID::CmdName = "GetMultipathForID";
    const char* const GetMultipathForID::Documentation = "Get multipath infos for the specified multipath ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ --------------\n"
      "Id   string A multipath ID";
    const char* const GetMultipathForID::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMultipathForID);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMultipathForID);


    GetMultipathForID::GetMultipathForID()
      : CommandBase(CmdName, TargetId)
    {}

    GetMultipathForID::GetMultipathForID(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMultipathForIDPtr GetMultipathForID::create(const std::string& id)
    {
      return std::make_shared<GetMultipathForID>(id);
    }

    GetMultipathForIDPtr GetMultipathForID::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMultipathForID>(ptr);
    }

    bool GetMultipathForID::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMultipathForID::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMultipathForID::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMultipathForID::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMultipathForID::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMultipathForID::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
