
#include "gen/RenameSpoofTx.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RenameSpoofTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RenameSpoofTx::CmdName = "RenameSpoofTx";
    const char* const RenameSpoofTx::Documentation = "Rename a spoofer.";

    REGISTER_COMMAND_FACTORY(RenameSpoofTx);


    RenameSpoofTx::RenameSpoofTx()
      : CommandBase(CmdName)
    {}

    RenameSpoofTx::RenameSpoofTx(const std::string& usualName, const std::string& id)
      : CommandBase(CmdName)
    {

      setUsualName(usualName);
      setId(id);
    }

    RenameSpoofTxPtr RenameSpoofTx::create(const std::string& usualName, const std::string& id)
    {
      return std::make_shared<RenameSpoofTx>(usualName, id);
    }

    RenameSpoofTxPtr RenameSpoofTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RenameSpoofTx>(ptr);
    }

    bool RenameSpoofTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["UsualName"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RenameSpoofTx::documentation() const { return Documentation; }


    int RenameSpoofTx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RenameSpoofTx::usualName() const
    {
      return parse_json<std::string>::parse(m_values["UsualName"]);
    }

    void RenameSpoofTx::setUsualName(const std::string& usualName)
    {
      m_values.AddMember("UsualName", parse_json<std::string>::format(usualName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RenameSpoofTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RenameSpoofTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
