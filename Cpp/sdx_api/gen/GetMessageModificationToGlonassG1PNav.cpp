
#include "GetMessageModificationToGlonassG1PNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGlonassG1PNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGlonassG1PNav::CmdName = "GetMessageModificationToGlonassG1PNav";
    const char* const GetMessageModificationToGlonassG1PNav::Documentation = "Get infos about the GLONASS G1 P-Code message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToGlonassG1PNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToGlonassG1PNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToGlonassG1PNav);


    GetMessageModificationToGlonassG1PNav::GetMessageModificationToGlonassG1PNav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToGlonassG1PNav::GetMessageModificationToGlonassG1PNav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToGlonassG1PNavPtr GetMessageModificationToGlonassG1PNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGlonassG1PNav>(id);
    }

    GetMessageModificationToGlonassG1PNavPtr GetMessageModificationToGlonassG1PNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGlonassG1PNav>(ptr);
    }

    bool GetMessageModificationToGlonassG1PNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGlonassG1PNav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToGlonassG1PNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToGlonassG1PNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGlonassG1PNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGlonassG1PNav::setId(const std::string& id)
    {
      setValue("Id", parse_json<std::string>::format(id, m_values.GetAllocator()));
    }


  }
}
