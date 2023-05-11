
#include "gen/SetRFOutputOffsets.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetRFOutputOffsets
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetRFOutputOffsets::CmdName = "SetRFOutputOffsets";
    const char* const SetRFOutputOffsets::Documentation = "Change modulation offsets of one RF output";

    REGISTER_COMMAND_FACTORY(SetRFOutputOffsets);


    SetRFOutputOffsets::SetRFOutputOffsets()
      : CommandBase(CmdName)
    {}

    SetRFOutputOffsets::SetRFOutputOffsets(int outputIdx, double powerOffset, double timeOffset, double phaseOffset)
      : CommandBase(CmdName)
    {

      setOutputIdx(outputIdx);
      setPowerOffset(powerOffset);
      setTimeOffset(timeOffset);
      setPhaseOffset(phaseOffset);
    }

    SetRFOutputOffsetsPtr SetRFOutputOffsets::create(int outputIdx, double powerOffset, double timeOffset, double phaseOffset)
    {
      return std::make_shared<SetRFOutputOffsets>(outputIdx, powerOffset, timeOffset, phaseOffset);
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
        ;

    }

    std::string SetRFOutputOffsets::documentation() const { return Documentation; }


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


  }
}
