#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells whether terrain-based attenuation of interference and spoofing signals is enabled.
    ///
    /// 
    ///

    class IsTxSignalTerrainAttenuationEnabled;
    typedef std::shared_ptr<IsTxSignalTerrainAttenuationEnabled> IsTxSignalTerrainAttenuationEnabledPtr;
    
    
    class IsTxSignalTerrainAttenuationEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsTxSignalTerrainAttenuationEnabled();

      static IsTxSignalTerrainAttenuationEnabledPtr create();
      static IsTxSignalTerrainAttenuationEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

