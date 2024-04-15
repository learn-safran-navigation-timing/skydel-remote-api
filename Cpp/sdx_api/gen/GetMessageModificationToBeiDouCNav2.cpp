
#include "GetMessageModificationToBeiDouCNav2.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToBeiDouCNav2
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToBeiDouCNav2::CmdName = "GetMessageModificationToBeiDouCNav2";
    const char* const GetMessageModificationToBeiDouCNav2::Documentation = "Get infos about the BeiDou CNAV2 message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToBeiDouCNav2::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToBeiDouCNav2);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToBeiDouCNav2);


    GetMessageModificationToBeiDouCNav2::GetMessageModificationToBeiDouCNav2()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToBeiDouCNav2::GetMessageModificationToBeiDouCNav2(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToBeiDouCNav2Ptr GetMessageModificationToBeiDouCNav2::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouCNav2>(id);
    }

    GetMessageModificationToBeiDouCNav2Ptr GetMessageModificationToBeiDouCNav2::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToBeiDouCNav2>(ptr);
    }

    bool GetMessageModificationToBeiDouCNav2::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToBeiDouCNav2::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToBeiDouCNav2::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToBeiDouCNav2::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToBeiDouCNav2::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToBeiDouCNav2::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
