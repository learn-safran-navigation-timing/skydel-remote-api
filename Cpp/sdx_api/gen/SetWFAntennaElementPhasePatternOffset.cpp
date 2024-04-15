
#include "SetWFAntennaElementPhasePatternOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWFAntennaElementPhasePatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWFAntennaElementPhasePatternOffset::CmdName = "SetWFAntennaElementPhasePatternOffset";
    const char* const SetWFAntennaElementPhasePatternOffset::Documentation = "Please note the command SetWFAntennaElementPhasePatternOffset is deprecated since 23.11. You may use AddVehiclePhasePatternOffset.\n"
      "\n"
      "Set WF Antenna phase pattern offset (in rad) for this element\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -------------------------------------------------------------------------\n"
      "PhaseOffset double Antenna phase pattern offset (in rad) to set for this element. [-Pi ; Pi]\n"
      "Element     int    One-based index for element in antenna.";
    const char* const SetWFAntennaElementPhasePatternOffset::TargetId = "";

    const char* const SetWFAntennaElementPhasePatternOffset::Deprecated = "Please note the command SetWFAntennaElementPhasePatternOffset is deprecated since 23.11. You may use AddVehiclePhasePatternOffset.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetWFAntennaElementPhasePatternOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetWFAntennaElementPhasePatternOffset);


    SetWFAntennaElementPhasePatternOffset::SetWFAntennaElementPhasePatternOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetWFAntennaElementPhasePatternOffset::SetWFAntennaElementPhasePatternOffset(double phaseOffset, int element)
      : CommandBase(CmdName, TargetId)
    {

      setPhaseOffset(phaseOffset);
      setElement(element);
    }

    SetWFAntennaElementPhasePatternOffsetPtr SetWFAntennaElementPhasePatternOffset::create(double phaseOffset, int element)
    {
      return std::make_shared<SetWFAntennaElementPhasePatternOffset>(phaseOffset, element);
    }

    SetWFAntennaElementPhasePatternOffsetPtr SetWFAntennaElementPhasePatternOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetWFAntennaElementPhasePatternOffset>(ptr);
    }

    bool SetWFAntennaElementPhasePatternOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["PhaseOffset"])
          && parse_json<int>::is_valid(m_values["Element"])
        ;

    }

    std::string SetWFAntennaElementPhasePatternOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetWFAntennaElementPhasePatternOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"PhaseOffset", "Element"}; 
      return names; 
    }

    Sdx::optional<std::string> SetWFAntennaElementPhasePatternOffset::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetWFAntennaElementPhasePatternOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetWFAntennaElementPhasePatternOffset::phaseOffset() const
    {
      return parse_json<double>::parse(m_values["PhaseOffset"]);
    }

    void SetWFAntennaElementPhasePatternOffset::setPhaseOffset(double phaseOffset)
    {
      m_values.AddMember("PhaseOffset", parse_json<double>::format(phaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetWFAntennaElementPhasePatternOffset::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void SetWFAntennaElementPhasePatternOffset::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
