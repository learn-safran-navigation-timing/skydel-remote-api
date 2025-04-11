#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the seed used to generate the Gaussian Noise. Gaussian Noise must be enabled on the output. It is optional to set the seed of an output. By default, the seed value used is the index of the output.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------------------------------
    /// Id        string Target identifier.
    /// OutputIdx int    RF Output index (zero-based).
    /// Seed      int    Gaussian Noise seed. Value must be a positive integer between 0 and 2147483647.
    ///

    class SetGaussianNoiseSeed;
    typedef std::shared_ptr<SetGaussianNoiseSeed> SetGaussianNoiseSeedPtr;
    
    
    class SetGaussianNoiseSeed : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGaussianNoiseSeed();

      SetGaussianNoiseSeed(const std::string& id, int outputIdx, int seed);

      static SetGaussianNoiseSeedPtr create(const std::string& id, int outputIdx, int seed);
      static SetGaussianNoiseSeedPtr dynamicCast(CommandBasePtr ptr);
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


      // **** seed ****
      int seed() const;
      void setSeed(int seed);
    };
    
  }
}

