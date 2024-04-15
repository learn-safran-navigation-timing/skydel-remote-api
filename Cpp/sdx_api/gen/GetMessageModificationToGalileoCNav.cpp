
#include "GetMessageModificationToGalileoCNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGalileoCNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGalileoCNav::CmdName = "GetMessageModificationToGalileoCNav";
    const char* const GetMessageModificationToGalileoCNav::Documentation = "Get infos about the Galileo C/NAV message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToGalileoCNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToGalileoCNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToGalileoCNav);


    GetMessageModificationToGalileoCNav::GetMessageModificationToGalileoCNav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToGalileoCNav::GetMessageModificationToGalileoCNav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToGalileoCNavPtr GetMessageModificationToGalileoCNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGalileoCNav>(id);
    }

    GetMessageModificationToGalileoCNavPtr GetMessageModificationToGalileoCNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGalileoCNav>(ptr);
    }

    bool GetMessageModificationToGalileoCNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGalileoCNav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToGalileoCNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToGalileoCNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGalileoCNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGalileoCNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
