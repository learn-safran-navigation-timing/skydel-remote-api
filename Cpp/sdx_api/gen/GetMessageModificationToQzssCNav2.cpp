
#include "gen/GetMessageModificationToQzssCNav2.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToQzssCNav2
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToQzssCNav2::CmdName = "GetMessageModificationToQzssCNav2";
    const char* const GetMessageModificationToQzssCNav2::Documentation = "Get infos about the QZSS CNAV2 message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToQzssCNav2);


    GetMessageModificationToQzssCNav2::GetMessageModificationToQzssCNav2()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToQzssCNav2::GetMessageModificationToQzssCNav2(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetMessageModificationToQzssCNav2Ptr GetMessageModificationToQzssCNav2::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToQzssCNav2>(id);
    }

    GetMessageModificationToQzssCNav2Ptr GetMessageModificationToQzssCNav2::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToQzssCNav2>(ptr);
    }

    bool GetMessageModificationToQzssCNav2::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToQzssCNav2::documentation() const { return Documentation; }


    int GetMessageModificationToQzssCNav2::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToQzssCNav2::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToQzssCNav2::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
