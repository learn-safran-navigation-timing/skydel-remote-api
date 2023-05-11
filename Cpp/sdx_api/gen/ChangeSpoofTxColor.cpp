
#include "gen/ChangeSpoofTxColor.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ChangeSpoofTxColor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ChangeSpoofTxColor::CmdName = "ChangeSpoofTxColor";
    const char* const ChangeSpoofTxColor::Documentation = "Set a spoofer color in spectrums";

    REGISTER_COMMAND_FACTORY(ChangeSpoofTxColor);


    ChangeSpoofTxColor::ChangeSpoofTxColor()
      : CommandBase(CmdName)
    {}

    ChangeSpoofTxColor::ChangeSpoofTxColor(const std::string& color, const std::string& id)
      : CommandBase(CmdName)
    {

      setColor(color);
      setId(id);
    }

    ChangeSpoofTxColorPtr ChangeSpoofTxColor::create(const std::string& color, const std::string& id)
    {
      return std::make_shared<ChangeSpoofTxColor>(color, id);
    }

    ChangeSpoofTxColorPtr ChangeSpoofTxColor::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ChangeSpoofTxColor>(ptr);
    }

    bool ChangeSpoofTxColor::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Color"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string ChangeSpoofTxColor::documentation() const { return Documentation; }


    int ChangeSpoofTxColor::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ChangeSpoofTxColor::color() const
    {
      return parse_json<std::string>::parse(m_values["Color"]);
    }

    void ChangeSpoofTxColor::setColor(const std::string& color)
    {
      m_values.AddMember("Color", parse_json<std::string>::format(color, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ChangeSpoofTxColor::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ChangeSpoofTxColor::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
