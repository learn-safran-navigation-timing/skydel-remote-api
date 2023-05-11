#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
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


      GetWFAntennaElementPhasePatternOffset();

      GetWFAntennaElementPhasePatternOffset(int element);

      static GetWFAntennaElementPhasePatternOffsetPtr create(int element);
      static GetWFAntennaElementPhasePatternOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** element ****
      int element() const;
      void setElement(int element);
    };
    
  }
}

