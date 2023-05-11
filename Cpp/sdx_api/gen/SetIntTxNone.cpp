
#include "gen/SetIntTxNone.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxNone
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxNone::CmdName = "SetIntTxNone";
    const char* const SetIntTxNone::Documentation = "Set an undefined trajectory to a transmitter, thus preventing it to be modulated (default value).";

    REGISTER_COMMAND_FACTORY(SetIntTxNone);


    SetIntTxNone::SetIntTxNone()
      : CommandBase(CmdName)
    {}

    SetIntTxNone::SetIntTxNone(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    SetIntTxNonePtr SetIntTxNone::create(const std::string& id)
    {
      return std::make_shared<SetIntTxNone>(id);
    }

    SetIntTxNonePtr SetIntTxNone::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxNone>(ptr);
    }

    bool SetIntTxNone::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxNone::documentation() const { return Documentation; }


    int SetIntTxNone::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string SetIntTxNone::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxNone::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
