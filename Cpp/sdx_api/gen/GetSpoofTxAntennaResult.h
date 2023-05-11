#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "gen/AntennaPatternType.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSpoofTxAntenna.
    ///
    /// Name Type               Description
    /// ---- ------------------ -------------------------------------------------------------------------------------------------------------------------
    /// Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// Type AntennaPatternType Pattern type
    /// Id   string             Transmitter unique identifier.
    ///

    class GetSpoofTxAntennaResult;
    typedef std::shared_ptr<GetSpoofTxAntennaResult> GetSpoofTxAntennaResultPtr;
    
    
    class GetSpoofTxAntennaResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSpoofTxAntennaResult();

      GetSpoofTxAntennaResult(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id);

      GetSpoofTxAntennaResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id);

      static GetSpoofTxAntennaResultPtr create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id);

      static GetSpoofTxAntennaResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id);
      static GetSpoofTxAntennaResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** gain ****
      std::vector<std::vector<double>> gain() const;
      void setGain(const std::vector<std::vector<double>>& gain);


      // **** type ****
      Sdx::AntennaPatternType type() const;
      void setType(const Sdx::AntennaPatternType& type);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSpoofTxAntennaResult);
  }
}

