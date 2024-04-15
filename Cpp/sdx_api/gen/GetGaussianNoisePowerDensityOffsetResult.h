#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGaussianNoisePowerDensityOffset.
    ///
    /// Name               Type   Description
    /// ------------------ ------ -------------------------------------------------------------------------------------
    /// Id                 string Target identifier
    /// OutputIdx          int    RF Output index (zero-based)
    /// PowerDensityOffset double Gaussian Noise power density offset (dB/Hz). Value must be between -10 and +10 dB/Hz.
    ///

    class GetGaussianNoisePowerDensityOffsetResult;
    typedef std::shared_ptr<GetGaussianNoisePowerDensityOffsetResult> GetGaussianNoisePowerDensityOffsetResultPtr;
    
    
    class GetGaussianNoisePowerDensityOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGaussianNoisePowerDensityOffsetResult();

      GetGaussianNoisePowerDensityOffsetResult(const std::string& id, int outputIdx, double powerDensityOffset);

      GetGaussianNoisePowerDensityOffsetResult(CommandBasePtr relatedCommand, const std::string& id, int outputIdx, double powerDensityOffset);

      static GetGaussianNoisePowerDensityOffsetResultPtr create(const std::string& id, int outputIdx, double powerDensityOffset);

      static GetGaussianNoisePowerDensityOffsetResultPtr create(CommandBasePtr relatedCommand, const std::string& id, int outputIdx, double powerDensityOffset);
      static GetGaussianNoisePowerDensityOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGaussianNoisePowerDensityOffsetResult);
  }
}

