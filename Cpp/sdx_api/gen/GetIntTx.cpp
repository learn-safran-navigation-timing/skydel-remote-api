
#include "gen/GetIntTx.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTx::CmdName = "GetIntTx";
    const char* const GetIntTx::Documentation = "Get an interference transmitter.";

    REGISTER_COMMAND_FACTORY(GetIntTx);


    GetIntTx::GetIntTx()
      : CommandBase(CmdName)
    {}

    GetIntTx::GetIntTx(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetIntTxPtr GetIntTx::create(const std::string& id)
    {
      return std::make_shared<GetIntTx>(id);
    }

    GetIntTxPtr GetIntTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTx>(ptr);
    }

    bool GetIntTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTx::documentation() const { return Documentation; }


    int GetIntTx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
