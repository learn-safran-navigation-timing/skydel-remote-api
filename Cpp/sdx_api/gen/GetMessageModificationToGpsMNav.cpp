
#include "GetMessageModificationToGpsMNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGpsMNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGpsMNav::CmdName = "GetMessageModificationToGpsMNav";
    const char* const GetMessageModificationToGpsMNav::Documentation = "Get infos about the GPS MNAV message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------------------------\n"
      "Id   string Unique identifier automatically set by simulator";
    const char* const GetMessageModificationToGpsMNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToGpsMNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToGpsMNav);


    GetMessageModificationToGpsMNav::GetMessageModificationToGpsMNav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToGpsMNav::GetMessageModificationToGpsMNav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToGpsMNavPtr GetMessageModificationToGpsMNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGpsMNav>(id);
    }

    GetMessageModificationToGpsMNavPtr GetMessageModificationToGpsMNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGpsMNav>(ptr);
    }

    bool GetMessageModificationToGpsMNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGpsMNav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToGpsMNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToGpsMNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGpsMNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGpsMNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
