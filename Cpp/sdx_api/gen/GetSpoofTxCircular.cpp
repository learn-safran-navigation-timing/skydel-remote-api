
#include "gen/GetSpoofTxCircular.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxCircular
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxCircular::CmdName = "GetSpoofTxCircular";
    const char* const GetSpoofTxCircular::Documentation = "Get spoofer transmitter circular trajectory";

    REGISTER_COMMAND_FACTORY(GetSpoofTxCircular);


    GetSpoofTxCircular::GetSpoofTxCircular()
      : CommandBase(CmdName)
    {}

    GetSpoofTxCircular::GetSpoofTxCircular(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetSpoofTxCircularPtr GetSpoofTxCircular::create(const std::string& id)
    {
      return std::make_shared<GetSpoofTxCircular>(id);
    }

    GetSpoofTxCircularPtr GetSpoofTxCircular::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxCircular>(ptr);
    }

    bool GetSpoofTxCircular::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxCircular::documentation() const { return Documentation; }


    int GetSpoofTxCircular::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSpoofTxCircular::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxCircular::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
