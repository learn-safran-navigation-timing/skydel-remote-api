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
    /// Result of GetGaussianNoiseSeed.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------------------------------
    /// Id        string Target identifier.
    /// OutputIdx int    RF Output index (zero-based).
    /// Seed      int    Gaussian Noise seed. Value must be a positive integer between 0 and 2147483647.
    ///

    class GetGaussianNoiseSeedResult;
    typedef std::shared_ptr<GetGaussianNoiseSeedResult> GetGaussianNoiseSeedResultPtr;
    
    
    class GetGaussianNoiseSeedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGaussianNoiseSeedResult();

      GetGaussianNoiseSeedResult(const std::string& id, int outputIdx, int seed);

      GetGaussianNoiseSeedResult(CommandBasePtr relatedCommand, const std::string& id, int outputIdx, int seed);

      static GetGaussianNoiseSeedResultPtr create(const std::string& id, int outputIdx, int seed);

      static GetGaussianNoiseSeedResultPtr create(CommandBasePtr relatedCommand, const std::string& id, int outputIdx, int seed);
      static GetGaussianNoiseSeedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGaussianNoiseSeedResult);
  }
}

