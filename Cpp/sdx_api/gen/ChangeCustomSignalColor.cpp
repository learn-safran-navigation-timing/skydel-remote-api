
#include "ChangeCustomSignalColor.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ChangeCustomSignalColor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ChangeCustomSignalColor::CmdName = "ChangeCustomSignalColor";
    const char* const ChangeCustomSignalColor::Documentation = "Changes the custom signal color\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ -------------------------------------------------------------------------------\n"
      "Color string Color 'name'. Either a common color (red, white, ...) or an hex code (#FFFFFF).\n"
      "Id    string Custom signal ID";
    const char* const ChangeCustomSignalColor::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ChangeCustomSignalColor);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ChangeCustomSignalColor);


    ChangeCustomSignalColor::ChangeCustomSignalColor()
      : CommandBase(CmdName, TargetId)
    {}

    ChangeCustomSignalColor::ChangeCustomSignalColor(const std::string& color, const std::string& id)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& ChangeCustomSignalColor::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Color", "Id"}; 
      return names; 
    }


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
