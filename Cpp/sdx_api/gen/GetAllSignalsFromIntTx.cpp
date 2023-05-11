
#include "gen/GetAllSignalsFromIntTx.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllSignalsFromIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllSignalsFromIntTx::CmdName = "GetAllSignalsFromIntTx";
    const char* const GetAllSignalsFromIntTx::Documentation = "Get all signal ID for this interference transmitters.";

    REGISTER_COMMAND_FACTORY(GetAllSignalsFromIntTx);


    GetAllSignalsFromIntTx::GetAllSignalsFromIntTx()
      : CommandBase(CmdName)
    {}

    GetAllSignalsFromIntTx::GetAllSignalsFromIntTx(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetAllSignalsFromIntTxPtr GetAllSignalsFromIntTx::create(const std::string& id)
    {
      return std::make_shared<GetAllSignalsFromIntTx>(id);
    }

    GetAllSignalsFromIntTxPtr GetAllSignalsFromIntTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllSignalsFromIntTx>(ptr);
    }

    bool GetAllSignalsFromIntTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetAllSignalsFromIntTx::documentation() const { return Documentation; }


    int GetAllSignalsFromIntTx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllSignalsFromIntTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetAllSignalsFromIntTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
