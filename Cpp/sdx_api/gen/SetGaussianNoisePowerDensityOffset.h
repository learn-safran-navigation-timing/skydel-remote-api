#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the Noise Power Density Offset (dB/Hz) added to the base Gaussian Noise power density on the GNSS output (-174 dB/Hz). Default offset value is 0. If Gaussian Noise is not enabled on the output, this offset has no effect.
    ///
    /// Name               Type   Description
    /// ------------------ ------ -------------------------------------------------------------------------------------
    /// Id                 string Target identifier
    /// OutputIdx          int    RF Output index (zero-based)
    /// PowerDensityOffset double Gaussian Noise power density offset (dB/Hz). Value must be between -10 and +10 dB/Hz.
    ///

    class SetGaussianNoisePowerDensityOffset;
    typedef std::shared_ptr<SetGaussianNoisePowerDensityOffset> SetGaussianNoisePowerDensityOffsetPtr;
    
    
    class SetGaussianNoisePowerDensityOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGaussianNoisePowerDensityOffset();

      SetGaussianNoisePowerDensityOffset(const std::string& id, int outputIdx, double powerDensityOffset);

      static SetGaussianNoisePowerDensityOffsetPtr create(const std::string& id, int outputIdx, double powerDensityOffset);
      static SetGaussianNoisePowerDensityOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);


      // **** outputIdx ****
      int outputIdx() const;
      void setOutputIdx(int outputIdx);


      // **** powerDensityOffset ****
      double powerDensityOffset() const;
      void setPowerDensityOffset(double powerDensityOffset);
    };
    
  }
}

