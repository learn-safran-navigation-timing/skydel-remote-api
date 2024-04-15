
#include "SetWFAntennaElementModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWFAntennaElementModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWFAntennaElementModel::CmdName = "SetWFAntennaElementModel";
    const char* const SetWFAntennaElementModel::Documentation = "Please note the command SetWFAntennaElementModel is deprecated since 23.11. You may use SetWFElement.\n"
      "\n"
      "Set WF Antenna model for this element\n"
      "\n"
      "Name             Type   Description\n"
      "---------------- ------ ----------------------------------------------------------------------------------------------------\n"
      "AntennaModelName string Antenna Model name to set for this element. Antenna models must be defined in vehicle antenna model.\n"
      "Element          int    One-based index for element in antenna.";
    const char* const SetWFAntennaElementModel::TargetId = "";

    const char* const SetWFAntennaElementModel::Deprecated = "Please note the command SetWFAntennaElementModel is deprecated since 23.11. You may use SetWFElement.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetWFAntennaElementModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetWFAntennaElementModel);


    SetWFAntennaElementModel::SetWFAntennaElementModel()
      : CommandBase(CmdName, TargetId)
    {}

    SetWFAntennaElementModel::SetWFAntennaElementModel(const std::string& antennaModelName, int element)
      : CommandBase(CmdName, TargetId)
    {

      setAntennaModelName(antennaModelName);
      setElement(element);
    }

    SetWFAntennaElementModelPtr SetWFAntennaElementModel::create(const std::string& antennaModelName, int element)
    {
      return std::make_shared<SetWFAntennaElementModel>(antennaModelName, element);
    }

    SetWFAntennaElementModelPtr SetWFAntennaElementModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetWFAntennaElementModel>(ptr);
    }

    bool SetWFAntennaElementModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["AntennaModelName"])
          && parse_json<int>::is_valid(m_values["Element"])
        ;

    }

    std::string SetWFAntennaElementModel::documentation() const { return Documentation; }

    const std::vector<std::string>& SetWFAntennaElementModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"AntennaModelName", "Element"}; 
      return names; 
    }

    Sdx::optional<std::string> SetWFAntennaElementModel::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetWFAntennaElementModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetWFAntennaElementModel::antennaModelName() const
    {
      return parse_json<std::string>::parse(m_values["AntennaModelName"]);
    }

    void SetWFAntennaElementModel::setAntennaModelName(const std::string& antennaModelName)
    {
      m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetWFAntennaElementModel::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void SetWFAntennaElementModel::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
