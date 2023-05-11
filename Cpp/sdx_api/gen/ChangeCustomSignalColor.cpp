
#include "gen/ChangeCustomSignalColor.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ChangeCustomSignalColor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ChangeCustomSignalColor::CmdName = "ChangeCustomSignalColor";
    const char* const ChangeCustomSignalColor::Documentation = "Changes the custom signal color";

    REGISTER_COMMAND_FACTORY(ChangeCustomSignalColor);


    ChangeCustomSignalColor::ChangeCustomSignalColor()
      : CommandBase(CmdName)
    {}

    ChangeCustomSignalColor::ChangeCustomSignalColor(const std::string& color, const std::string& id)
      : CommandBase(CmdName)
    {

      setColor(color);
      setId(id);
    }

    ChangeCustomSignalColorPtr ChangeCustomSignalColor::create(const std::string& color, const std::string& id)
    {
      return std::make_shared<ChangeCustomSignalColor>(color, id);
    }

    ChangeCustomSignalColorPtr ChangeCustomSignalColor::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ChangeCustomSignalColor>(ptr);
    }

    bool ChangeCustomSignalColor::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Color"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string ChangeCustomSignalColor::documentation() const { return Documentation; }


    int ChangeCustomSignalColor::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ChangeCustomSignalColor::color() const
    {
      return parse_json<std::string>::parse(m_values["Color"]);
    }

    void ChangeCustomSignalColor::setColor(const std::string& color)
    {
      m_values.AddMember("Color", parse_json<std::string>::format(color, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ChangeCustomSignalColor::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ChangeCustomSignalColor::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
