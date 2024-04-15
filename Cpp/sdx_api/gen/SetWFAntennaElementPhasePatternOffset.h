#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetWFAntennaElementPhasePatternOffset is deprecated since 23.11. You may use AddVehiclePhasePatternOffset.
    /// 
    /// Set WF Antenna phase pattern offset (in rad) for this element
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------------------------
    /// PhaseOffset double Antenna phase pattern offset (in rad) to set for this element. [-Pi ; Pi]
    /// Element     int    One-based index for element in antenna.
    ///

    class SetWFAntennaElementPhasePatternOffset;
    typedef std::shared_ptr<SetWFAntennaElementPhasePatternOffset> SetWFAntennaElementPhasePatternOffsetPtr;
    
    
    class SetWFAntennaElementPhasePatternOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      SetWFAntennaElementPhasePatternOffset();

      SetWFAntennaElementPhasePatternOffset(double phaseOffset, int element);

      static SetWFAntennaElementPhasePatternOffsetPtr create(double phaseOffset, int element);
      static SetWFAntennaElementPhasePatternOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** phaseOffset ****
      double phaseOffset() const;
      void setPhaseOffset(double phaseOffset);


      // **** element ****
      int element() const;
      void setElement(int element);
    };
    
  }
}

