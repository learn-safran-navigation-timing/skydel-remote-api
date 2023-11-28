
#include "gen/GetWFElement.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFElement
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFElement::CmdName = "GetWFElement";
    const char* const GetWFElement::Documentation = "Get Wavefront element properties. Properties define if an element is enabled/disabled, and the associated antenna.";

    REGISTER_COMMAND_FACTORY(GetWFElement);


    GetWFElement::GetWFElement()
      : CommandBase(CmdName)
    {}

    GetWFElement::GetWFElement(int element)
      : CommandBase(CmdName)
    {

      setElement(element);
    }

    GetWFElementPtr GetWFElement::create(int element)
    {
      return std::make_shared<GetWFElement>(element);
    }

    GetWFElementPtr GetWFElement::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFElement>(ptr);
    }

    bool GetWFElement::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Element"])
        ;

    }

    std::string GetWFElement::documentation() const { return Documentation; }


    int GetWFElement::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetWFElement::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void GetWFElement::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
