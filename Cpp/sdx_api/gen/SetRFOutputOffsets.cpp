
#include "SetRFOutputOffsets.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetRFOutputOffsets
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetRFOutputOffsets::CmdName = "SetRFOutputOffsets";
    const char* const SetRFOutputOffsets::Documentation = "Change modulation offsets of one RF output\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ----------------------------------------------------------------\n"
      "OutputIdx   int             RF Output index (zero-based)\n"
      "PowerOffset double          Power offset (dB), to apply on all signals of the RF Output\n"
      "TimeOffset  double          Time offset (seconds), to apply on all signals of the RF Output\n"
      "PhaseOffset double          Phase offset (radians), to apply on all signals of the RF Output\n"
      "PhaseStep   optional double How much the phase (radians) should change per millisecond";
    const char* const SetRFOutputOffsets::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetRFOutputOffsets);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetRFOutputOffsets);


    SetRFOutputOffsets::SetRFOutputOffsets()
      : CommandBase(CmdName, TargetId)
    {}

    SetRFOutputOffsets::SetRFOutputOffsets(int outputIdx, double powerOffset, double timeOffset, double phaseOffset, const std::optional<double>& phaseStep)
      : CommandBase(CmdName, TargetId)
    {

      setOutputIdx(outputIdx);
      setPowerOffset(powerOffset);
      setTimeOffset(timeOffset);
      setPhaseOffset(phaseOffset);
      setPhaseStep(phaseStep);
    }

    SetRFOutputOffsetsPtr SetRFOutputOffsets::create(int outputIdx, double powerOffset, double timeOffset, double phaseOffset, const std::optional<double>& phaseStep)
    {
      return std::make_shared<SetRFOutputOffsets>(outputIdx, powerOffset, timeOffset, phaseOffset, phaseStep);
    }

    SetRFOutputOffsetsPtr SetRFOutputOffsets::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetRFOutputOffsets>(ptr);
    }

    bool SetRFOutputOffsets::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["OutputIdx"])
          && parse_json<double>::is_valid(m_values["PowerOffset"])
          && parse_json<double>::is_valid(m_values["TimeOffset"])
          && parse_json<double>::is_valid(m_values["PhaseOffset"])
          && parse_json<std::optional<double>>::is_valid(m_values["PhaseStep"])
        ;

    }

    std::string SetRFOutputOffsets::documentation() const { return Documentation; }

    const std::vector<std::string>& SetRFOutputOffsets::fieldNames() const 
    { 
      static const std::vector<std::string> names {"OutputIdx", "PowerOffset", "TimeOffset", "PhaseOffset", "PhaseStep"}; 
      return names; 
    }


    int SetRFOutputOffsets::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    int SetRFOutputOffsets::outputIdx() const
    {
      return parse_json<int>::parse(m_values["OutputIdx"]);
    }

    void SetRFOutputOffsets::setOutputIdx(int outputIdx)
    {
      m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetRFOutputOffsets::powerOffset() const
    {
      return parse_json<double>::parse(m_values["PowerOffset"]);
    }

    void SetRFOutputOffsets::setPowerOffset(double powerOffset)
    {
      m_values.AddMember("PowerOffset", parse_json<double>::format(powerOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetRFOutputOffsets::timeOffset() const
    {
      return parse_json<double>::parse(m_values["TimeOffset"]);
    }

    void SetRFOutputOffsets::setTimeOffset(double timeOffset)
    {
      m_values.AddMember("TimeOffset", parse_json<double>::format(timeOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetRFOutputOffsets::phaseOffset() const
    {
      return parse_json<double>::parse(m_values["PhaseOffset"]);
    }

    void SetRFOutputOffsets::setPhaseOffset(double phaseOffset)
    {
      m_values.AddMember("PhaseOffset", parse_json<double>::format(phaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<double> SetRFOutputOffsets::phaseStep() const
    {
      return parse_json<std::optional<double>>::parse(m_values["PhaseStep"]);
    }

    void SetRFOutputOffsets::setPhaseStep(const std::optional<double>& phaseStep)
    {
      m_values.AddMember("PhaseStep", parse_json<std::optional<double>>::format(phaseStep, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
