#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells whether GNSS signals obscuration by terrain is enabled.
    ///
    /// 
    ///

    class IsGnssSignalTerrainObscurationEnabled;
    typedef std::shared_ptr<IsGnssSignalTerrainObscurationEnabled> IsGnssSignalTerrainObscurationEnabledPtr;
    
    
    class IsGnssSignalTerrainObscurationEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsGnssSignalTerrainObscurationEnabled();

      static IsGnssSignalTerrainObscurationEnabledPtr create();
      static IsGnssSignalTerrainObscurationEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

