
#include "GetMessageModificationToPulsarX1.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToPulsarX1
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToPulsarX1::CmdName = "GetMessageModificationToPulsarX1";
    const char* const GetMessageModificationToPulsarX1::Documentation = "Get infos about the PULSAR X1 message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToPulsarX1::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToPulsarX1);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToPulsarX1);


    GetMessageModificationToPulsarX1::GetMessageModificationToPulsarX1()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToPulsarX1::GetMessageModificationToPulsarX1(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToPulsarX1Ptr GetMessageModificationToPulsarX1::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToPulsarX1>(id);
    }

    GetMessageModificationToPulsarX1Ptr GetMessageModificationToPulsarX1::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToPulsarX1>(ptr);
    }

    bool GetMessageModificationToPulsarX1::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToPulsarX1::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToPulsarX1::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToPulsarX1::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToPulsarX1::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToPulsarX1::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
