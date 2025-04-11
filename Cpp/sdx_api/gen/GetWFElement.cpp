
#include "GetWFElement.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFElement
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFElement::CmdName = "GetWFElement";
    const char* const GetWFElement::Documentation = "Get the Wavefront element properties.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -----------------------------------------------------------------------------------\n"
      "Element int  One-based index of the element. Value -1 adds a new element at the end of the list.";
    const char* const GetWFElement::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetWFElement);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetWFElement);


    GetWFElement::GetWFElement()
      : CommandBase(CmdName, TargetId)
    {}

    GetWFElement::GetWFElement(int element)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetWFElement::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Element"}; 
      return names; 
    }


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
