
#include "gen/SetWFAntennaElementModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWFAntennaElementModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWFAntennaElementModel::CmdName = "SetWFAntennaElementModel";
    const char* const SetWFAntennaElementModel::Documentation = "Set WF Antenna model for this element";

    REGISTER_COMMAND_FACTORY(SetWFAntennaElementModel);


    SetWFAntennaElementModel::SetWFAntennaElementModel()
      : CommandBase(CmdName)
    {}

    SetWFAntennaElementModel::SetWFAntennaElementModel(const std::string& antennaModelName, int element)
      : CommandBase(CmdName)
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
