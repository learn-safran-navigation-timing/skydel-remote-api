
#include "gen/RemoveWFElement.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(RemoveWFElement);


    RemoveWFElement::RemoveWFElement()
      : CommandBase(CmdName)
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


    int RemoveWFElement::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
