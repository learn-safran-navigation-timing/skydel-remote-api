#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetWFAntennaElementPhasePatternOffset is deprecated since 23.11. You may use GetVehiclePhasePatternOffset.
    /// 
    /// Get WF Antenna phase pattern offset (in rad) for this element
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------
    /// Element int  One-based index for element in antenna.
    ///

    class GetWFAntennaElementPhasePatternOffset;
    typedef std::shared_ptr<GetWFAntennaElementPhasePatternOffset> GetWFAntennaElementPhasePatternOffsetPtr;
    
    
    class GetWFAntennaElementPhasePatternOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      GetWFAntennaElementPhasePatternOffset();

      GetWFAntennaElementPhasePatternOffset(int element);

      static GetWFAntennaElementPhasePatternOffsetPtr create(int element);
      static GetWFAntennaElementPhasePatternOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** element ****
      int element() const;
      void setElement(int element);
    };
    
  }
}

