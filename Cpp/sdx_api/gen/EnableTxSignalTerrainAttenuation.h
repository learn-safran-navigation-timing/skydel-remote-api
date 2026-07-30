#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) terrain-based attenuation of interference and spoofing signals.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------------------------------------------------------------------------
    /// Enabled bool If true, the power of interference and spoofing signals will be reduced based on the terrain profile between the transmitter and the receiver.
    ///

    class EnableTxSignalTerrainAttenuation;
    typedef std::shared_ptr<EnableTxSignalTerrainAttenuation> EnableTxSignalTerrainAttenuationPtr;
    
    
    class EnableTxSignalTerrainAttenuation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableTxSignalTerrainAttenuation();

      EnableTxSignalTerrainAttenuation(bool enabled);

      static EnableTxSignalTerrainAttenuationPtr create(bool enabled);
      static EnableTxSignalTerrainAttenuationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

