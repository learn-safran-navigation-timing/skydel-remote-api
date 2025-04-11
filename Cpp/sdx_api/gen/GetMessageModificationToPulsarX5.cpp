
#include "GetMessageModificationToPulsarX5.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToPulsarX5
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToPulsarX5::CmdName = "GetMessageModificationToPulsarX5";
    const char* const GetMessageModificationToPulsarX5::Documentation = "Get infos about the PULSAR X5 message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToPulsarX5::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToPulsarX5);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToPulsarX5);


    GetMessageModificationToPulsarX5::GetMessageModificationToPulsarX5()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToPulsarX5::GetMessageModificationToPulsarX5(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToPulsarX5Ptr GetMessageModificationToPulsarX5::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToPulsarX5>(id);
    }

    GetMessageModificationToPulsarX5Ptr GetMessageModificationToPulsarX5::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToPulsarX5>(ptr);
    }

    bool GetMessageModificationToPulsarX5::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToPulsarX5::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToPulsarX5::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToPulsarX5::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToPulsarX5::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToPulsarX5::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
