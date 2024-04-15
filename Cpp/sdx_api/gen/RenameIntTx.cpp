
#include "RenameIntTx.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RenameIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RenameIntTx::CmdName = "RenameIntTx";
    const char* const RenameIntTx::Documentation = "Rename a transmitter.\n"
      "\n"
      "Name      Type   Description\n"
      "--------- ------ -------------------------------\n"
      "UsualName string Usual name for the transmitter.\n"
      "Id        string Transmitter unique identifier.";
    const char* const RenameIntTx::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RenameIntTx);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RenameIntTx);


    RenameIntTx::RenameIntTx()
      : CommandBase(CmdName, TargetId)
    {}

    RenameIntTx::RenameIntTx(const std::string& usualName, const std::string& id)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& RenameIntTx::fieldNames() const 
    { 
      static const std::vector<std::string> names {"UsualName", "Id"}; 
      return names; 
    }


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
