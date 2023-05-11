
#include "gen/RenameIntTx.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RenameIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RenameIntTx::CmdName = "RenameIntTx";
    const char* const RenameIntTx::Documentation = "Rename a transmitter.";

    REGISTER_COMMAND_FACTORY(RenameIntTx);


    RenameIntTx::RenameIntTx()
      : CommandBase(CmdName)
    {}

    RenameIntTx::RenameIntTx(const std::string& usualName, const std::string& id)
      : CommandBase(CmdName)
    {

      setUsualName(usualName);
      setId(id);
    }

    RenameIntTxPtr RenameIntTx::create(const std::string& usualName, const std::string& id)
    {
      return std::make_shared<RenameIntTx>(usualName, id);
    }

    RenameIntTxPtr RenameIntTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RenameIntTx>(ptr);
    }

    bool RenameIntTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["UsualName"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RenameIntTx::documentation() const { return Documentation; }


    int RenameIntTx::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string RenameIntTx::usualName() const
    {
      return parse_json<std::string>::parse(m_values["UsualName"]);
    }

    void RenameIntTx::setUsualName(const std::string& usualName)
    {
      m_values.AddMember("UsualName", parse_json<std::string>::format(usualName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RenameIntTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RenameIntTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
