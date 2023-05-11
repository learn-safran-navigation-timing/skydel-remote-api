
#include "gen/GetMessageModificationToGpsCNav2.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGpsCNav2
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGpsCNav2::CmdName = "GetMessageModificationToGpsCNav2";
    const char* const GetMessageModificationToGpsCNav2::Documentation = "Get infos about the GPS CNAV-2 message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToGpsCNav2);


    GetMessageModificationToGpsCNav2::GetMessageModificationToGpsCNav2()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToGpsCNav2::GetMessageModificationToGpsCNav2(const std::string& id)
      : CommandBase(CmdName)
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
