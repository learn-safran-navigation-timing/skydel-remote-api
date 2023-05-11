
#include "gen/GetIntTxCircular.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxCircular
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxCircular::CmdName = "GetIntTxCircular";
    const char* const GetIntTxCircular::Documentation = "Get interference transmitter circular trajectory";

    REGISTER_COMMAND_FACTORY(GetIntTxCircular);


    GetIntTxCircular::GetIntTxCircular()
      : CommandBase(CmdName)
    {}

    GetIntTxCircular::GetIntTxCircular(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetIntTxCircularPtr GetIntTxCircular::create(const std::string& id)
    {
      return std::make_shared<GetIntTxCircular>(id);
    }

    GetIntTxCircularPtr GetIntTxCircular::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxCircular>(ptr);
    }

    bool GetIntTxCircular::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxCircular::documentation() const { return Documentation; }


    int GetIntTxCircular::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxCircular::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxCircular::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
