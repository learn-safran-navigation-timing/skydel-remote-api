
#include "SetWFElement.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWFElement
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWFElement::CmdName = "SetWFElement";
    const char* const SetWFElement::Documentation = "Set Wavefront element properties. Properties define if an element is enabled/disabled, and the associated antenna.\n"
      "\n"
      "Name             Type   Description\n"
      "---------------- ------ -------------------------------------------------------------------------------------------------\n"
      "Element          int    One-based index of the element. Value -1 adds a new element at the end of the list.\n"
      "Enabled          bool   If True, this antenna element will be simulated.\n"
      "AntennaModelName string Antenna Model name for this element. Antenna models can be defined in Vehicle Antenna Model menu.";
    const char* const SetWFElement::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetWFElement);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetWFElement);


    SetWFElement::SetWFElement()
      : CommandBase(CmdName, TargetId)
    {}

    SetWFElement::SetWFElement(int element, bool enabled, const std::string& antennaModelName)
      : CommandBase(CmdName, TargetId)
    {

      setElement(element);
      setEnabled(enabled);
      setAntennaModelName(antennaModelName);
    }

    SetWFElementPtr SetWFElement::create(int element, bool enabled, const std::string& antennaModelName)
    {
      return std::make_shared<SetWFElement>(element, enabled, antennaModelName);
    }

    SetWFElementPtr SetWFElement::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetWFElement>(ptr);
    }

    bool SetWFElement::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Element"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["AntennaModelName"])
        ;

    }

    std::string SetWFElement::documentation() const { return Documentation; }

    const std::vector<std::string>& SetWFElement::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Element", "Enabled", "AntennaModelName"}; 
      return names; 
    }


    int SetWFElement::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetWFElement::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void SetWFElement::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetWFElement::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetWFElement::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetWFElement::antennaModelName() const
    {
      return parse_json<std::string>::parse(m_values["AntennaModelName"]);
    }

    void SetWFElement::setAntennaModelName(const std::string& antennaModelName)
    {
      m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
