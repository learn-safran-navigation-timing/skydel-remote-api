
#include "GetMessageModificationToGlonassG2PNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGlonassG2PNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGlonassG2PNav::CmdName = "GetMessageModificationToGlonassG2PNav";
    const char* const GetMessageModificationToGlonassG2PNav::Documentation = "Get infos about the GLONASS G2 P-Code message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToGlonassG2PNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToGlonassG2PNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToGlonassG2PNav);


    GetMessageModificationToGlonassG2PNav::GetMessageModificationToGlonassG2PNav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToGlonassG2PNav::GetMessageModificationToGlonassG2PNav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToGlonassG2PNavPtr GetMessageModificationToGlonassG2PNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGlonassG2PNav>(id);
    }

    GetMessageModificationToGlonassG2PNavPtr GetMessageModificationToGlonassG2PNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGlonassG2PNav>(ptr);
    }

    bool GetMessageModificationToGlonassG2PNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGlonassG2PNav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToGlonassG2PNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToGlonassG2PNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGlonassG2PNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGlonassG2PNav::setId(const std::string& id)
    {
      setValue("Id", parse_json<std::string>::format(id, m_values.GetAllocator()));
    }


  }
}
