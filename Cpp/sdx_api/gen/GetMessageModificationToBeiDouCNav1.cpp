
#include "GetMessageModificationToBeiDouCNav1.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToBeiDouCNav1
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToBeiDouCNav1::CmdName = "GetMessageModificationToBeiDouCNav1";
    const char* const GetMessageModificationToBeiDouCNav1::Documentation = "Get infos about the BeiDou CNAV1 message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToBeiDouCNav1::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToBeiDouCNav1);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToBeiDouCNav1);


    GetMessageModificationToBeiDouCNav1::GetMessageModificationToBeiDouCNav1()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToBeiDouCNav1::GetMessageModificationToBeiDouCNav1(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToBeiDouCNav1Ptr GetMessageModificationToBeiDouCNav1::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouCNav1>(id);
    }

    GetMessageModificationToBeiDouCNav1Ptr GetMessageModificationToBeiDouCNav1::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToBeiDouCNav1>(ptr);
    }

    bool GetMessageModificationToBeiDouCNav1::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToBeiDouCNav1::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToBeiDouCNav1::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToBeiDouCNav1::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToBeiDouCNav1::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToBeiDouCNav1::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
