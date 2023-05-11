#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Change modulation offsets of one RF output
    ///
    /// Name        Type   Description
    /// ----------- ------ ----------------------------------------------------------------
    /// OutputIdx   int    RF Output index (zero-based)
    /// PowerOffset double Power offset (dB), to apply on all signals of the RF Output
    /// TimeOffset  double Time offset (seconds), to apply on all signals of the RF Output
    /// PhaseOffset double Phase offset (radians), to apply on all signals of the RF Output
    ///

    class SetRFOutputOffsets;
    typedef std::shared_ptr<SetRFOutputOffsets> SetRFOutputOffsetsPtr;
    
    
    class SetRFOutputOffsets : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetRFOutputOffsets();

      SetRFOutputOffsets(int outputIdx, double powerOffset, double timeOffset, double phaseOffset);

      static SetRFOutputOffsetsPtr create(int outputIdx, double powerOffset, double timeOffset, double phaseOffset);
      static SetRFOutputOffsetsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** outputIdx ****
      int outputIdx() const;
      void setOutputIdx(int outputIdx);


      // **** powerOffset ****
      double powerOffset() const;
      void setPowerOffset(double powerOffset);


      // **** timeOffset ****
      double timeOffset() const;
      void setTimeOffset(double timeOffset);


      // **** phaseOffset ****
      double phaseOffset() const;
      void setPhaseOffset(double phaseOffset);
    };
    
  }
}

