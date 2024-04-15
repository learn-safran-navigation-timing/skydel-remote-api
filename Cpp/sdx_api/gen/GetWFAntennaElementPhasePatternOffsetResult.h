#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetWFAntennaElementPhasePatternOffset.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------------------------
    /// PhaseOffset double Antenna phase pattern offset (in rad) to set for this element. [-Pi ; Pi]
    /// Element     int    One-based index for element in antenna.
    ///

    class GetWFAntennaElementPhasePatternOffsetResult;
    typedef std::shared_ptr<GetWFAntennaElementPhasePatternOffsetResult> GetWFAntennaElementPhasePatternOffsetResultPtr;
    
    
    class GetWFAntennaElementPhasePatternOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetWFAntennaElementPhasePatternOffsetResult();

      GetWFAntennaElementPhasePatternOffsetResult(double phaseOffset, int element);

      GetWFAntennaElementPhasePatternOffsetResult(CommandBasePtr relatedCommand, double phaseOffset, int element);

      static GetWFAntennaElementPhasePatternOffsetResultPtr create(double phaseOffset, int element);

      static GetWFAntennaElementPhasePatternOffsetResultPtr create(CommandBasePtr relatedCommand, double phaseOffset, int element);
      static GetWFAntennaElementPhasePatternOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** phaseOffset ****
      double phaseOffset() const;
      void setPhaseOffset(double phaseOffset);


      // **** element ****
      int element() const;
      void setElement(int element);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetWFAntennaElementPhasePatternOffsetResult);
  }
}

