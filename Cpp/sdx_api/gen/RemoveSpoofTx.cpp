
#include "gen/RemoveSpoofTx.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveSpoofTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveSpoofTx::CmdName = "RemoveSpoofTx";
    const char* const RemoveSpoofTx::Documentation = "Removes the spoofer transmitter. See EnableSpoofTx if all you want is to\ndisable the interference temporarily.";

    REGISTER_COMMAND_FACTORY(RemoveSpoofTx);


    RemoveSpoofTx::RemoveSpoofTx()
      : CommandBase(CmdName)
    {}

    RemoveSpoofTx::RemoveSpoofTx(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    RemoveSpoofTxPtr RemoveSpoofTx::create(const std::string& id)
    {
      return std::make_shared<RemoveSpoofTx>(id);
    }

    RemoveSpoofTxPtr RemoveSpoofTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveSpoofTx>(ptr);
    }

    bool RemoveSpoofTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveSpoofTx::documentation() const { return Documentation; }


    int RemoveSpoofTx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveSpoofTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveSpoofTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
