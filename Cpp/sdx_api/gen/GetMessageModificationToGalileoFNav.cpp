
#include "GetMessageModificationToGalileoFNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGalileoFNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGalileoFNav::CmdName = "GetMessageModificationToGalileoFNav";
    const char* const GetMessageModificationToGalileoFNav::Documentation = "Get infos about the Galileo F/NAV message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToGalileoFNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToGalileoFNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToGalileoFNav);


    GetMessageModificationToGalileoFNav::GetMessageModificationToGalileoFNav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToGalileoFNav::GetMessageModificationToGalileoFNav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToGalileoFNavPtr GetMessageModificationToGalileoFNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGalileoFNav>(id);
    }

    GetMessageModificationToGalileoFNavPtr GetMessageModificationToGalileoFNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGalileoFNav>(ptr);
    }

    bool GetMessageModificationToGalileoFNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGalileoFNav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToGalileoFNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToGalileoFNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGalileoFNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGalileoFNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
