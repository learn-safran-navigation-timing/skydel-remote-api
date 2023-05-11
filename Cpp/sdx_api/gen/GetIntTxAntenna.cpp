
#include "gen/GetIntTxAntenna.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxAntenna
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxAntenna::CmdName = "GetIntTxAntenna";
    const char* const GetIntTxAntenna::Documentation = "Get transmitter antenna pattern.";

    REGISTER_COMMAND_FACTORY(GetIntTxAntenna);


    GetIntTxAntenna::GetIntTxAntenna()
      : CommandBase(CmdName)
    {}

    GetIntTxAntenna::GetIntTxAntenna(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetIntTxAntennaPtr GetIntTxAntenna::create(const std::string& id)
    {
      return std::make_shared<GetIntTxAntenna>(id);
    }

    GetIntTxAntennaPtr GetIntTxAntenna::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxAntenna>(ptr);
    }

    bool GetIntTxAntenna::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxAntenna::documentation() const { return Documentation; }


    int GetIntTxAntenna::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxAntenna::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxAntenna::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
