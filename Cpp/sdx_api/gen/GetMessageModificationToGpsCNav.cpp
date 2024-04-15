
#include "GetMessageModificationToGpsCNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGpsCNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGpsCNav::CmdName = "GetMessageModificationToGpsCNav";
    const char* const GetMessageModificationToGpsCNav::Documentation = "Get infos about the GPS CNAV message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToGpsCNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToGpsCNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToGpsCNav);


    GetMessageModificationToGpsCNav::GetMessageModificationToGpsCNav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToGpsCNav::GetMessageModificationToGpsCNav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToGpsCNavPtr GetMessageModificationToGpsCNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGpsCNav>(id);
    }

    GetMessageModificationToGpsCNavPtr GetMessageModificationToGpsCNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGpsCNav>(ptr);
    }

    bool GetMessageModificationToGpsCNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGpsCNav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToGpsCNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToGpsCNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGpsCNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGpsCNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
