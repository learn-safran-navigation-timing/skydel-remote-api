
#include "GetMessageModificationToGalileoINav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGalileoINav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGalileoINav::CmdName = "GetMessageModificationToGalileoINav";
    const char* const GetMessageModificationToGalileoINav::Documentation = "Get infos about the Galileo I/NAV message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToGalileoINav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToGalileoINav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToGalileoINav);


    GetMessageModificationToGalileoINav::GetMessageModificationToGalileoINav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToGalileoINav::GetMessageModificationToGalileoINav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToGalileoINavPtr GetMessageModificationToGalileoINav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGalileoINav>(id);
    }

    GetMessageModificationToGalileoINavPtr GetMessageModificationToGalileoINav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGalileoINav>(ptr);
    }

    bool GetMessageModificationToGalileoINav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGalileoINav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToGalileoINav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToGalileoINav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGalileoINav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGalileoINav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
