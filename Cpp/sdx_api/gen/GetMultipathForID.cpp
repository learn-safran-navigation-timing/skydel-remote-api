
#include "gen/GetMultipathForID.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMultipathForID
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMultipathForID::CmdName = "GetMultipathForID";
    const char* const GetMultipathForID::Documentation = "Get multipath infos for the specified multipath ID.";

    REGISTER_COMMAND_FACTORY(GetMultipathForID);


    GetMultipathForID::GetMultipathForID()
      : CommandBase(CmdName)
    {}

    GetMultipathForID::GetMultipathForID(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetMultipathForIDPtr GetMultipathForID::create(const std::string& id)
    {
      return std::make_shared<GetMultipathForID>(id);
    }

    GetMultipathForIDPtr GetMultipathForID::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMultipathForID>(ptr);
    }

    bool GetMultipathForID::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMultipathForID::documentation() const { return Documentation; }


    int GetMultipathForID::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMultipathForID::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMultipathForID::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
