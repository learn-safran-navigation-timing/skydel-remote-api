
#include "gen/GetMessageModificationToBeiDouCNav2.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToBeiDouCNav2
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToBeiDouCNav2::CmdName = "GetMessageModificationToBeiDouCNav2";
    const char* const GetMessageModificationToBeiDouCNav2::Documentation = "Get infos about the BeiDou CNAV2 message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToBeiDouCNav2);


    GetMessageModificationToBeiDouCNav2::GetMessageModificationToBeiDouCNav2()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToBeiDouCNav2::GetMessageModificationToBeiDouCNav2(const std::string& id)
      : CommandBase(CmdName)
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
