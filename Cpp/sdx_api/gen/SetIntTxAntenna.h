#pragma once

#include <memory>
#include "command_base.h"

#include "gen/AntennaPatternType.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set transmitter antenna pattern.
    ///
    /// Name Type               Description
    /// ---- ------------------ -------------------------------------------------------------------------------------------------------------------------
    /// Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// Type AntennaPatternType Pattern type
    /// Id   string             Transmitter unique identifier.
    ///

    class SetIntTxAntenna;
    typedef std::shared_ptr<SetIntTxAntenna> SetIntTxAntennaPtr;
    
    
    class SetIntTxAntenna : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIntTxAntenna();

      SetIntTxAntenna(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id);

      static SetIntTxAntennaPtr create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id);
      static SetIntTxAntennaPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


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
    
  }
}

