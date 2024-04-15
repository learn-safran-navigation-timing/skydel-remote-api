
#include "GetMessageModificationToGpsCNav2.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGpsCNav2
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGpsCNav2::CmdName = "GetMessageModificationToGpsCNav2";
    const char* const GetMessageModificationToGpsCNav2::Documentation = "Get infos about the GPS CNAV-2 message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToGpsCNav2::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToGpsCNav2);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToGpsCNav2);


    GetMessageModificationToGpsCNav2::GetMessageModificationToGpsCNav2()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToGpsCNav2::GetMessageModificationToGpsCNav2(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToGpsCNav2Ptr GetMessageModificationToGpsCNav2::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGpsCNav2>(id);
    }

    GetMessageModificationToGpsCNav2Ptr GetMessageModificationToGpsCNav2::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGpsCNav2>(ptr);
    }

    bool GetMessageModificationToGpsCNav2::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGpsCNav2::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToGpsCNav2::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToGpsCNav2::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGpsCNav2::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGpsCNav2::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
