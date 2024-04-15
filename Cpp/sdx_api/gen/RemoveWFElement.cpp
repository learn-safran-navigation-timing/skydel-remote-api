
#include "RemoveWFElement.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveWFElement
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveWFElement::CmdName = "RemoveWFElement";
    const char* const RemoveWFElement::Documentation = "Remove last Wavefront element.";
    const char* const RemoveWFElement::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveWFElement);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveWFElement);


    RemoveWFElement::RemoveWFElement()
      : CommandBase(CmdName, TargetId)
    {

    }

    RemoveWFElementPtr RemoveWFElement::create()
    {
      return std::make_shared<RemoveWFElement>();
    }

    RemoveWFElementPtr RemoveWFElement::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveWFElement>(ptr);
    }

    bool RemoveWFElement::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string RemoveWFElement::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveWFElement::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int RemoveWFElement::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
