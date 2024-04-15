
#include "GetMessageModificationToQzssSlas.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToQzssSlas
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToQzssSlas::CmdName = "GetMessageModificationToQzssSlas";
    const char* const GetMessageModificationToQzssSlas::Documentation = "Get infos about the QZSS SLAS message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToQzssSlas::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToQzssSlas);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToQzssSlas);


    GetMessageModificationToQzssSlas::GetMessageModificationToQzssSlas()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToQzssSlas::GetMessageModificationToQzssSlas(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToQzssSlasPtr GetMessageModificationToQzssSlas::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToQzssSlas>(id);
    }

    GetMessageModificationToQzssSlasPtr GetMessageModificationToQzssSlas::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToQzssSlas>(ptr);
    }

    bool GetMessageModificationToQzssSlas::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToQzssSlas::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToQzssSlas::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToQzssSlas::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToQzssSlas::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToQzssSlas::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
