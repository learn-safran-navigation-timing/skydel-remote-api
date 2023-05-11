
#include "gen/GetIntTxColor.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxColor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxColor::CmdName = "GetIntTxColor";
    const char* const GetIntTxColor::Documentation = "Get a transmitter color in spectrums";

    REGISTER_COMMAND_FACTORY(GetIntTxColor);


    GetIntTxColor::GetIntTxColor()
      : CommandBase(CmdName)
    {}

    GetIntTxColor::GetIntTxColor(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    GetIntTxColorPtr GetIntTxColor::create(const std::string& id)
    {
      return std::make_shared<GetIntTxColor>(id);
    }

    GetIntTxColorPtr GetIntTxColor::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxColor>(ptr);
    }

    bool GetIntTxColor::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxColor::documentation() const { return Documentation; }


    int GetIntTxColor::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxColor::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxColor::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
